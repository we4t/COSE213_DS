#include <stdio.h>

int recursion(int* cnt_p, int arr[], int n) {
    (*cnt_p)++; // for if conditional
    if (n) {
        (*cnt_p)++; // for return and sum invocation
        return recursion(cnt_p, arr, n - 1) + arr[n - 1]; // 명명을 cnt_p로 하지 않고 cnt로 할 경우 헷갈릴 수 있음.
    }
    // if n == 0, which is base case
    (*cnt_p)++; // for base case returning operation
    return arr[0];
}

int cnt_recursion_sum_ops(int arr[], int n) {
    int cnt = 0;
	recursion(&cnt, arr, n);
    return cnt;
}

int cnt_loop_sum_ops(int arr[]) {
    int count = 0, sum = 0;
    count++; // for assignment

    for (int i = 0; i < 100; i++) {
        count++; // for the loop
                 // 처음 실행할 때는 (int i = 0; i < 100) 문장이 실행되고,
                 // 실행 도중에는 (i < 100; i++) 문장이 실행되지만
                 // 하나의 실행 단위로 보아 count를 하나만 증가시키는 것으로
                 // 보임.

        sum += arr[i];
        count++; // for the assignment (sum 값 갱신)
    }
    count++; // for ending condition (조심!)

    count++; // for return
    return count;
}

int main(int argc, char *argv[]) {
    // time complexcity = compile time + run time
    // how to calculate run time
    // b. counting operations
    // 1. using count variable.

    int arr[100];
    for (int i = 0; i < 100; i++) {
        arr[i] = i;
    }
    printf("%d\n", cnt_loop_sum_ops(arr));
    printf("%d\n", cnt_recursion_sum_ops(arr, 100));

    return 0;
}