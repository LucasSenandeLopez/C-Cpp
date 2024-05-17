/*
    We are proposed to creates a class for the functionality of a polynomial
*/
#include <iostream>

using std::cout;
using std::cin;

class Polynomial
{
private:
    int a;
    int b;
    int c;
public:

Polynomial(int init_a = 1, int init_b = 1, int init_c = 1) : a(init_a), b(init_b), c(init_c){}

int calc(int x){return x*x*a + x*b + c;}
void show()
{
    cout << a << "x^2 + " << b << "x + " << c << "\n";
}

Polynomial& operator+(int num);
Polynomial operator+(Polynomial poly);
bool operator==(Polynomial poly);
int& operator[](int index);

};

Polynomial& Polynomial::operator+(int num)
{
    a += num;
    b += num;
    c += num;

    return *this;
}

Polynomial Polynomial::operator+(Polynomial poly)
{
    return Polynomial(a + poly.a, b + poly.b, c + poly.c);
}

bool Polynomial::operator==(Polynomial poly)
{
    return ((this->a == poly.a) && (this->b == poly.b) && (this->c == poly.c));
}

int& Polynomial::operator[](int index)
{
    switch (index)
    {
    case 0:
        return a;
        break;
    case 1:
        return b;
        break;
    case 2:
        return c;
        break;
    default:
        cout << "Index out of bounds\n";
        exit(EXIT_FAILURE);
        break;
    }
}



int main()
{
    Polynomial pol_1;
    Polynomial pol_2 = pol_1 + 3; 
    Polynomial pol_3(4,4,4);

    if (pol_3 == pol_2)
    {
        cout << "True\n";
    } else {

        cout << "False\n";
    }

    pol_2[2] = 3;

    if (pol_3 == pol_2)
    {
        cout << "True\n";
    } else {

        cout << "False\n";
    }

    cout << "pol_2(2) = " << pol_2.calc(3) << "\n";
    pol_3.show();

    return 0;
}
