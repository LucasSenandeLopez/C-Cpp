/*
    We are proposed to make a template to a function that swaps the values of the two
    input parameters and overload it with a function that takes two arrays of the same 
    size and swaps their values
*/
#include <iostream>

template <typename T> T& swap_values(T& num_1, T& num_2);
template <typename T, unsigned int size> void swap_values(T (&num_1)[size], T (&num_2)[size]);


using std::cout;
using std::cin;

int main()
{

    int n_1 = 1; 
    int n_2 = 3;
    int largest = swap_values(n_1, n_2);
    int arr_1[3] = {4, 5, 6};
    int arr_2[3] = {1, 2, 3}; 

    cout << "n_1 = " << n_1 << ", n_2 = " << n_2 << " and their maximum is " << largest << "\n";

    swap_values<int, 3>(arr_1, arr_2);

  
    
    cout << "The array arr_1's values are: ";
    for(int j = 0; j < 3; ++j)
    {
        cout << arr_1[j] << " ";

    }

    cout << "\nWhile the array arr_2's values are: ";
    for(int j = 0; j < 3; ++j)
    {
        cout << arr_2[j] << " ";

    }
    cout << "\n";

    return 0;
}

template <typename T> T& swap_values(T& num_1, T& num_2)
{

    T temp = std::move(num_1);
    num_1 = std::move(num_2);
    num_2 = std::move(temp);

    if (num_2 > num_1)
    {
        return num_2;

    } else{

        return num_1;
    }
}

template <typename T, unsigned int size> void swap_values(T (&num_1)[size], T (&num_2)[size])
{

    T temp;

    for(unsigned int i = 0; i < size; ++i)
    {
        temp = std::move(num_1[i]);
        num_1[i] = std::move(num_2[i]);
        num_2[i] = std::move(temp);
    }

    return;
}