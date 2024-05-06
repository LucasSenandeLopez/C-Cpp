/*
    We are proposed to fix a macro definition
*/
#include <iostream>

using std::cout;
using std::cin;

#define abs(num) ((num > 0) ? num : -num)

int main()
{
    int num;

    cout << "Enter an integer: \n";
    cin >> num;

    cout << "The absolute value of " << num << " is " << abs(num) << " \n";

    return 0;
}