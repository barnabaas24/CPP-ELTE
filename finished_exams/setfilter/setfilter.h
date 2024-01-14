/*A feladat egy olyan osztály megírása amely egy halmaz szűrőjeként funkcionál.
Ezt úgy kell elképzelni, mintha rátennénk egy szűrőt a setre és tudnánk elemeket elrejteni, illetve visszaállítani a rejtett elemeket.
Több helyen elég bonyolult volt kibogarászni, hogy mit szeretne a kód de tudtommal a vizsgán elmondják hogyan kell működnie az osztálynak,
szóval nem a kódból kell majd mindenre rájönni.

2-es:
A set_filtering template osztály megírása egy T típusú elemeket tartalmazó setre. Ehhez ugyanaz a konstruktor mint ami
a kódban van csak std::set<T> típusú paramétert kap az std::set<T, Functor> helyett. Kell még egy filter és unfilter metódus.
A filter elrejt egy paraméterként kapott elemet, az unfilter pedig felfedi a kapott elemet. Itt figyelni kell arra, hogy filterben kapott
elem benne van-e a setben, illetve a rejtett elemek között megtalálható-e az unfilterben kapott elem, különben elhasal a kód a sstf.filter( "No such string" ); sornál.

3-as:
Egy inverse() metódus kell ami megcseréli a látható és rejtett elemeket. Ami eddig szűrve volt az bekerül a setbe, ami eddig benn volt azt kiszűrjük.
Illetve erre trükkös volt rájönni de kell egy destruktor ami minden szűrt elemet visszahelyez a setbe, visszaállítva az eredeti állapotot.
std::set<int> ti;
  ti.insert( 7 );
  ti.insert( 2 );
  bool empty = ti.empty();

  if ( 2 == smx.size() && 1 == smx.count( 0 ) && 0 == smx.count( 3 ) )
  {
    set_filtering<int> tif( ti );
    tif.filter( 7 );
    tif.filter( 2 );
    empty = ti.empty();
  }
  if ( empty && !ti.empty() && 1 == sst.count( "World" ) &&
       1 == ti.count( 7 ) )
  {
    your_mark = *(ti.begin()) + sst.size();
  }

A fenti kódrészletből lehet a destruktorra rájönni. Mivel az utolsó ifbe akkor lép be ha a ti set nem üres. Azért nem lesz üres,
mert bár felette az ifen belül a tif filterrel elrejtettük a két elemet, a filter scope-ja véget ér az if végén és így az objektum megsemmisül.
Így teljesülhet egyszerre empty és !ti.empty(), mivel empty azt tárolja, hogy az ifen belül volt-e a setben elem, !ti.empty()
pedig azt, hogy aktuálisan van-e. Ezt pedig, úgy érhetjük el ha a destruktor visszahelyezi a rejtett elemeket a setbe mielőtt az objektum megsemmisül.

4-es:
A ~ és += operátorokat kell megírni. Itt a ~ operátorra nem egyszerű rájönni de azért ki lehet találni. A += operátor elég egyértelmű, kap egy
funktort és kiszűri azokat az elemeket amelyekre a funktor igazat ad. A ~ operátor azt csinálja, hogy csak a kíszűrt elemeket fogja megtartani
és ezeket visszahelyezi a setbe, tehát amik az operátor meghívásakor a setben voltak azokat töröljük, a szűrt elemeket pedig visszahelyezzük a setbe.

5-ös:
Át kell írni úgy az osztályt, hogy egy második template paramétert is tudjon fogadni (ami egy funktor lesz),
Illetve a konstruktor is egy ilyen két template paraméteres setet kap majd. Értelemszerűen egy template paraméteres settel is meghívható lesz,
ha beállítjuk a Functor paraméter alapértelmezett értékét std::less<T>-re, mivel a set alapértelmezetten ezzel rendez ha nem kap
másik funktort. Mivel eddig std::set<T> volt mindenhol a használt típus, így itt majd át kell ezt mindenhol írni std::set<T, Functor>-ra.
Kell egy printfiltered metódus és a -= operátort kell még megírni. A prinfiltered kiírja a rejtett elemeket a -= operátor pedig értelemszerűen
a += inverze, tehát kap egy funktort és felfedi azokat a szűrt elemeket amelyekre a funktor igazat ad.
*/

/*Header guard, hogy ne legyen probléma a main eleji dupla include-al.*/
#ifndef SETFILTER_H
#define SETFILTER_H
#include <iostream>
#include <set>

/*A funktor alapértelmezetten az std::less<T>, hogy működjön a feladat elején lévő deklarációkra is, ahol csak 1 template paramétert kap.*/
template <class T, class Functor = std::less<T>>
/*Lehetne struct is, mivel mindent publikusra raktam. Ez most az egyszerűség miatt publikus mind.*/
class set_filtering{
    public:
        /*Ez egy referencia az eredeti setre amit a konstruktor kap. Azért kell, hogy referencia legyen, hogy amit az s-en változtatunk
        az az eredeti setnél is változzon.*/
        std::set<T, Functor> &s;

        /*Ez a set tárolja a szűrt/rejtett elemeket.*/
        std::set<T, Functor> filtered;

        /*Ez csak egy szinoníma, hogy ne kelljen mindig kiírni a jobb oldalon lévő hosszú típust amikor végigiterálunk valamelyik seten.
        A typename kulcsszó a dependent scope miatt kell.*/
        using iterator = typename std::set<T, Functor>::iterator;

        /*Konstruktor. Fontos, hogy a referenciákat mindig inicializálni kell az inicializációs listában! A filteredet nem kell
        külön inicializálni mivel alapértelmezetten egy üres setet fog létrehozni.*/
        set_filtering(std::set<T, Functor> &set) : s(set){}

        /*Destruktor. Visszaállítja a szűrt elemeket mielőtt megsemmisül az objektum.*/
        ~set_filtering(){
            for(iterator it = filtered.begin(); it != filtered.end(); ++it){
                s.insert(*it);
            }
        }

        /*Megkeresi, hogy a setben benne van-e a kapott elem (funktoroknál természetesen a funktortól függ az egyenlőségvizsgálat)
        és ha megtaláltuk akkor beletesszük a filteredbe, majd kiszedjük az eredeti setből.*/
        void filter(T val){
            iterator res = s.find(val);
            if (res != s.end()){
               filtered.insert(*res);
               s.erase(*res);
            }
        }

        /*Megkeresi, hogy a filteredben benne van-e a kapott elem (funktoroknál természetesen a funktortól függ az egyenlőségvizsgálat)
        és ha megtaláltuk akkor beletesszük az eredeti setbe, majd kiszedjük a filteredből.*/
        void unfilter(T val){
            iterator res = filtered.find(val);
            if (res != filtered.end()){
               s.insert(*res);
               filtered.erase(*res);
            }
        }

        /*Megcseréli az eredeti set és a filtered tartalmát.*/
        void inverse(){
            s.swap(filtered);
        }

        /*Kitörli az eredeti setben lévő elemeket, majd visszaállítja a szűrt elemeket az eredeti setbe.
        (Itt ki tudjuk használni az inverse metódosunkat. Kitöröljük az eredeti setből az elemeket majd kicseréljük a filteredel a tartalmát.)*/
        void operator~(){
            s.clear();
            inverse();
        }

        /*Kap egy funktort és leszűri az eredeti setet a funktorral.
        (Itt lehetne használni a filter és unfilter metódusokat azonban az a keresés miatt lassabb.)*/
        template<class Funct>
        void operator+=(Funct f){
            for(iterator it = s.begin(); it != s.end();){
                if (f(*it)){
                    filtered.insert(*it);
                    it = s.erase(it);
                }
                
                else{
                    ++it;
                }
            }
        }

        /*Kiírja a szűrt elemeket.*/
        void printFiltered(){
            std::cout << "Filtered:" << std::endl;
            for(iterator it = filtered.begin(); it != filtered.end(); ++it){
                std::cout << *it << std::endl;
            }
        }

        /*Kap egy funktort és visszaállítja aszűrt elemeket a funktorral.
        (Itt lehetne használni a filter és unfilter metódusokat azonban az a keresés miatt lassabb.)*/
        template<class Funct>
        void operator-=(Funct f){
            for(iterator it = filtered.begin(); it != filtered.end();){
                if (f(*it)){
                    s.insert(*it);
                    it = filtered.erase(it);
                }
                
                else{
                    ++it;
                }
            }
        }

        /*Ez csak segítségként van itt. Kiírja az eredeti set és a filtered set tartalmát.
        (Vizsgán az auto és a foreach miatt nem fogadnák el!)*/
        void print(){
            std::cout << "s:" << std::endl;
            for(auto v : s){
                std::cout << v << std::endl;
            }
            std::cout << "\n";
            std::cout << "filtered:" << std::endl;
            for(auto v : filtered){
                std::cout << v << std::endl;
            }
        }
};

/*Header guard lezárása.*/
#endif // SETFILTER_H