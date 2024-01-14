#ifndef ARSORTER_H
#define ARSORTER_H

#include <iostream>
#include <algorithm>


template<typename T>
struct ComparatorDescend{
    bool operator()(T a, T b){
        return a>b;
    }
};

template<typename T>
struct ComparatorAscend{
    bool operator()(T a, T b){
        return a<b;
    }

};


template<class T>
class array_sorter_util{

    T* array;
    T* arrayCopy;
    int array_size;

public:

    array_sorter_util(T* _array, int _size) : array(_array) , array_size(_size) {
        arrayCopy = new T [array_size];

        for (int i = 0; i < array_size; i++)
        {
            arrayCopy[i] = array[i];
        }
        
        std::sort(array,array+array_size);
        print();
    }

    ~array_sorter_util(){
        for (int i = 0; i < array_size; i++)
        {
            array[i] = arrayCopy[i]; 
        }

        delete[] arrayCopy;
    }

    void sort_asc() {
    std::stable_sort(array, array + array_size, std::less<int>());
    }

    void sort_desc() {
        std::stable_sort(array, array + array_size, std::greater<int>());
    }



    void print(){
        for (int i = 0; i < array_size; i++)
        {
            std::cout << array[i];
        }
        std::cout << std::endl;
    }

    void operator-(){
        std::sort(array,array+array_size,ComparatorDescend<T>());
        print();
    }

    void operator+(){
        std::sort(array,array+array_size,ComparatorAscend<T>());
        print();
    }

    int size() const{
        return array_size;
    }


};

//definiálok az adott tipusra egy másik nevet
//typedef array_sorter_util<int> array_sorter;

using array_sorter = array_sorter_util<int>;






#endif