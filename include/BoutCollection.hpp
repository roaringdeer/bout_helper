//
// Created by jacek on 2020-04-13.
//

#ifndef BOUT_HELPER_BOUTCOLLECTION_HPP
#define BOUT_HELPER_BOUTCOLLECTION_HPP

#include "Bout.hpp"
template <typename T>
class BoutCollection : public Collection<T>{
    using iterator = typename std::list<T>::iterator;
    using const_iterator = typename std::list<T>::const_iterator;
public:
    BoutCollection() = default;
    ~BoutCollection() = default;
    void deleteFromCollection(BoutId id) {
        auto element = getByID(id);
        this->_collection.erase(element);
    }
    iterator getByID(BoutId id) {
        for(auto it = this->begin(); it != this->end(); it++){
            if(it->getId() == id) return it;
        }
    }
};


#endif //BOUT_HELPER_BOUTCOLLECTION_HPP
