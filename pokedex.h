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
        void genericSearch(const std::string& userInput); 

    private: 
        std::vector<std::vector<std::string>> csvData;    // entire CSV row by row

};

class print {
    public:
        // constructor
        print();

        // setters
        // #,Name,Type 1,Type 2,Total,HP,Attack,Defense,Sp. Atk,Sp. Def,Speed,Generation,Legendary
        void setNumber(int pokeNumber);  
        void setName(std::string pokeName);
        void setType1(std::string pokeType1);
        void setType2(std::string pokeType2);
        void setTotal(int pokeTotal);  
        void setHP(int pokeHP);  
        void setAttack(int pokeAttack);  
        void setDefense(int pokeDefense);  
        void setSpatk(int pokeSpatk);  
        void setSpdef(int pokeSpdef);  
        void setSpeed(int pokeSpeed);  
        void setGen(int pokeGen);  
        void setLegend(int pokeLegend);  

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

        // print function
        void printPokemon();

    private:
        int number, total, hp, attack, defense, spatk, spdef, speed, generation;
        bool legendary;
        std::string name, type1, type2;
};


#endif // POKEDEX_H