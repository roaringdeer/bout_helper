//
// Created by jacek on 2020-04-11.
//

#ifndef BOUT_HELPER_FIGHTERCOLLECTION_HPP
#define BOUT_HELPER_FIGHTERCOLLECTION_HPP

#include <list>
#include <string>
#include "PrimitiveTypes.hpp"

template <typename T>
class FighterCollection {
    using iterator = typename std::list<T>::iterator;
    using const_iterator = typename std::list<T>::const_iterator;
private:
    std::list<T> _collection;
public:
    FighterCollection() = default;
    ~FighterCollection() = default;

    void addToCollection(T element) { _collection.push_back(element); }

    void deleteFromCollection(FighterId id) {
        iterator element = getByID(id);
        _collection.erase(element);
    }

    void deleteFromCollection(const std::string& name) {
        iterator element = getByName(name);
        _collection.erase(element);
    }

    iterator begin(){ return _collection.begin(); }
    iterator end(){ return  _collection.end(); }
    iterator cbegin(){ return _collection.cbegin(); }
    iterator cend(){ return _collection.cend(); }
    size_t getCollectionSize(){ return _collection.size(); }
    iterator getByID(FighterId id) {
        for(auto it = _collection.begin(); it != _collection.end(); it++){
            if(it->getID == id) return it;
        }
    }
    iterator getByName(const std::string& name){
        for(auto it = _collection.begin(); it != _collection.end(); it++){
            if(it->getName == name) return it;
        }
        return _collection.end();
    }
};


#endif //BOUT_HELPER_FIGHTERCOLLECTION_HPP
