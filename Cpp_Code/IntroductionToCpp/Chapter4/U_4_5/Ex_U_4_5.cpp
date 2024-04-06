/*
    We have to swap the values of two variables using the 
    x = (x ^ y) ^ y and y = (y ^ x) ^ x equations
    while using only two variables
*/

#include <iostream>

using namespace std;

int main()
{   
    int first;
    int second;
    

    cout << "Introduce two integer variables: \n";
    cin >> first >> second;

    
    first = first ^ second;
    second = first ^ second;
    first = first ^ second;

    cout << "The first number is now " << first << \
    " and the second now is " << second << " \n";

    return 0;
}