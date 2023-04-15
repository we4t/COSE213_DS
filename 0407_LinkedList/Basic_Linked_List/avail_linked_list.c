#include <stdio.h>
#include <stdlib.h>

// 이미 존재하는 노드들을 변수들에게 하나씩 나누어주는 방식.
// 하나씩 줄 때 가르킬 노드를 avail로 표현.
// avail은 이미 존재하고 나누어줄, 그리고 사용할 수 있는 노드를 가르킴.
// malloc()을 안 쓰고 getNode, free() 대신 retNode()

typedef struct POLY polyPointer;
typedef struct POLY {
    int data;
    polyPointer *link;
};

polyPointer *avail;

polyPointer *getNode(void) {
	// avail에서 노드 받아오기
    polyPointer *node;

    if (avail) {
        node = avail;
        avail = avail->link;
    } else
        node = (polyPointer *)malloc(sizeof(polyPointer));

    return node;
}

void retNode(polyPointer *ptr) {
	// ptr을 avail에 반환
    ptr->link = avail;
	// 현재 avail이 가르키고 있는 가용 연결 리스트의 제일 앞부분을 ptr로 엮고
    avail = ptr;
	// avail을 앞에다 둠.
}

void cerase(polyPointer *ptr){
	// ptr이 가리키는 원형 연결 리스트를 avail에 반환
	// ptr은 원형리스트에서 제일 마지막 부분.
	polyPointer *temp;
	if(ptr){
		temp = ptr->link; // 원형리스트라 temp는 제일 앞에 노드 가르킴.
		ptr->link = avail; // 현재 avail한 노드로 바꿔치기.
		avail = temp; // avail이 제일 앞 노드를 가르키게 바꿔치기
		ptr = NULL;
	}
}
