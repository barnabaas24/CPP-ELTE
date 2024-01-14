#ifndef DOMINO_H
#define DOMINO_H

#include <vector>
#include <utility>
#include <list>
#include <iostream>

template<typename T>
class domino{

private:

    std::list<std::pair<T,T>> container;
    T front;
    T back;

public:

    domino(const std::pair<T,T> pair): container({pair}), front(pair.first), back(pair.second)  {
        // container.push_back(pair);
    }

    //copy konstruktor - konstans referenciát vár egy megegyező típusú osztálytól.
    domino(const domino<T> &other) : container(other.container){}


    //konstans objektumra csak a konstans fuggvenyek hivodnak meg,
    //de ha modositjak az objektum adatait akkor nem lehetnek constok
    bool push_back(const std::pair<T,T> pair){
        if(back==pair.first){
            container.push_back(pair);
            back = pair.second;
            return true;
        }
        else if(back==pair.second){
            container.push_back(pair);
            back = pair.first;
            return true;
        }
        return false;
    }

    bool push_front(const std::pair<T,T> pair){
        if(front==pair.first){
            container.push_front(pair);
            front = pair.second;
            return true;
        }
        else if(front==pair.second){
            container.push_front(pair);
            front = pair.first;
            return true;

        }
        return false;
    }

    
    void operator >> (const std::pair<T,T> &pair){
        push_back(pair);
    }

    void operator << (const std::pair<T,T> &pair){
        push_front(pair);
    }





    //ertekado operator tulterhelese
    // template<typename T>
    // template<typename U>
    // domino<T>& domino<T>::operator=(const domino<U>& other) {
    //     if (this != &other) {
    //         // Clear existing content
    //         container.clear();

    //         // Copy elements from 'other' to 'this'
    //         typedef typename std::list<std::pair<U, U>>::const_iterator OtherIterator;
    //         for (OtherIterator it = other.container.begin(); it != other.container.end(); ++it) {
    //             container.push_back(std::make_pair(static_cast<T>(it->first), static_cast<T>(it->second)));
    //         }
    //     }
    //     return *this;
    // }


    int size() const{
        return container.size();
    }

    void printAll() const{
        typedef typename std::list<std::pair<T,T>>::iterator PairIterator;
        for (PairIterator it = container.begin(); it!=container.end(); ++it)
        {
            std::cout << (*it).first << " " << (*it).second << " ";
        }
        std::cout << std::endl;
        
    }


};



    template <typename T>    
    bool operator >> (const std::pair<T, T> &pair, domino<T>& d) {
        return d.push_front(pair);
        
    }

    template <typename T>    
    bool operator << (const std::pair<T, T> &pair, domino<T>& d){
        return d.push_back(pair);
    }



#endif