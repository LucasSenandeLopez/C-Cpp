/*

    We are proposed to compute the total taxes owed by an individual

*/
#include <iostream>

using namespace std;

int main()
{
    float income;
    float owed_taxes;

    cout << "Introduce your income: \n";
    cin >> income;

    if ((int)income <= 12000)
    {
        owed_taxes = 0.0f;

    } else if ((int)income <= 14000){

        owed_taxes = (income - 12001.0f) * 0.15f;

    } else if ((int)income <= 30000){

        owed_taxes = (14000.0f - 12001.0f) * 0.15f;
        owed_taxes += (income - 14001.0f) * 0.3f;

    } else {

        owed_taxes = (14000.0f - 12001.0f) * 0.15f;
        owed_taxes += (30000.0f - 14001.0f) * 0.3f;
        owed_taxes += (income - 30000.0f) * 0.4f;

    }

    cout << "You owe " << owed_taxes << "€ in taxes \n";

    return 0;
}
