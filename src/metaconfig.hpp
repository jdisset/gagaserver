#ifndef METACONFIG_HPP
#define METACONFIG_HPP

#include <boost/hana.hpp>
#include <fstream>
#include <iostream>
#include "external/cxxopts.hpp"
#include "external/gaga/include/json.hpp"

#define DECLARE_CONFIG(N, ...)                                                          \
	BOOST_HANA_DEFINE_STRUCT(N, __VA_ARGS__);                                             \
	void loadFromFile(std::string file) {                                                 \
		std::ifstream t(file);                                                              \
		std::stringstream buffer;                                                           \
		buffer << t.rdbuf();                                                                \
		auto o = nlohmann::json::parse(buffer.str());                                       \
		from_json(o);                                                                       \
	}                                                                                     \
                                                                                        \
	void from_json(const nlohmann::json& js) {                                            \
		nlohmann::json o(js);                                                               \
		constexpr auto accessors = boost::hana::accessors<N>();                             \
		boost::hana::for_each(                                                              \
		    boost::hana::transform(accessors, [](auto a) { return a; }), [&](auto p) {      \
			    constexpr auto getMember = boost::hana::second(p);                            \
			    std::string k(boost::hana::to<char const*>(boost::hana::first(p)));           \
			    if (o.count(k)) {                                                             \
				    getMember(*this) =                                                          \
				        o.at(k).get<std::remove_reference_t<decltype(getMember(*this))>>();     \
				    o.erase(k);                                                                 \
			    } else                                                                        \
				    std::cerr << "WARN: Unable to find param " << k << " in configuration file" \
				              << std::endl;                                                     \
		    });                                                                             \
		for (auto it = o.begin(); it != o.end(); ++it) {                                    \
			std::cerr << "Unknown param: " << it.key() << std::endl;                          \
		}                                                                                   \
	}                                                                                     \
                                                                                        \
	nlohmann::json to_json() const {                                                      \
		nlohmann::json j;                                                                   \
		boost::hana::for_each(*this, [&](auto p) {                                          \
			std::string k(boost::hana::to<char const*>(boost::hana::first(p)));               \
			j[k] = boost::hana::second(p);                                                    \
		});                                                                                 \
		return j;                                                                           \
	}                                                                                     \
                                                                                        \
	std::string print() {                                                                 \
		std::stringstream out;                                                              \
		out << to_json().dump(2);                                                           \
		return out.str();                                                                   \
	}                                                                                     \
                                                                                        \
	void save(std::string file) {                                                         \
		std::ofstream fs(file);                                                             \
		fs << print();                                                                      \
		fs.close();                                                                         \
	}                                                                                     \
	bool operator==(const N& other) { return (to_json() == other.to_json()); }

/*void parse(int argc, char** argv) {*/
// constexpr auto accessors = boost::hana::accessors<N>();
// cxxopts::Options options(argv[0]);
// options.allow_unrecognised_options();
// boost::hana::for_each(
// boost::hana::transform(accessors, [](auto a) { return a; }), [&](auto p) {
// std::string k(boost::hana::to<char const*>(boost::hana::first(p)));
// auto& r = boost::hana::second(p)(*this);
// options.add_options()(k, k,
// cxxopts::value<std::remove_reference_t<decltype(r)>>(r));
//});
// options.parse(argc, argv);
//}

// get_ref<decltype(getMember(*this))>();
#endif
