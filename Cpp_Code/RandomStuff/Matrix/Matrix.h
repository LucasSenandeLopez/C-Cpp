#ifndef ODR_check
#define ODR_check

#include <iostream>

using std::cout;

template <typename T, long unsigned int ROWS,long unsigned int COLS> void swap_rows(T (&matrix)[ROWS][COLS],\
long unsigned int former_row, long unsigned int new_row);

template <typename T, long unsigned int ROWS,long unsigned int COLS> void print_matrix(T (&matrix)[ROWS][COLS]);
template <typename T, long unsigned int COLS> T determinant(T (&matrix)[COLS][COLS]);

template <typename T> int is_near_zero(T num){return (num <= (T)0.0001 && num >= (T)-0.0001);}



template <typename T, long unsigned int ROWS,long unsigned int COLS> void swap_rows(T (&matrix)[ROWS][COLS],\
long unsigned int former_row, long unsigned int new_row)
{
    T temp;

    for (long unsigned int col = 0; col < COLS; ++col)
    {
        temp = std::move(matrix[new_row][col]);
        matrix[new_row][col] = std::move(matrix[former_row][col]);
        matrix[former_row][col] = std::move(temp);
    }

    return;
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
    int flag = 1;

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
            cout << "Element near zero\n";
            
            for (long unsigned int row_swap = row + 1; row_swap < COLS; ++row_swap)
            {
                if(!(is_near_zero(det_mat[row_swap][row])))
                {
                    swap_rows(det_mat, row, row_swap);
                    sign *= -1;
                    flag = 0;
                    break;
                }
            }
            if (flag){return T(0);}
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


#endif