#include <iostream>
using namespace std;

size_t partition(int* arr, size_t i, size_t j) {
    if(i > j) return -1;
    if(i == j) return i;
    
    size_t pivot = i;
    i++;
    while(i <= j) {
        if(arr[i] > arr[pivot]) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            j--;
        }
        else {
            i++;
        }
    }
    int temp = arr[pivot];
    arr[pivot] = arr[j];
    arr[j] = temp;
    
    return j;
}

int main()
{
    int arr[] = {4, 5, 3, 6, 2, 7, 1, 9, 8, 10};
    for(size_t i = 0; i <= 9; ++i)
        std::cout << arr[i] << " ";
    std::cout << std::endl;

    for(int k = 0; k < 10; k++) {
        int i = 0;
        int j = 9;
        while( true ) {
            int p = partition(arr, i, j);
            if(p == k) break;
            if(p < k) i = p+1;
            if(p > k) j = p-1;
        }
        
        std::cout << k+1 << "th " << arr[k] << std::endl;
    }
}
