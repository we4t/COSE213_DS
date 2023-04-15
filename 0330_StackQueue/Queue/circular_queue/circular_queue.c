#include <stdio.h>

#define MAX_STACK_SIZE 100

typedef struct {
    int key;
} element;

element queue[MAX_STACK_SIZE];

int front = 0, rear = 0;

int isFull() { return ((rear + 1) % MAX_STACK_SIZE == front); }

int isEmpty() { return (front == rear); }

void addQ(element item) {
    if (isFull()) {
        fprintf(stderr, "queue is full, cannot add item\n");
    }
    rear = (rear + 1) % MAX_STACK_SIZE;
    queue[rear] = item;
}

element deleteQ() {
    if (isEmpty()) {
        fprintf(stderr, "queue is empty, cannot delete item\n");
        return;
    }
    front = (front + 1) % MAX_STACK_SIZE;
	return queue[front];
}