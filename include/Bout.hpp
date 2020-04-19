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
    FighterId idFighter1 = 0;
    FighterId idFighter2 = 0;
    Stage stage;
    std::shared_ptr<Score> ptrScore;
    Result result = Result::Pending;
    Weapon weaponFighter1[2] = {Weapon::None, Weapon::None};
    Weapon weaponFighter2[2] = {Weapon::None, Weapon::None};

public:
    Bout(Stage boutStage) : id(staticId++){
        auto score = new Score();
        ptrScore = std::make_shared<Score>(*score);
        ptrScore->resetPoints();
        stage = boutStage;
    };
    Bout(FighterId idFighter1, FighterId idFighter2) : id(staticId++), idFighter1(idFighter1), idFighter2(idFighter2){
        auto score = new Score();
        ptrScore = std::make_shared<Score>(*score);
        ptrScore->resetPoints();
    };
    //getter
    Weapon* getWeaponFighter1() { return weaponFighter1;}
    Weapon* getWeaponFighter2() { return weaponFighter2;}
    [[nodiscard]] BoutId getId() const { return id; }
    [[nodiscard]] Result getResult() const { return result;}
    std::pair<int, int> getScoreFighter1();
    std::pair<int, int> getScoreFighter2();
    std::shared_ptr<Score> getScore() { return ptrScore;}
    std::pair<int, int> getFighterIds() {return std::make_pair(idFighter1, idFighter2);}
    std::pair<std::pair<int, int>, std::pair<int, int>> getFightersScores();

    //setter
    void setFighterIds(FighterId fighter1, FighterId fighter2){ idFighter1 = fighter1; idFighter2 = fighter2;};
    void setWeaponFighter1(Weapon weapon1, Weapon weapon2){ weaponFighter1[0] = weapon1; weaponFighter1[1] = weapon2;}
    void setWeaponFighter2(Weapon weapon1, Weapon weapon2){ weaponFighter2[0] = weapon1; weaponFighter2[1] = weapon2;}
    void setScore(int bigPointFighter1, int smallPointFighter1, int bigPointFighter2, int smallPointFighter2);

    //methods
    void resetScore();
    void resolve();
};

#endif //BOUT_HELPER_BOUT_HPP