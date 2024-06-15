#ifndef ODR_check
#define ODR_check

#include <iostream>
#include <cstring>
#include <iomanip>

using std::cout;



namespace Matrix_nmp
{
typedef long unsigned int luint;

template <typename T> int is_near_zero(T num){return (num <= (T)0.0001 && num >= (T)-0.0001);}

template <typename T, luint ROWS_A, luint ROWS_B,\
 luint COLS_A, luint COLS_B>\
  void matmul(T (&mat_A)[ROWS_A][COLS_A], T(&mat_B)[ROWS_B][COLS_B], T(&res_mat)[ROWS_A][COLS_B]);

template <typename T, luint ROWS, luint COLS> void swap_rws(T (&mat)[ROWS][COLS], luint former_row, luint new_row);


template <typename T, luint ROWS_A, luint ROWS_B,\
 luint COLS_A, luint COLS_B>\
 void matmul(T (&mat_A)[ROWS_A][COLS_A], T(&mat_B)[ROWS_B][COLS_B], T(&res_mat)[ROWS_A][COLS_B])
{

    T num = 0;
    luint row_A;
    luint col_B;

    for (row_A = 0; row_A < ROWS_A; ++row_A)
    {
        for (col_B = 0; col_B < COLS_B; ++col_B)
        {
            for(luint i = 0; i < ROWS_B; ++i)
            {
                num += mat_A[row_A][i] * mat_B[i][col_B];
            }

            res_mat[row_A][col_B] = num;
            num = T(0);

        }  
    }

    return;
}


template <typename T, luint ROWS, luint COLS> class Matrix
{
private:
    T matrix[ROWS][COLS];
    T determinant;
    bool have_det = false;
public:
    
    Matrix(T *ptr);
    Matrix(const T(& mat)[ROWS][COLS])
    {
        for(luint row = 0; row < ROWS; ++row)
        {
            for(luint col = 0; col < COLS; ++col)
            {
                matrix[row][col] = mat[row][col];
            }
        }
    }
    void print() const;
    void swap_rows(luint row_1, luint row_2);
    void swap_cols(luint col_1, luint col_2);
    T get_determinant();
    T*& operator[](luint idx);
    
    Matrix<T, ROWS, COLS> operator+(T num); 
    Matrix<T, ROWS, COLS> operator+(Matrix<T, ROWS, COLS> mat); 
    Matrix<T, ROWS, COLS> operator+(Matrix<T, 1, COLS>& row_vector); 
    Matrix<T, ROWS, COLS> operator+(Matrix<T, ROWS, 1>& col_vector); 
   
};

template <typename T, luint ROWS, luint COLS> T*& Matrix<T, ROWS, COLS>::operator[](luint idx)
{
    return matrix[idx];
}

template <typename T, luint ROWS, luint COLS> Matrix<T, ROWS, COLS>::Matrix(T *ptr)
{
    luint el = 0;
    for(luint row = 0; row != ROWS; ++row)
    {
        for(luint col = 0; col != COLS; ++col)
        {
            matrix[row][col] = ptr[el++];
        }
    }
};

template <typename T, luint ROWS, luint COLS> void Matrix<T, ROWS, COLS>::print() const
{
    std::cout << "{\n";
    for (luint row = 0; row < ROWS; ++row)
    {
        std::cout << "{  ";
        for (luint col = 0; col < COLS; ++col)
        {
            std::cout << std::fixed << std::setprecision(2) << matrix[row][col] << "  ";
        }
        std::cout << "}\n";
    }
    std::cout << "}" << ROWS << "x" << COLS << "\n" << std::endl; 

};

template <typename T, luint ROWS,luint COLS> void swap_rws(T (&mat)[ROWS][COLS],\
    luint former_row, luint new_row)
{
    T temp;

    for (luint col = 0; col < COLS; ++col)
    {
        temp = std::move(mat[new_row][col]);
        mat[new_row][col] = std::move(mat[former_row][col]);
        mat[former_row][col] = std::move(temp);
    }

    return;
}

template <typename T, long unsigned ROWS, long unsigned COLS> void Matrix<T, ROWS, COLS>::swap_rows(luint row_1, luint row_2)
{
    luint idx_col;
    T temp;
    if (row_1 >= ROWS || row_2 >= ROWS){throw "Index Error; there are not as many rows";}
    
    for (idx_col = 0; idx_col < COLS; ++idx_col)
    {
        temp = matrix[row_2][idx_col];
        matrix[row_2][idx_col] = matrix[row_1][idx_col];
        matrix[row_1][idx_col] = temp;
    }

}

template <typename T, long unsigned ROWS, long unsigned COLS> void Matrix<T, ROWS, COLS>::swap_cols(luint col_1, luint col_2)
{
    luint idx_row;
    T temp;
    if (col_1 >= COLS || col_2 >= COLS){throw "Index Error; there are not as many columns";}
    
    for (idx_row = 0; idx_row < ROWS; ++idx_row)
    {
        temp = matrix[idx_row][col_2];
        matrix[idx_row][col_2] = matrix[idx_row][col_1];
        matrix[idx_row][col_1] = temp;
    }

}

template <typename T, long unsigned ROWS, long unsigned COLS> T Matrix<T, ROWS, COLS>::get_determinant()
{

    if(have_det == true){return determinant;}

    if (ROWS != COLS){throw "Dimension Mismatch";}

    T det_mat[COLS][COLS];
    int sign = 1;
    T new_row_times_last = 0;
    T result = T(1);
    int flag = 1;

    for (luint row = 0; row < COLS; ++row)
    {
        for(luint col = 0; col < COLS; ++col)
        {
            det_mat[row][col] = matrix[row][col];
        }
    }


    for(luint row = 0; row < COLS; ++row)
    {
        if (is_near_zero(det_mat[row][row]))
        {
            
            for (luint row_swap = row + 1; row_swap < COLS; ++row_swap)
            {
                if(!(is_near_zero(det_mat[row_swap][row])))
                {
                    swap_rws(det_mat, row, row_swap);
                    sign *= -1;
                    flag = 0;
                    break;
                }
            }
            if (flag){return T(0);}
        }
    


        for(luint next_row = row + 1; next_row < COLS; ++next_row)
        {
            new_row_times_last = det_mat[next_row][row] / det_mat[row][row];

            for(luint col = 0; col < COLS; ++col)
            {
                det_mat[next_row][col] -= new_row_times_last*det_mat[row][col];
            }
        }
        result *= det_mat[row][row];
    }

    have_det = true;
    determinant = (T)sign * result;
    return determinant;

}

template <typename T, long unsigned ROWS, long unsigned COLS> Matrix<T, ROWS, COLS> Matrix<T, ROWS, COLS>::operator+(T num)
{

    Matrix<T, ROWS, COLS> mat = *this;

    luint row;
    luint col;

    for (row = 0; row < ROWS; ++row)
    {
        for(col = 0; col < COLS; ++col)
        {
            mat.matrix[row][col] += num;
        }
    }

    return mat;

}

template <typename T, long unsigned ROWS, long unsigned COLS> Matrix<T, ROWS, COLS> Matrix<T, ROWS, COLS>::operator+(Matrix<T, ROWS, COLS> mat)
{

    Matrix<T, ROWS, COLS> mat_2 = *this;

    luint row;
    luint col;

    for (row = 0; row < ROWS; ++row)
    {
        for(col = 0; col < COLS; ++col)
        {
            mat_2.matrix[row][col] += mat.matrix[row][col];
        }
    }

    return mat_2;

}





}

#endif