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
    // assign member variables
    _number = number;
    _name = name;
    _type1 = type1;
    _type2 = type2;
    _total = total;
    _hp = hp;
    _attack = attack;
    _defense = defense;
    _spatk = spatk;
    _spdef = spdef;
    _speed = speed;
    _generation = gen;
    _legendary = legend;
}

// getter definitions
int Pokemon::getNumber() const { 
    return _number; 
}
std::string Pokemon::getName() const { 
    return _name; 
}
std::string Pokemon::getType1() const { 
    return _type1; 
}
std::string Pokemon::getType2() const { 
    return _type2; 
}
int Pokemon::getTotal() const { 
    return _total; 
}
int Pokemon::getHP() const { 
    return _hp; 
}
int Pokemon::getAttack() const { 
    return _attack; 
}
int Pokemon::getDefense() const { 
    return _defense; 
}
int Pokemon::getSpatk() const { 
    return _spatk; 
}
int Pokemon::getSpdef() const { 
    return _spdef; 
}
int Pokemon::getSpeed() const { 
    return _speed; 
}
int Pokemon::getGen() const { 
    return _generation; 
}
bool Pokemon::getLegend() const { 
    return _legendary; 
}

// print individual pokemon info

/*

reworking print to take in specific name and print from there
next task ^^^

*/
void Pokedex::printPokemon() const {

    std::cout << "Name: " << _name << std::endl
              << "Number: " << _number << std::endl
              << "Type 1: " << _type1 << std::endl
              << "Type 2: " << _type2 << std::endl
              << "Total: " << _total << std::endl
              << "HP: " << _hp << std::endl
              << "Attack: " << _attack << std::endl
              << "Defense: " << _defense << std::endl
              << "Sp. Atk: " << _spatk << std::endl
              << "Sp. Def: " << _spdef << std::endl
              << "Speed: " << _speed << std::endl
              << "Generation: " << _generation << std::endl
              << "Legendary: " << isLegendary << std::endl;
}

// using this for search later on below
std::string Pokedex::getName() const {
    return _name;
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