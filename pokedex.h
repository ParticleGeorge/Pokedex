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
        std::vector<std::vector<std::string>>    csvData;    // entire CSV row by row

};









#endif // POKEDEX_H