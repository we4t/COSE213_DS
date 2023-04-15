#include <stdio.h>

#define MAX_STACK_SIZE 100

typedef struct {
    int key;
} element;

element queue[MAX_STACK_SIZE];

int front = -1, rear = -1;

int isFull() { return (rear == MAX_STACK_SIZE - 1); }

int isEmpty() { return (front == rear); }

void addQ(element item) {
    if (isFull()) {
		fprintf(stderr, "queue is full, cannot push item\n");
    }
    queue[++rear] = item;
}

element deleteQ() {
    if (isEmpty()) {
        fprintf(stderr, "queue is empty, cannot delete item\n");
        return;
    }
    return queue[++front];
}