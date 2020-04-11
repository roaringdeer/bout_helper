//
// Created by jacek on 2020-04-11.
//

#ifndef BOUT_HELPER_UTILITIES_HPP
#define BOUT_HELPER_UTILITIES_HPP

#include <string>
#include <map>
#include "EnumClasses.hpp"

class Utilities {
private:
    static std::map<std::string, Gender> genderLUT;
    static std::map<std::string, Result> resultLUT;
public:
    static Gender genderStr2Enum(const std::string& gender);
    static std::string genderEnum2Str(Gender gender);
    static Result resultStr2Enum(const std::string& result);
    static std::string resultEnum2Str(Result result);

};


#endif //BOUT_HELPER_UTILITIES_HPP
