/*
    We are proposed to reverse the elements of a char[]
*/
#include <iostream>
#include <cstring>

using std::cout;
using std::cin;

int main()
{
    char str[100] = {'\0'};
    unsigned int len = 0;
    char temp;


    cout << "Enter a string with less than 100 characters: \n";
    cin.getline(str, 100);

    do
    {
    } while (str[len++] != '\0');
    

    for (unsigned int i = 0; i < len / 2; ++i)
    {
        temp = str[len - 1 - i];
        str[len - 1 - i] = str[i];
        str[i] = temp;
    }

    for(unsigned int i = 0; i < len; ++i)
    {
        cout << *(str + i);
    }

    return 0;
}
