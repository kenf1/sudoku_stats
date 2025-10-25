#ifndef WRITER_HPP
#define WRITER_HPP

#include "game_stats.hpp"
#include <string>
#include <vector>

std::string get_connection_string();

void insert_into_db(const std::vector<GameStats>& games,
                    const std::string& conn_str);

#endif
