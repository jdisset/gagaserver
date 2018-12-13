#pragma once
#include <cxxopts.hpp>
#include <gaga/dna/vectordna.hpp>
#include <metaconfig/metaconfig.hpp>

struct Config {
	// ---------   STATIC CONFIG  ----------
	using dna_t = GAGA::VectorDNA<double>;
	// the dna also has its own config (cf. its header file)

	// ---------   DYNAMIC CONFIG  ----------
	DECLARE_CONFIG(Config, (dna_t::Config, DNA), (std::string, port), (size_t, popSize),
	               (double, mutationRate), (double, crossoverRate), (int, verbosity),
	               (size_t, nbGenerations), (std::string, saveFolder), (bool, enableNovelty),
	               (size_t, nbThreads), (bool, saveNoveltyArchive),
	               (size_t, popSaveInterval), (size_t, genSaveInterval), (bool, SQLiteSaveEnabled), (std::string, SQLiteSaveFile),
	               (bool, saveGenerationStats), (bool, saveIndividualStats),
	               (bool, saveParetoFront))

	Config() {
		// default values:
		port = "tcp://*:4321";
		popSize = 200;
		mutationRate = 0.5;
		crossoverRate = 0.5;
		verbosity = 2;
		nbGenerations = 200;
		saveFolder = "../evos/";
		enableNovelty = false;
		nbThreads = 1;
		saveNoveltyArchive = true;
		popSaveInterval = 1;
		genSaveInterval = 1;
		saveGenerationStats = true;
		saveIndividualStats = false;
		saveParetoFront = true;
		SQLiteSaveEnabled = false;
	}
};
