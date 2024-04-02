/*

    We have two float variables and we want to write one as the sum of 
    the integer and fractional parts of the division of that one against
    the other one

*/

#include <iostream>

int main()
{

    float float_one = 5.9f;
    float float_two = 9.4f;
    int integer_part;
    float remainder;

    // We will write float two as the sum of the two components
    integer_part = int(float_two / float_one);
    remainder = float_two - (float)integer_part * float_one;
    

    std::cout << (float)integer_part * float_one + remainder << "\n\n";

    return 0;

}