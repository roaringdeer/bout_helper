//
// Created by jacek on 2019-11-19.
//

#include "../include/Fighter.hpp"

int Fighter::_staticId = 0;

std::string Fighter::getName() {
    std::string name = _forename + " " + _surname;
    return name;
}

void Fighter::setForename(const std::string& forename){
    _forename = forename;
}

void Fighter::setSurname(const std::string& surname) {
    _surname = surname;
}

void Fighter::setGender(Gender gender) {
    _gender = gender;
}

void Fighter::setClub(const std::string& clubName) {
    _club = clubName;
}

void Fighter::setNationality(const std::string& nationality) {
    _nationality = nationality;
}