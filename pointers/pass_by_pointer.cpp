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


//Mutató szerinti átadás -> Bármilyen nem primitív típusnál ugyan úgy működik.
template<class T>
void doSomethingwClass(T* c){
    c.data = 0;
}

//shallow copy. if value changes here, it doesn't change in the main.
template<class T>
void doSomethingwClass(T c){
    c.data = 0;
}

class myClass{
public:
    int data = 10;
};

int main(){

    int nums[] = {1,2,3,4};

    //minkét implementáció a nums tomb 0. elemére mutató pointert adja át:
    doSomething(nums);
    //doSomething(&nums[0]);

    //a fenti esetben tömböt adunk át, ami nem primitív típus.
    //primitív típus esetében a mutató szerinti átadás az alábbi:
    int a = 12;
    doSomethingWithInts(&a);


    myClass c;
    doSomethingwClass(c);
    std::cout <<"Az osztály adata nem változott: " << c.data << std::endl;



    //std::cout << "a's memory adress: " << &a <<std::endl;

}