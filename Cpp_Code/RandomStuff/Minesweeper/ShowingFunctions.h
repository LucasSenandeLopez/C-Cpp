
#include <iostream>
using std::cout;
using std::cin;


static const int ROWS = 5;
static const int COLS = ROWS;



void print_minefield(short field[ROWS][COLS])
{
    cout << ' ' << ' ' << ' '; // Formats column headers

    for (int col = 0; col < COLS; ++col) {cout << col + 1 << 'C' << ' ';}

    cout << '\n';

    for (int row = 0; row < ROWS; ++row)
    {
        cout << row + 1 << 'R'<< ' ';

       for (int col = 0; col < COLS; ++col)
        {
            if (field[row][col] != 9)
            {
                cout << field[row][col] << ' ' << ' ';
            } else {

                cout << '*' << ' ' << ' '; 
            }
            

        } 
        cout << '\n';
    }


    return;
}

void number_mines(unsigned short input_row, unsigned short input_col,\
    short minefield[ROWS][COLS], short shown_minefield[ROWS][COLS], int* ptr_win_cond)
{
    short count = 0;

    --input_row;
    --input_col;

    if (minefield[input_row][input_col])
    {
        print_minefield(minefield);

        cout << "\nYou fell on a mine!\n";

        *ptr_win_cond = 0;
        return;
    }

    if(input_row)
    {
        count += minefield[input_row - 1][input_col];

        if(input_col)
        {
            count += minefield[input_row - 1][input_col - 1];   
        }   
    }

    if (input_row != (ROWS - 1))
    {
        count += minefield[input_row + 1][input_col];

        if (input_col != (COLS - 1))
        {
            count += minefield[input_row + 1][input_col + 1];
        }
    }

    if (input_col)
    {
        count += minefield[input_row][input_col - 1];
        if (input_row != (ROWS - 1))
        {
            count += minefield[input_row + 1][input_col - 1]; 
        }
    }

    if (input_col != (COLS - 1))
    {
        count += minefield[input_row][input_col + 1];

        if (input_row)
        {
            count += minefield[input_row - 1][input_col + 1];
        }
    }

    if (shown_minefield[input_row][input_col] == 9){--(*ptr_win_cond);}

    if(*ptr_win_cond)
    {
        shown_minefield[input_row][input_col] = count; 

        print_minefield(shown_minefield);

    } else {

        cout << "You win!";
        print_minefield(minefield);
    }
    
    return;
}