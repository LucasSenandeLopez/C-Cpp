/*
    We are proposed to create an inheritance chain so that the console displays:

    B()  A()  C()  D()  E()
    ~E() ~D() ~C() ~A() ~B()

*/
#include <iostream>

using std::cout;
using std::cin;

class A
{
    public:
    A(){cout << "A()  ";}
    ~A(){cout << "~A()  ";}
};

class B
{
    public:
    B(){cout << "B()  ";}
    ~B(){cout << "~B()  \n";}
};

class C : virtual public B, virtual public A
{
    public:
    C(){cout << "C()  ";}
    ~C(){cout << "~C()  ";}
};

class D : virtual public B
{
    public:
    D(){cout << "D()  ";}
    ~D(){cout << "~D()  ";}
};

class E : virtual public C, virtual public D
{
    public:
    E(){cout << "E()  \n";}
    ~E(){cout << "~E()  ";}
};

int main()
{
    E e;
    return 0;
}