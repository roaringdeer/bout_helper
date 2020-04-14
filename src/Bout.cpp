//
// Created by jacek on 2019-11-19.
//

#include "../include/Bout.hpp"
int Bout::staticId = 0;

void Bout::setScore(int bigPointFighter1, int smallPointFighter1, int bigPointFighter2, int smallPointFighter2) {
    ptrScore->setBigPointsFighter1(bigPointFighter1);
    ptrScore->setSmallPointsFighter1(smallPointFighter1);
    ptrScore->setBigPointsFighter2(bigPointFighter2);
    ptrScore->setSmallPointsFighter2(smallPointFighter2);
}

void Bout::resetScore() {
    ptrScore->resetPoints();
}

std::pair<int, int> Bout::getScoreFighter1() {
    return std::pair<int, int>(ptrScore->getBigPointsFighter1(), ptrScore->getSmallPointsFighter1());
}

std::pair<int, int> Bout::getScoreFighter2() {
    return std::pair<int, int>(ptrScore->getBigPointsFighter2(), ptrScore->getSmallPointsFighter2());
}

void Bout::resolve() {
    ptrScore->reload();
    if(getScoreFighter1().first == getScoreFighter2().first){
        if(getScoreFighter1().second > getScoreFighter2().second) result = Result::WonFighter1;
        if(getScoreFighter1().second < getScoreFighter2().second) result = Result::WonFighter2;
        if(getScoreFighter1().second == getScoreFighter2().second) result = Result::Tie;
    }
    if(getScoreFighter1().first > getScoreFighter2().first){
        result = Result::WonFighter1;
    }
    if(getScoreFighter1().first < getScoreFighter2().first){
        result = Result::WonFighter2;
    }
}

std::pair<std::pair<int, int>, std::pair<int, int>> Bout::getFightersScores() {
    return std::make_pair(getScoreFighter1(), getScoreFighter2());
}
