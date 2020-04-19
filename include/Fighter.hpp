//
// Created by jacek on 2019-11-19.
//

#ifndef BOUT_HELPER_FIGHTER_HPP
#define BOUT_HELPER_FIGHTER_HPP

#include "EnumClasses.hpp"
#include "Utilities.hpp"
#include "PrimitiveTypes.hpp"
#include <iostream>
#include <map>
#include <utility>

class Fighter {

private:
    static FighterId _staticId;
    FighterId _id;
    std::string _forename = "";
    std::string _surname = "";
    std::string _club = "";
    std::string _nationality = "";
    Gender _gender = Gender::Undefined;

public:
    Fighter() : _id(_staticId++){};
    Fighter(std::string forename, std::string surname, const std::string& gender , std::string club, std::string nationality){
        _forename = std::move(forename);
        _surname = std::move(surname);
        _club = std::move(club);
        _nationality = std::move(nationality);
        _gender = Utilities::genderStr2Enum(gender);
        _id = _staticId;
        _staticId++;
    }
    Fighter(FighterId id, std::string forename, std::string surname, const std::string& gender , std::string club, std::string nationality){
        _id = id;
        _forename = std::move(forename);
        _surname = std::move(surname);
        _club = std::move(club);
        _nationality = std::move(nationality);
        _gender = Utilities::genderStr2Enum(gender);
    }

    //getter
    std::string getName();
    std::string getClub() { return _club;};
    std::string getNationality(){ return _nationality;};
    Gender getGender() { return _gender;};
    FighterId getId() const { return _id;}

    //setter
    void setForename(const std::string& forename);
    void setSurname(const std::string& surname);
    void setGender(Gender gender);
    void setClub(const std::string& clubName);
    void setNationality(const std::string& nationality);
};


#endif //BOUT_HELPER_FIGHTER_HPP