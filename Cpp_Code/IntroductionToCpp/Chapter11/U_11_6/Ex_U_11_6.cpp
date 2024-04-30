/*
    We are proposed to write a void function that returns the number of equal elements
    in an array
*/
#include <iostream>
#include <cstdlib>

using std::cout;


void compare_arrays(unsigned int arr_1[], unsigned int arr_2[], unsigned int *count_ptr, unsigned int length);

int main()
{
    unsigned int sum_eq = 0;
    unsigned int arr_1[100];
    unsigned int arr_2[100];

    srand((unsigned int)time(NULL));

    for (int i = 0; i < 100; ++i)
    {
        arr_1[i] = (unsigned int)rand() % 10U;
        arr_2[i] = (unsigned int)rand() % 10U;
    }

    compare_arrays(arr_1, arr_2, &sum_eq, sizeof(arr_1)/sizeof(arr_1[0]));

    cout << "The number of equal elements is: " << sum_eq << " \n";    

    return 0;
}

void compare_arrays(unsigned int arr_1[], unsigned int arr_2[], unsigned int *count_ptr, unsigned int length)
{

    for (unsigned int i = 0; i < length; ++i)
    {

        if (arr_1[i] != arr_2[i])
        {
            continue;
        }

        ++(*count_ptr);
    }

    return;
}