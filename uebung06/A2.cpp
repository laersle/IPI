#include <iostream>
#include <cmath>
#include "fcpp.hh"


struct PrimeFactorization { //struct that contains data & functionality to calculate prime factors of a number
    int primeFactors[100];
    int primeFactorCount;
    int number;

    PrimeFactorization(int nbr){
        primeFactorCount = 0;
        number = nbr;
    }

    void primeFactorize() {
        int result = number;

        //begin at 2 (1 not a primenumber) and go up to sqrt(n)
        for (int i = 2; i < std::sqrt(number) + 1; ++i) {
            while (result % i == 0) {   //if and while i divides result add it to the list
                primeFactors[primeFactorCount] = i;
                primeFactorCount++;
                result /= i;
            }
        }

        if (result > 1){    //if result is not 1 at the end it's a primenumber itself -> add to list
            primeFactors[primeFactorCount] = result;
            primeFactorCount++;
        }
    }

    void sortArray(){ //bubblesort from ueb5/A2
        int temp;
        for (int i = 0; i < primeFactorCount; i++)
        {
            for (int j = 0; j + 1 < primeFactorCount - i; j++)
            {
                // Swaping the elements if first one is greater than second one.
                if (primeFactors[j] > primeFactors[j + 1])
                {
                    temp = primeFactors[j];
                    primeFactors[j] = primeFactors[j + 1];
                    primeFactors[j + 1] = temp;

                }
            }
        }
    }

    void printPrimeFactors(){    //prints array to console in a formatted way
        std::cout << number << " = ";
        for (int i = 0; i < primeFactorCount - 1; ++i) {
            std::cout << primeFactors[i] << " * ";
        }
        std::cout << primeFactors[primeFactorCount - 1] << std::endl;
    }
};

int main(int argc, char** argv){

    // fange kein Kommandozeilenargument ab
    if (argc < 2)  throw std::runtime_error("expected arguments but none were given");

    PrimeFactorization p(readarg_int(argc, argv, 1));   //init struct with argument
    p.primeFactorize();                                        //find prime factors
    p.sortArray();                                             //sort prime factors

    std::cout << "Prime Factorization of " << argv[1] << " is: ";
    p.printPrimeFactors();                                     //print prime factors

    return 0;
}

//2b) Die Laufzeit des Algorithmus beträgt im schlechtesten Fall O(sqrt(n))