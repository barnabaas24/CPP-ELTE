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

    //beszúrás --> key serint rendezett a map.
    myMap.insert(std::make_pair(400,"kk"));
    myMap.insert(std::make_pair(2,"bsdfs"));
    myMap.insert(std::make_pair(3,"ac"));
    myMap.insert(std::make_pair(4,"d"));
    
    //mar letezo kulcsra szuras -> nem tortenik meg
    myMap.insert(std::make_pair(400,"FFFFFFFF"));

    //atirja a kulcson levo erteket
    myMap.insert_or_assign(400,"FFFFFFFF");

    myMap[2] = "kettestisatirta" ;

    //find kulcs szerint mukodik
    auto it = myMap.find(10);
    if(it==myMap.end()){
        std::cout << "NOT FOUND" <<std::endl;
    }


    //lehet adni custom sortolot
    std::map<int,std::string,std::greater<int>> descendMap;
    

    //iterálás + kiiratás
    for (std::map<int, std::string>::iterator i = myMap.begin(); i != myMap.end(); i++) {
        std::cout << i->first << " " << i->second << "  ";
    }


    


}