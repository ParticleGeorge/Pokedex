// main file for pokedex
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>  
#include "pokedex.h"


/*

have not adjusted main for new classes and implentations other than pokedex object


*/

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

    // variables needed for loop
    bool online = true;
    char userQuit;

    do {
        std::cout << "Welcome to Pokedex" << std::endl;
        std::cout << "How can I help you today?" << std::endl;
        std::cout << "vvv Select an option below vvv " << std::endl;
        std::cout << "1 - Search by Pokemon name... " << std::endl;
        std::cout << "2 - Type 'exit' to quit" << std::endl;
 
        // get user input as a full line
        std::string userInputLine;
        std::getline(std::cin, userInputLine);

        // check for exit
        if (userInputLine == "exit") {
            online = false;
            continue;
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
                std::cout << "If there is a match, the Pokemon's information" << std::endl;
                std::cout << "will be printed to the screen!" << std::endl;
                std::string userStringInput;
                std::getline(std::cin, userStringInput);

                // make sure his is a string entered
                if (!isValidName(userStringInput)) {
                    std::cout << "Error, please enter letters only." << std::endl;
                    break;
                }

                // std::cout << "DEBUG: user entered: '" << userStringInput << "'" << std::endl;
                pokedex.searchByName(userStringInput);
                break;
            }
            case 2:
            case 3:
            case 4:
            default:
                std::cout << "Invalid option, try again." << std::endl;

        }
        

    } while (online);

    // exit
    std::cout << "Program is now exiting... " << std::endl;



    // print test to ensure CSV is being read correctly
    /*
    for (const std::vector<std::string>& row : csvData) {
        // prints cell for current row all in one line
        for (const std::string& cell : row) {
            std::cout << cell << " ";         
        }
        std::cout << std::endl; // continue to next line in main vector       
    }
    */

    // g++ -g main.cpp pokedex.cpp -o main.exe

    return 0;
}
