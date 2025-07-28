#include "pokedex.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>

// constructor
search::search() {

}

// function defintions
// loading CSV file
void search::loadFromCSV() {

    // for this project we will be reading from a CSV file containing all pokemon plus their respective attributes
    // we will begin by reading in the file
    std::ifstream file("pokemon.csv");

    // will hold each line of the CSV file
    std::string line;

    while (std::getline(file, line)) {
        // stringsteam to split lines, cell will hold each cell in lines, row for the current row
        std::stringstream ss(line);                

        // split the line by commas
        while (std::getline(ss, cell, ',')) {
            // each cell will be added to current row
            row.push_back(cell);              
        }

        // the completed row will be added to the main vector
        csvData.push_back(row);   
    }
}

// generic search feature
void search::genericSearch(const std::string& userInput) const {
    
    // will return whether something exists in the CSV could be anything
    bool found = false;

    for (const std::vector<std::string>& row : csvData) {
        // search for the input in the current row
        auto locate = std::find(row.begin(), row.end(), userInput);
        
        if (locate != row.end()) {
            std::cout << "found in row: ";
            for (const std::string& cell : row) {
                std::cout << cell << " ";
            }
            std::cout << std::endl;
            found = true;
        }
    }

    if (!found) {
        std::cout << "No matches found for: " << userInput <<  std::endl;
    }
}