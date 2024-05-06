/*
    We are proposed to write a macro that checks if a number is between
    other two
*/
#include <iostream>

using std::cout;
using std::cin;

#define between(x, a, b) ((x >= a) && (x <= b))


int main()
{
    int low_bound;
    int upp_bound;
    int num;

    cout << "Enter a number x and the extremes of a closed interval [a, b]: \n";
    cin >> num >> low_bound >> upp_bound;

    if (between(num, low_bound, upp_bound))
    {
        cout << "The number is inside the interval! \n";
        
    } else {

        cout << "The number is not inside the interval! \n";
    }

    return 0;
}