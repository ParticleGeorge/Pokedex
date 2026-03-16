// main file for pokedex
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>  
#include "pokedex.h"

bool isValidName(const std::string& input) {
    // checking for character validation when asking for pokemon
    for (size_t i = 0; i < input.length(); i++) {
        char c = input[i];
        if (!std::isalpha(c) && c != ' ' && c != '-') {
            return false;
        }
    }
    return !input.empty();
}

void handleNameSearch(const Pokedex& pokedex) {
    // moved the name search logic into a separate function for better readability
    std::cout << "Please enter the name of the Pokemon..." << std::endl;

    std::string userStringInput;
    std::getline(std::cin, userStringInput);

    if (!isValidName(userStringInput)) {
        std::cout << "Error, please enter letters, spaces, or hyphens only." << std::endl;
        return;
    }

    pokedex.searchByName(userStringInput);
}

int main() {

    // create an object from the Pokedex class
    Pokedex pokedex;

    // load in files
    pokedex.loadFromCSV();

 
    while(true) {
        std::cout << "\nWelcome to the Pokedex\n";
        std::cout << "1 - Search by Pokemon name\n";
        /* WIP
        std::cout << "2 - Search by Pokemon type\n";
        std::cout << "3 - Search by Pokemon generation\n";
        std::cout << "4 - Search by Pokemon legendary status\n";  
        std::cout << "5 - Show random Pokemon\n";
        */
        std::cout << "0 - Exit\n";

        // cleaner input handling
        int choice;

        std::cout << "Enter option: ";
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cin.clear();             
            std::cin.ignore(10000, '\n'); 
            std::cout << "Invalid input.\n";
            continue;
        }

        std::cin.ignore(10000, '\n');

        switch (choice) {
            case 1:
                handleNameSearch(pokedex);
                break;
            case 0:
                std::cout << "Program is now exiting... " << std::endl;
                return 0;
            default:
                std::cout << "Invalid option, try again." << std::endl;
        }
    } 

    // exit
    std::cout << "Program is now exiting... " << std::endl;

    // g++ -g main.cpp pokedex.cpp -o main.exe

    return 0;
}
