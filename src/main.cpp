#include <csignal>
#include <gaga/gaga.hpp>
#include <iostream>
#include <string>
#include "config.hpp"
#include "helper.hpp"

using dna_t = Config::dna_t;

static int s_interrupted = 0;
static void s_signal_handler(int) { s_interrupted = 1; }

static void s_catch_signals() {
	struct sigaction action;
	action.sa_handler = s_signal_handler;
	action.sa_flags = 0;
	sigemptyset(&action.sa_mask);
	sigaction(SIGINT, &action, NULL);
	sigaction(SIGTERM, &action, NULL);
}

std::queue<request_t> readyRequests;  // ready requests are stored here when waiting

void terminate(zmq::socket_t& socket) {
	std::cerr << "Terminating server, sending STOP signal to all workers" << std::endl;
	// we send a stop to all workers
	int timeout = 300;
	zmq_setsockopt(socket, ZMQ_RCVTIMEO, &timeout, sizeof(int));
	// first we check if some workers are still sending stuff
	zmq::message_t message;
	while (socket.recv(&message)) {
		// a worker has sent its identity
		std::string id(static_cast<char*>(message.data()), message.size());
		recv(socket);
		json j = recvJson(socket);
		// we add it to the readyRequests (even if it's not a ready request...)
		readyRequests.push(std::make_pair(id, j));
	}
	// then we go through all readyRequests and tell the senders to stop working
	while (readyRequests.size() > 0) {
		auto r = readyRequests.front();
		readyRequests.pop();
		json j = {{"req", "STOP"}};
		sendJson(socket, r.first, j);
	}
}

template <typename G> void distributedEvaluate(G& ga, zmq::socket_t& socket) {
	std::unordered_set<size_t> toEvaluate;  // id of individuals to evaluate
	for (size_t i = 0; i < ga.population.size(); ++i)
		if (ga.getEvaluateAllIndividuals() || !ga.population[i].evaluated)
			toEvaluate.insert(i);

	size_t waitingFor = toEvaluate.size();
	ga.printLn(3, toEvaluate.size(), " evaluations ready to be distributed");

	s_catch_signals();
	while (waitingFor > 0) {
		try {
			if (toEvaluate.size() > 0 && readyRequests.size() > 0) {
				auto request = readyRequests.front();
				readyRequests.pop();
				auto& req = request.second;
				size_t qtty = 1u;  // size of dna batch
				if (req.count("qtty"))
					qtty = std::min(toEvaluate.size(), req.at("qtty").get<size_t>());
				std::vector<json> dnas;
				for (size_t i = 0; i < qtty; ++i) {
					size_t indId = *toEvaluate.begin();
					toEvaluate.erase(indId);
					dnas.push_back({{"id", indId}, {"dna", ga.population[indId].dna.serialize()}});
				}
				json j = {{"req", "EVAL"}, {"individuals", dnas}};
				sendJson(socket, request.first, j);
				ga.printLn(3, "Sending \"", request.first, "\" ", qtty, " DNA for evaluation");
			} else {
				auto request = recvRequest(socket);
				auto& req = request.second;
				if (req.at("req") == "READY") {  // we save for the next iteration
					readyRequests.push(request);
					ga.printLn(3, "Received READY");
				} else if (req.at("req") == "RESULT") {  // we need to update the individuals
					ga.printLn(3, "Received RESULT");
					auto individuals = req.at("individuals");
					for (auto& i : individuals) {
						auto id = i.at("id");
						if (i.count("fitnesses"))
							ga.population[id].fitnesses =
							    i.at("fitnesses")
							        .get<decltype(std::declval<typename G::Ind_t>().fitnesses)>();
						if (i.count("footprint"))
							ga.population[id].footprint =
							    i.at("footprint")
							        .get<decltype(std::declval<typename G::Ind_t>().footprint)>();
						if (i.count("infos")) ga.population[id].infos = i.at("infos");
						if (i.count("evalTime")) ga.population[id].evalTime = i.at("evalTime");
						if (ga.getVerbosity() >= 2) ga.printIndividualStats(ga.population[id]);
					}
					assert(individuals.size() <= waitingFor);
					waitingFor -= individuals.size();
					sendStr(socket, request.first, "");
				}
			}
		} catch (zmq::error_t& e) {
			std::cout << "W: interrupt received, proceeding…" << std::endl;
		}
		if (s_interrupted) {
			std::cout << "W: killing server…" << std::endl;
			terminate(socket);
			exit(0);
		}
	}
}

int main(int argc, char** argv) {
	Config cfg;
	if (argc > 1) {
		auto configPath = argv[1];
		std::cout << "Using config file " << configPath << std::endl;
		cfg.loadFromFile(configPath);
	}

	// cfg.parse(argc, argv);

	GAGA::GA<dna_t> ga;

	std::random_device rd;
	dna_t::getRandomEngine().seed(rd());

	zmq::context_t context(1);
	zmq::socket_t socket(context, ZMQ_ROUTER);
	socket.bind(cfg.port);
	ga.setEvaluateFunction([&]() { distributedEvaluate(ga, socket); });
	ga.setPopSize(cfg.popSize);
	ga.setMutationRate(cfg.mutationRate);
	ga.setCrossoverRate(cfg.crossoverRate);
	ga.setVerbosity(cfg.verbosity);
	ga.initPopulation([&]() { return dna_t::random(&(cfg.DNACfg)); });
	ga.step(cfg.nbGenerations);
	terminate(socket);
	return 0;
}
