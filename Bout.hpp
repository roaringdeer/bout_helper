//
// Created by jacek on 2019-11-19.
//

#ifndef BOUT_HELPER_BOUT_HPP
#define BOUT_HELPER_BOUT_HPP

#include "Fighter.hpp"
#include "EnumClasses.hpp"
#include "Score.hpp"
#include "PrimitiveTypes.hpp"
#include <memory>
class Bout {



private:
    static BoutId staticId;
    BoutId id;
    std::shared_ptr<Fighter> ptrFighter1;
    std::shared_ptr<Fighter> ptrFighter2;
    std::shared_ptr<Score> ptrScore;
    Result result = Result::Pending;
    Weapon weaponFighter1[2] = {Weapon::None, Weapon::None};
    Weapon weaponFighter2[2] = {Weapon::None, Weapon::None};

public:
    Bout(std::shared_ptr<Fighter> fighter1, std::shared_ptr<Fighter> fighter2);
    Bout(std::shared_ptr<Fighter> fighter1, std::shared_ptr<Fighter> fighter2, Weapon mainWeaponFighter1, Weapon offhandWeaponFighter1, Weapon mainWeaponFighter2, Weapon offhandWeaponFighter2);
    Bout(const Bout& bout): id(bout.getId()){};
    //getter
    Weapon* getWeaponFighter1() { return weaponFighter1;}
    Weapon* getWeaponFighter2() { return weaponFighter2;}
    [[nodiscard]] BoutId getId() const { return id; }
    [[nodiscard]] Result getResult() const { return result;}

    //TODO temporary
    std::pair<int, int> getScoreFighter1();
    std::pair<int, int> getScoreFighter2();

    //setter
    void setWeaponFighter1(Weapon weapon1, Weapon weapon2){ weaponFighter1[0] = weapon1; weaponFighter1[1] = weapon2;}
    void setWeaponFighter2(Weapon weapon1, Weapon weapon2){ weaponFighter2[0] = weapon1; weaponFighter2[1] = weapon2;}
    void setScore(int bigPointFighter1, int smallPointFighter1, int bigPointFighter2, int smallPointFighter2);

    //methods
    void resetScore();
    void resolve();
};

#endif //BOUT_HELPER_BOUT_HPP
