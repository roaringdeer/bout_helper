//
// Created by jacek on 2019-11-19.
//

#ifndef BOUT_HELPER_BOUT_HPP
#define BOUT_HELPER_BOUT_HPP

#include "Fighter.hpp"
#include "EnumClasses.hpp"
#include <memory>
class Bout {



private:
    std::shared_ptr<Fighter> ptrFighter1;
    std::shared_ptr<Fighter> ptrFighter2;
    int bigPointFighter1 = 0;
    int smallPointFighter1 = 0;
    int bigPointFighter2 = 0;
    int smallPointFighter2 = 0;
    inline static int pointsDivider = 3;
    Weapon weaponFighter1[2] = {Weapon::None, Weapon::None};
    Weapon weaponFighter2[2] = {Weapon::None, Weapon::None};

public:
    Bout(std::shared_ptr<Fighter> fighter1, std::shared_ptr<Fighter> fighter2);
    //getter
    int getBigPointFighter1();
    int getSmallPointFighter1();
    int getBigPointFighter2();
    int getSmallPointFighter2();
    Weapon* getWeaponFighter1();
    Weapon* getWeaponFighter2();
    std::map<Points, int> getScoreFighter1();
    std::map<Points, int> getScoreFighter2();
    static int getPointsDivider();

    //setter
    void setBigPointFighter1(int score);
    void setSmallPointFighter1(int score);
    void setBigPointFighter2(int score);
    void setSmallPointFighter2(int score);
    void setWeaponFighter1(Weapon weapon1, Weapon weapon2);
    void setWeaponFighter2(Weapon weapon1, Weapon weapon2);
    static void setPointsDivider(int pointsDiv);

    //methods

};


#endif //BOUT_HELPER_BOUT_HPP
