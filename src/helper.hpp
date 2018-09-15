#include <gaga/include/json.hpp>
#include <zmq.hpp>

using json = nlohmann::json;
using request_t = std::pair<std::string, json>;  // identity + request content

// helpers functions for zmq
inline zmq::message_t recv(zmq::socket_t& socket) {
	zmq::message_t message;
	socket.recv(&message);
	return message;
}
inline std::string recvString(zmq::socket_t& socket) {
	zmq::message_t message;
	socket.recv(&message);
	return std::string(static_cast<char*>(message.data()), message.size());
}

inline json recvJson(zmq::socket_t& socket) {
	zmq::message_t req;
	socket.recv(&req);
	return json::parse(static_cast<char*>(req.data()),
	                   static_cast<char*>(req.data()) + req.size());
}

inline void sendStr(zmq::socket_t& socket, const std::string& identity,
                    const std::string& strg) {
	{
		std::string s = identity;
		zmq::message_t m(s.size());
		memcpy(m.data(), s.data(), s.size());
		socket.send(m, ZMQ_SNDMORE);
	}
	{
		zmq::message_t m(0);
		socket.send(m, ZMQ_SNDMORE);
	}
	{
		std::string s = strg;
		zmq::message_t m(s.size());
		memcpy(m.data(), s.data(), s.size());
		socket.send(m);
	}
}

inline void sendJson(zmq::socket_t& socket, const std::string& identity, const json& j) {
	{
		std::string s = identity;
		zmq::message_t m(s.size());
		memcpy(m.data(), s.data(), s.size());
		socket.send(m, ZMQ_SNDMORE);
	}
	{
		zmq::message_t m(0);
		socket.send(m, ZMQ_SNDMORE);
	}
	{
		std::string s = j.dump(1);
		zmq::message_t m(s.size());
		memcpy(m.data(), s.data(), s.size());
		socket.send(m);
	}
}

inline request_t recvRequest(zmq::socket_t& socket) {
	std::string identity = recvString(socket);
	recv(socket);  // delimiter
	json req = recvJson(socket);
	return std::make_pair(identity, req);
}
