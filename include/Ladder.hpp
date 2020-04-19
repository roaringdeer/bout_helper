//
// Created by jacek on 2020-04-10.
//

#ifndef BOUT_HELPER_LADDER_HPP
#define BOUT_HELPER_LADDER_HPP


#include "Bout.hpp"
#include "Scoreboard.hpp"
class Ladder {
private:
    BoutId eighths[8] = {0, 0, 0, 0, 0, 0, 0, 0};
    BoutId fourths[4] = {0, 0, 0, 0};
    BoutId semifinals[2] = {0, 0};
    BoutId final = 0;
    BoutId thirdPlace = 0;
    std::shared_ptr<Scoreboard> ptrScoreboard;
    std::vector<FighterId> fighters;
    FighterId luckyPassFighter = 0;
    void initilizeLadder();
public:
    Ladder() = default;
    ~Ladder() = default;
    Ladder(std::vector<FighterId> groupWinners, std::shared_ptr<Scoreboard> scoreBoard);
    bool addFighter(FighterId fighterId){};
    void startLadder();

    int getFightersNumber(){ return fighters.size();}

};


#endif //BOUT_HELPER_LADDER_HPP
