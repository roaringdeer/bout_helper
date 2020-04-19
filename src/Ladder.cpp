//
// Created by jacek on 2020-04-10.
//

#include <ctime>
#include <random>
#include <algorithm>
#include <utility>
#include "../include/Ladder.hpp"

void Ladder::initilizeLadder() {
    for (auto& i : eighths) {
        i = ptrScoreboard->addBout(Stage::EighthFinals);
    }
    for (auto& i : fourths) {
        i = ptrScoreboard->addBout(Stage::QuaterFinals);
    }
    for (auto& i : semifinals) {
        i = ptrScoreboard->addBout(Stage::SemiFinals);
    }
    thirdPlace = ptrScoreboard->addBout(Stage::ThirdPlace);
    final = ptrScoreboard->addBout(Stage::Final);
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
        ptrScoreboard->getBoutByID(i)->setFighterIds(f1, f2);
    }
}

Ladder::Ladder(std::vector<FighterId> groupWinners, std::shared_ptr<Scoreboard> scoreBoard) {
    fighters = std::move(groupWinners);
    ptrScoreboard = std::move(scoreBoard);
    startLadder();
}


