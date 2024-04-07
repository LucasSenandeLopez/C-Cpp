/*

    With four integers, we have to display the highest sum of any pair
    without using the && operator

*/
#include <iostream>

using namespace std;

int main()
{
    int number_1;
    int number_2;
    int number_3;
    int number_4;
    int counter_1 = 0;
    int counter_2 = 0;
    int counter_3 = 0;
    int counter_4 = 0;
    int largest_sum;

    cout << "Input four integers: \n";
    cin >> number_1 >> number_2 >> number_3 >> number_4;

    // Number one

    (number_1 > number_2) ? ++counter_1 : ++counter_2;
    (number_1 > number_3) ? ++counter_1 : ++counter_3;
    (number_1 > number_4) ? ++counter_1 : ++counter_4;

    (number_2 > number_3) ? ++counter_2 : ++counter_3;
    (number_2 > number_4) ? ++counter_2 : ++counter_4;

    (number_3 > number_4) ? ++counter_3 : ++counter_4;

    if (counter_1 == 3)
    {
        if (counter_2 == 2){

            largest_sum = number_1 + number_2;

        } else if (counter_3 == 2){

            largest_sum = number_1 + number_3;

        } else if (counter_4 == 2){

            largest_sum = number_1 + number_4;

        }

    } else if (counter_2 == 3){

                if (counter_1 == 2){

            largest_sum = number_1 + number_2;

        } else if (counter_3 == 2){

            largest_sum = number_2 + number_3;

        } else if (counter_4 == 2){

            largest_sum = number_2 + number_4;

        }

    } else if (counter_3 == 3){

        if (counter_1 == 2){

            largest_sum = number_1 + number_3;

        } else if (counter_2 == 2){

            largest_sum = number_2 + number_3;

        } else if (counter_4 == 2){

            largest_sum = number_3 + number_4;

        }

    } else if (counter_4 == 3){

        if (counter_1 == 2){

            largest_sum = number_1 + number_4;

        } else if (counter_2 == 2){

            largest_sum = number_2 + number_4;

        } else if (counter_3 == 2){

            largest_sum = number_3 + number_4;

        }

    }

    cout << "The largest sum of pairs is: " << largest_sum << " \n";

    return 0;
}
