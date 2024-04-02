/*

    We are proposed to obtain the remainder of the division of two positive integers
    without using the "%" operator

*/

#include <iostream>

int main()
{

    int integer_one = 77;
    int integer_two = 92;
    int remainder;

    // Remainder of integer_two divided by integer one
    remainder = integer_two - (integer_two / integer_one) * integer_one;
    
    std::cout << remainder << "\n" << integer_two % integer_one << "\n\n";

    return 0;

}