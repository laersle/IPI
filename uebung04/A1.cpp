#include "fcpp.hh"

//A1a--------------------------------------------------------------------
float determinante(float a, float b, float c, float d){
    return a*d-b*c;
}

//A1b--------------------------------------------------------------------
double doubleDeterminante(double a, double b, double c, double d){
    return a*d-b*c;
}

void printAssoziativBerechnung(float a, float b, float c){
    print((a+b)+c, " = ", a+(b+c), 0);
}

float power(float b, int e){    //return result of b^e
    if (e == 0) return 1;

    float result = 1;
    for (int i = 1; i <= e; i++) result *= b;
    if (e > 0) return result;
    else return 1/result;
}

//main--------------------------------------------------------------------
int main(){
    print("Aufgabe 1a:");
    print("float:  det(A) = ",determinante(100, 0.01, -0.01, 100), 0);
    print("double: det(A) = ", doubleDeterminante(100, 0.01, -0.01, 100), 0);

    print("\nAufgabe 1b:");
    for (int i = 6; i <= 14; ++i) { //check if 	associtative law is true for multiple inputs
        print("n =", i, ":", 0);
        printAssoziativBerechnung(power(10,i), -power(10, i), power(10, -i));
    }
    return 0;
}