#include "prompts.hpp"

#include <iostream>
#include <limits>

void show_menu() {
    std::cout << "\nMenu:\n\n";
    std::cout << "1. Add new stat entry\n";
    std::cout << "2. Show all stats\n";
    std::cout << "3. Exit\n\n";
    std::cout << "Enter option: ";
}

int promptMenuChoice() {
    int option;
    while (true) {
        show_menu();

        if (!(std::cin >> option)) {
            std::cout << "Invalid input. Please enter a valid number.\n";
            std::cin.clear();  // clear error flags before ignoring
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                        '\n');  // remove trailing input (for exact match)

        if (option >= 1 && option <= 3) {
            return option;
        }

        std::cout << "Invalid option. Try again.\n";
    }
}

Difficulty promptDifficulty() {
    int choice;
    while (true) {
        std::cout << "\nSelect difficulty:\n\n1. Easy\n2. Medium\n3. Hard\n4. "
                     "Expert\n\nChoice: ";
        if (!(std::cin >> choice)) {
            std::cout << "Invalid input. Please enter a number.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        if (choice >= 1 && choice <= 4) {
            return static_cast<Difficulty>(choice - 1);
        }
        std::cout << "Invalid choice. Try again.\n";
    }
}

double promptTime() {
    double time;
    std::cout
        << "\nEnter completion time (min.sec, e.g., 1.30 for 1 min 30 sec): ";
    while (!(std::cin >> time)) {
        std::cout << "Invalid input. Please enter a valid number: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return time;
}
