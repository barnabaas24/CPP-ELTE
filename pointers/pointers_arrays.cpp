#include <iostream>

class ArrayStorage{

    int array[10];

};

using namespace std;

int main(){

    int arr[10];                //mindket opcio ugyan azt jelenti
    int* array = new int[10];   //mindket opcio ugyan azt jelenti

    for (int i = 0; i < 10; i++)
    {
        //array[i] =i;       // Using the [] operator
        *(array + i) =i+1;    // Using pointer arithmetic
    }

    for (int i = 0; i < 10; i++)
    {
        cout << array[i] <<" ";
    }
    cout << endl;


    //pointer pointing to the same values
    int* otherArray;
    otherArray = array;
    for (int i = 0; i < 10; i++)
    {
        //modifying the values where the new pointer points == modifying the original values
        otherArray[i] =i+11;       
    }

    for (int i = 0; i < 10; i++)
    {
        cout << array[i]<< " ";
    }
    cout << endl;



    int* valueCopies;
    valueCopies = new int[10];

    for (int i = 0; i < 10; i++)
    {
        //we only copy the values, at each i-th location, not the pointer.
        valueCopies[i] = array[i];
    }

    for (int i = 0; i < 10; i++)
    {
        //so if we modify the values in the new array, the original doesn't change
        valueCopies[i] = 0;
    }

    for (int i = 0; i < 10; i++)
    {
        //the original remains unchanged
        cout << array[i]<< " ";
    }
    cout << endl;
    

    



    return 0;
}