/*

    We are proposed to write a program that from three integers, checks if they 
    are in succesive increasing order

*/

#include <iostream>

using namespace std;

int main()
{
    int number_1;
    int number_2;
    int number_3;

    cout << "Input three numbers: \n";
    cin >> number_1 >> number_2 >> number_3;

    if (number_3 > number_2 && number_2 > number_1)
    {

        cout << "The numbers are in succesive increasing order. \n";

    } else {

        cout << "The numbers are not in succesive increasing order. \n";

    }

    return 0;
}
