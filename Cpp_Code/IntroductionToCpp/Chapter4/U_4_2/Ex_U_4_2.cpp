/*

    We are proposed to build a program that, from a given cost, 
    has to calculate the discount in case it is higher than 100€

*/

#include <iostream>

using namespace std;

int main()
{
    float input_cost;
    float amount_paid;

    cout << "Introduce the total undiscounted cost: \n";
    cin >> input_cost;

    amount_paid = (input_cost < 100) * input_cost + (input_cost >= 100) * input_cost * 0.95f;

    cout << "The final cost is: " << amount_paid << "€ \n";

    return 0;

}
