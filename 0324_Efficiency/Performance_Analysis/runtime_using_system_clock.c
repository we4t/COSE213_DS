#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
		if(arr[middle] == key) return;
		else if(arr[middle] < key) left = middle + 1;
		else right = middle - 1;
    }
	return;
}

int main(int argc, char *argv[]) {
    // time complexcity = compile time + run time
    // how to calculate run time
    // a. using system clock

    clock_t start, finish;
    double duration;
	int n = 2000000;
    int key = n; // worst case;
    int arr[n];
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }
    // 수행시간을 측정하고자 하는 코드
    // ex) linear search, binary search.
    start = clock();
    linear_search(arr, key);
    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    printf("선형 탐색 : %lf초 입니다\n", duration);
    start = clock();
    binary_search(arr, key);
    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    printf("이분 탐색 : %lf초 입니다\n", duration);

    return 0;
}