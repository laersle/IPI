// Programm zu Aufgabe Objektverhalten in C++
// Volker Reichenberger, Sommersemester 2001

/* @VERBON */
#include <iostream>

class Zahl
{
public:
  Zahl();                // Konstruktor
  Zahl( const int& n );  // int-Konstruktor
  Zahl( const Zahl& n ); // Copy-Konstruktor
  ~Zahl();               // Destruktor
  // int-Zuweisung
  Zahl& operator=( const int& n );
  // Zuweisung
  Zahl& operator=( const Zahl& n );
  // Addition
  Zahl operator+( const Zahl& n );
private:
  int z;
};

Zahl::Zahl() { z = 0;
    std::cout << this << ":    Default Konstruktor" << std::endl;
}
Zahl::Zahl( const int& n )  { z = n;
    std::cout << "Int Konstruktor" << std::endl;
}
Zahl::Zahl( const Zahl& n ) { z = n.z;
    std::cout << "Copy Konstruktor" << std::endl;
}
Zahl::~Zahl() {
    std::cout << "Destruktor" << std::endl;
}
Zahl& Zahl::operator=( const int& n )
{
    z=n;
    std::cout << "Zuweisung (int-ref)" << std::endl;
    return *this;
}
Zahl& Zahl::operator=( const Zahl& n )
{
    z=n.z;
    std::cout << "Zuweisung (Obj-ref)" << std::endl;
    return *this; }

Zahl Zahl::operator+( const Zahl& n )
{
    std::cout << "Addition" << std::endl;
    return Zahl(z+n.z); }

Zahl f( Zahl a, Zahl& b) { return a+b; }

int main()
{
  Zahl a(3), b(4);
  Zahl c(a), d, e;
  d = 5;
  d = f(d,c);
  e = d + a + b;
  return 0;
}
/* @VERBOFF */
