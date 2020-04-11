//
// Created by jacek on 2019-11-19.
//

#include "Bout.hpp"

int Bout::getBigPointFighter1() {
    return bigPointFighter1;
}

int Bout::getSmallPointFighter1() {
    return smallPointFighter1;
}

int Bout::getBigPointFighter2() {
    return bigPointFighter2;
}

int Bout::getSmallPointFighter2() {
    return smallPointFighter2;
}

Weapon* Bout::getWeaponFighter1() {
    return weaponFighter1;
}

Weapon* Bout::getWeaponFighter2() {
    return weaponFighter2;
}

void Bout::setBigPointFighter1(int score) {
    bigPointFighter1 = score;
}

void Bout::setSmallPointFighter1(int score) {
    smallPointFighter1 = score;
}

void Bout::setBigPointFighter2(int score) {
    bigPointFighter2 = score;
}

void Bout::setSmallPointFighter2(int score) {
    smallPointFighter2 = score;
}

void Bout::setWeaponFighter1(Weapon weapon1, Weapon weapon2) {
    weaponFighter1[0] = weapon1;
    weaponFighter1[1] = weapon2;
}

void Bout::setWeaponFighter2(Weapon weapon1, Weapon weapon2) {
    weaponFighter1[0] = weapon1;
    weaponFighter1[1] = weapon2;
}

std::map<Points, int> Bout::getScoreFighter1() {
    std::map<Points, int> score;
    int bigPoints = getBigPointFighter1() + getSmallPointFighter1()/pointsDivider;
    int smallPoints = getSmallPointFighter1()%pointsDivider;
    score[Points::BigPoint] = bigPoints;
    score[Points::SmallPoint] = smallPoints;
    return score;
}

std::map<Points, int> Bout::getScoreFighter2() {
    std::map<Points, int> score;
    int bigPoints = getBigPointFighter2() + getSmallPointFighter2()/pointsDivider;
    int smallPoints = getSmallPointFighter2()%pointsDivider;
    score[Points::BigPoint] = bigPoints;
    score[Points::SmallPoint] = smallPoints;
    return score;
}

Bout::Bout(std::shared_ptr<Fighter> fighter1, std::shared_ptr<Fighter> fighter2) {
    ptrFighter1 = fighter1;
    ptrFighter2 = fighter2;
}

int Bout::getPointsDivider() {
    return pointsDivider;
}

void Bout::setPointsDivider(int pointsDiv) {
    pointsDivider = pointsDiv;
}
