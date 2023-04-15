#include <stdio.h>
#include <stdlib.h>

#define MAX_STACKS 10

typedef struct {
    int key;
} element;

typedef struct stack SP;
typedef struct stack {
    element item;
    SP *link;
};

SP *top[MAX_STACKS]; // top이 여러 개

void push(int i, element item){
	// i 번째 스택에 item 추가.
	// top[i] 가 가르키는게 스택 top.
	// item을 top으로 바꾸기.
	SP *temp;
	temp = malloc(sizeof(SP));
	temp->item = item;
	temp->link = top[i];
	top[i] = temp;
}

element pop(int i){
	SP *temp = top[i];
	// 굳이 temp 쓰는 이유는 top[i]를 없앨려고.
	element item;

	if(!temp)
		{
			// return stackEmpty();
			1;
		}	
	item = temp->item;
	top[i] = temp->link;
	free(temp);

	return item;	
}