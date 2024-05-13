/*
    We are proposed to define a fraction class
*/
#include <iostream>

using std::cout;
using std::cin;

class Fraction
{
private:
    int numer;
    int denom;

    void simplify();

public:
    Fraction(int numerator, int denominator)
    {
        numer = numerator;
        denom = denominator;
    }
    void mul(Fraction b);
    void add(Fraction b);
    void sub(Fraction b);
    void div(Fraction b);
    void show();
};

void Fraction::mul(Fraction b)
{
    numer *= b.numer;
    denom *= b.denom;

    int sign = 1;

    if(numer < 0)
    {
        numer *= -1;
        sign *= -1;
    }
    if(denom < 0)
    {
        denom *= -1;
        sign *= -1;
    }

    simplify();

    numer *= sign;
    return;
}


void Fraction::show()
{
    cout << numer << "/" << denom << "\n";
    return;
}

void Fraction::div(Fraction b)
{
    numer *= b.denom;
    denom *= b.numer;

    int sign = 1;

    if(numer < 0)
    {
        numer *= -1;
        sign *= -1;
    }
    if(denom < 0)
    {
        denom *= -1;
        sign *= -1;
    }


    simplify();

    numer *= sign;
    return;
}

void Fraction::simplify()
{
    int max;
    int flag;

    do
    {
        max = ((numer > denom) ? numer : denom);
        flag = 0;
        for (int i = max; i >= 2; --i)
        {
            if(!(numer % i) && !(denom % i))
            {
                numer /= i;
                denom /= i;
                flag = 1;
            }
        }
    } while (flag);
    
    return;
}

void Fraction::add(Fraction b)
{
    numer = numer*b.denom + b.numer*denom;
    denom *= b.denom;

    int sign = 1;

    if(numer < 0)
    {
        numer *= -1;
        sign *= -1;
    }
    if(denom < 0)
    {
        denom *= -1;
        sign *= -1;
    }


    simplify();

    numer *= sign;
    return;
}

void Fraction::sub(Fraction b)
{
    numer = numer*b.denom - b.numer*denom;
    denom *= b.denom;

    int sign = 1;

    if(numer < 0)
    {
        numer *= -1;
        sign *= -1;
    }
    if(denom < 0)
    {
        denom *= -1;
        sign *= -1;
    }

    simplify();

    numer *= sign;
    return;
}

int main()
{
    Fraction a(4, 6), b(1, 2);
    a.mul(b);

    a.show();

    return 0;
}
