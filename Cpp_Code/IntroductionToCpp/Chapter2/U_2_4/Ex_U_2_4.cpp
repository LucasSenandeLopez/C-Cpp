/*

    The exercise proposes that, from two negative integers, we use them
    to obtain their corresponding positives.

*/

#include <iostream>

int main()
{

    int integer_one = -30;
    int integer_two = -72;

    integer_one = (int)(1UL << 32) - integer_one; // Acts as 0 - integer_one
    integer_two = (int)(1UL << 32) - integer_two;

    std::cout << integer_one << "\n" << integer_two << "\n\n";

    return 0;

}