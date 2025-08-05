#ifndef POKEDEX_H
#define POKEDEX_H

#include <vector>
#include <string>

// main class that will contain all the search functions
// eventually will be adding different ways to search for the user
class search {
    public:
        // constructor 
        search();

        // loading CSV function & additional search functions
        void loadFromCSV(); 
        void searchByName(const std::string& userInput); 

    private: 
        std::vector<std::vector<std::string>> csvData;    // entire CSV row by row

};

class Pokemon {
    public:
        // constructor
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
        bool isLegendary() const;
        

    private:
        int number, total, hp, attack, defense, spatk, spdef, speed, generation;
        bool legendary;
        std::string name, type1, type2;
};

#endif // POKEDEX_H