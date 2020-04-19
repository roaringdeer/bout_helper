//
// Created by jacek on 2020-04-10.
//

#include "../include/Scoreboard.hpp"

BoutId Scoreboard::addBout(Stage stage) {
    auto bout = new Bout(stage);
    BoutId tempId= bout->getId();
    boutCollection.addToCollection(std::move(*bout));
    return tempId;
}

std::list<Bout>::iterator Scoreboard::getBoutByID(BoutId boutId) {
    return boutCollection.getByID(boutId);
}

std::list<BoutId> Scoreboard::getBoutIdsByFighterId(FighterId fighterId) {
    std::list<BoutId> tempList;
    for(auto & it : boutCollection){
        if(fighterId == it.getFighterIds().first || fighterId == it.getFighterIds().second){
            tempList.push_back(it.getId());
        }
    }
    return tempList;
}

std::pair<std::pair<int, int >, std::pair<int, int>> Scoreboard::getScoreByBoutId(BoutId boutId) {
    return boutCollection.getByID(boutId)->getFightersScores();
}

double Scoreboard::estimateFighterProwess(FighterId fighterId) {
    std::list<BoutId> boutList = getBoutIdsByFighterId(fighterId);
    double estimator = 0.0;
//    double scaledPoints = 0.0;
    int bigPoints = 0;
    int smallPoints = 0;
//    int bigPointsTaken = 0;
//    int smallPointsTaken = 0;
    int won = 0;
    int lost = 0;
    for(auto id : boutList){
        if(getBoutByID(id)->getResult() != Result::Pending) {
            if (fighterId == getBoutByID(id)->getFighterIds().first) {
                bigPoints += getScoreByBoutId(id).first.first;
                smallPoints += getScoreByBoutId(id).first.second;
                bigPoints -= getScoreByBoutId(id).second.first;
                smallPoints -= getScoreByBoutId(id).second.second;
                if (getBoutByID(id)->getResult() == Result::WonFighter1) won += 1;
                if (getBoutByID(id)->getResult() == Result::WonFighter2) lost += 1;
            } else {
                bigPoints += getScoreByBoutId(id).second.first;
                smallPoints += getScoreByBoutId(id).second.second;
                bigPoints -= getScoreByBoutId(id).first.first;
                smallPoints -= getScoreByBoutId(id).first.second;
                if (getBoutByID(id)->getResult() == Result::WonFighter1) lost += 1;
                if (getBoutByID(id)->getResult() == Result::WonFighter2) won += 1;
            }
        }
    }
    std::cout<<bigPoints<<" "<<smallPoints<<" "<<won<<" "<<lost<<std::endl;
    //wersja 1:
//    if(bigPoints != 0 && smallPoints != 0) scaledPoints = abs((bigPoints+smallPoints)/(abs(bigPoints)+abs(smallPoints)));
//    estimator = 0.5*(0.7 * scaledBigPoints + 0.3 * scaledSmallPoints)+0.5*(won/(won+lost)-0.5);
    //wersja 2:
//    estimator = won/(won+lost)*scaledPoints - (1-scaledPoints)*lost/(won+lost);
    //wersja 3:
//    double percentageWon = won*1.0/(won+lost);
//    estimator = (bigPoints+smallPoints/3.0)*percentageWon - (bigPointsTaken + smallPointsTaken/3.0)*(1-percentageWon);
    //wersja 4:
//    estimator = (0.8 + 0.2*percentageWon)*(bigPoints+smallPoints/3.0);
    estimator = 1.0*(won-lost)/(won + lost);
    return estimator;
}