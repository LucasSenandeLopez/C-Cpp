/*

    We are proposed to use pointers to display the absolute value of the sum of two
    double variables

*/
#include <iostream>

using namespace std;

int main()
{
    double num_1, *ptr_1 = &num_1;
    double num_2, *ptr_2 = &num_2;

    cout << "Input two numbers: \n";
    cin >> *ptr_1 >> *ptr_2;

    cout << "|num_1 + num_2| = " << ((*ptr_1 + *ptr_2 < 0) ? -(*ptr_1 + *ptr_2) : *ptr_1 + *ptr_2) << "\n";

    return 0;
}
