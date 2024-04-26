/*
    NOTE: This implementatin was not made by me but by the author of "Introduction to C++",
    this is here as notes
*/

unsigned int quicksort_partition(int arr[], unsigned int left_ptr, unsigned int right_ptr);
void quick_sort(int arr[], unsigned int left_ptr, unsigned int right_ptr);

void quick_sort(int arr[], unsigned int left_ptr, unsigned int right_ptr)
{
    unsigned int left;

    /*
        Because this means that the right array is considered sorted, 
        as is the left array, thus we terminate
    */
    if (right_ptr <= left_ptr){return;} 

    left = quicksort_partition(arr, left_ptr, right_ptr);
    quick_sort(arr, left_ptr, left - 1);
    quick_sort(arr, left + 1, right_ptr);
    
}

unsigned int quicksort_partition(int arr[], unsigned int left_ptr, unsigned int right_ptr)
{
    unsigned int right = right_ptr - 1;
    unsigned int left = left_ptr;

    int rightmost_value = arr[right_ptr];
    int temp;

    while (1)
    {
        while (arr[left] < rightmost_value) 
        {   // If this happens, we move on because the element is correctly sorted
            ++left;
        }


        /*
            We move the right pointer only if the array is not sorted because
            that right pointer is the one we will exchange the last element with
        */
        while(arr[right] >= rightmost_value)
        {
            if(right == left_ptr){break;} // If the pointers cross, we terminate and exchange values (1)
            
            --right; 
        }

        if (right <= left){break;} // We only exit the loop when the pointers cross eachother (1)

        /*
            Because left and right only move when:
                arr[left] < rightmost_value
                arr[right] >= rightmost value

            If they have not crossed, it's because the element is incorrectly sorted as
            arr[left] > rightmost_value but right < rightmost_value, so they swap
    
        */
        temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;

    }

    /*
        Because the pointers have crossed, this only happens when left == right; 
        meaning that arr[left] >= arr[right_ptr]
    */
    temp = arr[left];
    arr[left] = arr[right_ptr];
    arr[right_ptr] = temp;
    
    return left;
}