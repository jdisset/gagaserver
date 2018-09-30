#ifndef METACONFIG_HPP
#define METACONFIG_HPP
#include <boost/hana.hpp>
#include <cstring>
#include <fstream>
#include <iostream>
#include <memory>
#include <regex>
#include "helper.hpp"
#include "includes/cxxopts.hpp"
#include "includes/json.hpp"

template <class METACONFIG_T>
constexpr bool isConfig(typename METACONFIG_T::isAConfigClass*) {
	return true;
}
template <class METACONFIG_T> constexpr bool isConfig(...) { return false; }

class Argv {
 public:
	Argv(const std::vector<std::string>& args)
	    : m_argv(new char*[args.size()]), m_argc(args.size()) {
		int i = 0;
		auto iter = args.begin();
		while (iter != args.end()) {
			auto len = (*iter).size() + 1;
			auto ptr = std::unique_ptr<char[]>(new char[len]);
			std::strcpy(ptr.get(), (*iter).c_str());
			m_args.push_back(std::move(ptr));
			m_argv.get()[i] = m_args.back().get();
			++iter;
			++i;
		}
	}

	char** argv() const { return m_argv.get(); }

	int argc() const { return m_argc; }

 private:
	std::vector<std::unique_ptr<char[]>> m_args;
	std::unique_ptr<char* []> m_argv;
	int m_argc;
};

#define METACONFIG_DECLARE_SERIALIZABLE_BODY(N)                                         \
	using isAConfigClass = bool;                                                          \
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
	}

#define METACONFIG_DECLARE_PARSABLE(N)                                                \
	void parse(int argc, char** argv) {                                                 \
		cxxopts::Options opt(argv[0]);                                                    \
		declareOptions<N>("", *this, opt);                                                \
		opt.allow_unrecognised_options();                                                 \
		std::vector<std::string> strArgv;                                                 \
		for (int i = 0; i < argc; ++i) {                                                  \
			std::string s(argv[i]);                                                         \
			std::replace(s.begin(), s.end(), ':', '_');                                     \
			strArgv.push_back(s);                                                           \
		}                                                                                 \
		Argv margv(strArgv);                                                              \
		char** actualArgv = margv.argv();                                                 \
		opt.parse(argc, actualArgv);                                                      \
	}                                                                                   \
                                                                                      \
	template <typename C>                                                               \
	static inline void declareOptions(const std::string& nspace, C& c,                  \
	                                  cxxopts::Options& opt) {                          \
		constexpr auto accessors = boost::hana::accessors<C>();                           \
		boost::hana::for_each(                                                            \
		    boost::hana::transform(accessors, [](auto a) { return a; }), [&](auto p) {    \
			    std::string k(boost::hana::to<char const*>(boost::hana::first(p)));         \
			    k = nspace + k;                                                             \
			    auto& r = boost::hana::second(p)(c);                                        \
			    addOrRecurse(k, r, opt);                                                    \
		    });                                                                           \
	}                                                                                   \
                                                                                      \
	template <typename METACONFIG_T>                                                    \
	static inline typename std::enable_if<isConfig<METACONFIG_T>(nullptr)>::type        \
	    addOrRecurse(const std::string& name, METACONFIG_T& t, cxxopts::Options& opt) { \
		std::string nextnspace = name + "__";                                             \
		declareOptions<METACONFIG_T>(nextnspace, t, opt);                                 \
	}                                                                                   \
                                                                                      \
	template <typename METACONFIG_T>                                                    \
	static inline typename std::enable_if<!isConfig<METACONFIG_T>(nullptr)>::type       \
	    addOrRecurse(const std::string& name, METACONFIG_T& t, cxxopts::Options& opt) { \
		if (name[0] == '"' && name[name.size() - 1] == '"')                               \
			std::cerr << name << " is json" << std::endl;                                   \
		opt.add_options()(name, name,                                                     \
		                  cxxopts::value<std::remove_reference_t<decltype(t)>>(t));       \
	}

#define DECLARE_CONFIG_BODY(N)            \
	METACONFIG_DECLARE_SERIALIZABLE_BODY(N) \
	METACONFIG_DECLARE_PARSABLE(N)

#define DECLARE_SERIALIZABLE(N, ...)        \
	BOOST_HANA_DEFINE_STRUCT(N, __VA_ARGS__); \
	METACONFIG_DECLARE_SERIALIZABLE_BODY(N)

#define DECLARE_CONFIG(N, ...)              \
	BOOST_HANA_DEFINE_STRUCT(N, __VA_ARGS__); \
	DECLARE_CONFIG_BODY(N)

#define DECLARE_CONFIG_WITH_DEFAULT(N, ...) \
	TUN_DEFINE_STRUCT(N, __VA_ARGS__);        \
	DECLARE_CONFIG_BODY(N)
#endif
