//
// Created by jacek on 2020-04-11.
//

#ifndef BOUT_HELPER_COLLECTION_HPP
#define BOUT_HELPER_COLLECTION_HPP

#include <list>
#include <string>
#include "PrimitiveTypes.hpp"

template <typename T>
class Collection {
    using iterator = typename std::list<T>::iterator;
    using const_iterator = typename std::list<T>::const_iterator;
protected:
    std::list<T> _collection;
public:
    Collection() = default;
    ~Collection() = default;

    void deleteFromCollection(iterator element){
        _collection.erase(element);
    }
    size_t getCollectionSize(){ return _collection.size(); }
    //iterators
    iterator begin(){ return _collection.begin(); }
    iterator end(){ return  _collection.end(); }
    const_iterator cbegin(){ return _collection.cbegin(); }
    const_iterator cend(){ return _collection.cend(); }
    //methods
    void addToCollection(T element) { _collection.push_back(element); }
};


#endif //BOUT_HELPER_COLLECTION_HPP
