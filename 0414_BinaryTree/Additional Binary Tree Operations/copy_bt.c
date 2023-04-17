#include <stdio.h>

typedef struct node tp;
typedef struct node {
    int data;
    tp *lc;
    tp *rc;
};

tp *copy(tp *original) {
    tp *temp;
    if (original) {
        temp = (tp *)malloc(sizeof(tp));
        temp->lc = copy(original->lc);
        temp->rc = copy(original->rc);
        temp->data = original->data;
        return temp;
    }
    return 0;
}

int equal(tp *first, tp *second) {
    return ((!first && !second) ||
            (first && second) && (first->data == second->data) &&
                equal(first->lc, second->lc) && equal(first->rc, second->rc));
}