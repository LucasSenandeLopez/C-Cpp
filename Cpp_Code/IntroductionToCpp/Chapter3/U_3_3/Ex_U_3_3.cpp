/*

    We are proposed to find the sum of three numbers with different bases

*/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{

    int octal_num;
    int hexadec_num;
    int dec_num;

    cout << "Introduct three numbers; the first octal, the second hexadecimal and the third decimal: \n";
    cin >> oct >> octal_num >> hex >> hexadec_num >> dec >> dec_num;

    cout << "The sum of the three numbers is: " << octal_num + hexadec_num + dec_num << "\n";

    return 0;
}