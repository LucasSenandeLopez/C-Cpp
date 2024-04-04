/*

    We are proposed to create a program that inputs a two-digit positive integer and
    duplicate its digits in order

*/
#include <iostream>

using namespace std;

int main()
{
    unsigned int number;
    unsigned int first_digit;
    unsigned int second_digit;

    cout << "Introduce a two-digit positive integer: \n";
    cin >> number;

    first_digit = number / 10;
    second_digit = number - ((number / 10) * 10); // Equivalent to number % 10

    cout << "The duplicated number is: " << first_digit << first_digit << second_digit << second_digit;

    return 0;
}