#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int key;
} element;

int front = 0, rear = 0, capacity = 100;
element *queue;  // declare queue as a pointer

int isFull() { return ((rear + 1) % capacity == front); }

int isEmpty() { return (front == rear); }

void queueFull() {
    element *newQueue;
    newQueue = malloc(capacity * 2 * sizeof(*newQueue));

    int start = (front + 1) % capacity;

    if (start < 2) {
        // copy the first part of the old queue to the new queue
        for (int i = start; i < start + capacity - 1; i++) {
            newQueue[i - start] = queue[i % capacity];
        }
    } else {
        // copy the first part of the old queue to the new queue
        for (int i = start; i < capacity; i++) {
            newQueue[i - start] = queue[i];
        }
        // copy the second part of the old queue to the new queue
        for (int i = 0; i < rear + 1; i++) {
            newQueue[capacity - start + i] = queue[i];
        }
    }

    front = 2 * capacity - 1;
    rear = capacity - 2;
    capacity *= 2;
    free(queue);  // free the old queue
    queue = newQueue;  // assign the new queue to the queue pointer
}

void addQ(element item) {
    if (isFull()) {
        queueFull();
    }
    rear = (rear + 1) % capacity;
    queue[rear] = item;
}

element deleteQ() {
    if (isEmpty()) {
        fprintf(stderr, "queue is empty, cannot delete item\n");
        return;
    }
    front = (front + 1) % capacity;
    return queue[front];
}

int main() {
    // allocate memory for the queue pointer
    queue = malloc(capacity * sizeof(*queue));
    // use the queue pointer in the rest of the code
    // ...
    return 0;
}
