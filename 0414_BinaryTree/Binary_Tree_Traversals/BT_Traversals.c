#include <stdio.h>

typedef struct node tp;
typedef struct node {
    int data;
    tp *lc;
    tp *rc;
};

void preorder(tp *ptr) {
    if (ptr) {
        printf("%d ", ptr->data);
        preorder(ptr->lc);
        preorder(ptr->rc);
    }
}

void inorder(tp *ptr) {
    if (ptr) {
        inorder(ptr->lc);
        printf("%d ", ptr->data);
        inorder(ptr->rc);
    }
}

void postorder(tp *ptr) {
    if (ptr) {
        postorder(ptr->lc);
        postorder(ptr->rc);
        printf("%d ", ptr->data);
    }
}

void iter_inorder(tp *ptr) {
    int top = -1;
    int MAX_STACK_SIZE = 100;
    tp stack[MAX_STACK_SIZE];

    for (;;) {
        for (; ptr; ptr = ptr->lc)
            ;
        push(&top, ptr);
        ptr = pop(&top, ptr);
        if (!ptr)
            break;
        printf("%d ", ptr->data);
        ptr = ptr->rc;
    }
}

void levelOrder(tp *ptr) {
    int front = rear = 0;
    tp queue[100];
    if (!ptr)
        return;
    addq(ptr);

    for (;;) {
        ptr = deleteq(&front, rear);
        if (ptr) {
			printf("%d", ptr->data);
            if (ptr->lc)
                addq(ptr->lc);
            if (ptr->rc)
                addq(ptr->rc);
        }
		else break;
    }
}