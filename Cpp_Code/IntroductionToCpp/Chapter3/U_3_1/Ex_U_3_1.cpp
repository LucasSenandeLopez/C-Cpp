/*

    We are proposed to obtain the percentage of passing and failing students 
    that we pass into the program

*/

#include <iostream>
#include <iomanip>

using namespace std;


int main()
{

    int passing;
    int failing;
    int total;
    float perc_passing;
    float perc_failing;


    cout << "Introduce the number of passing and then the number of failing students in that order \n";
    cin >> passing >> failing;

    total = passing + failing;
    perc_passing = 100.0f * ((float)passing / (float)total);
    perc_failing = 100.0f - perc_passing;

    cout.fill('%');
    cout.precision(1);
    cout.setf(ios_base::left, ios_base::adjustfield);
    cout.setf(ios_base::fixed, ios_base::floatfield);
    cout << "Success Ratio: " << setw(5) << perc_passing << "\nFail Ratio: " \
        << setw(5) << perc_failing << "\n";


    return 0;

}