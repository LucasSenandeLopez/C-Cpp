/*

    We are proposed to use pointers to display the fractional part of a double
   

*/
#include <iostream>

using namespace std;

int main()
{
    double num_doub, *ptr_doub = &num_doub;
    double num_frac, *ptr_frac = &num_frac;
    int num_base, *ptr_base = &num_base;

    cout << "Input a number: \n";
    cin >> *ptr_doub;

    *ptr_base = (int)(*ptr_doub);
    *ptr_frac =  *ptr_doub - double(*ptr_base);
    *ptr_frac = ((*ptr_frac < 0.0) ? -(*ptr_frac) : (*ptr_frac));

    cout << "The fractional part of "  << *ptr_doub  << " is " << *ptr_frac << "\n";

    return 0;
}