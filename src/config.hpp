#pragma once
#include "metaconfig.hpp"
#include <cxxopts.hpp>

struct Config {
	// ---------   STATIC CONFIG  ----------
	using dna_t = GAGA::ArrayDNA<double, 10>;

	// ---------   DYNAMIC CONFIG  ----------
	DECLARE_CONFIG(Config, (std::string, port), (size_t, popSize), (double, mutationRate),
	               (double, crossoverRate), (int, verbosity), (int, nbGenerations))

	Config() {
		// default values:
		port = "tcp://*:4321";
		popSize = 200;
		mutationRate = 0.5;
		crossoverRate = 0.5;
		verbosity = 2;
		nbGenerations = 400;
	}
};
