#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE 10

typedef struct {
    int key;
} element;

typedef struct queue QP;
typedef struct queue {
    element item;
    QP *link;
};

QP *front[MAX_QUEUE]; // top이 여러 개
QP *rear[MAX_QUEUE];

void addq(int i, element item){
	QP *temp = malloc(sizeof(QP));
	temp->item = item;
	temp->link = NULL;

	if(front[i]){ // 공백 큐가 아님.
		rear[i]->link = temp;
		// 포인터라 헷갈릴 수도 있음!
	}
	else{
		front[i] = temp;
	}
	rear[i] = temp;
	// 얘도 맞음!
}

element deleteq(int i){
	QP *temp = front[i];
	element item;

	if(!temp){ // 공백큐이면
		1;
	}

	item = temp->item;
	front[i] = temp->link;
	free(temp);

	return item;
}