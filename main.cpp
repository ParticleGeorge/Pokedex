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
    std::string userStringInput;
    int userIntInput;
    


    do {
        std::cout << "Welcome to Pokedex" << std::endl;
        std::cout << "How can I help you today?" << std::endl;
        std::cout << "vvv Select an option below vvv " << std::endl;
        std::cout << "1 - Search by typing anything... " << std::endl;
        std::cout << "2 - coming later" << std::endl;
        std::cout << "3 - coming later" << std::endl;
        std::cout << "4 - coming later" << std::endl;

        std::cin >> userIntInput;

        // add logic to check if userIntInput is a digit

        switch (userIntInput) {
            case 1:
                std::cout << "Please enter your search request..." << std::endl;
                std::cin >> userStringInput;
                pokedex.genericSearch(userStringInput);
                break;
            case 2:
            case 3:
            case 4:
            default:
                std::cout << "Invalid option, try again." << std::endl;

        }
        

    } while (online);





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


    return 0;
}
