#include <iostream>
#include <cstdlib>
#include <ctime>
#include "/home/fedesuarez/Documents/C-Cpp/Cpp_Code/RandomStuff/Matrix/Matrix.h"

using std::cout;
using std::cin;


int main()
{
    float matrix[5][5] = {0.0f};
    float result = float(0);
    long unsigned int rows = sizeof(matrix)/(sizeof(matrix[0]));
    long unsigned int cols = sizeof(matrix)/(rows*sizeof(matrix[0][0]));
   
   
    srand((unsigned int)time(NULL));

    for (long unsigned int row = 0; row < rows; ++row)
    {
        for (long unsigned int col = 0; col < cols; ++col)
        {
            matrix[row][col] = float(rand() % 9);
        }
    }
    

    result = determinant(matrix);
    cout << "Rows: " << rows << " Cols: " << cols << "\n";
    cout << "The determinant is " << result << "\n";


    return 0;
}



