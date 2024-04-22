/*
    We are proposed to write a program that copies the elements of a string into the one 
    that is one place right
*/
#include <iostream>
#include <cstring>

using std::cout;
using std::cin;

int main()
{
    char str_1[100];
    char str_2[100];
    char str_3[100];
    char temp[100] = {0};

    cout << "Enter three strings: \n";

    cin.getline(str_1, 100);
    cin.getline(str_2, 100);
    cin.getline(str_3, 100);

    strcpy(temp, str_3);
    strcpy(str_3, str_2);
    strcpy(str_2, str_1);
    strcpy(str_1, temp);

    cout << "String one: " << str_1 << "\nString two: " << str_2 << "\nString three: " << str_3 << "\n";
    return 0;
}
