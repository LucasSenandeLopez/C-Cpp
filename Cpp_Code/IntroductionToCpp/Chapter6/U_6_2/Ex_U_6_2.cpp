/*
    We have to compute a program that reads integers and calculates their sum until
    it exceeds 100

*/
#include <iostream>

using namespace std;

int main()
{

    long sum = 0L;
    long number;
    unsigned int counter = 0;

    for(;;)
    {

        cout << "Introduce a number: \n";
        cin >> number;
    
        sum += number;
        ++counter;

        if (sum >= 100L) {break;}

    }

    cout << "The sum is: " << sum << " and it took " << counter << " input(s) to reach it \n";

    return 0;
}
