/*

    We are porposed to write a program that rotates the bytes of an integer (number)
    by another integer rotation_n between 1 and 3 so that if we choose rotation_n = 1 and
    number = 553799974 == 00100001 00000010 01010001 00100110
    we get   639697489 == 00100110 00100001 00000010 01010001

*/

#include <iostream>

using namespace std;

int main()
{   
    unsigned int number;  
    unsigned int rotation_n;
    unsigned int left_part;
    unsigned int rotated_number;

    cout << "Introduce an UInt32 and then an integer between 1 and 3: \n";
    cin >> number >> rotation_n;

    left_part = number << (32U - rotation_n * 8U);
    rotated_number = (number >> rotation_n * 8U) + left_part;

    cout << "The number has gone from " << number << " to " << rotated_number << " \n";

    return 0;
}