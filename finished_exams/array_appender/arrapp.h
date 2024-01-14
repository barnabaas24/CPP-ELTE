#ifndef ARRAPP_H
#define ARRAPP_H


#include <vector>


//egy mutatót tárol, amit ha kiértékelünk, már a rendes számot kapjuk meg.
class Array_Iterator{
    int* p;

    public:
    Array_Iterator(int* pointer): p(pointer){}

    Array_Iterator operator=(const int num){
        *p = num;
        return p;
    }

    Array_Iterator operator++(){
        ++*p;
        return p;
    }

    //a suffix miatt kell irni a paraméterbe az int-et
    Array_Iterator operator--(int){
        --*p;
        return p;
    }

    

    //ha mas tipussal akarom osszehasonlitani akkor muszaj konverzios operator.
    bool operator==(int num){
        return *p==num;
    }

    //konverzios operator
    operator int() const{
        return *p;
    }


};


class array_appender{

    int** array;    //mutatókra mutató mutatókat tárol
    int arraySize = 0;


public:

    array_appender(){}


    void append(int* passed_array,int arr_size){

        int** oldarray = new int*[arraySize];
        for (int i = 0; i < arraySize; i++)
        {
            //memoria cimeket allitunk at
            oldarray[i] = array[i];
        }

        int newSize = arraySize+arr_size;

        array = new int*[newSize];

        for (int i = 0; i < arraySize; i++)
        {
            array[i] = oldarray[i];
        }

        for (int i = arraySize; i < newSize; i++) {
            //std::cout << "HERE" << passed_array[i-arraySize]<< std::endl;
            array[i] = &(passed_array[i-arraySize]);
        }

        arraySize = newSize;
    }

    // a méretet template paraméterként várjuk
    template<int N>
    void append(int (&passed_array)[N]){
        append(passed_array,N);
    }

    int size(){
        return arraySize;
    }

    //vissza adunk egy Iteratort (aminek adunk egy pointert)
    Array_Iterator at(int index){
        return Array_Iterator(array[index]);
    }

    Array_Iterator operator[](int index){
        return at(index);
    }


    
    void array_printer(){
        for (int i = 0; i < arraySize; i++)
        {
            std::cout << *(array[i]) << " ";
        }
        std::cout << std::endl;
    }




};



#endif