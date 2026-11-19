#include <iostream> 
#include <vector>
#include "myheaders.h"
#include <algorithm>

using namespace std;

void combsort(long* arr, int n) {
    int gap = n;
    bool swapped = true;

    while (gap > 1 || swapped) {
        gap = gap * 10 / 13; // Shrink gap by a factor of 1.3
        if (gap < 1){ gap = 1;}

        swapped = false;
        for (int i = 0; i + gap < n; i++) {
            if (arr[i] > arr[i + gap]) {
                swap(arr[i], arr[i + gap]);
                swapped = true;
            }
        }
    }
}