/*

    We are porposed to write a porgram that reads three integers and if the num of
    any two of them is equal to the other one, it should display the integers within
    [0,10]. Otherwise, the program should input three more integers and display how many
    of those three are multiples of 6.

*/
#include <iostream>

using namespace std;

int main()
{
    int number_1;
    int number_2;
    int number_3;
    unsigned int counter;

    cout << "Input three integers: \n";
    cin >> number_1 >> number_2 >> number_3;

    if (number_1 + number_2 == number_3 || number_1 + number_3 == number_2 \
        || number_2 + number_3 == number_2)
    {

        cout << "0 1 2 3 4 5 6 7 8 9 10 \n";

    } else {

        cout << "Input three more integers: \n";
        cin >> number_1 >> number_2 >> number_3;

        counter = 0U;
        
        (!(number_1 % 6)) ? ++counter : counter;
        (!(number_2 % 6)) ? ++counter : counter;
        (!(number_3 % 6)) ? ++counter : counter;
        
        if (counter != 1)
        {
            cout << "Of those three numbers, " << counter << " are multiples of 6 \n";
        } else {

          cout << "Of those three numbers, 1 is a multiple of 6 \n";

        }

    }


    return 0;
}
