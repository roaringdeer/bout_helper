//
// Created by jacek on 2020-04-10.
//

#ifndef BOUT_HELPER_SCOREBOARD_HPP
#define BOUT_HELPER_SCOREBOARD_HPP

#include <vector>
#include <memory>
#include <map>
#include "Fighter.hpp"
#include "Rooster.hpp"
#include "BoutCollection.hpp"


class Scoreboard {
private:
    BoutCollection<Bout> boutCollection;
public:
    Scoreboard(){
        auto nullBout = new Bout(0, 0);
        boutCollection.addToCollection(std::move(*nullBout));
    };
    //methods
    BoutId addBout();
    //getter
    std::list<Bout>::iterator getBoutByID(BoutId boutId);
    std::list<BoutId> getBoutIdsByFighterId(FighterId fighterId);
    std::pair<std::pair<int, int >, std::pair<int, int>> getScoreByBoutId(BoutId boutId);
    double estimateFighterProwess(FighterId fighterId);
    //setter


};


#endif //BOUT_HELPER_SCOREBOARD_HPP
