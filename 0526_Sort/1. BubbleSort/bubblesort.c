/*
이웃하는 숫자를 비교하여 수를 이동.
패스 : 입력을 전체적으로 1번 처리하는 것.
첫번쨰 패스엔 arr[n-1]이 정렬됨
두번쨰 패스엔 arr[n-2]가 정렬됨.
....
n개의 데이터 정렬 : n-1번의 패스 진행.
->O(n*(n-1)/2) = O(n^2)

0. 50 40 90 10
1. 40 50 10 90
2. 40 10 50 90
3. 10 40 50 90
*/

typedef struct {
    int key;
} element;

void bubbleSort(element a[], int n) {
    int i, j, tmp;
    for (i = 1; i < n; i++) {
        for (j = 2; j <= n - i; j++) {
            if (a[j - 1].key > a[j].key) {
                tmp = a[j - 1].key;
                a[j - 1].key = a[j].key;
                a[j].key = tmp;
            }
        }
    }
}
