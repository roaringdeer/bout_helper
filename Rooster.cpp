//
// Created by jacek on 2020-04-10.
//

#include "Rooster.hpp"
#include "CSVManager.hpp"

void Rooster::getRoosterFromCSV(const std::string &fileName) {
    int id = 0;
    CSVManager csvManager(fileName, ';');
    for(auto iterFighter : csvManager.getData()){
        auto* fighter = new Fighter(iterFighter[0], iterFighter[1], iterFighter[2], iterFighter[3], iterFighter[4]);
        std::shared_ptr<Fighter> ptr = std::make_shared<Fighter>(*fighter);
        rooster.push_back(ptr);
//        std::cout << iterFighter[0] << " " << iterFighter[1] << " " << iterFighter[2] << " " << iterFighter[3] << std::endl;
        id++;
    }

}

std::vector<std::shared_ptr<Fighter>> Rooster::getRooster() {
    return rooster;
}