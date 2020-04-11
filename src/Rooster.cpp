//
// Created by jacek on 2020-04-10.
//

#include "../include/Rooster.hpp"
#include "../include/CSVManager.hpp"

void Rooster::getRoosterFromCSV(const std::string &fileName) {
    int id = 0;
    CSVManager csvManager(fileName, ';');
    for(auto iterFighter : csvManager.getData()){
        auto* fighter = new Fighter(iterFighter[0], iterFighter[1], iterFighter[2], iterFighter[3], iterFighter[4]);
        std::shared_ptr<Fighter> ptr = std::make_shared<Fighter>(*fighter);
        rooster.addToCollection(ptr);
//        std::cout << iterFighter[0] << " " << iterFighter[1] << " " << iterFighter[2] << " " << iterFighter[3] << std::endl;
        id++;
    }
}

std::shared_ptr<Fighter> Rooster::getFighterById(FighterId id) {
    return *rooster.getByID(id);
}

std::shared_ptr<Fighter> Rooster::getFighterByName(const std::string& name) {
    return *rooster.getByName(name);
}
