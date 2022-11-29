#include "fcpp.hh"

float powerfloat(float b, int e){ //calculates b^e as float
    if (e == 0) return 1;

    float result = 1;
    for (int i = 1; i <= e; i++) result *= b;
    if (e > 0) return result;
    else return 1/result;
}

double powerdouble(double b, int e){ //calculates b^e as double
    if (e == 0) return 1;

    double result = 1;
    for (int i = 1; i <= e; i++) result *= b;
    if (e > 0) return result;
    else return 1/result;
}

float zinsf(float z, int n){ //calculate "zins" as float
    return powerfloat((1 + z / n), n) - 1;
}

double zinsd(double z, int n){ //calculate "zins" as double
    return powerdouble((1 + z / n), n) - 1;
}

void printFormattedInformation(int n){
    print("-------------Anzahl Abrechnungsvorgaenge:", n, "-------------", 0);
    print("Zinssatz (float):               ", zinsf(0.06, n), 0);
    print("Differenz zu exp(z)-1 (double): ", (exp(zinsf(0.06, n))-1)-zinsf(0.06, n), 0);
    print("Zinssatz (double):              ", zinsd(0.06, n), 0);
    print("Differenz zu exp(z)-1 (double): ", (exp(zinsd(0.06, n))-1)-zinsd(0.06, n), 0);
}

//main -------------------------------------------------------------
int main(){
    printFormattedInformation(1);
    printFormattedInformation(4);
    printFormattedInformation(12);
    printFormattedInformation(365);
    printFormattedInformation(365*24);
    printFormattedInformation(365*24*60);
    printFormattedInformation(365*24*60*2);
    printFormattedInformation(365*24*60*60);


    return 0;
}
