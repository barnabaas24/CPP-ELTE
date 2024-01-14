#include <iostream>
#include <list>

int main(){


    //lista deklaráció, függvények használata, kiiratás.


    std::list<int> mylist2 (5);
    for(std::list<int>::iterator it = mylist2.begin(); it!=mylist2.end(); ++it){
        std::cout << *it << " ";
    }
    std::cout << std::endl;


    std::list<int> mylist;
    for (int i = 0; i < 5; i++)
    {
        mylist.push_back(i+1);
    }

    mylist.push_back(10);
    mylist.push_front(50);


    for (auto it = mylist.begin(); it!=mylist.end(); ++it)
    {
        std::cout << *it << " ";
    }
    
    
    

    return 0;
}