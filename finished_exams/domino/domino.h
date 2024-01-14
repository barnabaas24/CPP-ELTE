#ifndef DOMINO_H
#define DOMINO_H

#include <vector>
#include <utility>
#include <deque>
#include <iostream>
#include <algorithm>

//class Functor = std::less<T>

template <typename K>
struct equalNum{

    bool operator()(const K &a,const K &b) const{
        return a==b;
    }
};


template<typename T,class Functor = equalNum<T>>
class domino{

private:

    std::deque<std::pair<T,T>> container;
    T front;
    T back;
    Functor f;


public:

    domino(const std::pair<T,T> pair): container({pair}), front(pair.first), back(pair.second)  {
        // container.push_back(pair);
    }

    //copy konstruktor - konstans referenciát vár egy megegyező típusú osztálytól.
    domino(const domino<T> &other) : container(other.container){}


    //konstans objektumra csak a konstans fuggvenyek hivodnak meg,
    //de ha modositjak az objektum adatait akkor nem lehetnek constok

    bool decide(T a, T b, Functor f){
        return f(a,b);
    }

    bool push_back(std::pair<T,T> pair){
        if(f(pair.first,back)){
            container.push_back(pair);
            back = pair.second;
            return true;
        }
        else if(f(pair.second,back)){
            //std::swap(pair.first, pair.second);
            container.push_back(pair);
            back = pair.first;
            return true;
        }
        return false;
    }


    bool push_front(std::pair<T,T> pair){

        if(f(pair.first,front)){
            //std::swap(pair.first, pair.second);
            container.push_front(pair);
            front = pair.second;
            return true;
        }
        else if(f(pair.second,front)){
            container.push_front(pair);
            front = pair.first;
            return true;
        }
        return false;


        // if(decide(pair.first,front,Functor())){
        //     container.push_front(pair);
        //     front = pair.second;
        //     return true;
        // }
        // else if(decide(pair.second,front,Functor())){
        //     container.push_front(pair);
        //     front = pair.first;
        //     return true;
        // }
        // return false;
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
        typedef typename std::deque<std::pair<T,T>>::iterator PairIterator;
        for (PairIterator it = container.begin(); it!=container.end(); ++it)
        {
            std::cout << (*it).first << " " << (*it).second << " ";
        }
        std::cout << std::endl;
    }


    bool equals(const domino<T,Functor> &d) const{
        if(d.container.size()!=this->container.size()){
            return false;
        }

        for (int i = 0; i < container.size(); i++)
        {
            if(container[i]!=d.container[i]){
                return false;
            }
        }
        return true;
    }


};


    //, class Functor = std::less<T>
    template <typename T, class Functor = equalNum<T>>    
    bool operator >> (const std::pair<T, T> &pair, domino<T,Functor>& d) {
        return d.push_front(pair);
    }

    //, class Functor = std::less<T>
    template <typename T, class Functor = equalNum<T>>    
    bool operator << (const std::pair<T, T> &pair, domino<T, Functor>& d){
        return d.push_back(pair);
    }



#endif