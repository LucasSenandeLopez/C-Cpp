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
   
    float mat_A[3][2] = {{1.0f, 2.0f}, 
                         {2.0f, 1.0f},
                         {1.0f, 2.0f}};

    float mat_B[2][3] = {{3.0f, 0.0f, 1.0f},
                         {1.0f, 0.0f, 3.0f}};

    float res_1[3][3];
    float res_2[2][2];

   
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


    matmul(mat_A, mat_B, res_1);

    print_matrix(res_1);

    matmul(mat_B, mat_A, res_2);

    print_matrix(res_2);


    Matrix<int, 2, 2> mat({{1, 2},{3, 4}});

    mat.print();

    return 0;
}



