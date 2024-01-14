#ifndef LINEEDIT_H
#define LINEEDIT_H

#include <list>
#include <iostream>

//kap egy template konténert, és egy másik tipust, ami a kontéreren belül van.
template<class Cont, typename CharT = typename Cont::value_type>
class line_editor{

private:

    bool isInsert;
    std::list<CharT> container;
    typename std::list<CharT>::iterator position;


public:
    line_editor(): position(container.end()), isInsert(false){}

    template <class T, class U>
    friend class line_editor;

    
    
    void press(CharT key){
        if(isInsert && position!=container.end()){
            *position = key;
        }
        else{
            //vissza adja azt az iterátort ami a beszurt elemre mutat
            position= container.insert(position,key);
        }
        //növeljük, hogy a beszurt elem után szurjunk be ismét
        position++;
    }


    void printAll(){
        for (int i = 0; i < container.size(); i++)
        {
            std::cout << container[i] << " ";
        }
        std::cout << std::endl;
    }

    void home(){
        position = container.begin();
    }

    void insert(){
        isInsert= !isInsert;
    }

    void del(){
        position = container.erase(position);
    }

    void backspace(){
        position--;
        del();
    }


    //swap fuggveny egy ugyan olyan objektumot kap paraméterül, viszont ugye az is template, 
    //tehát két template paraméter kell 
    template<class T, class U>
    void swap(line_editor<T,U> &other){

        std::swap(this->container,other.container);
        std::swap(this->position, other.position); 
        std::swap(this->isInsert, other.isInsert);

    }


    //amilyen tipusú kontérenünk van azt adjuk vissza, ezért Cont template a return type.
    Cont enter()
    {
        Cont ret(container.begin(), container.end());
        container.clear();
        position = container.end();
        return ret;
    }


};






#endif