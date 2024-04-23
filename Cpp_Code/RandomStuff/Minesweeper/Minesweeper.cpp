#include <cstdlib>
#include <iostream>
#include "./ShowingFunctions.h"



extern const int ROWS;
extern const int COLS;

using std::cout;
using std::cin;


int main()
{
    unsigned short difficulty;
    short field[ROWS][COLS];
    short shown_minefield[ROWS][COLS];
    unsigned short row_to_reveal;
    unsigned short col_to_reveal;
    int win_condition = 0;
    int* ptr_win_condition = &win_condition;
    
    //short break_code;


    do
    {
        cout << "Insert the difficulty level from 1 to 7: \n";
        cin >> difficulty;

    } while (difficulty < 1 || difficulty > 7);
    

    difficulty = 8 - difficulty;

    srand(1);

    // Fills the mines
    for (int i = 0; i < COLS * ROWS; ++i)
    {
        *(field[0] + i) = ((rand() % 9) > difficulty);
        *(shown_minefield[0] + i) = 9;

        win_condition += *(field[0] + i);
    }

    // We summed the ones before, doing this we get the zeroes
    win_condition = COLS * ROWS - win_condition; 
    
    do
    {
        cout << "You need to clear " << win_condition << " cells to win. \n";

        do
        {
            cout << "Input the row you'd like to reveal (From 1 to " << COLS << "): ";
            cin >> row_to_reveal;

            cout << "Now enter the column you'd like to reveal (From 1 to 9): ";
            cin >> col_to_reveal;

        } while (row_to_reveal > ROWS || col_to_reveal > COLS);
    
        number_mines(row_to_reveal, col_to_reveal, field, shown_minefield, ptr_win_condition);

    } while (win_condition); 

    return 0;
}

