/*

    We are proposed to build a program that, from a 5-digit integer, writes it in words

    -12 -> minus one two

*/
#include <iostream>

using namespace std;

int main()
{
    int number;
    int pow_ten;
    long temp;
    unsigned short length = 0U;
    

    cout << "Insert an integer with five digits at most: \n";

    cin >> number;

    cout << "\nThe number " << number << " is written as: ";

    if (number < 0) 
    {
        cout << "minus "; 
        number *= -1;
    }


    for(temp = number * 10; temp / 10; temp /= 10)
    {
        ++length;
    }
    
    for(int i = length; i; --i)
    {
        pow_ten = 1;

        for (int j = length - i + 1; j < length; ++j)
        {
            pow_ten *= 10;
        }

        switch (number / pow_ten)
        {
            case 0:
                
                cout << "zero ";

                break;
            
            case 1:
                
                cout << "one ";
                number -= pow_ten;

                break;

            case 2:
                
                cout << "two ";
                number -= pow_ten * 2;

                break;
            case 3:
                
                cout << "three ";
                number -= pow_ten * 3;

                break;
            case 4:
                
                cout << "four ";
                number -= pow_ten * 4;

                break;        
                
            case 5:
                
                cout << "five ";
                number -= pow_ten * 5;

                break;            
                
            case 6:
                
                cout << "six ";
                number -= pow_ten * 6;

                break;            

            case 7:
                
                cout << "seven ";
                number -= pow_ten * 7;

                break;

            case 8:
                
                cout << "eight ";
                number -= pow_ten * 8;

                break;

            case 9:
                
                cout << "nine ";
                number -= pow_ten * 9;

                break;
        }

    }

    cout << " \n";
    return 0;
}
