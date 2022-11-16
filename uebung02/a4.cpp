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
    int lim = 8128;
    for(int i = 0; i <= lim; i++){
        print(i);
        print(vollkommen(i));
    }
}
