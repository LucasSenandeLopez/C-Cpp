#include <stdio.h>


int remove_duplicates(int arr[], int len_arr);

int main(){

    int n_array[] = {1, 2, 2, 3, 4, 5, 5, 6, 7, 9, 14, 15, 15, 15, 15, 16, 19, 20};
    int length_array = sizeof(n_array)/sizeof(n_array[0]);
    int uniques = remove_duplicates(n_array, length_array);
    printf("uniques: %d\n", uniques);

    for(int i = 0; i < length_array; i++){
        printf("%d ",n_array[i]);
    }

    return 0;
}


int remove_duplicates(int arr[], int len_arr){

    int n_unique = 1;
    int idx_nonunique = 0;
    for (long idx = 0; idx < len_arr; idx++) {

        if (arr[idx] > arr[idx_nonunique]) {

            n_unique++;
            idx_nonunique++;
            arr[idx_nonunique] = arr[idx];

        } 

    }
    return n_unique;
}