#pragma once
#include <boost/hana.hpp>
#include <cxxopts.hpp>
#include <fstream>
#include <gaga/include/json.hpp>

#define DECLARE_CONFIG(N, ...)                                                     \
	BOOST_HANA_DEFINE_STRUCT(N, __VA_ARGS__);                                        \
	bool warningsEnabled = false;                                                    \
	void load(std::string file) {                                                    \
		std::ifstream t(file);                                                         \
		std::stringstream buffer;                                                      \
		buffer << t.rdbuf();                                                           \
		auto o = nlohmann::json::parse(buffer.str());                                  \
		constexpr auto accessors = boost::hana::accessors<N>();                        \
		boost::hana::for_each(                                                         \
		    boost::hana::transform(accessors, [](auto a) { return a; }), [&](auto p) { \
			    constexpr auto getMember = boost::hana::second(p);                       \
			    std::string k(boost::hana::to<char const*>(boost::hana::first(p)));      \
			    if (o.count(k)) {                                                        \
				    getMember(*this) = o.at(k);                                            \
				    o.erase(k);                                                            \
			    } else if (warningsEnabled)                                              \
				    std::cerr << "Unable to find param " << k << " in configuration file"  \
				              << std::endl;                                                \
		    });                                                                        \
		if (warningsEnabled)                                                           \
			for (auto it = o.begin(); it != o.end(); ++it) {                             \
				std::cerr << "Unknown param: " << it.key() << std::endl;                   \
			}                                                                            \
	}                                                                                \
                                                                                   \
	void parse(int argc, char** argv) {                                              \
		constexpr auto accessors = boost::hana::accessors<N>();                        \
		cxxopts::Options options(argv[0]);                                             \
		boost::hana::for_each(                                                         \
		    boost::hana::transform(accessors, [](auto a) { return a; }), [&](auto p) { \
			    constexpr auto getMember = boost::hana::second(p);                       \
			    std::string k(boost::hana::to<char const*>(boost::hana::first(p)));      \
			    auto& r = getMember(*this);                                              \
			    options.add_options()(                                                   \
			        k, k, cxxopts::value<std::remove_reference_t<decltype(r)>>(r));      \
		    });                                                                        \
		options.parse(argc, argv);                                                     \
	}                                                                                \
                                                                                   \
	std::string printJSON() {                                                        \
		nlohmann::json j;                                                              \
		std::stringstream out;                                                         \
		boost::hana::for_each(*this, [&](auto p) {                                     \
			std::string k(boost::hana::to<char const*>(boost::hana::first(p)));          \
			j[k] = boost::hana::second(p);                                               \
		});                                                                            \
		out << j.dump(2);                                                              \
		return out.str();                                                              \
	}                                                                                \
	void save(std::string file) {                                                    \
		std::ofstream fs(file);                                                        \
		fs << printJSON();                                                             \
		fs.close();                                                                    \
	}
