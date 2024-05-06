/*
    We are proposed to read the sum of an int and double number using only
    two pointer variables
*/
#include <iostream>

//using namespace std
using std::cout;
using std::cin;

int main()
{
    int *p_int;
    double *p_double;

    p_int = new int;
    p_double = new double;

    cout << "Enter an integer and a double: \n";
    cin >> *p_int >> *p_double;

    cout << "The sum of " << *p_int << " and " << *p_double << " is " << (double)*p_int + *p_double << " \n";

    delete p_int;
    delete p_double;
    return 0;
}