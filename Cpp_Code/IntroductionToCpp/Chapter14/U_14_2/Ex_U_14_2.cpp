/*
    We are proposed to use a single pointer variable to obtain the maximum of three integers
*/
#include <iostream>

//using namespace std
using std::cout;
using std::cin;

int main()
{
    int *ptr;
    
    ptr = new int[3];

    cout << "Enter three integers: \n";
    cin >> ptr[0] >> ptr[1] >> ptr[2];

    if (ptr[0] > ptr[1] && ptr[0] > ptr[2])
    {
        cout << "The maximum is: " << ptr[0] << "\n";

    } else if (ptr[1] > ptr[0] && ptr[1] > ptr[2]){

        cout << "The maximum is: " << ptr[1] << "\n";

    } else {

        cout << "The maximum is: " << ptr[2] << "\n";
    }

    delete[] ptr;


    return 0;
}