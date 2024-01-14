#include <iostream>


// Egy kis szintaktikai cukorkával megúszhatjuk azt, hogy folyton kiírjuk a * const-ot (lévén nem akarjuk
// megváltoztatni, hogy ilyen esetben a pointer hova mutasson). Erre való a referencia szerinti paraméter
// átváétel (pass by reference). A referencia hasonlóan működik, mintha egy konstans pointer lenne, csak
// nem lehet sehova se mutató referenciát létrehozni.
void doSomethingWithArray(int (&array)[4]){
    //itt valszeg irl nem tudjuk hogy mekkora a mérete tehát ezt nem fogjuk használni.
}


void doSomethingWithInts(int &num){
    //ha itt változtatjuk, akkor kívül is megváltozik.
    num *=3;
}

//a fordító előre tudja (látja), a kód alapján, hogy mekkora lesz az adott NEM PRIMITÍV típus mérete,
//ezért ha referenciaként adjuk át a tömböt, akkor megy vele a mérete is.
template<class T, std::size_t N>
void doSomethingWithTemplate(T (&array)[N]){
    for (int i = 0; i < N; i++)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
    
}

int main(){

    int nums[] = {1,2,3,4};
    doSomethingWithTemplate(nums);

    int a = 12;
    doSomethingWithInts(a);
    std::cout << a << std::endl;




}