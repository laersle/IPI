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
    std::cout << this << ":    Int Konstruktor  n=" << n << std::endl;
}
Zahl::Zahl( const Zahl& n ) { z = n.z;
    std::cout << this << ":    Copy Konstruktor | copy of: " << &n << std::endl;
}
Zahl::~Zahl() {
    std::cout << this << ":    Destruktor" << std::endl;
}
Zahl& Zahl::operator=( const int& n )
{
    z=n;
    std::cout << this << ":    Zuweisung (int-ref)  n=" << n  << std::endl;
    return *this;
}
Zahl& Zahl::operator=( const Zahl& n )
{
    z=n.z;
    std::cout << this << ":    Zuweisung (Obj-ref)  obj=" << &n << std::endl;
    return *this; }

Zahl Zahl::operator+( const Zahl& n )
{
    std::cout << this << ":    Addition | add: " << &n << std::endl;
    return Zahl(z+n.z); }

Zahl f( Zahl a, Zahl& b) { return a+b; }

int main()
{
  std::cout << "Zeile 37" << std::endl;
  Zahl a(3), b(4);
  std::cout << "Zeile 38" << std::endl;
  Zahl c(a), d, e;
  std::cout << "Zeile 39" << std::endl;
  d = 5;
  std::cout << "Zeile 40" << std::endl;
  d = f(d,c);
  std::cout << "Zeile 41" << std::endl;
  e = d + a + b;
  std::cout << "Zeile 42" << std::endl;
  return 0;
}
/* @VERBOFF */
