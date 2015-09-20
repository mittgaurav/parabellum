#include <iostream>

/*
** Swap values at given locations in an array
*/
void swap(int arr[], int i, int j) {
    int temp = arr[ i ];
    arr[ i ] = arr[ j ];
    arr[ j ] = temp;
}

/*
** Print an array in given range
*/
void print(int arr[], int low, int high) {
    for(int i = low; i <= high; ++i) std::cout << arr[i] << "\t";
    std::cout << "\n";
}

// merge the sorted pieces of dup array into original array.
void merge(int arr[], int dup[], int low, int split, int high) {
    int i = low;
    int j = split;

    while(low <= high) {
        // we have exhausted the first part of array
        if( i >= split )            arr[low++] = dup[j++];
        // we have exhausted the second part of array
        else if( j >= high )        arr[low++] = dup[i++];
        // element to element comparison
        else if( dup[i] > dup[j] )  arr[low++] = dup[j++];
        else                        arr[low++] = dup[i++];
    }
}

// Divide et impera. Divide and conquer at its best. We break the array
// into two (or smaller, really) arrays and sort these arrays. Merging
// smaller arrays into a bigger sorted array is simple. Trust me...
// Only problem I see, must allocate arrays at all steps for merge. Uh!
// slow paced dance: https://www.youtube.com/watch?v=XaqR3G_NVoo.
void mergesortinternal(int arr[], int dup[], int low, int high) {
    if(high <= low) return;
    if(high - low == 1) {
        // Trivial solution for array length == 2. Induce henceforth.
        if(dup[high] < dup[low])
            swap(dup,high,low);
        arr[low] = dup[low];
        arr[high]= dup[high];
    }
    else {
        int split = (high + low + 1) / 2;
        mergesortinternal(arr, dup, low, split - 1);
        mergesortinternal(arr, dup, split, high);
    
        // merge the two pieces within dup into arr.
        merge(arr, dup, low, split, high);
    }

    // duplicate array into dup again.
    for(int i = low; i <= high; ++i) dup[i] = arr[i];
}

// merge sort requires duplicate array. Let's give it exactly that.
void mergesort(int arr[], int low, int high) {
    int *dup = new int[high + 1];
    for(int i = low; i <= high; ++i) dup[i] = arr[i];

    mergesortinternal(arr, dup, low, high);
    delete[] dup;
}

int main()
{
    int array[] = {4,6,7,5,3,1,2,8};
    print(array,0,7);
    mergesort(array,0,7);
    print(array,0,7);
}
