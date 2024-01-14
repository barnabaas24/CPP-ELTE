#include <iostream>


class array_appender{

    int* innerArray;

public:

    array_appender(int* array){
        innerArray = new int[4];
        for (int i = 0; i < 4 ; i++)
        {
            innerArray[i] = array[i];
        }

        innerArray[0]=1000;
    }



};


int main(){

    int array[4] = {1,2,3,4};
    array_appender ap(array);

    for (int i = 0; i < 4; i++)
    {
        std::cout << array[i] << std::endl;
    }
    

}

