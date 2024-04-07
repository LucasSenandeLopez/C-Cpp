/*

    We have to create a program that displays the total discount of an order

*/
#include <iostream>

using namespace std;

int main()
{
    
    unsigned int n_small_bottles;
    unsigned int n_large_bottles;
    float order_price;

    cout << "Input the number of small and then the number of large bottles: \n";
    cin >> n_small_bottles >> n_large_bottles;

    order_price = (float)n_small_bottles * 0.008f + (float)n_large_bottles * 0.02f;

    if(order_price > 600.0f)
    {

        cout << "The total price is: " << order_price * 0.8f << "€ \n";

    } else if(n_small_bottles + n_large_bottles > 3000U || order_price > 200.0f){

        cout << "The total price is: " << order_price * 0.92f << "€ \n";

    } else {

        cout << "The total price is: " << order_price << "€ \n";

    }


    return 0;
}
