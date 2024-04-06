/*

    We are porposed to write a program that swaps the two quads of an 8 bit integer
    so we go from 10 (00001010) to 160 (10100000)

*/

#include <iostream>

using namespace std;

int main()
{   
    unsigned int number;
    unsigned int first_quad;
    unsigned int second_quad;

    cout << "Introduce a positive 8 bit integer [0, 255]: \n";
    cin >> number;

    number = (number > 255) * 255 + (number <= 255) * number;

    first_quad = number >> 4;
    
    second_quad = (number << 4) - (first_quad << 8);

    /*
        Explanation: take number = 0000 0000 1010 1101

        number >> 4 == 0000 0000 0000 1010
    
        number << 4 == 0000 1010 1101 0000

        We then substract (number >> 4) << 8

        So:            0000 1010 1101 0000
                    -  0000 1010 0000 0000
                    == 0000 0000 1101 0000

        From which we obtain the second quad

    */
   
    cout << "The number went from " << number << " to " << (first_quad ^ second_quad) << " \n";
    return 0;
}