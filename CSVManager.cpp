//
// Created by jacek on 2020-04-10.
//

#include "CSVManager.hpp"

std::vector<std::vector<std::string>> CSVManager::getData() {

    std::fstream f;
    f.open(fileName);
    int count = 0;
    std::string line, temp;
    std::vector<std::vector<std::string>> dataRead;
    while(!f.eof()) {
        std::getline(f, line);
        std::vector<std::string> row;
        std::string temporaryString;
        for(auto character = line.cbegin(); character != line.cend(); ++character){

//            std::cout<<temporaryString<<std::endl;
            if(line.empty()) break;
            if(*character == delimiter || character == line.cend() || *character == '\n' || *character == '\r')
            {
                row.push_back(temporaryString);
                temporaryString = "";
            }
            else{
                temporaryString += *character;
            }
        }
//        row.push_back(temporaryString);
        dataRead.push_back(row);
        count++;
    }
        dataRead.pop_back();
    if (count == 0) std::cout << "Record not found\n";
    //TODO rzucanie wyjatku
    f.close();
    return dataRead;
}