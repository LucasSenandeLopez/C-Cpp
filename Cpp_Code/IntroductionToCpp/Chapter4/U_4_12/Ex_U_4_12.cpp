/*
    We are porposed to write a program that rounds up a given positive integer to the next 
    highest power of two;
    
    If we input 35, we get 64, if we input 16 we get 16

*/

#include <iostream>

using namespace std;

int main()
{   
    unsigned int number;


    cout << "Introduce a positive integer: \n";
    cin >> number;

    number -= (number > 0U);

    number |= number >> 1;
    number |= number >> 2;
    number |= number >> 4;
    number |= number >> 8;
    number |= number >> 16;

    number++;

    cout << number << "\n";

    return 0;
}