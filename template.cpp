#include <iostream>

//még nincs átnézve a teljes téma!

template<typename T>
void swap(T &a, T &b){
    T tmp = a;
    a = b;
    b = tmp;
}

//=======TEMPLATE SPECIALIZÁCIÓ==========
template<typename T>
void foo(){
    std::cout << "general foo" << std::endl;
}

template<>  //template specializáció -> megadjuk, hogy int template paraméter esetén mi történjen.
void foo<int>(){
    for (int i = 0; i < 2; i++)
    {
        std::cout << "special foo" << std::endl;
    }
   
}
//===============================



int main(int argc, char const *argv[])
{
    int a = 2, b = 3;
    std::cout << "Before swap: " << a << ", " << b << std::endl;
    swap<int>(a,b); // explicit megadjuk a fordítónak a template paraméterét
    std::cout << "After swap: " << a << ", " << b << std::endl;

    //swap(a,b);      // de a fordító tudja a és b típusát, ezért nem kötelező

    double c = 1.3, d = 7.8;
    std::cout << "Before swap: " << c << ", " << d << std::endl;
    swap(c,d);  //template parameter deduction
    std::cout << "After swap: " << c << ", " << d << std::endl;


    //template specializáció példa:
    foo<std::string>();
    foo<int>();



    

    
    return 0;
}


//fontos definíciók:
//======================


//EXPLICIT TEMPLATE PARAMÉTER
//   -> amikor mi adjuk meg a fordítónak, a template paraméter típusát

//TEMPLATE PARAMÉTER DEDUKCIÓ
//  -> amikor a fordító maga találja ki a tempalte paramétert
