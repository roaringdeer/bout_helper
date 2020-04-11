//
// Created by jacek on 2019-11-18.
//

#include "include/main.hpp"
#include "include/CSVManager.hpp"
#include "include/Rooster.hpp"
#include "include/Bout.hpp"
#include <iostream>


int main(){
    //test Rooster
    Rooster rooster;
    rooster.getRoosterFromCSV();
    std::cout<<rooster.getFighterById(0)->getName()<<std::endl;

    //test Bout
    Bout bout(rooster.getFighterById(0), rooster.getFighterByName("Hurr Durr"));
    bout.setWeaponFighter1(Weapon::OneHandedSword, Weapon::Buckler);
    bout.setScore(1, 3,1, 4);
    bout.resolve();
    std::cout<<bout.getScoreFighter1().first<<"|"<<bout.getScoreFighter1().second<<" : "<<bout.getScoreFighter2().first<<"|"<<bout.getScoreFighter2().second<<std::endl;
    std::cout<<Utilities::resultEnum2Str(bout.getResult());




    return 0;
}