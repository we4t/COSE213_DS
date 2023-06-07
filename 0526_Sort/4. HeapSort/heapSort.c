/*
1. 입력받은 걸 하나씩 힙에 넣음.
2. 힙에서 하나씩 빼서 n-i에 넣음.
끝!

1. 리스트를 배열에 저장해서 힙을 구성.
2. 힙에서 n개의 데이터를 삭제하고 힙을 재구성하는 과정 반복
3. 2에서 삭제된 노드를 차례로 배열에 저장하면 정렬된 리스트가 됨.

힙 재구성 : adjust
O(log n)

-> adjust n 번 반복 : O(n log n)

리스트를 배열
*/

typedef struct {
    int key;
} element;

void adjust(element a[], int root, int n) {
	// root에서 leaf 까지 부모/자식 값 비교
    int child, rootkey;
    element tmp;
    tmp = a[root];
    rootkey = a[root].key;
    child = 2 * root;
	// a[root]에 있는 값을 제대로 넣는 과정.
    while (child <= n) {
		// O(log n)
        if (child < n && a[child].key < a[child + 1].key) {
            child++;
			// 더 큰 key 값 가지는 자식 찾기.
        }
        if (rootkey > a[child].key) {
			// 부모가 올바른 위치에 있음.
            break;
        } else {
			// 자식 값이 더 큼.
			// 자식 값을 부모 위치로 이동.
            a[child / 2] = a[child];
			// child 값을 2배 시켜서 부모값을 저장할 노드를 찾기.
            child *= 2;
        }
    }
    a[child / 2] = tmp;
}

void heapSort(element a[], int n){
	// precondition : index starts at 1
	// index : 1 ~ n
	// outcome : a[1]~ a[n] is ordered in ascending order
	int i, j;
	element tmp;
	for(i = n/2; i > 0; i--){
		adjust(a, i, n);
	}
	for(i = n-1; i > 0; i--){
		swap(&a[1], &a[i+1], tmp);
		// a[1]은 최대값.
		// a[i+1]과 바꿔서
		// a[i+1] ~ a[n]은 정렬되어있는 상태로, 
		// a[1] ~ a[i] 까지를 다시 heapify함.
		adjust(a, 1, i);
	}
}