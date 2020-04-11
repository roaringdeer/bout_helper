//
// Created by jacek on 2019-11-18.
//

#include "main.hpp"
#include "CSVManager.hpp"
#include "Rooster.hpp"
#include <iostream>


int main(){
    Rooster rooster;
    rooster.getRoosterFromCSV();

    std::cout<<rooster.getRooster()[0]->getName();

    return 0;
}