//
// Created by jacek on 2020-04-11.
//

#include <iostream>
#include "Score.hpp"


void Score::reload() {
//    std::cout<<"pre: "<<bigPointFighter1<<" "<<smallPointFighter1<<" "<<bigPointFighter2<<" "<<smallPointFighter2<<std::endl;
    bigPointFighter1 += smallPointFighter1/pointsDivider;
    bigPointFighter2 += smallPointFighter2/pointsDivider;
    smallPointFighter1 = smallPointFighter1%pointsDivider;
    smallPointFighter2 = smallPointFighter2%pointsDivider;
//    std::cout<<"post: "<<bigPointFighter1<<" "<<smallPointFighter1<<" "<<bigPointFighter2<<" "<<smallPointFighter2<<std::endl;
}

void Score::reset() {
    bigPointFighter1 = 0;
    smallPointFighter1 = 0;
    bigPointFighter2 = 0;
    smallPointFighter2 = 0;
}
