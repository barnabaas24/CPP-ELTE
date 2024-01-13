#include <iostream>

//Mutató szerinti átadás
void doSomething(int* array){

    for (int i = 0; i < 4; i++)
    {
        //itt nem kell dereferálni, mert a [i] automatán dereferálja
       std::cout<< array[i] <<  " ";
    }
    std::cout << std::endl;
}

//Szintén mutató szerinti átadás
void doSomethingWithInts(int* num){
    //itt kell dereferálni, mert nincs [i];
    std::cout<< *num <<  " ";

    //....
    //std::cout << "the pointer's memory adress: " << &num <<std::endl;
}

int main(){

    int nums[] = {1,2,3,4};

    //minkét implementáció a nums tomb 0. elemére mutató pointert adja át:
    doSomething(nums);
    //doSomething(&nums[0]);

    //a fenti esetben tömböt adunk át, ami nem primitív típus.
    //primitív típus esetében a mutató szerinti átadás az alábbi:
    int a = 12;
    doSomethingWithInts(&a);



    //std::cout << "a's memory adress: " << &a <<std::endl;

}