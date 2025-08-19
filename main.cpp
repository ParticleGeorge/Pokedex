// main file for pokedex
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>  
#include "pokedex.h"

bool isValidName(const std::string& input) {
    // checking for character validation when asking for pokemon
    for (int i = 0; i < input.length(); i++) {
        char c = input[i];
        if (!std::isalpha(c) && c != ' ' && c != '-') {
            return false;
        }
    }
    return !input.empty();
}

int main() {

    // create an object from the Pokemon class
    Pokedex pokedex;

    // load in files
    pokedex.loadFromCSV();

 
    while(true) {
        std::cout << "Welcome to Pokedex" << std::endl;
        std::cout << "vvv Select an option below vvv " << std::endl;
        std::cout << "1 - Search by Pokemon name... " << std::endl;
        std::cout << "2 - Type 'exit' to quit" << std::endl;
 
        // get user input as a full line
        std::string userInputLine;
        std::getline(std::cin, userInputLine);

        // check for exit
        if (userInputLine == "exit") {
            break;
        }

        // added logic to check if userIntInput is a digit, used ss to read from string
        int userIntInput;
        std::stringstream ss(userInputLine);
        if (!(ss >> userIntInput)) {
            std::cout << "Erorr, please enter a digit or type in exit." << std::endl;
            continue;
        }

        switch (userIntInput) {
            case 1: {
                std::cout << "Please enter the name of the Pokemon..." << std::endl;
                std::string userStringInput;
                std::getline(std::cin, userStringInput);

                // make sure his is a string entered
                if (!isValidName(userStringInput)) {
                    std::cout << "Error, please enter letters only." << std::endl;
                    break;
                }

                std::transform(userStringInput.begin(), userStringInput.end(), userStringInput.begin(), ::tolower);
                pokedex.searchByName(userStringInput);
                break;
            }
            default:
                std::cout << "Invalid option, try again." << std::endl;

        }
        

    } 

    // exit
    std::cout << "Program is now exiting... " << std::endl;


    // g++ -g main.cpp pokedex.cpp -o main.exe

    return 0;
}
