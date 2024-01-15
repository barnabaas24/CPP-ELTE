#include <iostream>
#include <list>



int main(){

    std::list<int> myList = {10,23,42,123};

    std::list<int>::iterator iter = myList.begin();
    //iter+=2; //ez nem mukodik mert a lista nem tamogatja a random acces iteratort.
    iter++;
    iter--;
    std::cout<<*iter<<std::endl;




}