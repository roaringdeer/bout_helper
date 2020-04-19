//
// Created by jacek on 2020-04-14.
//

#ifndef BOUT_HELPER_GROUPSTAGE_HPP
#define BOUT_HELPER_GROUPSTAGE_HPP


#include "Scoreboard.hpp"
#include "Group.hpp"

class GroupStage {
private:
    std::shared_ptr<Scoreboard> ptrScoreboard;
    std::vector<Group> groups;

    void scatterAndAssignFighters(const Rooster& rooster, int maxGroupSize);
public:
    GroupStage(std::shared_ptr<Scoreboard> scoreboard) : ptrScoreboard(scoreboard){};
    void createGroups(const Rooster& rooster);
    int optimizeGroupCount(int roosterSize, int maxGroupSize = 8);
    std::vector<Group> getGroups() { return groups;}
};


#endif //BOUT_HELPER_GROUPSTAGE_HPP
