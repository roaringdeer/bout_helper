//
// Created by jacek on 2020-04-14.
//

#ifndef BOUT_HELPER_GROUP_HPP
#define BOUT_HELPER_GROUP_HPP


#include <vector>
#include "PrimitiveTypes.hpp"

class Group {
private:
    static GroupId staticId;
    GroupId id = 0;
    std::vector<FighterId> fighters;
    std::vector<std::vector<BoutId>> boutIds;
public:
    explicit Group(std::vector<FighterId> vecFighterIds) : fighters(std::move(vecFighterIds)), id(staticId++){}

    int getGroupId(){return id;}

    std::vector<FighterId> getFighterIds(){return fighters;}
    BoutId getFightersScore(FighterId fighter1, FighterId fighter2){return boutIds[fighter1][fighter2];}
    void printFighterIds();
};


#endif //BOUT_HELPER_GROUP_HPP