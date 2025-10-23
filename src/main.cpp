#include <iostream>
#include <string>
#include <vector>

#include "models/game_stats.hpp"
#include "ui/prompts.hpp"

int main() {
    std::vector<GameStats> stats;
    int option = 0;

    std::cout << "Sudoku stats main page\n";

    while (true) {
        option = promptMenuChoice();

        switch (option) {
            case 1: {
                std::cout << "Add new stat entry selected\n";

                Difficulty diff = promptDifficulty();
                double time = promptTime();

                GameStats newStat(diff, time);
                stats.push_back(newStat);

                std::cout << "\nNew stat added:\n";
                newStat.print();
                break;
            }

            case 2: {
                std::cout << "Show all stats selected\n";
                if (stats.empty())
                    std::cout << "No stats available.\n";
                else {
                    for (const auto& stat : stats) stat.print();
                }
                break;
            }

            case 3: {
                std::cout << "Exiting program.\n";
                return 0;
            }

            default:
                std::cout << "Invalid option. Try again.\n";
        }
    }

    return 0;
}
