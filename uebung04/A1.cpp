#include "fcpp.hh"

float determinante(float a, float b, float c, float d){
    return a*d-b*c;
}

double doubleDeterminante(double a, double b, double c, double d){
    return a*d-b*c;
}

void printAssoziativBerechnung(float a, float b, float c){
    print((a+b)+c);
    print(a+(b+c));
}

float power(float b, int e){
    if (e == 0) return 1;

    float result = 1;
    for (int i = 1; i <= e; i++) result *= b;
    if (e > 0) return result;
    else return 1/result;
}

int main(){
    print(determinante(100, 0.01, -0.01, 100));
    print(doubleDeterminante(100, 0.01, -0.01, 100));

    for (int i = 6; i <= 14; ++i) {
        printAssoziativBerechnung(power(10,i), -power(10, i), power(10, -i));
    }
    return 0;
}