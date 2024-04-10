/*
    Input the number of years, the population growth of a country in a year and the population
    and return the population in said number of years
*/
#include <iostream>

using namespace std;

int main()
{

    float pop_growth;
    long population;
    unsigned short years;

    cout << "Enter the current population \n";
    cin >> population;

    cout << "Enter the population growth as a percentage per year (without using the '%' sign): \n";
    cin >> pop_growth;
    
    cout << "Enter the number of years: \n";
    cin >> years;

    pop_growth /= 100.0f;

    for (int i = 1; i <= years; ++i)
    {

        population = (long)((float)population * (1.0f + pop_growth));

    }

    cout << "The population in " << years << " years will be: " << population << " people. \n";

    return 0;
}
