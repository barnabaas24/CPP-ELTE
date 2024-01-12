#include <iostream>
#include <vector>
#include <string>




int main(){
    std::vector<std::string> s(5);
    //["","","","",""]

    std::vector<int> v(10);
    //[0,0,0,0,0,0,0,0,0,0] --> alapbol 0-val inicializálja
    //std::cout << v.size() << std::endl; // 10

    v.push_back(124);
    typedef std::vector<int>::iterator VectorIt;

    for(VectorIt it = v.begin(); it != v.end(); it++){
        std::cout << *it << std::endl; 
    }

    std::cout << v.at(10) << std::endl;

    v.resize(0);

    std::cout << "Size: " << v.size() << std::endl;



    //Copy content of array into vector
    int nums[6] = {10,20,30,40,50,60};
    std::vector<int> numVec(nums,nums+6);

    for(int i : numVec){
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}