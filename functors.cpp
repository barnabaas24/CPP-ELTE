#include <iostream>


//egy sima függvény, ami vár egy template osztályt paraméterül, ami functor, mivel meghívjuk a () operátorát.
template<class Comparator>
bool decide(int a, int b, Comparator c){
    return c(a,b);
}


//Functor: Olyan osztaly aminek tul van terhelve a () operátora.

struct IsEven // unary predicate -> mert csak egy adott típusú objektumot vár és bool a visszatérési értéke
{
bool operator()(const int &a) const { return a % 2 == 0; }
};

struct Less {   // bináris predikátum, azaz a gömbölyű zárójel operátora két azonos típusú objektumhoz rendel egy logikai értéket
bool operator()(int a, int b) const { return a < b; }
};


class SumGreaterThanX {
private:            
    int x;

public:
    // Constructor that takes a value and stores it in x
    SumGreaterThanX(int value) : x(value) {}

    // Overloaded function call operator
    bool operator()(int a, int b) {
        return a + b > x;
    }
};


int main()
{
    if(decide(3,4,SumGreaterThanX(7))){
        std::cout << "yaay!" << std::endl;
    }
    else{
        std::cout << "naay!" << std::endl;
    }
    
    return 0;
}
