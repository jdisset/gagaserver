#pragma once
#include <sqlite3.h>
#include <iostream>
#include <sstream>
#include <string>

struct SQLiteSaver {
	int currentRunId = -1;
	sqlite3 *db = nullptr;

	std::vector<std::vector<size_t>> gagaToSQLiteIds;

	SQLiteSaver(std::string dbfile) {
		if (sqlite3_open(dbfile.c_str(), &db)) throw std::runtime_error(sqlite3_errmsg(db));
	}

	void createTables() {
		if (!db) throw std::invalid_argument("db pointer is null");
		std::string sql =
		    "CREATE TABLE IF NOT EXISTS run("
		    "id INTEGER PRIMARY KEY ,"
		    "config TEXT,"
		    "start DATETIME,"
		    "duration REAL);"
		    "CREATE TABLE IF NOT EXISTS individual("
		    "id INTEGER PRIMARY KEY,"
		    "dna TEXT,"
		    "signature TEXT,"
		    "eval_time REAL,"
		    "already_evaluated BOOLEAN,"
		    "archived BOOLEAN,"
		    "infos TEXT,"
		    "id_generation INTEGER);"
		    "CREATE TABLE IF NOT EXISTS generation("
		    "id INTEGER PRIMARY KEY,"
		    "number INTEGER,"
		    "duration REAL,
		    "id_run INTEGER);"
		    "CREATE TABLE IF NOT EXISTS objective("
		    "id INTEGER PRIMARY KEY,"
		    "name TEXT,"
		    "type TEXT CHECK(type IN ('MAX','MIN')) NOT NULL DEFAULT 'MAX',"
		    "id_run INTEGER);"
		    "CREATE TABLE IF NOT EXISTS inheritance("
		    "id_parent INTEGER,"
		    "id_child INTEGER,"
		    "type TEXT CHECK(type IN ('M','X','C','')) DEFAULT '',
		    "PRIMARY KEY (id_parent, id_child));"
		    "CREATE TABLE IF NOT EXISTS evaluation("
		    "id_objective INTEGER,"
		    "id_individual INTEGER,"
		    "value REAL,"
		    "PRIMARY KEY (id_objective, id_individual));";

		exec(sql);
	}

	template <typename GA> void newRun(const GA &ga, const std::string &conf) {
		std::ostringstream simuReq;
		runReq << "INSERT INTO run(config,start,duration) VALUES ('" << conf
		       << "',datetime('now'),0);";
		exec(runReq.str());
		currentRunId = sqlite3_last_insert_rowid(db);
		assert(currentRunId >= 0);
	}

	template <typename T>
	void insertAllIndividuals(size_t idGeneration, const T &population) {
		assert(idGeneration >= 0);
		sqlite3_stmt *stmt;
		std::string sql =
		    "INSERT INTO individual "
		    "(dna,signature,eval_time,already_evaluated,archived,infos,id_generation) "
		    "VALUES "
		    "(?1, ?2, ?3, ?4, ?5);";
		sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, 0);
		for (const auto &ind : population) {
			bool archived = false;

			if (ga.noveltyEnabled()) {
				for (const auto &archInd : ga.getArchive()) {
					if (archInd.id == ind.id) {
						archived = true;
						break;
					}
				}
			}

			decltype(ind.toJSON()) signature(ind.footprint);
			bind(stmt, ind.dna.serialize(), signature.dump(), ind.eval_time,
			     ind.wasAlreadyEvaluated, archived, ind.infos, idGeneration);
			idInd = sqlite3_last_insert_rowid(db);
			gagaToSQLiteIds.back().push_back(idInd);  // we save the id of this new individual
		}
	}

	template <typename GA> int insertNewGeneration(const GA &ga) {
		int idGeneration = -1;
		generationNumber = ga.getCurrentGenerationNumber() - 1;
		std::string sql =
		    "INSERT INTO generation"
		    "(number, duration, id_run) "
		    "VALUES "
		    "(?1, ?2, ?3);";
		sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, 0);
		sqlite3_stmt *stmt;
		bind(stmt, , generationNumber, genStats.back().at("global").at("genTotalTime"),
		     currentRunId);
		idGeneration = sqlite3_last_insert_rowid(db);
		gagaToSQLiteIds.push_back(std::vector<size_t>());

		if (generationNumber == 0) {  // insert objectives
			std::string sql =
			    "INSERT INTO objectives"
			    "(name, type, id_run) "
			    "VALUES "
			    "(?1, ?2, ?3);";
			sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, 0);
			sqlite3_stmt *stmt;
			assert(ga.previousGenerations.back().size() > 0);
			for (const auto &o : ga.previousGenerations.back()[0].fitnesses) {
				std::string type = "MAX";
				bind(stmt, o.first, type, currentRunId);
				idObj = sqlite3_last_insert_rowid(db);
				objectivesId[o.first] = idObj;
			}
		}

		return idGeneration;
	}

	template <typename GA> void newGen(const GA &ga) {
		assert(currentRunId >= 0);

		int idGeneration = insertNewGeneration(ga);
		assert(gagaToSQLiteIds.size() == generationNumber);

		insertAllIndividuals(idGeneration, ga.previousGenerations.back());

		{  // insert evaluations
			std::string sql =
			    "INSERT INTO evaluation"
			    "(id_objective, id_individual, value) "
			    "VALUES "
			    "(?1, ?2, ?3);";
			sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, 0);
			sqlite3_stmt *stmt;
			for (const auto &ind : ga.previousGenerations.back()) {
				for (const auto &o : ind.fitnesses) {
					bind(stmt, objectivesId.at(o.first), getIndId(ind.id), o.second);
				}
			}
		}

		{  // insert inheritance relations
			std::string sql =
			    "INSERT INTO inheritance"
			    "(id_parent, id_child, type) "
			    "VALUES "
			    "(?1, ?2, ?3);";
			sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, 0);
			sqlite3_stmt *stmt;
			for (const auto &ind : ga.previousGenerations.back()) {
				for (const auto &p : ind.parents) {
					std::string type = "";
					if (ind.inheritanceType == "mutation")
						type = 'M';
					else if (ind.inheritanceType == "crossover")
						type = 'X';
					else if (ind.inheritanceType == "copy")
						type = 'C';
					bind(stmt, getIndId(p), getIndId(ind.id), type);
				}
			}
		}

		assert(gagaToSQLiteIds.back().size() == ga.previousGenerations.back());
	}

	size_t getIndId(std::pair<size_t, size_t> id) {
		assert(gagaToSQLiteIds.size() > id.first);
		assert(gagaToSQLiteIds[id.first].size() > id.second);
		return gagaToSQLiteIds[id.first][id.second];
	}

	void endRun() {}

	void exec(std::string sql) {
		if (!db) throw std::invalid_argument("db pointer is null");
		char *err_msg = 0;
		int rc = sqlite3_exec(db, sql.c_str(), 0, 0, &err_msg);
		if (rc != SQLITE_OK) {
			std::ostringstream errorMsg;
			errorMsg << "SQL error: " << err_msg << ". \n\nREQ = " << sql << std::endl;
			sqlite3_free(err_msg);
			throw std::invalid_argument(errorMsg.str());
		} else
			sqlite3_free(err_msg);
	}

	template <typename T, typename = std::enable_if_t<std::is_integral<T>::value>>
	int sqbind(sqlite3_stmt *stmt, int index, Tvalue) {
		if constexpr (sizeof(T) <= sizeof(int))
			return sqlite3_bind_int(stmt, index, value);
		else
			return sqlite3_bind_int64(stmt, index, value);
	}

	int sqbind(sqlite3_stmt *stmt, int index, const std::string &value) {
		return sqlite3_bind_text(stmt, index, value.c_str(), -1, SQLITE_TRANSIENT);
	}

	template <typename T, typename = std::enable_if_t<std::is_floating_point<T>::value>>
	int sqbind(sqlite3_stmt *stmt, int index, T value) {
		return sqlite3_bind_double(stmt, index, static_cast<double>(value));
	}

	template <class... Args, size_t... Is>
	int bind_impl(sqlite3_stmt *stmt, std::index_sequence<Is...>, Args &&... args) {
		return (sqbind(stmt, Is + 1, std::forward<Args>(args)) + ...);
	}

	void exec(std::string sql) {
		if (!db) throw std::invalid_argument("db pointer is null");
		char *err_msg = 0;
		int rc = sqlite3_exec(db, sql.c_str(), 0, 0, &err_msg);
		if (rc != SQLITE_OK) {
			std::ostringstream errorMsg;
			errorMsg << "SQL error: " << err_msg << ". \n\nREQ = " << sql << std::endl;
			sqlite3_free(err_msg);
			throw std::invalid_argument(errorMsg.str());
		} else
			sqlite3_free(err_msg);
	}

	template <typename T, typename = std::enable_if_t<std::is_integral<T>::value>>
	int sqbind(sqlite3_stmt *stmt, int index, Tvalue) {
		if constexpr (sizeof(T) <= sizeof(int))
			return sqlite3_bind_int(stmt, index, value);
		else
			return sqlite3_bind_int64(stmt, index, value);
	}

	int sqbind(sqlite3_stmt *stmt, int index, const std::string &value) {
		return sqlite3_bind_text(stmt, index, value.c_str(), -1, SQLITE_TRANSIENT);
	}

	template <typename T, typename = std::enable_if_t<std::is_floating_point<T>::value>>
	int sqbind(sqlite3_stmt *stmt, int index, T value) {
		return sqlite3_bind_double(stmt, index, static_cast<double>(value));
	}

	template <class... Args, size_t... Is>
	int bind_impl(sqlite3_stmt *stmt, std::index_sequence<Is...>, Args &&... args) {
		return (sqbind(stmt, Is + 1, std::forward<Args>(args)) + ...);
	}

	template <class... Args> int bind(sqlite3_stmt *stmt, Args &&... args) {
		res =
		    bind_impl(stmt, std::index_sequence_for<Args...>{}, std::forward<Args>(args)...);

		sqlite3_step(stmt);
		sqlite3_clear_bindings(stmt);
		sqlite3_reset(stmt);
		return res;
	}

	~SQLiteSaver() {
		if (db) sqlite3_close(db);
	}
};
