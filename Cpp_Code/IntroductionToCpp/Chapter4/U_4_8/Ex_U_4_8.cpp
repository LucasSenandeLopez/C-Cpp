/*

    We are porposed to write a program that sums the binary digits of an integer
    in positions 2, 4, 6 and 8

*/

#include <iostream>

using namespace std;

int main()
{   
    int number;

    cout << "Introduce an integer:  \n";
    cin >> number;

    number = ((number & 2) != 0) + ((number & 8) != 0) + ((number & 32) != 0) + ((number & 128) != 0);

    cout << "The sum of binary digits in positions [2, 4, 6 and 8] is: " << number << "\n";
    return 0;
}