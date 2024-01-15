#include <iostream>

#ifndef ARSHIFT_H
#define ARSHIFT_H

template<class T>
class array_shifter_util{
    
    T* array;
    int array_size;
    int shiftCount = 0;

public:
    
    // a benti array ugyan oda mutat mint a kinti, tehát ugyan azokra az értékekre mutat
    array_shifter_util(T* _array, int _array_size): array_size(_array_size) {
        array = _array;
    }

    ~array_shifter_util() {
        if (shiftCount > 0) {
            for (int i = 0; i < shiftCount; i++)
            {
                operator<<(shiftCount);
            }
        } else {
           for (int i = 0; i < -shiftCount; i++)
            {
                operator>>(-shiftCount);
            } 
        }
    }

    int size() const{
        //mivel a size nem módopsítja az objectet, ezért a konstans korrektség miatt a függvény visszatérési értéke konstans
        return array_size;
    }

    void operator <<(int amount){
        shiftLeft(amount);
    }

    void operator >>(int amount){
        shiftRight(amount);
    }


private:

    void shiftLeft(int amount){

        shiftCount-=amount;

        T* otherArray = new T[array_size];

        for (int i = 0; i < array_size; i++)
        {

            if(i+amount>array_size-1){
                int remaining = (i+amount) - array_size;
                otherArray[i] = array[remaining];
            }else{
                otherArray[i] = array[i+amount];
            }
        }
        

        for (int i = 0; i < array_size; i++)
        {
            array[i] = otherArray[i];
        }

        for (int i = 0; i < array_size; i++)
        {
            array[i] = otherArray[i];
            std::cout << array[i];
        }

        std::cout<< std::endl;

        delete[] otherArray;
    }

    void shiftRight(int amount){
        shiftCount+=amount;


        T* otherArray = new T[array_size];


        for (int i = 0; i < array_size; i++)
        {

            if(i-amount<0){
                int remaining = -1*(i-amount);
                otherArray[i] = array[array_size-remaining];
            }else{
                otherArray[i] = array[i-amount];
            }
        }

        for (int i = 0; i < array_size; i++)
        {
            array[i] = otherArray[i];
            std::cout << array[i];
        }

        std::cout<< std::endl;

        delete[] otherArray;
    }


};

using array_shifter = array_shifter_util<int>;

#endif