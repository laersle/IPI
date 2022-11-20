#include "fcpp.hh"

int fac(int n);

int binRecFast(int n,int k){
    return fac(n)/(fac(k)*fac(n-k));
}

int fac(int n){
    return cond(n > 1, n*fac(n-1), n);
}

int main(int argc, char** argv){
    print(binRecFast(readarg_int(argc, argv, 1), readarg_int(argc, argv,2)));
    return 0;
}