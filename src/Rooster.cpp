//
// Created by jacek on 2020-04-10.
//

#include <random>
#include <algorithm>
#include "../include/Rooster.hpp"
#include "../include/CSVManager.hpp"
Fighter Rooster::nullFighter = Fighter(0,"---", "---", "Undefined", "---", "---");

void Rooster::getRoosterFromCSV(const std::string &fileName) {
    int id = 0;
    CSVManager csvManager(fileName, ';');
    for(auto iterFighter : csvManager.getData()){
        auto fighter = new Fighter(iterFighter[0], iterFighter[1], iterFighter[2], iterFighter[3], iterFighter[4]);
        rooster.addToCollection(std::move(*fighter));
//        std::cout << iterFighter[0] << " " << iterFighter[1] << " " << iterFighter[2] << " " << iterFighter[3] << std::endl;
        id++;
    }
}

std::list<Fighter>::iterator Rooster::getFighterById(FighterId id) {
    return rooster.getByID(id);
}

std::list<Fighter>::iterator Rooster::getFighterByName(const std::string& name) {
    return rooster.getByName(name);
}

std::vector<FighterId> Rooster::getShuffledFighters() const {
    std::vector<FighterId> ids;
    for(auto it = rooster.cbegin(); it != rooster.cend(); it++){
        ids.push_back(it->getId());
    }
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(ids.begin(), ids.end(), g);
    return ids;
}
