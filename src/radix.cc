/*
 * radix.cc
 *
 *  Created on: Nov 12, 2026
 *      Author: caellum-heinlein
 */


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Stable counting sort of arr based on the digit at place value 'exp'
void countingSortByDigit(vector<long long>& arr, long long exp) {
    int n = arr.size();
    vector<long long> output(n);
    int count[10] = {0};

    // Count occurrences of each digit
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    // Convert counts to ending positions
    for (int d = 1; d < 10; d++)
        count[d] += count[d - 1];

    // Build output from the back to keep the sort stable
    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        output[--count[digit]] = arr[i];
    }

    arr = output;
}

void radixSort(vector<int>& arr) {
    if (arr.size() < 2) return;

    // Shift all values so they are non-negative
    int minVal = *min_element(arr.begin(), arr.end());
    vector<long long> shifted(arr.size());
    for (size_t i = 0; i < arr.size(); i++)
        shifted[i] = static_cast<long long>(arr[i]) - minVal;

    long long maxVal = *max_element(shifted.begin(), shifted.end());

    // Sort by each digit: 1s, 10s, 100s, ...
    for (long long exp = 1; maxVal / exp > 0; exp *= 10)
        countingSortByDigit(shifted, exp);

    // Shift back to original values
    for (size_t i = 0; i < arr.size(); i++)
        arr[i] = static_cast<int>(shifted[i] + minVal);
}


