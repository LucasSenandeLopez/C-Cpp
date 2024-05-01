/*
    We are propsoed to implement the floodfill algorithm on a 8x8 matrix
*/
#include <iostream>
#include <cstdlib>

//using namespace std
using std::cout;
using std::cin;

const static unsigned int ROWS = 8;
const static unsigned int COLS = 8;
static unsigned int matrix[ROWS][COLS];

void floodfill(unsigned int row, unsigned int col, unsigned int new_color, unsigned int current_color);

int main()
{
    
    unsigned int sel_row;
    unsigned int sel_column;
    
    unsigned int sel_color;

    srand(1);

    for (unsigned int row = 0; row < ROWS; ++row)
    {
        for(unsigned int col = 0; col < COLS; ++col)
        {
            matrix[row][col] = (unsigned int)(rand() % 5);

            cout << matrix[row][col] << "  ";
        }

            cout << "\n";
    }

    cout << "\n";

    do
    {
        cout << "Enter the row and column you would like to paint: \n";
        cin >> sel_row >> sel_column;

    } while ((sel_row > ROWS || sel_column >> COLS) || !(sel_row && sel_column));
    
    --sel_row;
    --sel_column;

    do
    {
        cout << "Selected a color as an integer in [0,4]: \n";
        cin >> sel_color;

    } while (sel_color > 4);
    
    floodfill(sel_row, sel_column, sel_color, matrix[sel_row][sel_column]);

    cout << "\n\n";

    for (unsigned int row = 0; row < ROWS; ++row)
    {
        for(unsigned int col = 0; col < COLS; ++col)
        {

            cout << matrix[row][col] << "  ";
        }

        cout << "\n";
    }


    return 0;
}

void floodfill(unsigned int row, unsigned int col, unsigned int new_color, unsigned int current_color)
{

    matrix[row][col] = new_color;

    if ((row) && (matrix[row - 1][col] == current_color))
    {
        floodfill(row - 1, col, new_color, current_color);
    }

    if ((col) && (matrix[row][col - 1] == current_color))
    {
        floodfill(row, col - 1, new_color, current_color);
    }

    if ((row < ROWS - 1) && (matrix[row + 1][col] == current_color))
    {
        floodfill(row + 1, col, new_color, current_color);
    }

    if ((col < COLS - 1) && (matrix[row][col + 1] == current_color))
    {
        floodfill(row, col + 1, new_color, current_color);
    }

    return;
}