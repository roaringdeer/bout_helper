//
// Created by jacek on 2019-11-19.
//

#ifndef BOUT_HELPER_FIGHTER_HPP
#define BOUT_HELPER_FIGHTER_HPP

#include "EnumClasses.hpp"
#include <iostream>
#include <map>
#include <utility>

class Fighter {

private:
    std::string _forename;
    std::string _surname;
    std::string _club;
    std::string _nationality;
    Gender _gender;

public:
    Fighter() = default;
    Fighter(std::string forename, std::string surname, Gender gender , std::string club, std::string nationality){
        _forename = std::move(forename);
        _surname = std::move(surname);
        _club = std::move(club);
        _gender = gender;
        _nationality = std::move(nationality);
    }

    //getter
    std::string getName();
    std::string getClub();
    std::string getNationality();
    Gender getGender();

    //setter
    void setForename(const std::string& forename);
    void setSurname(const std::string& surname);
    void setGender(Gender gender);
    void setClub(const std::string& clubName);
    void setNationality(const std::string& nationality);
};


#endif //BOUT_HELPER_FIGHTER_HPP