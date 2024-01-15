#ifndef ARVIOPS_H
#define ARVIOPS_H

#include <algorithm>

template<class T>
class array_view_operations{
    T* array;
    T* originalArray;
    int arraySize;

public:

    //pointer szerinti átvétel. módosulnak az eredeti értékek is
    array_view_operations(T* _array, int _array_size) : array(_array) , arraySize(_array_size) {
        originalArray = new T[arraySize];
        for (int i = 0; i < arraySize; i++)
        {
            originalArray[i] = array[i];
        }
    }

    //referencia szerinti átvétel. atjon a méret is. //így módosulnak az eredeti tömbök is.
    //ha const T (&_array)[N]-ként vennénk át, akkor az eredeti tömbök nem módosulnának.
    template <int N>
    array_view_operations(T (&_array)[N]) : array(_array), arraySize(N) {
        originalArray = new T[arraySize];
        for (int i = 0; i < arraySize; ++i) {
            originalArray[i] = array[i];
        }
    }
    


    ~array_view_operations(){
        reset();
        delete[] originalArray;
    }

    void reverse(){
        std::reverse(array,array+arraySize);
        print();

    }

    void reset(){
        for (int i = 0; i < arraySize; i++)
        {
            array[i] = originalArray[i];
        }
        
    }

    
    void shift(int amount) {
        if (amount == 0) return;
            int realRotate = amount % arraySize;
        if (amount > 0) {
            std::rotate(array, array - realRotate + arraySize, array + arraySize);
        } else {
            std::rotate(array, array - realRotate, array + arraySize);
        }
    }

    void print(){
        for (int i = 0; i < arraySize; i++)
        {
            std::cout << array[i]<< " ";
        }
        std::cout << std::endl;
    }

    void sort(){
        std::sort(array,array+arraySize);
    }

    template<class Comparator>
    void sort(Comparator c){
        std::sort(array,array+arraySize,c);
    }

    //"egyszerubb" alternatíva
    // template<typename Functor = std::less<T>>
    // void sort(const Functor& f = Functor()){
    //     std::sort(array, array + arraySize, f);
    // }

    template<class Comparator>
    int get_first_index_if(Comparator c){
        for (int i = 0; i < arraySize; i++)
        {
            if(c(array[i])){
                return i;
            }
        }

        return -1;
    }








};









#endif