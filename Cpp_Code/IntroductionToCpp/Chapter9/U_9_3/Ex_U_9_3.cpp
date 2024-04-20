/*
    We are proposed to read the digits of an up-to-10-digit number as chars
    and output the number
*/
#include <iostream>

using std::cout;
using std::cin;

int main()
{
    int number;
    int temp;
    short int neg;
    char ch_digit; 
    unsigned int count = 0;
    
    

    do
    {
        number = 0;
        count = 0;
        neg = 1;

        cout << "Input ten digits or less: \n";
        do
        {
            temp = 0;

            ch_digit = (char)cin.get();

            if (ch_digit >= '0' && ch_digit <= '9')
            {

                temp = (int)ch_digit - 48;
                
                number *= 10;
                ++count;
                

            } else if (ch_digit == '-' && count == 0){
                
                neg *= -1;
                ++count;
            } 
        
            if (temp > 10) {break;}
            number += temp;

        } while (ch_digit != '\n');

    } while (count > 10);
    
    number *= neg;

    cout << "The number is: " << number <<" \n";
    return 0;
}
