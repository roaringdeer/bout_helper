//
// Created by jacek on 2019-11-19.
//

#include "Bout.hpp"
int Bout::staticId = 0;

Bout::Bout(std::shared_ptr<Fighter> fighter1, std::shared_ptr<Fighter> fighter2){
    ptrFighter1 = fighter1;
    ptrFighter2 = fighter2;
    id = staticId;
    staticId++;
    auto score = new Score();
    ptrScore = std::make_shared<Score>(*score);
}

Bout::Bout(std::shared_ptr<Fighter> fighter1, std::shared_ptr<Fighter> fighter2, Weapon mainWeaponFighter1,
           Weapon offhandWeaponFighter1, Weapon mainWeaponFighter2, Weapon offhandWeaponFighter2){
    ptrFighter1 = fighter1;
    ptrFighter2 = fighter2;
    id = staticId;
    staticId++;
    auto score = new Score();
    ptrScore = std::make_shared<Score>(*score);
    setWeaponFighter1(mainWeaponFighter1, offhandWeaponFighter1);
    setWeaponFighter2(mainWeaponFighter2, offhandWeaponFighter2);
}

void Bout::setScore(int bigPointFighter1, int smallPointFighter1, int bigPointFighter2, int smallPointFighter2) {
    ptrScore->setBigPointsFighter1(bigPointFighter1);
    ptrScore->setSmallPointsFighter1(smallPointFighter1);
    ptrScore->setBigPointsFighter2(bigPointFighter2);
    ptrScore->setSmallPointsFighter2(smallPointFighter2);
}

void Bout::resetScore() {
    ptrScore->reset();
}

std::pair<int, int> Bout::getScoreFighter1() {
    return std::pair<int, int>(ptrScore->getBigPointsFighter1(), ptrScore->getSmallPointsFighter1());
}

std::pair<int, int> Bout::getScoreFighter2() {
    return std::pair<int, int>(ptrScore->getBigPointsFighter2(), ptrScore->getSmallPointsFighter2());
}

void Bout::resolve() {
    if(getScoreFighter1().first == getScoreFighter2().first){
        if(getScoreFighter1().second > getScoreFighter2().second) result = Result::WonFighter1;
        if(getScoreFighter1().second < getScoreFighter2().second) result = Result::WonFighter2;
        if(getScoreFighter1().second == getScoreFighter2().second) result = Result::Tie;
    }
    if(getScoreFighter1().first > getScoreFighter2().first){
        result = Result::WonFighter1;
    }
    if(getScoreFighter1().first > getScoreFighter2().first){
        result = Result::WonFighter2;
    }
}
