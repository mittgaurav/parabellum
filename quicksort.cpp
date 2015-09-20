#include <iostream>

/*
** Swap values at given locations in an array
*/
void swap(int arr[], int i, int j) {
    int temp = arr[ i ];
    arr[ i ] = arr[ j ];
    arr[ j ] = temp;
}

// I just take the first int, and then find its rightful place in the array.
// Swap them as I go ahead - it swaps its place with larger/smaller number.
// Based on this beautiful dance - www.youtube.com/watch?v=ywWBy6J5gz8.
// Number of swaps: worst case is still n^2 swaps. Average case, n*log n.
void quicksort(int arr[], int low, int high) {
    if(high <= low) return;

    int n = low;
    int l = low;
    int h = high;

    // first find the first smaller num from the end and swap.
    // then, find the first larger num from the start and swap.
    // keep doing this till your legs give out and can no more.
    for(int i = 0; i <= high - low; ++i) {
        if(n <= l) {
            if(arr[n] > arr[h]) {
                // low has reached a number smaller than pivot.
                swap(arr,n,h);
                n = h;
            }
            --h;
        }
        else if(n >= h) {
            if(arr[n] < arr[l]) {
                // high has reached a number larger than pivot.
                swap(arr,n,l);
                n = l;
            }
            ++l;
        }
        else
            break;
    }

    // we have broken the array into two pieces, the first piece
    // has all elements smaller than arr[ n ]; the second one,
    // larger than arr[ n ]. Now, sort them independently.
    quicksort(arr,low,n-1);
    quicksort(arr,n+1,high);
}

/*
** Print an array in given range
*/
void print(int arr[], int low, int high) {
    for(int i = low; i <= high; ++i) std::cout << arr[i] << "\t";
    std::cout << "\n";
}

int main()
{
    int array[] = {4,6,7,5,3,1,2,8};
    print(array,0,7);
    quicksort(array,0,7);
    print(array,0,7);
}
