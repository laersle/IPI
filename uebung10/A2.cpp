//!!Nur benutzt um den Code zu Überprüfen!!

class A
{
public:
  int ap;
  void X();
private:
  int aq;
  void aX();
};

class B : public A
{
public:
  int bp;
  void Y();
private:
  int bq;
  void bY();
};

class C : public B
{
public:
  int cp;
  void Z();
private:
  int cq;
  void cZ();
};

void A::X() { };
void A::aX() { };
void B::bY() { };
void C::Z() { };

void B::Y()
{
  bq = bp;
  //aq = ap;    //Fehler: aq ist privat
  bY();
}

void C::cZ()
{
  ap = 1;
  bp = 2;
  cq = 3;
  X();
  Y();
  //aX();       //Fehler: aX() ist privat
}

int main()
{
  A a; B b; C c;

  a.X();
  //b.bY();     //Fehler: bY() ist privat
  c.cp = 4;
  c.bp = 1;
  c.ap = 2;
//c.aq = 5;     //Fehler: aq ist privat

  b.ap = c.ap;

  return 0;
}
