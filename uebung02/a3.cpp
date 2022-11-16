#include "fcpp.hh"

int quadrat(int x){
  return(x*x);
}

int potenz(int x, int exp) {
    return cond(exp == 1, x,
                cond(exp % 2 == 1, x * potenz(x, exp-1),
                     quadrat(potenz(x, exp / 2))));
}

int main() {
    print(potenz(2,1));
    print(potenz(2,8));
    print(potenz(2,6));
    print(potenz(2,7));
    print(potenz(3, 7));
    return 0;
}
