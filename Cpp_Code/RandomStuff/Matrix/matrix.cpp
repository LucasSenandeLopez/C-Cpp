#include <iostream>
#include <cstdlib>
#include <algorithm>

using std::cout;
using std::cin;

template <typename T, long unsigned int ROWS,long unsigned int COLS> void print_matrix(T (&matrix)[ROWS][COLS]);
template <typename T, long unsigned int COLS> T determinant(T (&matrix)[COLS][COLS]);

template <typename T> int is_near_zero(T num){return (num <= (T)0.0001 && num >= (T)-0.0001);}
int main()
{
    float matrix[5][5] = {0.0};
    float result = float(0);
    long unsigned int rows = sizeof(matrix)/(sizeof(matrix[0]));
    long unsigned int cols = sizeof(matrix)/(rows*sizeof(matrix[0][0]));
   
    srand(1);

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


template <typename T, long unsigned int ROWS,long unsigned int COLS> void print_matrix(T (&matrix)[ROWS][COLS])
{
    std::cout << "{\n";
    for (long unsigned int row = 0; row < ROWS; ++row)
    {
        std::cout << "{  ";
        for (long unsigned int col = 0; col < COLS; ++col)
        {
            std::cout << matrix[row][col] << "  ";
        }
        std::cout << "}\n";
    }
    std::cout << "}\n\n";

    return;
}

template <typename T, const long unsigned int COLS> T determinant(T (&matrix)[COLS][COLS])
{
    T det_mat[COLS][COLS];
    int sign = 1;
    T new_row_times_last = 0;
    T result = T(1);


    for (long unsigned int row = 0; row < COLS; ++row)
    {
        for(long unsigned int col = 0; col < COLS; ++col)
        {
            det_mat[row][col] = matrix[row][col];
        }
    }


    for(long unsigned int row = 0; row < COLS; ++row)
    {
        if (is_near_zero(det_mat[row][row]))
        {
            cout << "Element near zero";
            sign *= -1;
            //switch_rows(); (This is going to be implemented soon)
        }

        for(long unsigned int next_row = row + 1; next_row < COLS; ++next_row)
        {
            new_row_times_last = det_mat[next_row][row] / det_mat[row][row];

            for(long unsigned int col = 0; col < COLS; ++col)
            {
                det_mat[next_row][col] -= new_row_times_last*det_mat[row][col];
            }
        }
        result *= det_mat[row][row];
    }

    print_matrix(matrix);

    return result * (T)sign;
}



