#include <stdio.h>

// todo

void linear_search(int arr[], int key) {
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < arr_size; i++) {
        if (arr[i] == key) {
            return;
        }
    }
}

void binary_search(int arr[], int key) {
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    int left = 0, right = arr_size - 1, middle;
    while (left <= right) {
        middle = (left + right) / 2;
        if (arr[middle] == key)
            return;
        else if (arr[middle] < key)
            left = middle + 1;
        else
            right = middle - 1;
    }
    return;
}

void test() {
    // linear, binary search
    int n = 2000000;
    int key = n; // worst case;
    int arr[n];
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }
    linear_search(arr, key);
    binary_search(arr, key);
}


int main(int argc, char *argv[]) {
    // time complexcity = compile time + run time
    // how to calculate run time
    // b. counting operations
    // 1. using count variable.

    test();

    return 0;
}
