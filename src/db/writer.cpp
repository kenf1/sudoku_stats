#include <iostream>
#include <pqxx/pqxx>

#include "game_stats.hpp"

std::string get_connection_string() {
    const char* conn = std::getenv("DATABASE_URL");
    if (!conn) {
        std::cerr << "Environment variable DATABASE_URL is not set.\n";
        return {};
    }
    return std::string(conn);
}

void insert_into_db(const std::vector<GameStats>& games,
                    const std::string& conn_str) {
    try {
        pqxx::connection c(conn_str);
        pqxx::work txn(c);

        txn.exec(R"(
            CREATE TABLE IF NOT EXISTS gamestats (
                id SERIAL PRIMARY KEY,
                timestamp TIMESTAMP,
                difficulty TEXT,
                completion_time_min_sec DOUBLE PRECISION,
                completion_time_sec_only INTEGER
            )
        )");

        for (const auto& g : games) {
            std::time_t dt =
                std::chrono::system_clock::to_time_t(g.getTimestamp());
            std::string diff_str = difficultyToString(g.getDifficulty());
            txn.exec_params(
                "INSERT INTO gamestats (timestamp, difficulty, "
                "completion_time_min_sec, completion_time_sec_only) "
                "VALUES (to_timestamp($1), $2, $3, $4)",
                dt, diff_str, g.getCompletionTimeMinSec(),
                g.getCompletionTimeSecOnly());
        }

        txn.commit();
        std::cout << "Inserted " << games.size()
                  << " records into the gamestats table.\n";
    } catch (const std::exception& e) {
        std::cerr << "PostgreSQL insert error: " << e.what() << std::endl;
    }
}
