//
// Created by jacek on 2020-04-14.
//

#include "../include/Group.hpp"
#include "../include/Utilities.hpp"

#include <utility>

int Group::staticId = 1;

void Group::printFighterIds() {
    Utilities::printVectorInline(fighters);
}
