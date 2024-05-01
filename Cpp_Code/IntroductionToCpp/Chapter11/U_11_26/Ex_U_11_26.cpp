/*
    We are proposed to write a program that, using recursion, returns a triangular number
*/
#include <iostream>

using std::cout;
using std::cin;

unsigned int triag_num(unsigned int num);

int main()
{
    unsigned int number;

    do
    {
        cout << "Enter a positive integer less than or equal to 20: \n";

        cin >> number;
    } while (number > 20);

    cout << "T(" << number << ") = " << triag_num(number) << "\n";
    
    return 0;
}

unsigned int triag_num(unsigned int num)
{

    if (num < 2){return num;}

    return num +  triag_num(num - 1);

}