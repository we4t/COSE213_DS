/*
삽입 정렬
시작 상태 : 배열의 첫 번째 원소만이 정렬됨.
배열을 정렬된 부분과 정렬 안 된 부분으로 나누고,
정렬 안 된 부분의 가장 왼쪽 원소를
정렬된 부분의 적절한 위치에 계속 삽입하는 방식
best case : insert()에서 while이 한 번에 깨질 때
-> 이미 정렬됨 :  O(n)
worst case : insert()에서 while이 전부 이동할 때
-> 역순으로 정렬됨 : O(n^2)

LOO인 것들만 옮기면 됨 : 전부 옮길 필요 없다!
-> R[i] is Loo when a[i] is not the maximum element
Computing time : 
LOO의 개수가 K : O(kn)
*/

typedef struct {
    int key;
} element;

void insert(element e, element a[], int i) {
    // i : 정렬된 개수
    // precondition :
    // first index starts at 1
    a[0] = e;
    while (e.key < a[i].key) {
        a[i + 1] = a[i];
        i--;
    }
    a[i + 1] = e;
}

void insertionSort(element a[], int n) {
    // precondition :
    // index : 1~n
    int j;
    for (j = 2; j <= n; j++) {
        // j : 삽입할 원소의 index
        element tmp = a[j];
        insert(tmp, a, j - 1);
    }
}

