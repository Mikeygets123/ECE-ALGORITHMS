#include "myheaders.h"

void heapsort(long data[], int n){
    for (int i = n/2 - 1; i >= 0; --i){ //create the heap
        moveDown(data, i, n - 1);
    }
    for (int i = n - 1; i >= 1; --i){
        swap(data[0], data[i]);    //move the largest to the end
        moveDown(data, 0, i - 1);  //rebuild the heap
    }
}

void moveDown(long data[], int first, int last){

    int largest;
    int left;
    int right;

    while (2 * first + 1 <= last) {

        left = 2 * first + 1;
        right = 2 * first + 2;

        largest = left;

        if (right <= last && data[right] > data[left]) {
            largest = right;
        }

        if (data[first] < data[largest]) {
            break;
        }

        swap(data[first], data[largest]);

        first = largest;
    }

}