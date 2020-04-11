//
// Created by jacek on 2020-04-10.
//

#ifndef BOUT_HELPER_SCOREBOARD_HPP
#define BOUT_HELPER_SCOREBOARD_HPP

#include <vector>
#include <memory>
#include <map>
#include "Bout.hpp"
#include "Fighter.hpp"
#include "Rooster.hpp"

class Scoreboard {

    Scoreboard(Rooster rooster);

private:
    std::map<std::shared_ptr<Fighter>, std::map<std::shared_ptr<Fighter>, std::shared_ptr<Bout>>> scoreboard;
};


#endif //BOUT_HELPER_SCOREBOARD_HPP
