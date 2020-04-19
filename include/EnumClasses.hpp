//
// Created by jacek on 2019-11-19.
//

#ifndef BOUT_HELPER_ENUMCLASSES_HPP
#define BOUT_HELPER_ENUMCLASSES_HPP

enum class Weapon{
    Longsword,
    Sabre,
    Rapier,
    OneHandedSword,
    Buckler,
    Messer,
    Katana,
    Naginata,
    Cape,
    None
};

enum class Points{
    BigPoint,
    SmallPoint
};

enum class Stage{
    GroupStage,
    EighthFinals,
    QuaterFinals,
    SemiFinals,
    Final,
    ThirdPlace
};

enum class Gender{
    Male,
    Female,
    Other,
    Undefined
};

enum class Result{
    WonFighter1,
    WonFighter2,
    Tie,
    Pending
};
#endif //BOUT_HELPER_ENUMCLASSES_HPP
