#include <stdio.h>

typedef struct listNode NODE;
typedef struct listNode {
    int data;
    NODE *link
};

NODE* invert(NODE *head){
	NODE *current, *next, *previous;
	
	current = head;
	next = previous = NULL;

	while(current){
		next = current->link;
		current->link = previous;
		previous = current;
		current = next;
	}

	head = previous;
	return head;
}