/*
    We are proposed to write a program that reads two strings, the first as long or longer
    than the second one and check how many times the second one is contained in the first one
*/
#include <iostream>

using std::cout;
using std::cin;

int main()
{
    char str_1[100];
    char str_2[100];
    unsigned int len_1;
    unsigned int len_2;

    cout << "Enter two strings; the first longer than the second one. \n";

    cin.getline(str_1, 100);
    cin.getline(str_2, 100);

    do
    {
    } while (str_1[len_1++] != '\0');

    do
    {
    } while (str_2[len_2++] != '\0');

    if (len_2 > len_1)
    {
        cout << "The first string should be as long or longer than the second one. \n";
        return 0;
    }

    return 0;
}
