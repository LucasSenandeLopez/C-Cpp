/*
    We are proposed to write a program that reads N strings and after doing so, if
    we write a string that is equal to one in the array, we erase it
*/
#include <iostream>
#include <cstring>

//using namespace std
using std::cout;
using std::cin;

int main()
{
    const int ROWS = 5;
    char arr[ROWS][100] = {"\0"};
    int i = 0;

    char comp_str[100];

    do
    {
        cout << "Enter a string: \n";
        cin.getline(arr[i], 100);
        
        ++i;

    } while (i < ROWS);
    
    cout << "Enter another string: \n";
    cin.getline(comp_str, 100);

    for(i = 0; i < ROWS; ++i)
    {
        if (!strcmp(arr[i], comp_str))
        {

            for(; i < ROWS - 1; ++i)
            {
                strcpy(arr[i], arr[i + 1]);
            }

            strcpy(arr[ROWS - 1], "\0");
            
            break;
        }
    }

    for(i = 0; i < ROWS - 1; ++i)
    {
        cout << arr[i] << "\n";
    }

    return 0;
}