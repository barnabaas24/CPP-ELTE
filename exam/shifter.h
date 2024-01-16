#ifndef SHIFTER_H
#define SHIFTER_H

#include <iostream>
#include <algorithm>
#include <map>


template<class Cont, typename T = typename Cont::value_type>
class shifter{

    public:

    Cont& container;

    
    shifter(Cont &cont) : container(cont) {}


    void shift(int amount){
        if(amount==0) return;
        if(amount < 0){
            amount = abs(amount);
            shift_left(amount);
        }
        else{
            shift_right(amount);
        }

    }

    // void shift(int amount) {
    //     if (amount == 0) return;
    //         int realValue = abs(amount) % container.size();
    //     if (amount > 0) {
    //         std::rotate(container.begin(), container.begin() - realValue + container.size(), container.end());
    //     } else {
    //         std::rotate(container.begin(), container.begin() + realValue, container.end());
    //     }
    // }

    void shift_left(int amount) {
        int realRotate = amount % container.size();
        realRotate*=-1;
        std::rotate(container.begin(), container.begin() - realRotate, container.begin() + container.size());
    }

    void shift_right(int amount) {
        int realRotate = amount % container.size();
        std::rotate(container.begin(), container.begin() - realRotate + container.size(), container.begin() + container.size());
    }


    //suffix
    void operator >>(int value){
        shift(value);
    }

    void operator << (int value){
        shift(-value);
    }

    //prefix
    friend void operator >>(int value, shifter& rhs){
        rhs.shift(-value);
    }

    friend void operator <<(int value, shifter& rhs){
        rhs.shift(value);
    }

    void printall(){
        for (int i = 0; i < container.size(); i++)
        {
            std::cout << container[i] << " ";
        }
        std::cout << std::endl;
    }


};


template <typename Key, typename Value>
class shifter<std::map<Key, Value>> {
public:
    std::map<Key, Value> &container;

    shifter(std::map<Key, Value> &cont) : container(cont) {}

    void shift(int amount) {
        if (amount == 0) return;

        int map_size = container.size();
        amount = (amount % map_size + map_size) % map_size;

        std::vector<Value> values;
        values.reserve(map_size);

        for (typename std::map<Key, Value>::const_iterator it = container.begin(); it != container.end(); ++it) {
            values.push_back(it->second);
        }

        if(amount==0) return;
        if(amount < 0){
            amount = abs(amount);
            int realRotate = amount % values.size();
            realRotate*=-1;
            std::rotate(values.begin(), values.begin() - realRotate, values.begin() + values.size());
    
        }
        else{
            int realRotate = amount % values.size();
            std::rotate(values.begin(), values.begin() - realRotate + values.size(), values.begin() + values.size());
        }


        typename std::vector<Value>::iterator valueIt = values.begin();
        for(typename std::map<Key, Value>::iterator it = container.begin(); it!=container.end(); ++it){
            it->second = *valueIt;
            ++valueIt;
        }

    }
};



#endif
