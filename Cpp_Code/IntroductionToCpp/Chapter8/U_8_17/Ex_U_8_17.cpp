/*
    We are proposed to read three integers and display the sum of the even numbers
*/
#include <iostream>

using namespace std;

int main()
{
    int j, k, m, sum = 0;
    int *arr[3] = {&j, &k, &m}, i;
    
    cout << "Enter three integers: \n";
    cin >> *arr[0] >> *arr[1] >> *arr[2];

    for (i = 0; i < (int)size(arr); ++i)
    {
        sum += !(*arr[i] % 2) * (*arr[i]);
    }

    cout << "The sum is: " << sum << " \n";

    return 0;
}
