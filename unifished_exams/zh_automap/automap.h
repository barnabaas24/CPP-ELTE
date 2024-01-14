#ifndef AUTOMAP_H
#define AUTOMAP_H

#include <map>
#include <iostream>


template<class K, class V, typename Compare = std::less<K>>
class auto_map
{

private:
    std::map<K,V,Compare> myMap;

public:

    auto_map(){}

    ~auto_map() {
        // Clean up memory when the map is destroyed
        for (typename std::map<Key, Value, Compare>::iterator it = myMap.begin(); it != myMap.end(); ++it) {
            delete it->first;   // Delete the key
            delete it->second;  // Delete the value
        }
    }

    void insert(K* key, V* value) {
        // Convert the key before inserting into the map
        myMap.emplace(std::make_pair(*key, *value));
    }


    int size(){
        return myMap.size();
    }


    




};







#endif