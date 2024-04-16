/*
    We are proposed to write a program that reverses the elements of the array
*/
#include <iostream>

using namespace std;

int main()
{
    double arr[] = {1.3, -4.1, -3.8, 9.4, 2.5, 8.7};
    auto *ptr_1 = arr;
    auto *ptr_2 = arr + 4;
    double temp;
    const unsigned int len_arr = sizeof(arr)/sizeof(arr[0]);

    for(; ptr_1 < arr + len_arr / 2; ++ptr_1)
    {
        temp = *ptr_1;
        *ptr_1 = *ptr_2;
        *ptr_2 = temp;

        --ptr_2;
    }

    for(unsigned int i = 0; i < len_arr; ++i)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
