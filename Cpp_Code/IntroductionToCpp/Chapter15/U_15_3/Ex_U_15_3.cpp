/*
    We are proposed to fix a macro definition
*/
#include <iostream>

using std::cout;
using std::cin;

#define min(num_1, num_2) ((num_1 < num_2) ? num_1 : num_2)

int main()
{
    int num_1;
    int num_2;

    cout << "Enter two integers: \n";
    cin >> num_1 >> num_2;

    cout << "min(" << num_1 << "," << num_2 << ") = " << min(num_1, num_2) << "\n";

    return 0;
}