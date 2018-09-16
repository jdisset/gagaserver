#pragma once
#include <cxxopts.hpp>
#include <gaga/dna/vectordna.hpp>
#include "metaconfig.hpp"

struct Config {
	// ---------   STATIC CONFIG  ----------
	using dna_t = GAGA::VectorDNA<double>;

	// ---------   DYNAMIC CONFIG  ----------
	DECLARE_CONFIG(Config, (dna_t::Config, DNACfg), (std::string, port), (size_t, popSize),
	               (double, mutationRate), (double, crossoverRate), (int, verbosity),
	               (int, nbGenerations))

	Config() {
		// default values:
		port = "tcp://*:4321";
		popSize = 200;
		mutationRate = 0.5;
		crossoverRate = 0.5;
		verbosity = 2;
		nbGenerations = 10;
	}
};
