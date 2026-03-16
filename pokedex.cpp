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
    // lowercase from here
    _name = name;
    std::transform(_name.begin(), _name.end(), _name.begin(), ::tolower);
    _type1 = type1;
    std::transform(_type1.begin(), _type1.end(), _type1.begin(), ::tolower);
    _type2 = type2;
    std::transform(_type2.begin(), _type2.end(), _type2.begin(), ::tolower);
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

// function definitions for Pokedex class

void Pokedex::printPokemon(const Pokemon& pokemon) const {

    std::cout << "Printing..." << std::endl;
    std::cout << "Name: " << pokemon.getName() << std::endl
              << "Number: " << pokemon.getNumber() << std::endl
              << "Type 1: " << pokemon.getType1() << std::endl
              << "Type 2: " << pokemon.getType2() << std::endl
              << "Total: " << pokemon.getTotal() << std::endl
              << "HP: " << pokemon.getHP() << std::endl
              << "Attack: " << pokemon.getAttack() << std::endl
              << "Defense: " << pokemon.getDefense() << std::endl
              << "Sp. Atk: " << pokemon.getSpatk() << std::endl
              << "Sp. Def: " << pokemon.getSpdef() << std::endl
              << "Speed: " << pokemon.getSpeed() << std::endl
              << "Generation: " << pokemon.getGen() << std::endl
              << "Legendary: " << pokemon.getLegend() << std::endl;
}

void Pokedex::searchByName(const std::string& name) const {
    std::string loweredName = name;
    std::transform(loweredName.begin(), loweredName.end(), loweredName.begin(), ::tolower);

    // First, look for an exact match
    for (size_t i = 0; i < pokedex.size(); i++) {
        if (pokedex[i].getName() == loweredName) {
            printPokemon(pokedex[i]);
            return;
        }
    }

    // Collect partial matches
    std::vector<const Pokemon*> matches;

    for (size_t i = 0; i < pokedex.size(); i++) {
        if (pokedex[i].getName().find(loweredName) != std::string::npos) {
            matches.push_back(&pokedex[i]);
        }
    }

    // No matches
    if (matches.size() == 0) {
        std::cout << "Error: could not find any Pokemon matching \"" 
                  << name << "\"." << std::endl;
        return;
    }

    // One match
    if (matches.size() == 1) {
        std::cout << "Found one partial match:\n";
        printPokemon(*matches[0]);
        return;
    }

    // Multiple matches
    std::cout << "Multiple matches found:\n";
    for (size_t i = 0; i < matches.size(); i++) {
        std::cout << i + 1 << " - " << matches[i]->getName() << std::endl;
    }

    std::cout << "Enter the number of the Pokemon you want: ";
    int choice;
    std::cin >> choice;

    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Invalid input." << std::endl;
        return;
    }

    std::cin.ignore(10000, '\n');

    if (choice < 1 || choice > static_cast<int>(matches.size())) {
        std::cout << "Invalid selection." << std::endl;
        return;
    }

    printPokemon(*matches[choice - 1]);
}

void Pokedex::loadFromCSV() {
    std::ifstream file("pokemon.csv");

    if (!file.is_open()) {
        std::cout << "Error: file could not be opened" << std::endl;
        return;
    }

    std::string line;

    // Skip header row
    std::getline(file, line);

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string cell;
        std::vector<std::string> row;

        while(std::getline(ss, cell, ',')) {
            row.push_back(cell);
        }

        // Make sure the row has enough columns
        if (row.size() < 13) {
            std::cout << "Warning: skipped invalid row: " << line << std::endl;
            continue;
        }

         try {
            // going to convert to ints here for value comparison later
            int number = std::stoi(row[0]);
            std::string name = row[1];
            std::string type1 = row[2];
            std::string type2 = row[3];
            int total = std::stoi(row[4]);
            int hp = std::stoi(row[5]);
            int attack = std::stoi(row[6]);
            int defense = std::stoi(row[7]);
            int spatk = std::stoi(row[8]);
            int spdef = std::stoi(row[9]);
            int speed = std::stoi(row[10]);
            int generation = std::stoi(row[11]);
            bool legendary = (row[12] == "True" || row[12] == "true" || row[12] == "1");

            // create pokemon object and push it back
            Pokemon indiPoke(number, name, type1, type2, total, hp, attack,
                             defense, spatk, spdef, speed, generation, legendary);

            pokedex.push_back(indiPoke);
        }
        catch (const std::exception& e) {
            std::cout << "Warning: skipped malformed row: " << line << std::endl;
        }
    }
}

