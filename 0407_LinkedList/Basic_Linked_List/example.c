#include <stdio.h>
#include <stdlib.h>

#define IS_EMPTY(first) (!(first)))

typedef struct listNode listPointer;
// typedef struct listNode *listPointer;

// typedef struct listNode
struct listNode{
	char data[4];
	listPointer *link;
};

listPointer *first = NULL;
// listPOinter first = NULL;

int main(void){
	first = malloc(sizeof(*first));
	strcpy(first->data, "Bat");
	first -> link = NULL;
}