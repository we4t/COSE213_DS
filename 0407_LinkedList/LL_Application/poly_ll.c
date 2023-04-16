#include <stdio.h>

typedef struct polyNode pp;
typedef struct polyNode {
    float coef;
    int expon;
    pp *link
};

int compare(int a, int b) {
    if (a > b)
        return 1;
    else if (a == b)
        return 0;
    else
        return -1;
}

void attach(float coef, int expon, pp *ptr) {
    // ptr 뒤에 coef 추가
    // ptr은 다항식의 마지막 항을 가르키는 포인터.
    pp *temp = malloc(sizeof(pp));

    temp->coef = coef;
    temp->expon = expon;

    ptr->link = temp;
    ptr = temp;
}

pp *padd(pp *a, pp *b) {
    pp *c;
    pp *rear, *temp;
    int sum;
    // rear : c의 마지막 노드를 가리키는 포인터.
    rear = (pp *)malloc(sizeof(pp));
    c = rear;

    while (a && b) {
        switch (compare(a->expon, b->expon)) {
        case -1:
            attach(b->coef, b->expon, rear);
            b = b->link;
            break;

        case 0:
            sum = a->coef + b->coef;
            if (sum)
                attach(sum, a->coef, rear);
            a = a->link;
            b = b->link;
            break;

        case 1:
            attach(a->coef, a->expon, rear);
            a = a->link;
            break;
        }
    }
    for (; a; a = a->link)
        attach(a->coef, a->expon, rear);

    for (; b; b = b->link)
        attach(b->coef, b->expon, rear);

    rear->link = NULL;

    temp = c;
    c = c->link;
    free(temp);
    // temp : 처음 만들어진 rear 포인터 값
    // c = c->link를 함으로써
    // 초기 rear 값 다음부터 생성된
    // 다항식의 첫 항을 가르킴.
    // 안 쓰는 temp는 free.

    return c;
}

void erase(pp *ptr) {
    // ptr이 가르키는 항 전체를 삭제
    pp *temp = (pp *)malloc(sizeof(pp));
    while (ptr) {
        temp = ptr;
        ptr = ptr->link;
        free(temp);
    }
}