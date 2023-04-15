#include <stdio.h>
#define MAX_STACK_SIZE 100

typedef struct{
	int key;
} element;

typedef struct{
	int top; // the top index of 
	element stack[MAX_STACK_SIZE];
} Stack;

int isEmpty(Stack s){
	return s.top < 0;
}

int isFull(Stack s){
	return s.top >= MAX_STACK_SIZE - 1;
}

void stackFull(){
	fprintf(stderr, "Stack is full, cannot add element");
	exit(0);
}

void push(Stack s, element item){
	if(s.top >= MAX_STACK_SIZE - 1){
		stackFull();
		return;
	}
	s.stack[++(s.top)] = item;
}

void stackEmpty(){
	fprintf(stderr, "Stack is empty, cannot remove element\n");
	exit(0);
}

element pop(Stack s){
	if(s.top == -1){
		stackEmpty();
		return s.stack[0];
	}
	return s.stack[(s.top)--];
}