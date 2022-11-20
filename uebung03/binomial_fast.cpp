#include "fcpp.hh"

int fac(int n);

int binRecFast(int n,int k){
    return fac(n)/(fac(k)*fac(n-k));
}

int fac(int n){
    return cond(n > 1, n*fac(n-1), n);
}

int main(){
    print(binRecFast(215,122));
    print(fac(12));
    return 0;
}