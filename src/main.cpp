#include <chrono>
#include <csignal>
#include <gaga/gaga.hpp>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_set>
#include "config.hpp"
#include "helper.hpp"

using dna_t = Config::dna_t;
using namespace std::chrono_literals;
static int s_interrupted = 0;
static void s_signal_handler(int) {
	s_interrupted = 1;
	std::cerr << "sig" << std::endl;
	throw std::runtime_error("interrupted");
}
static void s_catch_signals() {
	struct sigaction action;
	action.sa_handler = s_signal_handler;
	action.sa_flags = 0;
	sigemptyset(&action.sa_mask);
	sigaction(SIGINT, &action, NULL);
	sigaction(SIGTERM, &action, NULL);
}

std::queue<request_t> readyRequests;  // ready requests are stored here when waiting
std::unordered_set<std::string> workingWorkers;  // list of currently working clients

void terminate(zmq::context_t& context, zmq::socket_t& socket) {
	std::cerr << "Terminating server, sending STOP signal to all workers" << std::endl;
	json stop = {{"req", "STOP"}};
	// we send a stop to all workers
	int timeout = 400;
	zmq_setsockopt(socket, ZMQ_RCVTIMEO, &timeout, sizeof(int));
	// same for all working workers
	for (const auto& w : workingWorkers) {
		sendJson(socket, w, stop);
		sendJson(socket, w, stop);
		std::cerr << "working : " << w << std::endl;
	}
	workingWorkers.clear();
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
	std::cerr << readyRequests.size() << " ready, " << workingWorkers.size() << " working."
	          << std::endl;
	while (readyRequests.size() > 0) {
		auto r = readyRequests.front();
		readyRequests.pop();
		std::cerr << "ready : " << r.first << std::endl;
		sendJson(socket, r.first, stop);
		recvString(socket);
		sendJson(socket, r.first, stop);
	}
	socket.close();
	context.close();
}

template <typename G>
void distributedEvaluate(
    G& ga, zmq::context_t& context, zmq::socket_t& socket,
    json extra = {}) {  // extra is sent to the workers with each EVAL re
	if (workingWorkers.size() > 0)
		std::cerr << "[WARNING] non empty working client list at begining of evaluation"
		          << std::endl;
	workingWorkers.clear();
	std::unordered_set<size_t> toEvaluate;  // id of individuals to evaluate
	for (size_t i = 0; i < ga.population.size(); ++i)
		if (ga.getEvaluateAllIndividuals() || !ga.population[i].evaluated)
			toEvaluate.insert(i);

	size_t waitingFor = toEvaluate.size();
	ga.printLn(3, toEvaluate.size(), " evaluations ready to be distributed");

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
				workingWorkers.insert(request.first);
				ga.printLn(3, "Sending \"", request.first, "\" ", qtty, " DNA for evaluation");
			} else {
				auto request = recvRequest(socket);
				auto& req = request.second;
				if (req.at("req") == "READY") {  // we save for the next iteration
					readyRequests.push(request);
					ga.printLn(3, "Received READY from ", request.first);
				} else if (req.at("req") == "RESULT") {  // we need to update the individuals
					if (!workingWorkers.count(request.first))
						std::cerr << "[WARNING] An unknown worker just sent a result." << std::endl;
					else
						workingWorkers.erase(request.first);
					ga.printLn(3, "Received RESULT from ", request.first);
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
		} catch (...) {
			std::cout << "Exception was raised, aborting" << std::endl;
			s_interrupted = 1;
		}
		if (s_interrupted) {
			terminate(context, socket);
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

	GAGA::GA<dna_t> ga;

	std::random_device rd;
	dna_t::getRandomEngine().seed(rd());

	zmq::context_t context(1);
	zmq::socket_t socket(context, ZMQ_ROUTER);
	socket.bind(cfg.port);

	ga.setEvaluateFunction([&]() { distributedEvaluate(ga, context, socket); });

	ga.setComputeFootprintDistanceFunction([](const auto& fpA, const auto& fpB) {
		// sum of squared distances
		// assuming footprint_t is vector<vector<double>>
		assert(fpA.size() == fpB.size());
		double dist = 0;
		for (size_t i = 0; i < fpA.size(); ++i)
			for (size_t j = 0; j < fpA[i].size(); ++j)
				dist += std::pow(fpA[i][j] - fpB[i][j], 2);
		return dist;
	});

	ga.setPopSize(cfg.popSize);
	ga.setMutationRate(cfg.mutationRate);
	ga.setCrossoverRate(cfg.crossoverRate);
	ga.setVerbosity(cfg.verbosity);
	ga.setSaveFolder(cfg.saveFolder);
	ga.setNbThreads(cfg.nbThreads);

	ga.setPopSaveInterval(cfg.popSaveInterval);
	ga.setGenSaveInterval(cfg.genSaveInterval);
	ga.setSaveParetoFront(cfg.saveParetoFront);
	ga.setSaveIndStats(cfg.saveIndividualStats);
	ga.setSaveGenStats(cfg.saveGenerationStats);

	if (cfg.enableNovelty)
		ga.enableNovelty();
	else
		ga.disableNovelty();

	if (cfg.saveNoveltyArchive)
		ga.enableArchiveSave();
	else
		ga.disableArchiveSave();

	s_catch_signals();
	ga.initPopulation([&]() { return dna_t::random(&(cfg.DNA)); });

	SQLiteSaver saver(cfg.SQLiteSaveFile);
	if (cfg.SQLiteSaveEnabled) saver.createTables();
	for (size_t i = 0; i < cfg.nbGenerations; ++i) {
		ga.step();
		if (cfg.SQLiteSaveEnabled) saver.newGen(ga);
	}
	terminate(context, socket);
	return 0;
}
