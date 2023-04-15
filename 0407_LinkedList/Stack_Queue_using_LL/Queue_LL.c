// front : 맨 앞 요소를 가르킴.
// 앞에선 큐의 front가 integer이어서 제일 앞 원소의 index -1을 가르켰는데,
// 여기선 그렇게 못하니까..
// rear : 맨 뒤의 요소를 가르킴.
// 공백 큐 : front = rear = NULL;

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int key;
} element;

typedef struct queue QP;
typedef struct queue {
    element item;
    QP *link;
};

QP *front;
QP *rear;

void addq(element item, QP *temp) {
    // 하나의 큐에 노드 temp를 삽입하기.
    temp->item = item;
    temp->link = NULL;
    if (front) { // non-empty queue
        rear->link = temp;
        // rear의 link를 수정함.
        // rear = temp 한다고
        // rear->link도 temp->link가 되지는 않음.
    } else { // empty queue
        front = temp;
    }
    rear = temp;
    // rear는 포인터라 기존에 rear이 포인팅하던건 바뀌지 않음.
}

element deleteq() {
    QP *temp = front;
    element item;
    front = temp->link;
    item = temp->item;
    free(temp);
    return item;
}