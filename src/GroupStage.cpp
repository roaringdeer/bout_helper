//
// Created by jacek on 2020-04-14.
//

#include <random>
#include <algorithm>
#include "../include/GroupStage.hpp"

void GroupStage::scatterAndAssignFighters(const Rooster &rooster, int maxGroupSize) {
    auto fighters = rooster.getShuffledFighters();
    while(fighters.size()>maxGroupSize){
        std::vector<FighterId> group;
        for (int j = 0; j < maxGroupSize; j++) {
            auto f = fighters.back();
            fighters.pop_back();
            group.push_back(f);
        }
        groups.emplace_back(group);
    }
    if(!fighters.empty()) groups.emplace_back(fighters);
}

void GroupStage::createGroups(const Rooster& rooster) {
    if(rooster.size() > 64) throw std::runtime_error("Too many fighters. What were you thinking?");
    if(rooster.size() < 16) throw std::runtime_error("Too little fighters. Is it Women's Longsword?");
    int optimized = optimizeGroupCount(rooster.size());
    scatterAndAssignFighters(rooster, optimized);
}

int GroupStage::optimizeGroupCount(int roosterSize, int maxGroupSize) {
    int groupCount;
    int minGroupSize = 0;
    int localMin;
    int globalMin = 1000000000;
    if(roosterSize%2 == 1) roosterSize++;
    for(int i = 4; i < maxGroupSize+1; i++) {
        groupCount = roosterSize / i;
        if(roosterSize%maxGroupSize != 0) groupCount++;
        localMin = groupCount * (i - 1) * i / 2;
        if(localMin < globalMin){
            globalMin = localMin;
            minGroupSize = i;
        }
    }
    return minGroupSize;
}
