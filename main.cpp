//
// Created by jacek on 2019-11-18.
//

#include "main.hpp"
#include "CSVManager.hpp"
#include "Rooster.hpp"
#include "Bout.hpp"
#include <iostream>


int main(){
    Rooster rooster;
    rooster.getRoosterFromCSV();

    std::cout<<rooster.getRooster()[0]->getName()<<std::endl;
    Bout bout(rooster.getRooster()[0], rooster.getRooster()[1]);
    bout.setWeaponFighter1(Weapon::OneHandedSword, Weapon::Buckler);
    bout.setScore(1, 3,1, 4);
    bout.resolve();
    std::cout<<bout.getScoreFighter1().first<<"|"<<bout.getScoreFighter1().second<<" : "<<bout.getScoreFighter2().first<<"|"<<bout.getScoreFighter2().second<<std::endl;
    std::cout<<Utilities::resultEnum2Str(bout.getResult());
    return 0;
}