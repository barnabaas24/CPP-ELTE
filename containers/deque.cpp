#include <deque>
#include <iostream>
#include <vector>


//deque
//double ended queue.
//előre és hátra hatékony beszúrás.
//support RANDOM ACCESS ITERATOR

int main(){

    //insertions
    std::deque<int> myDeq;

    for (int i = 0; i < 5; i++)
    {
        myDeq.push_back(i);
        myDeq.push_front(i);
    }
    
    for(int i : myDeq){
        std::cout << i << " ";
    }
    std::cout << std::endl;

    //indexelni lehet ugyan ugy

    std::cout << myDeq[1] << std::endl;

    //iterators:

    //random acces:
    std::deque<int>::iterator it1 = myDeq.begin()+3;


    //swapping:
    std::deque<int> first = {10,20,30,40};
    std::deque<int> sec = {10,10,10,10,10,10};
    first.swap(sec);

    // for(int i : first){
    //     std::cout << i << std::endl;
    // }
 





    std::cout << std::endl;


    return 0;
}