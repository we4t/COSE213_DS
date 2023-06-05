#include <stdio.h>

#define MAX_ElEMENTS 200
#define HEAP_FULL(n) (n == MAX_ElEMENTS - 1)
#define HEAP_EMPTY(n) (!n)

typedef struct {
    int key;
} element;

element heap[MAX_ElEMENTS];
int n = 0;

void push(element item, int n) {
    int i;
    if (HEAP_FULL(n)) {
        printf("heap is full. \n");
        return;
    }
    i = ++n;
    while ((i != 1) && (item.key > heap[i / 2].key)) {
        heap[i] = heap[i / 2];
        i /= 2;
    }
	heap[i] = item;
}

element pop(int n){
	/*
	1번 요소를 pop 하고
	n번 요소를 올바른 자리에 삽입함과 동시에
	1번 노드를 제거하면서 1번과 연결된 요소들을 재구성 
	*/
	int parent, child;
	element item, temp;
	if(HEAP_EMPTY(n)){
		printf("Empty heap.\n");
	}
	item = heap[1];
	temp = heap[(n)--];
	parent = 1;
	child = 2;
	while(child <= n){
		if( (child < n) && (heap[child].key < heap[child+1].key))
			child++; // 큰 놈을 고른다.
		if( temp.key >= heap[child].key) break;
		// temp 보다 루트 노드의 자식 노드보다 작으면 바꿀 준비 완료.
		heap[parent] = heap[child]; // child 값을 parent에 복사.
		parent = child;
		child *= 2;
	}
	heap[parent] = temp;
	return item;
}