//
// Created by jacek on 2020-04-11.
//

#ifndef BOUT_HELPER_FIGHTERCOLLECTION_HPP
#define BOUT_HELPER_FIGHTERCOLLECTION_HPP


#include "Fighter.hpp"
#include "Collection.hpp"

template <typename T>
class FighterCollection : public Collection<T> {
    using iterator = typename std::list<T>::iterator;
    using const_iterator = typename std::list<T>::const_iterator;
public:
    FighterCollection() = default;
    ~FighterCollection() = default;

    void deleteFromCollection(FighterId id) {
        auto element = getByID(id);
        this->_collection.erase(element);
    }
    void deleteFromCollection(const std::string& name) {
        auto element = getByName(name);
        this->_collection.erase(element);
    }
    iterator getByID(FighterId id) {
        for(iterator it = this->_collection.begin(); it != this->_collection.end(); it++){
            if(it->getId() == id) return it;
        }
    }
    iterator getByName(const std::string& name){
        for(auto it = this->_collection.begin(); it != this->_collection.end(); it++){
            if(it->getName() == name) return it;
        }
        return this->_collection.end();
    }
    std::list<T> getCollection() const{
        return this->_collection;
    }
};


#endif //BOUT_HELPER_FIGHTERCOLLECTION_HPP
