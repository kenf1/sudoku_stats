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

Difficulty promptDifficulty() {
    int choice;
    while (true) {
        std::cout << "\nSelect difficulty:\n\n";
        std::cout << "1. Easy\n2. Medium\n3. Hard\n4. Expert\n\n";
        std::cout << "Choice: ";
        std::cin >> choice;
        if (choice >= 1 && choice <= 4)
            return static_cast<Difficulty>(choice - 1);
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
