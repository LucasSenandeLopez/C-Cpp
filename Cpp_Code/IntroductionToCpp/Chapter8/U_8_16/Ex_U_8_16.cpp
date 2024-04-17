/*
    We are proposed to write a program that writes the elements of an array
    in reverse order without using digits
*/
#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int *ptr, arr[] = {10, 20, 30, 40, 50};

    cout << "{ ";

    for (ptr = arr + size(arr); ptr != arr;)
    {
        --ptr;
        cout << *ptr << " ";
    }
    cout << "} \n";

    return 0;
}
