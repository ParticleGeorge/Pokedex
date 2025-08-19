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

    for(int i = 0; i < pokedex.size(); i++) {
        std::string pokeName = pokedex[i].getName();
        
        // lowercase
        std::transform(pokeName.begin(), pokeName.end(), pokeName.begin(), ::tolower);
        
        if (pokeName == loweredName) {
            printPokemon(pokedex[i]);
            return;
        }

    }

    std::cout << "Erro: could not find Pokemon. " << name << std::endl;
}

void Pokedex::loadFromCSV() {
    std::ifstream file("pokemon.csv");
    if (!file.is_open()) {
        std::cout << "Error: file could not be opened" << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string cell;
        std::vector<std::string> row;

        while(std::getline(ss, cell, ',')) {
            row.push_back(cell);
        }

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
        Pokemon indiPoke(number, name, type1, type2, total, hp, attack, defense, spatk, spdef, speed, generation, legendary);
        pokedex.push_back(indiPoke);
    }
}

