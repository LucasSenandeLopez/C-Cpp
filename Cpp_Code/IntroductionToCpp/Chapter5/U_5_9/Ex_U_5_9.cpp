/*

    We have to write a number that reads a four digit positive integer and displays
    whether it can be displayed backwards

*/
#include <iostream>

using namespace std;

int main()
{
    unsigned int number;
    unsigned int first_two_digits;
    unsigned int last_two_digits;
    unsigned int third_digit;
    unsigned int last_digit;

    cout << "Introduce a 4-digit positive integer \n";
    cin >> number;

    first_two_digits = number / 100U;
    last_two_digits = number - first_two_digits * 100U;
    third_digit = last_two_digits / 10U;
    last_digit = last_two_digits - third_digit * 10;

    (first_two_digits == (last_digit * 10U + third_digit)) ? \
        cout << "The number is a palindrome \n" : cout << "The number is not a palindrome. \n";

    return 0;
}
