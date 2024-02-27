#include <stdio.h>
#include <stdlib.h>

int main(){

    
    // Select the number of rows (which is also max nº of columns) by changing the varianble n_rows
    unsigned long n_rows = 5;

    int** triag_pointer = (int** ) malloc(n_rows * sizeof(int*));

    // Fill the first and last member of the row with 1; 
    for(unsigned long i = 0; i < n_rows; i++){

        triag_pointer[i] = (int* ) malloc((i + 1) * sizeof(int));
        triag_pointer[i][0] = 1;
        triag_pointer[i][i] = 1;
    }
    
    // Create the triangle itself, O(n^2)
    for(unsigned long row = 2; row < n_rows; row++){

        for(unsigned long col = 1; col < row; col++){

            triag_pointer[row][col] = triag_pointer[row - 1][col - 1] + triag_pointer[row - 1][col];
        }

    }

    /*Prints the base of the triangle, technically unnecessary 
    for the algortithmbut nice to show the results*/    
    for(unsigned long col = 0; col < n_rows; col++){

        printf("%d ", triag_pointer[n_rows - 1][col]);

    }

    


    // Frees the memory holding triangle 
    for(unsigned long row = 0; row < n_rows; row++){

        free(triag_pointer[row]);
    }
    
    free(triag_pointer);

    return 0;
}