#include <stdio.h>

enum logic { not, and, or, TRUE, FALSE };

typedef struct node tp;
typedef struct node {
    tp *lc;
    enum logic data;
    short int value;
    tp *rc;
};

void postOrderEval(tp *node) {
    if (node) {
        postOrderEval(node->lc);
        postOrderEval(node->rc);
        switch (node->data) {
        case not:
            node->value = !node->rc->value;
            break;
            // not node는 not을 연산할
            // 연산자를 오른쪽 자식에게 갖고 있도록
            // 데이터를 저장함.
        case and:
            node->value = node->rc->value && node->lc->value;
            break;

        case or:
            node->value = node->rc->value || node->lc->value;
            break;

        case TRUE:
            node->value = TRUE;
            break;

        case FALSE:
            node->value = FALSE;
            break;
        }
    }
}