#include <stdio.h>
#include <stdlib.h>

#define MEMORY_SIZE 100
#define MAX_STACK_SIZE 100
#define MAX_STACKS 5

// more than two stacks
// initially, boundary[i] = top[i]
// 스택 초기에는 경계에 top을 둠.
// 각 스택의 boundary가 bottom

typedef struct {
    int key;
} element;

element memory[MEMORY_SIZE];

int top[MAX_STACKS];
int boundary[MAX_STACKS];
int n = 5;
// top 배열은 각 스택들의 top의 값을 담고 있다.
// boundary 배열은 각 스택들의 boundary를 저장한다.
// 예를 들어, boundary[i] <= top[i] <= boundary[i+1]
// 만약 현재 boundary[i] == top[i]이면
// i 번째 스택은 비어있다.
// 만약 현재 boundary[i] == top[i+1]이면
// 스택에 더이상 넣을 수 없다.
// 즉, 스택 i의 index들은
// boundary[i] + 1 <= index <= boundary[i+1]
// 을 만족한다.

void push(int i, element item) {
    if (top[i] == boundary[i + 1]) {
        // stackFull(i);
    }
    memory[++top[i]] = item;
}

element pop(int i) {
    if (top[i] == boundary[i]) {
        // return stackEmpty(i);
    }
    return memory[top[i]--];
}

int main(void) {
    top[0] = boundary[0] = -1;
    int i;
    for (i = 1; i < n; i++)
        top[i] = boundary[i] = (MEMORY_SIZE / n) * i - 1;
    boundary[n] = MEMORY_SIZE - 1;
}