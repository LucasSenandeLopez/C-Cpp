/*
    We have to swap the values of two variables using the 
    x = (x ^ y) ^ x and y = (y ^ x) ^ y equations
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

    //temp = (first ^ second);
    first = second ^= (first ^ second);
    //second ^= temp;

    cout << "The first number is now " << first << \
    " and the second now is " << second << " \n";

    return 0;
}