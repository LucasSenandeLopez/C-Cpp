/*

    We are proposed to write a program that checks if any of three products
    costs more than 100€ using the ternary operator

*/
#include <iostream>

using namespace std;

int main()
{
    float price_1;
    float price_2;
    float price_3;

    cout << "Input the price of three products: \n";
    cin >> price_1 >> price_2 >> price_3;

    ((int)price_1 >= 100 || (int)price_2 >= 100 || (int)price_3 >= 100) ? \
        (cout << "One of the products costs more than 100€ \n") : \
        (cout << "All the products cost less than 100€ \n");


    return 0;
}