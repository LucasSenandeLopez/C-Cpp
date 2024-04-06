/*

    We are porposed to write a program that sums the right and left shifted numbers by a factor
    while not losing any digits

*/

#include <iostream>

using namespace std;

int main()
{   
    unsigned int number;  
    unsigned int shift_n;
    unsigned int eight_minus_shift;
    unsigned int shifted_off_left;
    unsigned int sum_shift_left;
    unsigned int shifted_off_right;
    unsigned int sum_shift_right;

    cout << "Introduce an integer between [0, 255] and a shifting factor: \n";
    cin >> number >> shift_n;

    number = (number > 255U) * 255U + (number <= 255U) * number;

    eight_minus_shift = 8U - shift_n;

    shifted_off_left = (number >> eight_minus_shift);
    sum_shift_left = (number << shift_n) - (shifted_off_left << 8U) + shifted_off_left;

    /*
    We have to shift back by 8 positions because we shifted by -(8 - n), so to make sure
    that we substract to the n-shifted number, we have to shift by 8
    */


    shifted_off_right = (number << eight_minus_shift);
    shifted_off_right -= (((number >> shift_n)) << 8U);
    sum_shift_right = (number >> shift_n) + shifted_off_right;

    cout << "The left-transformed number is: " << sum_shift_left << \
        " \nThe right-transformed number is: " << sum_shift_right << " \n" << \
        "And their sum is: " << sum_shift_left + sum_shift_right << "\n";

    return 0;
}