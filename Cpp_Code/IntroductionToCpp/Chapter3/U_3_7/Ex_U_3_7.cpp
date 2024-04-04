/*

    We are proposed to create a program that inputs a positive integer and
    analyzes it in terms of the numbers 50, 20, 10 and 1

*/
#include <iostream>

using namespace std;

int main()
{
    unsigned int number;
    unsigned int fifties;
    unsigned int twenties;
    unsigned int tens;
    unsigned int units;


    cout << "Introduce a positive integer: \n";
    cin >> number;
    
    fifties = number / 50;

    twenties = (number - fifties * 50) /  20;
    tens = (number - fifties * 50 - twenties * 20) / 10;
    units = number - fifties * 50 - twenties * 20 - tens * 10;

    cout << "The number " << number << " is: (" << fifties << " * 50) + (" << twenties << \
        " * 20) + (" << tens << " * 10) + (" << units << " * 1) \n";

    return 0;
}