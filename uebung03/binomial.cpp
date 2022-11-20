#include "fcpp.hh"

int binRec(int n,int k){
    return cond(k == 0, 1,
                cond(n == k, 1,binRec(n-1, k-1) + binRec(n-1, k)));
}

void printint(int a, int b){
    print(a);
    print(b);
}

int main(){
    print(binRec(34,18));
    return 0;
}