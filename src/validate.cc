
bool is_sorted(long arr[], int size) {
    if (size <= 1) {
        return true; // An array with 0 or 1 element is considered sorted
    }
    for (int i = 0; i < size - 1; i++) {
        long element = arr[i];
        long next_element = arr[i + 1];
        if (element > next_element) {
            return false; // Array is not sorted
        }
    }
    return true; // Array is sorted
}