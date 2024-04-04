/*

    We are proposed to create a program that inputs two three-digit positive integers
    and swaps the hundreds of the first one wth the units of the second one

*/
#include <iostream>

using namespace std;

int main()
{
    unsigned int number_1;
    unsigned int number_2;
    unsigned int hundreds_1;
    unsigned int units_2;
    
    cout << "Introduce two three-digit positive integers: \n";
    cin >> number_1 >> number_2;

    hundreds_1 = number_1 / 100;
    units_2 = (number_2 - (number_2 / 100) * 100) % 10;

    number_1 = number_1 - (hundreds_1 * 100) + (units_2 * 100);
    number_2 = number_2 - units_2 + hundreds_1;

    cout << "Now the numbers are: " << number_1 << " and " << number_2 << "\n";

    return 0;
}