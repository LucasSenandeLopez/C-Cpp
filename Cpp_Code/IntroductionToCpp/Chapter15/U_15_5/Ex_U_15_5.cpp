/*
    We are proposed to write a program that displays the lowercase letters as uppercase
    in a string using a macro
*/
#include <iostream>

using std::cout;
using std::cin;

#define UPPER(chr) ((chr >= 'a' && chr <= 'z') ? (char)(chr - 32) : chr)

int main()
{
    char str[100];
    unsigned int i = 0;

    cout << "Enter a string of less than 100 characters: \n";
    cin.getline(str, 100);

    cout << "The string \"" << str << "\" in uppercase is \"";

    do
    {
       cout << UPPER(str[i]);

    } while (str[i++] != '\0');
    
    cout << "\" \n";

    return 0;
}