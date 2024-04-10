/*

    We are proposed to write a program that displays all the numbers from 111 to 999
    except those that begin with 4 or end with 6

*/
#include <iostream>

using namespace std;

int main()
{
    for (unsigned short num = 111; num != 1000; ++num)
    {

        if ((num % 10 == 6) || (num / 100 == 4)) {continue;}

        cout << num << " ";

    }
        cout << " \n";

    return 0;
}
