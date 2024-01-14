//Névterek: Segítségükkel elkerülhető a név ütközés. 
//Az alábbi példa mutatja, hogy pl. lenne több féle konténerünk, mint pl egy Vector,
//akkor annak is írhatunk egy saját Iterator nevű osztályt, viszont azt bele tehetjük a VectorDetail névtérbe. Így elkerülve a név ütközést

namespace detail {
    class Iterator {
    //...
    };
    class ConstIterator {
    //...
    };
} // namespace detail

namespace VectorDetail{
    class Iterator{
        //...
    };

    class ConstIterator{
        //....
    };
}

int main(){

    detail::Iterator it;
    VectorDetail::Iterator it;

}


