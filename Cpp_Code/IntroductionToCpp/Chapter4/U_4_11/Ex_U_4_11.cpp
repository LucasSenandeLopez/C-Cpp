/*
    We are porposed to write a program that, from an integer and two slected bits,
    gets the number formed by the bits between them

    Example: number = 10110000 (176) between bits 4 and 6 then we get 110 = 6
*/

#include <iostream>

using namespace std;

int main()
{   
    int number;
    unsigned int lower_bit;
    unsigned int upper_bit;
    unsigned int interval_length;
    int shifted_number;
    int substraction_num;

    cout << "Introduce the value of an integer and then the lower and upper extremes of the interval: \n";
    cin >> number >> lower_bit >> upper_bit;

    lower_bit -= (lower_bit > upper_bit) * (lower_bit - upper_bit);
    interval_length = upper_bit - lower_bit + 1;

    shifted_number = (number >> (lower_bit - 1));  
    substraction_num = ((shifted_number >> interval_length) << interval_length);

    shifted_number -= substraction_num;

    cout << "The interval of bits [" << lower_bit << "," << upper_bit << "] In the number " << \
        number << " forms the number " << shifted_number << ". \n";

    return 0;
}