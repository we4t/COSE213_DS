#include <stdio.h>

typedef struct listNode NODE;
struct listNode{
	int data;
	NODE *link
};

void insertFront(NODE *last, NODE *node){
	// last 다음에 node 붙이기.
	if(!last){
		last = node;
		node->link = node;
	}
	else{
		node->link = last->link;
		last->link = node;
	}
}

int length(NODE *last){
	NODE *temp;
	int cnt = 0;
	if(!last){
		temp = last;
		do{
			cnt++;
			temp = temp->link;
		}
		while(temp != last);
	}
	return cnt;
}