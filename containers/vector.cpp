#include <iostream>
#include <vector>
#include <string>


//hatra hatekony beszuras. (előre kevésbé)



int main(){
    std::vector<std::string> vec;

    std::vector<std::string> s(5);
    //["","","","",""] -> alapbol üres "betűkre" inicializálja

    std::vector<int> v(10);
    //[0,0,0,0,0,0,0,0,0,0] --> alapbol 0-val inicializálja
    //std::cout << v.size() << std::endl; // 10

    //beszuras a vegere
    v.push_back(124);

    //Iterator létrehozása vectorhoz
    typedef std::vector<int>::iterator VectorIt;
    for(VectorIt it = v.begin(); it != v.end(); it++){
        std::cout << *it << std::endl; 
    }

    std::cout << v.at(10) << std::endl;

    //ujrameretezes
    v.resize(0);
    std::cout << "Size: " << v.size() << std::endl;


    //Copy content of array into vector
    int nums[6] = {10,20,30,40,50,60};
    std::vector<int> numVec(nums,nums+6);

    for(int i : numVec){
        std::cout << i << " ";
    }
    std::cout << std::endl;

    //insert to the front
    
    std::vector<int> myVector = {2, 3, 4, 5};

    // Element to insert at the front
    int elementToInsert = 1;

    // Insert at the front
    //std::cout <<"Eddig ez volt az eleje: " << *myVector.begin() << std::endl;
    myVector.insert(myVector.begin(), elementToInsert);

    // Display the vector
    for (const auto& element : myVector) {
        std::cout << element << " ";
    }



    return 0;
}