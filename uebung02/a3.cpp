#include "fcpp.hh"

int quadrat(int x){
  return(x*x);
}

int zaehler(int exp, int count1){
  return cond(exp/2 > 1, zaehler(exp/2, count1+1), count1);
}

int ppotenz(int x, int count){
  return cond(count > 0, ppotenz(quadrat(x), count-1), x);
}

int potenz (int x, int exp){
  return cond(exp == 1, x,
    cond(x%2 == 0, potenz(quadrat(ppotenz(x, zaehler(exp, 0))), exp-2*zaehler(exp,0)),potenz(x, exp-1)*x)
  );
}

int main() {
  print(potenz(2,1));
  print(potenz(2,8));
  print(potenz(2,6));
  print(potenz(2,7));
  return 0;
}
