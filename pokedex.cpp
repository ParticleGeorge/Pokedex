#include "pokedex.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <cctype>  

// default constructor
Pokemon::Pokemon() {}

// function definitions for Pokemon class
// creating pokemon object
Pokemon::Pokemon(int number, const std::string& name, const std::string& type1, const std::string& type2,
                 int total, int hp, int attack, int defense, int spatk, int spdef,
                 int speed, int gen, bool legend) 
{
    // using this-> because I will be using the same names for members and parameters
    this->number = number;
    this->name = name;
    this->type1 = type1;
    this->type2 = type2;
    this->total = total;
    this->hp = hp;
    this->attack = attack;
    this->defense = defense;
    this->spatk = spatk;
    this->spdef = spdef;
    this->speed = speed;
    this->generation = gen;
    this->legendary = legend;
}

// print individual pokemon info
void Pokemon::printPokemon() const {

    // for bool getter
    std::string isLegendary;
    if (legendary) {
        isLegendary = "Yes";
    } 
    else {
        isLegendary = "No";
    }

    std::cout << "Name: " << name << std::endl
              << "Number: " << number << std::endl
              << "Type 1: " << type1 << std::endl
              << "Type 2: " << type2 << std::endl
              << "Total: " << total << std::endl
              << "HP: " << hp << std::endl
              << "Attack: " << attack << std::endl
              << "Defense: " << defense << std::endl
              << "Sp. Atk: " << spatk << std::endl
              << "Sp. Def: " << spdef << std::endl
              << "Speed: " << speed << std::endl
              << "Generation: " << generation << std::endl
              << "Legendary: " << isLegendary << std::endl;
}

// using this for search later on below
std::string Pokemon::getName() const {
    return name;
}

// function definitions for Pokedex class

/*

Work in progress

*/
void Pokedex::loadFromCSV() {

}

void Pokedex::searchByName(const std::string& name) const {

}







/* ----> redoing all of this



// loading CSV file
void Pokemon::loadFromCSV() {
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
// adjust this function to return 
void Pokemon::searchByName(const std::string& userInput) {
    
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

*/