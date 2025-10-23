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
        show_menu();
        std::cin >> option;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (option == 1) {
            Difficulty diff = promptDifficulty();
            double time = promptTime();
            GameStats gs(diff, time);
            stats.push_back(gs);
            std::cout << "Stat added.\n";
        } else if (option == 2) {
            std::cout << "\nCurrent stats:\n";
            if (stats.empty()) {
                std::cout << "(none)\n";
            } else {
                for (size_t i = 0; i < stats.size(); ++i) {
                    std::cout << i + 1 << ". ";
                    stats[i].print();
                }
            }
        } else if (option == 3) {
            std::cout << "Exited\n\n";
            break;
        } else {
            std::cout << "Invalid option. Try again.\n";
        }
    }

    return 0;
}
