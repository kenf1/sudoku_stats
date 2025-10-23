#include "game_stats.hpp"

std::string difficultyToString(Difficulty d) {
    switch (d) {
        case Difficulty::Easy:
            return "Easy";
        case Difficulty::Medium:
            return "Medium";
        case Difficulty::Hard:
            return "Hard";
        case Difficulty::Expert:
            return "Expert";
        default:
            return "Unknown";
    }
}

GameStats::GameStats(Difficulty diff, double min_sec)
    : current_datetime(std::chrono::system_clock::now()),
      difficulty(diff),
      complete_time_min_sec(min_sec) {
    int minutes = static_cast<int>(complete_time_min_sec);
    double fractional = complete_time_min_sec - minutes;
    int seconds = static_cast<int>(std::lround(fractional * 100));
    complete_time_sec_only = minutes * 60 + seconds;
}

void GameStats::print() const {
    std::time_t dt = std::chrono::system_clock::to_time_t(current_datetime);
    std::cout << "Timestamp: "
              << std::put_time(std::localtime(&dt), "%Y-%m-%d %H:%M:%S")
              << ", Difficulty: " << difficultyToString(difficulty)
              << ", Completion Time (min:sec): " << complete_time_min_sec
              << ", Completion Time (sec): " << complete_time_sec_only << "s\n";
}
