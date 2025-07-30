// main file for pokedex
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include "pokedex.h"

int main() {

    // create an object from the search class
    search pokedex;

    // load in files
    pokedex.loadFromCSV();

    // variables needed for loop
    bool online = true;
    char userQuit;

    do {
        std::cout << "Welcome to Pokedex" << std::endl;
        std::cout << "How can I help you today?" << std::endl;
        std::cout << "vvv Select an option below vvv " << std::endl;
        std::cout << "1 - Search by typing anything... " << std::endl;
        std::cout << "2 - coming later" << std::endl;
        std::cout << "3 - coming later" << std::endl;
        std::cout << "4 - coming later" << std::endl;
        std::cout << "5 - Type 'exit' to quit" << std::endl;

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
                std::cout << "Please enter your search request..." << std::endl;
                std::string userStringInput;
                std::getline(std::cin, userStringInput);
                // std::cout << "DEBUG: user entered: '" << userStringInput << "'" << std::endl;
                pokedex.genericSearch(userStringInput);
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
