#include "fcpp.hh"

float powerfloat(float b, int e){
    if (e == 0) return 1;

    float result = 1;
    for (int i = 1; i <= e; i++) result *= b;
    if (e > 0) return result;
    else return 1/result;
}

double powerdouble(double b, int e){
    if (e == 0) return 1;

    double result = 1;
    for (int i = 1; i <= e; i++) result *= b;
    if (e > 0) return result;
    else return 1/result;
}

float zinsf(float z, int n){
    return powerfloat((1 + z / n), n) - 1;
}

double zinsd(double z, int n){
    return powerdouble((1 + z / n), n) - 1;
}
int main(){
    print(zinsf(0.06, 3));
    print(zinsd(0.06, 3));
    return 0;
}
