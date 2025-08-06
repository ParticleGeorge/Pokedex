#ifndef POKEDEX_H
#define POKEDEX_H

#include <vector>
#include <string>

// class for a single pokemon 
class Pokemon {
public:
    // constructor
    Pokemon();
    Pokemon(int number, const std::string& name, const std::string& type1, const std::string& type2,
            int total, int hp, int attack, int defense, int spatk, int spdef, int speed, int gen, bool legend);

    // printing single pokemon + getName for search
    void printPokemon() const;
    std::string getName() const;
        
private:
    int number, total, hp, attack, defense, spatk, spdef, speed, generation;
    bool legendary;
    std::string name, type1, type2;

};

// class that manages all pokemon
class Pokedex {
public:
    void loadFromCSV();
    void searchByName(const std::string& name) const;

private:
    // using for csvData
    std::vector<Pokemon> pokedex;

};

#endif // POKEDEX_H