/*
    We are proposed to store the elements of a sparse array:

    A : [[0 0 6 8] -> B : [0 2 6; 0 3 8; 1 3 -1; 2 0 -3] 
        [0 0 0 -1]  
        [-3 0 0 0]]


*/
#include <iostream>

using std::cout;
using std::cin;

int main()
{

    const unsigned int ROWS = 3;
    const unsigned int COLS = 4;
    unsigned int non_zero_count = 0;
    int array[ROWS][COLS] = {{0, 0, 6, 8},
                            {0, 0, 0, -1},
                            {-3, 0, 0, 0}};
    int *ptr;
    unsigned int position = 0;

    for (unsigned int i = 0; i < ROWS * COLS; ++i)
    {
        non_zero_count += (*(*array + i) != 0);
    }

    ptr = new int[non_zero_count * 3];
    
    for (unsigned int row = 0; row < ROWS; ++row)
    {
        for (unsigned int col = 0; col < COLS; ++col)
        {
            if (array[row][col])
            {
                *(ptr + position++) = (int)row;
                *(ptr + position++) = (int)col;
                *(ptr + position++) = array[row][col];
            }
        }
    }

    cout << "B = { ";
    for (unsigned int i = 0; i < (non_zero_count * 3); ++i)
    {
        cout << *(ptr + i) << " ";
    }
    cout << "} \n";

    return 0;
}