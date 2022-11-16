#include "fcpp.hh"

bool summeteiler(int zahl, int summe, int teiler );

bool vollkommen(int zahl){
   return cond(summeteiler(zahl, 0, 1), true, false);
}

bool summeteiler(int zahl, int summe, int teiler){
    return cond(zahl > teiler,
            cond(zahl == teiler + 1 && summe == zahl, true,
                cond(zahl%teiler == 0, summeteiler(zahl, summe += teiler, teiler + 1), summeteiler(zahl, summe, teiler + 1))), false);
}

int main(){
    print(vollkommen(6));
    print(vollkommen(5));
    print(vollkommen(28));
}
