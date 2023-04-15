#include <stdio.h>
#include <stdlib.h>

#define IS_EMPTY(ptr) (!(ptr))

typedef struct listNode NODE;
struct listNode {
    int data;
    NODE *link;
};

NODE *ptr;

NODE *create2() {
    NODE *first, *second;

    first = (NODE *)malloc(sizeof(NODE));
    second = (NODE *)malloc(sizeof(NODE));

    second->data = 20;
    second->link = NULL;

    first->data = 50;
    first->link = second;

    return first;
}

void insert(NODE *ptr, NODE *first) {
    // first 뒤에 새로운 노드 temp 설치하기.
    // first나 ptr이나 같은 객체 표시하려고 있음.
    // ptr은 연결리스트 전체를 순회하기 위해 표시하는 것 같고..
    // first는 꼭 첫 번째 노드를 표기하기 위해 두는 것 같은..
    // 그러니까, 왜 두 개나 뒀는지 ㅅㅂ 모르겠다 ㅋㅋ
    NODE *temp;
    temp = (NODE *)malloc(sizeof(NODE));
    temp->data = 50;
    if (ptr) {
        temp->link = first->link;
        first->link = temp;
    } else {
        temp->link = NULL;
        ptr = temp;
    }
}

void deletee(NODE *ptr, NODE *first, NODE *temp) {
    // first의 다음 노드 temp 삭제하기
    if (first) // first가 존재하는 리스트일 때
        first->link = temp->link;
    else // first 따윈 존재하지 않았고, 알고보니 temp가 첫 원소였을 떄
        ptr = ptr->link;
    free(temp);
}

void printList(NODE *ptr) {
    printf("노드 값 : \n");
    for (; ptr; ptr = ptr->link) {
        printf("%d\n", ptr->data);
    }
	printf("\n");
}

int main() {
    ptr = (NODE *)malloc(sizeof(NODE));

    return 0;
}