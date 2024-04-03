/*

    We are porposed to create a program that returns the change the customer will receive

*/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{

    int n_plates;
    int n_cups;
    float customer_payment;
    const float price_plate = 5.32f;
    const float price_cup = 2.84f;
    float change;

    cout << "Type the number of plates, the number of cups and then the amount you paid: \n";
    cin >> n_plates >> n_cups >> customer_payment;

    change = customer_payment - ((float)n_plates * price_plate + (float)n_cups * price_cup);

    cout.setf(ios_base::fixed, ios_base::floatfield);
    cout.precision(2);
    cout.setf(ios_base::left, ios_base::adjustfield);

    cout << setw(6) << "Your change is: " << change << "€" << "\n";

    return 0;

}
