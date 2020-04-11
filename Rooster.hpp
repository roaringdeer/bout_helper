//
// Created by jacek on 2020-04-10.
//

#ifndef BOUT_HELPER_ROOSTER_HPP
#define BOUT_HELPER_ROOSTER_HPP

#include "Fighter.hpp"
#include <memory>
#include <vector>
class Rooster {

private:
    std::vector<std::shared_ptr<Fighter>> rooster;

public:
    Rooster() = default;
    void getRoosterFromCSV(const std::string& fileName = "fighters.csv");
    std::vector<std::shared_ptr<Fighter>> getRooster();
};


#endif //BOUT_HELPER_ROOSTER_HPP
