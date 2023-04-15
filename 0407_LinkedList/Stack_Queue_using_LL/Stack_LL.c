#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int key;
} element;

typedef struct stack SP;
typedef struct stack
{
	element item;
	SP *link;
};

SP *top;

void push(element item, SP *temp){
	temp->item = item;
	temp->link = top;
	top = temp;
}

element pop(){
	SP *temp = top;
	element item;
	item = temp->item;
	top = temp->link;
	free(temp);
	return item;
}

