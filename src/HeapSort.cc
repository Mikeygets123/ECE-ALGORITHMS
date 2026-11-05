#include "myheaders.h"

template <typename T>
void heapsort(T data[], int n){
    for (int i = n/2 - 1; i >= 0; --i){ //create the heap
        moveDown(data, i, n - 1);
    }
    for (int i = n - 1; i >= 1; --i){
        swap(data[0], data[i]);    //move the largest to the end
        moveDown(data, 0, i - 1);  //rebuild the heap
    }
}