/*
    We are proposed to make the user input three numbers until they are in decreasing order
*/
#include <iostream>

using namespace std;

int main()
{
    int num_1;
    int num_2;
    int num_3;

    while(1)
    {
        cout << "Input the first number: \n";
        cin >> num_1;

        cout << "Input the second number: \n";
        cin >> num_2;

        if (num_1 > num_2)
        {
            cout << "Input the third number: \n";
            cin >> num_3;

            if (num_2 > num_3){break;}
        }

        cout << "The numbers have to be in strictly descending order! \n\n";
    }

    cout << num_1 << " > " << num_2 << " > " << num_3 << " \n";

    return 0;
}
