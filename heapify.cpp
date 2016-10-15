// Heapify
#include <iostream>
// ====== print array
template< class T >
void print( T* arr, size_t n ) {
    for( size_t i = 0; i < n; ++i ) 
        std::cout << arr[ i ] << ",";
    std::cout << "\n";
}

// ====== swap around elements
template< class T >
void swap( T* a, T* b ) {
    T t = *a;
    *a  = *b;
    *b  = t;
}

template< class T >
T* swapAndRetNewLoc( T* parent, T* boy, T* girl ) {
    if( girl && *girl > *boy ) boy = girl;
    if( boy  && *boy  > *parent ) {
        swap( boy, parent );
        return boy;
    }
    else 
        return parent;
}

// ====== functions to create heap
template< class T >
void heapify( T* arr, size_t n, size_t index ) {
    if( index >= n ) return;

    T* node = arr + index;
    T* a    = index * 2 + 1 < n ? arr + index * 2 + 1 : 0;
    T* b    = index * 2 + 2 < n ? arr + index * 2 + 2 : 0;

    T* newN = swapAndRetNewLoc( node, a, b );
    if( newN > node )
        heapify( arr, n, newN - arr );
}

template< class T >
void build( T* arr, size_t n ) {
    size_t parent = n / 2 - 1;
    do heapify( arr, n, parent );
    while( parent-- > 0 );
}

// ====== main
int main() {
    int arr[] = { 60, 100, 20, 40, 1, 2, 57, 65, 200 };
    size_t size = sizeof( arr ) / sizeof( arr[ 0 ] );
    print( arr, size );
    build( arr, size );
    print( arr, size );
}