#include <iostream>

class A
{
public :
    void a();
    virtual void va() = 0;
    virtual void a(int n);
private :
    void c();
};

class B : public A
{
public :
    void b();
    virtual void vb();
    void a(double d);
    void a(int i);
    virtual void va();
};

class C : public B
{
public :
    virtual void c();
    void a(float);
    virtual void a();
    virtual void va();
};

int main(){
    //A a;  Fehler: A ist pure virtual
    B b;
    C c;
    A* pa=&b;
    B* pb=&c;
    float x = 1.2;

    pa->a(); pa->va(); pa->a(1); /*pa->c();*/ /*pa->b();*/ /*pa->vb();*/ pa->a(x);
    /*pb->a();*/ pb->va(); pb->a(1); /*pb->c();*/ pb->b(); pb->vb(); pb->a(x);

    pa = &c;
    pa->a(); pa->va(); pa->a(1); /*pa->c();*/ /*pa->b();*/ /*pa->vb();*/ pa->a(x);
}

void A::a() {
    std::cout << "A::a()" << std::endl;
}
void A::a(int n) {
    std::cout << "A::a(int n)" << std::endl;
}
void A::c() {
    std::cout << "A::c()" << std::endl;
}

void B::b() {
    std::cout << "B::b()" << std::endl;
}
void B::vb() {
    std::cout << "B::vb()" << std::endl;
}
void B::a(double d) {
    std::cout << "B::a(double d)" << std::endl;
}
void B::a(int i) {
    std::cout << "B::a(int i)" << std::endl;
}
void B::va() {
    std::cout << "B::va()" << std::endl;
}

void C::c() {
    std::cout << "C::c()" << std::endl;
}
void C::a(float) {
    std::cout << "C::a(float)" << std::endl;
}
void C::a() {
    std::cout << "C::a()" << std::endl;
}
void C::va() {
    std::cout << "C::va()" << std::endl;
}