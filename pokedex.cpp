#include "pokedex.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <cctype>  

// constructor
search::search() {

}

// function defintions
// loading CSV file
void search::loadFromCSV() {
    std::ifstream file("pokemon.csv");
    std::string line;

    while (std::getline(file, line)) {
        // stringsteam to split lines, cell will hold each cell in lines, row for the current row
        std::stringstream ss(line); 
        std::vector<std::string> row;  // made these local now
        std::string cell;               

        // split the line by commas
        while (std::getline(ss, cell, ',')) {
            // each cell will be added to current row & convert to lowercase
            std::transform(cell.begin(), cell.end(), cell.begin(), ::tolower);
            row.push_back(cell);              
        }

        // the completed row will be added to the main vector
        csvData.push_back(row);   
    }
}

// generic search feature
void search::genericSearch(const std::string& userInput) {
    
    // will return whether something exists in the CSV could be anything
    bool found = false;

    // convert user input into lower case, will check for match with CSV (converted loadCSV as well)
    std::string userInputCopy = userInput;
    std::transform(userInputCopy.begin(), userInputCopy.end(), userInputCopy.begin(), ::tolower);

    for (const std::vector<std::string>& row : csvData) {
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