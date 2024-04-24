/*
    We are proposed to define two functions
*/
#include <iostream>

int f(int x);
int g(int x);

//using namespace std
using std::cout;
using std::cin;

int main()
{
    int x;
    cout << "Enter an integer: \n";
    cin >> x;

    cout << "f(g(" << x << ")) = " << f(g(x)) << "\n";
    return 0;
}

int f(int x)
{
    return (x + 2)*(x > 0) + (-3*x + 7)*(x <= 0);
}

int g(int x)
{
    return (x*x + 2)*(x > 0) + (7*x - 5)*(x <= 0);
}