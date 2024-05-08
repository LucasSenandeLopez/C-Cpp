/*
    We are proposed to build two functions so that the cout statement outputs 10 twice
*/
#include <iostream>

using std::cout;

int& f(int& num);
int& g(int& num);

int main()
{
    int n_1 = 1, n_2 = 2;

    f(n_1) = g(n_2) = 10; // You could just replace g(n_2) with f(n_2) and save space in the executable

    cout << n_1 << " " << n_2 << "\n";

    return 0;
}


int& f(int& num)
{
    return num;
}

int& g(int& num)
{
    return num;
}