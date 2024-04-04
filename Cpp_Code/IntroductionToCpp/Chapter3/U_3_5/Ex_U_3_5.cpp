/*

    We are proposed to create a program that reads a positive integer and rounds it up
    to its two last digits

*/

#include <iostream>

using namespace std;

int main()
{

    unsigned int number;

    cout << "Introduce a positive integer: \n";
    cin >> number;

    cout << (number + 50) / 100 * 100;

    return 0;
}