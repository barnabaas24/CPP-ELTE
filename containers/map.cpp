#include <iostream>
#include <string>
#include <map>
#include <algorithm>


/* a map-nek a
 find nevű tagfüggvénye egy iterátort ad vissza a talált elemre, illetve visszaadja egy past-the-end iterátort
 ha nem találja meg.
*/
bool contains(const std::map<int,std::string> &map){
    return map.find(1) != map.end();
}

int main(){

    std::map<int,std::string> myMap;

    //beszúrás
    myMap.insert(std::make_pair(1,"a"));

    //iterálás + kiiratás
    for (std::map<int, std::string>::iterator i = myMap.begin(); i != myMap.end(); i++) {
        std::cout << i->first << " " << i->second;
    }


    


}