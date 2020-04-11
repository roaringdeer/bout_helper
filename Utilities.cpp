//
// Created by jacek on 2020-04-11.
//

#include "Utilities.hpp"

std::map<std::string, Gender> Utilities::genderLUT = {
    {"Male", Gender::Male},
    {"Female", Gender::Female},
    {"Other", Gender::Other},
    {"Undefined", Gender::Undefined}
};

std::map<std::string, Result> Utilities::resultLUT = {
        {"Won Fighter 1", Result::WonFighter1},
        {"Won Fighter 2", Result::WonFighter2},
        {"Tie", Result::Tie},
        {"Pending", Result::Pending}
};

std::string Utilities::genderEnum2Str(Gender gender) {
    for(auto & it : genderLUT){
        if(it.second==gender) return it.first;
    }
}

Gender Utilities::genderStr2Enum(const std::string& gender) {
    return genderLUT[gender];
}

std::string Utilities::resultEnum2Str(Result result) {
    for(auto & it : resultLUT){
        if(it.second == result) return it.first;
    }
}

Result Utilities::resultStr2Enum(const std::string &result) {
    return resultLUT[result];
}


