/*
    We are proposed to enter a string and how many characters we want deleted
*/
#include <iostream>

using std::cout;
using std::cin;

int main()
{
    char str[100] = {'\0'};
    unsigned int len = 0;
    unsigned int pos_first;
    unsigned int number_deleted;


    cout << "Enter a string with less than 100 characters: \n";
    cin.getline(str, 100);

    cout << "Enter the position of the first character to delete and the number characters to delete: \n";
    cin >> pos_first >> number_deleted;

    --pos_first;

    do
    {
    } while (str[len++] != '\0');

    if ((len < pos_first + number_deleted) || (len < pos_first) || (len < number_deleted))
    {
        cout << "There are not that many characters. \n";

    } else {

        for (unsigned int i = 0; i < len; ++i)
        {
            str[pos_first + i] = str[pos_first + i + number_deleted];

        }
    }

    for(unsigned int i = 0; i < len; ++i)
    {
        cout << *(str + i);
    }

    return 0;
}
