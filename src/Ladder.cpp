//
// Created by jacek on 2020-04-10.
//

#include <ctime>
#include <random>
#include <algorithm>
#include "../include/Ladder.hpp"

void Ladder::initilizeLadder() {
    for (auto i : eighths) {
        i = scoreboard->addBout();
    }
    for (auto i : fourths) {
        i = scoreboard->addBout();
    }
    for (auto i : semifinals) {
        i = scoreboard->addBout();
    }
    thirdPlace = scoreboard->addBout();
    final = scoreboard->addBout();
}

void Ladder::startLadder() {
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(fighters.begin(), fighters.end(), g);
    std::vector<FighterId> copiedFighters(fighters);

    initilizeLadder();
    for(auto i : eighths){
        auto f1 = copiedFighters.back();
        copiedFighters.pop_back();
        auto f2 = copiedFighters.back();
        copiedFighters.pop_back();

        scoreboard->getBoutByID(i)->setFighterIds(f1, f2);
    }

}


