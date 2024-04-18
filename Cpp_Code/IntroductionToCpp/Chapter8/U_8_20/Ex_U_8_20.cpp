/*
    We are proposed to write a program that sums the elements of the diagonals of
    an array and say if they are equal
*/
#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

int main()
{
    int mat[5][5] = {};
    int *ptr = mat[0];
    int sum_main_diag = 0;
    int sum_sec_diag = 0;

    srand((unsigned int)time(NULL));

    for (unsigned int i = 0; ptr + i < mat[0] + 25; ++i)
    {
        *(ptr + i) = rand() % 10;
       (!(i % 5) ? cout << "\n" << *(ptr + i) << "  ":  cout << *(ptr + i) << "  ");
        
    }

    cout << "\n";

    for (unsigned int i = 0; i < 5; ++i)
    {
        sum_main_diag += *(ptr + 6*i);
        sum_sec_diag += *(ptr + 4*(i+1));
        
    }

    switch (sum_main_diag - sum_sec_diag)
    {
    case 0:
        cout << "The diagonals add up to " << sum_main_diag << " \n";
        break;
    
    default:
        cout << "The main diagonal adds up to " << sum_main_diag <<\
         " while the secondary one does to " << sum_sec_diag << "\n";
        break;
    }
    
    return 0;
}
