//
// Created by jacek on 2020-04-10.
//

#ifndef BOUT_HELPER_ROOSTER_HPP
#define BOUT_HELPER_ROOSTER_HPP

#include "Fighter.hpp"
#include "Collection.hpp"
#include "FighterCollection.hpp"
#include <memory>
#include <vector>
class Rooster {
using iterator = typename std::list<Fighter>::iterator;
using const_iterator = typename std::list<Fighter>::const_iterator;
private:
    FighterCollection<Fighter> rooster;
public:
    Rooster(){
        auto nullFighter = new Fighter("---", "---", "Undefined", "---", "---");
        rooster.addToCollection(std::move(*nullFighter));
    };
    void getRoosterFromCSV(const std::string& fileName = "fighters.csv");
    iterator begin() { return rooster.begin();}
    iterator end() { return rooster.end();}
    const_iterator cbegin() { return rooster.cbegin();}
    const_iterator cend() { return rooster.cbegin();}
    std::list<Fighter>::iterator getFighterById(FighterId id);
    std::list<Fighter>::iterator getFighterByName(const std::string& name);
};


#endif //BOUT_HELPER_ROOSTER_HPP