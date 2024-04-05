/*

    We have to display the smaller of two integers

*/

#include <iostream>

using namespace std;

int main()
{

    int number_1;
    int number_2;
    int larger_num;

    cout << "Type two integers, one smaller than the other: \n";
    cin >> number_1 >> number_2;

    larger_num = (number_1 < number_2) * number_2 + (number_2 <= number_1) * number_1;

    cout << "The larger number is: " << larger_num << " \n";

    return 0;

}
