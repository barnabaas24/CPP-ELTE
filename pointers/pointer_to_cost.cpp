#include <iostream>



void doSomething(int* array, int arr_size){
    array[0] =1000;
}


//this does not work
//points to const int, which is not modifiable
void doSomething(const int* array, int arr_size){
    //array[0] =1000; ->err: expression must be modifiable.

    // for (int i = 0; i < arr_size; i++)
    // {
    //     std::cout << array[i] << std::endl; //this works.
    // }
}


//T const, de T adattagjai nem biztos hogy const-ok tehát no problem.
template<class T>
void doSomethingwClass(const T* any){
    any->data = 0;  // Remove const qualifier from function parameter to allow modification
}


//ez se mukodik
void doSomethingwInt(const int* num){
    //num = 10;
}

class MyClass{
    public:
    int data = 10;  

    MyClass(){

    }

};









int main(){

    //const int
    const int size = 4;
    int array[size] ={1,2,3,4};

    doSomething(array,size);
    std::cout << array[0] << std::endl;



    //objectnél és primitívnél & jellel kell átadni pointer szerint
    MyClass c;
    doSomethingwClass(&c);

    int num = 10;
    doSomethingwInt(&num);















}