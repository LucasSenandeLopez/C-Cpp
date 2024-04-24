/*
    We are proposed to write a program that reads a number in form of a string and 
    displays the nmber as an int; we can assume that the number is only 10 digits max
*/
#include <iostream>

//using namespace std
using std::cout;
using std::cin;

int main()
{
    char str[12] = {};
    long num = 0;
    long sign = 1;
    int len = 0;

    cout << "Input a number: \n";
    cin.getline(str, 11);

    do
    {
    } while (str[len++] != '\0');
    --len;

    if (str[0] == '-')
    {

        sign = -1;
        
        for(int i = 1; i < len; ++i)
        {
            num *= 10;
            num += (long)str[i] - 48; 
        }

    } else {

        for(int i = 0; i < len; ++i)
        {
            num *= 10;
            num += (long)str[i] - 48;  
        }
    }

    cout << "The number is: " << sign * num << " \n";
    return 0;
}
