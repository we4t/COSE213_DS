#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100

typedef struct {
    int key;
} element;

void stackFull(element *s, int *capacity) {
    int cap = (*capacity);
    realloc(s, 2 * cap * sizeof(s));
    cap *= 2;
    return;
}

int main(void) {

    element *stack;
    stack = (element *)malloc(sizeof(element));
    int capacity = 1;
    int top = -1;

	stackFull(stack, &capacity);

    return 0;
}