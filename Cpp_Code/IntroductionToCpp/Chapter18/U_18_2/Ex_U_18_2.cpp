/*
    We have to create a classs that dinamically creates a safe array and use it
*/
#include <iostream>

using std::cout;
using std::cin;

class Safe_arr
{
private:

    int *arr;
    int size;

public:

    Safe_arr(int init_size)
    {
        this -> size = init_size;
        arr = new int[init_size];
    }

    int& operator[](int index);
    ~Safe_arr(){ delete[] arr;}
};

int& Safe_arr::operator[](int index)
{
    if (index >= size || index < 0)
    {
        cout << "Cancelled operation: Index out of bounds\n";
        exit(EXIT_FAILURE);
    } else {

        return *(arr + index);
    }
}



int main()
{
    int i;
    Safe_arr s_arr(10);

    s_arr[0] = 1;

    //s_arr[30] = 2;

    i = s_arr[0];

    cout << "s_arr[" << i << "] = " << i << "\n";

    return 0;
}
