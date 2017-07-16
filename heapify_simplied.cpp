// Heapify
#include <iostream>

// ====== print array
template< class T >
void print( T* arr, size_t n ) {
    for( size_t i = 0; i < n; ++i ) {
        std::cout << arr[ i ] << " ";
    }
    std::cout << std::endl;
}

// ====== swap around elements
template< class T >
void swap( T* arr, size_t a, size_t b ) {
    T t = arr[ a ];
    arr[ a ] = arr[ b ];
    arr[ b ] = t;
}

// ====== functions to create heap
template< class T >
void heapify( T* arr, size_t n ) {
    size_t parent;
    while( ( parent = ( n - 1 ) / 2 ) >= 0 && arr[ n ] > arr[ parent ] ) {
        swap( arr, n, parent );
    }
}

template< class T >
void build( T* arr, size_t n ) {
    for( int i = 1; i < n; ++i ) {
        heapify( arr, i );
    }
}

// ====== main
int main() {
    int arr[] = { 60, 100, 20, 40, 1, 2, 57, 65, 200 };
    size_t size = sizeof( arr ) / sizeof( arr[ 0 ] );
    print( arr, size );
    build( arr, size );
    print( arr, size );
}