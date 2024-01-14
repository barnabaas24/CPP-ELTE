#include <iostream>
#include <vector>
#include <algorithm>

//unary predicate
struct BigNumber {
bool operator()(const int param) const { return param > 100; }
};

struct Greater {
bool operator()(int lhs, int rhs) const { return lhs > rhs; }
};



int main() {

    
    //=========find==========
    std::vector<int> v;
    v.push_back(2);

    std::vector<int>::iterator result = find(v.begin(), v.end(),2);
    if(result!=v.end()){
        std::cout << *result << std::endl; 
    }

    //mutatott érték átírása
    *result = 20;
    std::cout << v[0] << std::endl; 


    //=========find_if==========   
    v.push_back(10);
    v.push_back(11);
    v.push_back(12);
    v.push_back(1000);

    std::vector<int>::iterator it = find_if(v.begin(),v.end(),BigNumber());
    if( it!=v.end()){
        std::cout <<"Found big number: " << *it << std::endl;
    }


    //============sort=============
    //Az std::sort, ha külön paramétert nem adunk neki, az < operátor szerint rendez.
    std::vector<int> vecAscend{6, 3, 7, 4, 1, 3};
    std::sort(vecAscend.begin(), vecAscend.end());

    for (std::vector<int>::iterator it = vecAscend.begin(); it != vecAscend.end(); ++it) {
        std::cout << *it << " "; // 1 3 3 4 6 7
    }

    std::vector<int> vecDesc{6, 3, 7, 4, 1, 3};
    sort(vecDesc.begin(), vecDesc.end(), Greater());
    std::cout << std::endl;

    for (std::vector<int>::iterator it = vecDesc.begin(); it != vecDesc.end(); ++it){
        std::cout << *it << " "; // 7 6 4 3 3 1
    }

    //=========stable_sort===========
    //megtartja az elemek eredeti sorrendjét







}