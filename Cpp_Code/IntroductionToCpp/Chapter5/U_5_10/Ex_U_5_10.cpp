/*

    We are proposed to define a piecewise function

*/
#include <iostream>

using namespace std;

int main()
{
    float x;
    float f_x;

    cout << "Introduce a number: \n";
    cin >> x;

    if (int(x) < -5)
    {
        f_x = 8.0f;

    } else if (int(x) < 3) {

        f_x = (1.0f / x);

    } else if (int(x) < 12){

        f_x = x * x - 4.0f;

    } else {

        f_x = 6.0f/((x - 14.0f) * (x - 14.0f));
    }

    cout << "f(" << x << ") = " << f_x << " \n";

    return 0;
}
