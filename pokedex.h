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

    // getters
    int getNumber() const;
    std::string getName() const;
    std::string getType1() const;
    std::string getType2() const;
    int getTotal() const;
    int getHP() const;
    int getAttack() const;
    int getDefense() const;
    int getSpatk() const;
    int getSpdef() const;
    int getSpeed() const;
    int getGen() const;
    bool getLegend() const;
        
private:
    int _number, _total, _hp, _attack, _defense, _spatk, _spdef, _speed, _generation;
    bool _legendary;
    std::string _name, _type1, _type2;

};

// class that manages all pokemon
class Pokedex {
public:
    void loadFromCSV();
    void searchByName(const std::string& name) const;
    void printPokemon(const Pokemon& p) const;

private:
    // using for csvData
    std::vector<Pokemon> pokedex;

};

#endif // POKEDEX_H