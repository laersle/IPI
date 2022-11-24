#include "fcpp.hh"

int binRec(int n,int k){
    return cond(k == 0, 1,
                cond(n == k, 1,binRec(n-1, k-1) + binRec(n-1, k)));
}

int main(int argc, char** argv){
    print(binRec(readarg_int(argc, argv, 1), readarg_int(argc, argv,2)));
    return 0;
}