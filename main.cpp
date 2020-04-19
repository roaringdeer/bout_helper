//
// Created by jacek on 2019-11-18.
//

#include "include/main.hpp"
#include "include/CSVManager.hpp"
#include "include/Rooster.hpp"
#include "include/Bout.hpp"
#include "include/Scoreboard.hpp"
#include "include/Ladder.hpp"
#include "include/GroupStage.hpp"
#include <iostream>


int main(){
    //test Rooster
    std::cout<<std::endl;
    std::cout<<"ROOSTER"<<std::endl;
    Rooster rooster;
    rooster.getRoosterFromCSV();
    std::cout<<rooster.getFighterById(2)->getName()<< " vs "<< rooster.getFighterById(3)->getName()<<std::endl;

    //test Bout
    std::cout<<std::endl;
    std::cout<<"BOUT"<<std::endl;
    Bout bout(rooster.getFighterById(2)->getId(), rooster.getFighterByName("Young Jip")->getId());
    bout.setWeaponFighter1(Weapon::OneHandedSword, Weapon::Buckler);
    bout.setScore(1, 3,1, 4);
    bout.resolve();
    std::cout<<bout.getScoreFighter1().first<<"|"<<bout.getScoreFighter1().second<<" : "<<bout.getScoreFighter2().first<<"|"<<bout.getScoreFighter2().second<<std::endl;
    std::cout<<Utilities::resultEnum2Str(bout.getResult())<<std::endl;


    std::cout<<std::endl;
    std::cout<<"SCOREBOARD"<<std::endl;
    Scoreboard scoreboard;
    auto id1 = scoreboard.addBout(Stage::Final);
    auto id2 = scoreboard.addBout(Stage::Final);
    auto id3 = scoreboard.addBout(Stage::Final);

    scoreboard.getBoutByID(id1)->setFighterIds(2, 3);
    scoreboard.getBoutByID(id2)->setFighterIds(1, 2);
    scoreboard.getBoutByID(id3)->setFighterIds(1, 3);

    scoreboard.getBoutByID(id1)->setScore(1, 10, 1, 3);
    scoreboard.getBoutByID(id2)->setScore(0, 0, 2, 3);
    scoreboard.getBoutByID(id3)->setScore(4, 0, 0, 1);

    scoreboard.getBoutByID(id1)->resolve();
    scoreboard.getBoutByID(id2)->resolve();
    scoreboard.getBoutByID(id3)->resolve();

    std::cout<<"Bout 1: "<<scoreboard.getScoreByBoutId(id1).first.first<<"|"<<scoreboard.getScoreByBoutId(id1).first.second<<" - "<<scoreboard.getScoreByBoutId(id1).second.first<<"|"<<scoreboard.getScoreByBoutId(id1).second.second<<std::endl;
    std::cout<<Utilities::resultEnum2Str(scoreboard.getBoutByID(id1)->getResult())<<std::endl;
    std::cout<<"Bout 2: "<<scoreboard.getScoreByBoutId(id2).first.first<<"|"<<scoreboard.getScoreByBoutId(id2).first.second<<" - "<<scoreboard.getScoreByBoutId(id2).second.first<<"|"<<scoreboard.getScoreByBoutId(id2).second.second<<std::endl;
    std::cout<<Utilities::resultEnum2Str(scoreboard.getBoutByID(id2)->getResult())<<std::endl;
    std::cout<<"Bout 2: "<<scoreboard.getScoreByBoutId(id3).first.first<<"|"<<scoreboard.getScoreByBoutId(id3).first.second<<" - "<<scoreboard.getScoreByBoutId(id3).second.first<<"|"<<scoreboard.getScoreByBoutId(id3).second.second<<std::endl;
    std::cout<<Utilities::resultEnum2Str(scoreboard.getBoutByID(id3)->getResult())<<std::endl;


    std::cout<<"Fighter Prowess 1: "<<scoreboard.estimateFighterProwess(1)<<std::endl;
    std::cout<<"Fighter Prowess 2: "<<scoreboard.estimateFighterProwess(2)<<std::endl;
    std::cout<<"Fighter Prowess 3: "<<scoreboard.estimateFighterProwess(3)<<std::endl;

    std::cout<<std::endl;
    std::cout<<"LADDER"<<std::endl;
    std::vector<FighterId> ids;
    for(int i = 0; i<16; i++){
        ids.push_back(i+1);
    }
    auto ptr = std::shared_ptr<Scoreboard>(&scoreboard);
    Ladder ladder(ids, ptr);
    std::cout<<ladder.getFightersNumber()<<std::endl;

    std::cout<<std::endl;
    std::cout<<"GROUP STAGE"<<std::endl;
    GroupStage groupStage(ptr);
    groupStage.createGroups(rooster);
    std::cout<<std::endl;

    for(auto i : groupStage.getGroups()){
        std::cout<<"Group "<< i.getGroupId()<<": ";
        Utilities::printVectorInline(i.getFighterIds(), " ");
    }

    return 0;
}