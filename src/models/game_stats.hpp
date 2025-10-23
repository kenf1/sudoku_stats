#pragma once
#include <chrono>
#include <cmath>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <string>

//round down aka suppress difficulty
enum class Difficulty : uint8_t { Easy, Medium, Hard, Expert };
std::string difficultyToString(Difficulty d);

struct GameStats {
    std::chrono::system_clock::time_point current_datetime;
    Difficulty difficulty;
    double complete_time_min_sec; //e.g. 1.30 = 1 min 30 sec
    long complete_time_sec_only; //e.g. 90 = 1 min 30 sec
    GameStats(Difficulty diff, double min_sec);
    void print() const;
};
