/*
    We are proposed to write a function that takes two floats and returns
    a pointer to the one with the highest value
*/
#include <iostream>

float *ptr_max(float *ptr_1, float *ptr_2);

//using namespace std
using std::cout;
using std::cin;

int main()
{
    float num_1;
    float num_2;
    float *ptr_m;

    cout << "Enter two numbers: \n";
    cin >> num_1 >> num_2;

    ptr_m = ptr_max(&num_1, &num_2);

    cout << "The max of " << num_1 << " and " << num_2 << " is: " << *ptr_m << " \n";
    return 0;
}

float *ptr_max(float *ptr_1, float *ptr_2)
{
    if (*ptr_1 > *ptr_2)
    {
        return ptr_1;

    } else {

        return ptr_2;
    }
}