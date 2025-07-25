// main file for pokedex
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

int main() {
    std::cout << "Welcome to the modern dex...\n";
    std::cout << "Please wait while we set things up...\n";
    
    // for this project we will be reading from a CSV file containing all pokemon plus their respective attributes
    // we will begin by reading in the file
    std::ifstream file("pokemon.csv");

    // will hold each line of hte CSV file
    std::string line;

    // vector a line, within rows of of the CSV.. vector within vector
    std::vector<std::vector<std::string>> csvData;

    while (std::getline(file, line)) {
        // stringsteam to split lines, cell will hold each cell in lines, row for the current row
        std::stringstream ss(line);           
        std::string cell;                    
        std::vector<std::string> row;         

        // split the line by commas
        while (std::getline(ss, cell, ',')) {
            // each cell will be added to current row
            row.push_back(cell);              
        }

        // the completed row will be added to the main vector
        csvData.push_back(row);               
    }

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
