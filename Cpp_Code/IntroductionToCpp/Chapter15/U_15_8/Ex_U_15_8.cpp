/*
    We are proposed to write a program that, based on if a macro or another is defined,
    prints either the number of uppercase characters or digits
*/
#include <iostream>

using std::cout;
using std::cin;

//#define UL 

int main()
{
    char str[100];
    unsigned int count = 0;
    unsigned int i = 0;

    cout << "Enter a string of less than 100 characters: \n";
    cin.getline(str, 100);

    #ifdef UL

        do
        {
            if (str[i] >= 'A' && str[i] <= 'Z'){++count;}
        } while (str[i++] != '\0');
        
        cout << "The number of uppercase characters in \"" << str << "\" is " << count << "\n";

    #else

        do
        {
            if (str[i] >= '0' && str[i] <= '9'){++count;}
        } while (str[i++] != '\0');
        
        cout << "The number of digits in \"" << str << "\" is " << count << "\n";

    #endif

    return 0;
}