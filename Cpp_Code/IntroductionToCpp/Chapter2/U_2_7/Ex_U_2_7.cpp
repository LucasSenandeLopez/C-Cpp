/*

    We are proposed to compute the sum of the digits of a three-digit positive integer

*/

#include <iostream>

int main()
{

    int integer_in_question = 514;
    int hundreds;
    int tens;
    int last_digit;

    hundreds = integer_in_question / 100;
    tens = (integer_in_question - (hundreds * 100)) / 10;
    last_digit = integer_in_question - (hundreds * 100) - (tens * 10);

    std::cout << hundreds << " " << tens << " " << last_digit << "\n" << "---> " <<  \
    hundreds + tens + last_digit << "\n\n";

    return 0;

}