/*
    We are proposed to write that program that verifiees if the given IP address is valid:
    Valid format: x.x.x.x where x is an integer in [0, 255]
*/
#include <iostream>

using std::cout;
using std::cin;

int main()
{
    int x_digit = 0;
    char ch_temp;
    unsigned short x_count = 1;
    char ch_prev = '.';

    cout << "Introduce an IP adress: \n";

    do
    {
        ch_temp = (char)cin.get();

        if (x_digit > 255) 
        {
            cout << "Invalid IP address; an integer is above 255. \n";
            return 0;

        } else if (ch_temp == '.') {

            switch (ch_prev)
            {
            case '.':
                {
                    cout << "Invalid IP address; two dots next to eachother. \n";
                    return 0;
                    break;
                }
            default:
                {
                    ++x_count;
                    x_digit = 0;
                    break;
                }
            }
            
        } else if ((ch_temp != '\n') && (ch_temp < '0' || ch_temp > '9')){
            
            cout << "Invalid IP address; character '" << ch_temp << "' not accepted. \n";
            return 0;

        } else {

            x_digit *= 10;
            x_digit += ch_temp - 48;
        }

        ch_prev = ch_temp;

    } while (ch_temp != '\n');
    

    switch (x_count)
    {
    case 4:
        {
            cout << "The IP address is valid! \n";
            break;
        }
    default:
        {
            cout << "Invalid IP address; number of numeric parts has to be 4. \n";
            break;
        }
        
    }

    return 0;
}
