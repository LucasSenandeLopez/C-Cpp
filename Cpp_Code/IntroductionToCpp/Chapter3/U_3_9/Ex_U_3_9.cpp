/*

    We are proposed to create a program that inputs a four-digit and then a one-digit
    positive integer and converts the four-digit into five-digit 
    by placing the one-digit in the middle

*/
#include <iostream>

using namespace std;

int main()
{
    unsigned int four_digit;
    unsigned int one_digit;
    unsigned int thousands;
    unsigned int hundreds;
    unsigned int new_four_digit;

    cout << "Introduce a four digit integer and then a one-digit integer: \n";
    cin >> four_digit >> one_digit;

    thousands = four_digit / 1000;
    hundreds = (four_digit - thousands * 1000) / 100;

    new_four_digit = (thousands * 10000) + (hundreds * 1000) + (one_digit * 100) + \
        (four_digit - thousands * 1000 - hundreds * 100);

    cout << "The new five-digit number is: " << new_four_digit << "\n";

    return 0;
}