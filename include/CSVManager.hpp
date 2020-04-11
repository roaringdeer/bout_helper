//
// Created by jacek on 2020-04-10.
//

#ifndef BOUT_HELPER_CSVMANAGER_HPP
#define BOUT_HELPER_CSVMANAGER_HPP

#include <utility>
#include <string>
#include <vector>
#include <map>
#include <iosfwd>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

class CSVManager { ;

private:
    std::string fileName;
    char delimiter;
public:
    CSVManager(std::string fileName, char delimiter): fileName(std::move(fileName)), delimiter(delimiter){}

    std::vector<std::vector<std::string>> getData();
};


#endif //BOUT_HELPER_CSVMANAGER_HPP
