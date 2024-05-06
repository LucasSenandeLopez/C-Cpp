/*
    We are proposed to write a program that stores in dinamically allocated memory
    ten numbers and then do it again in a way depending on if you input 0 or 1.
    If 0, store them in reverse order
    If 1, store the negatives first
*/
#include <iostream>

//using namespace std
using std::cout;
using std::cin;

int main()
{
    double *ptr;
    ptr = new double[10];
    int selection;

    for (int i = 0; i < 10; ++i)
    {
        cout << "Input a double (" << i + 1 << "/10): \n";
        cin >> *(ptr + i);

    }

    double *n_ptr = new double[10];

    do
    {
        cout << "Enter 1 or 0: \n";
        cin >> selection;

    } while (selection != 1 && selection != 0);
    

    if(selection)
    {
        int count = 0;
        for(int i = 0; i < 10; ++i)
        {
            if (ptr[i] < 0) {++count;}
        }

        for (int i = 0, neg_pos = 0; i < 10; ++i)
        {
            
            if (ptr[i] < 0) 
            {
                n_ptr[neg_pos++] = ptr[i];

            } else {

                n_ptr[count++] = ptr[i];

            }
        }

    } else {

        for (int i = 9; i >= 0; --i)
        {

            n_ptr[i] = ptr[9 - i]; // Reverses the elements
        }

    }

    for (int i = 0; i < 10; ++i)
    {

        cout << n_ptr[i] << " ";
    }

    delete[] ptr;

    cout << "\n";
    return 0;
}