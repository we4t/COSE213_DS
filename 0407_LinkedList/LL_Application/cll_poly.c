#include <stdio.h>

#define TRUE 1
#define FALSE 0

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

pp *cpadd(pp *a, pp *b) {
    // a와 b는 헤더 노드.
    // c는 리턴할 CLL 다항식, lastc는 c의 마지막 노드.
    int sum, done = FALSE;
    pp *startA, *c, *lastC;
    startA = a;
    a = a->link;
    b = b->link;
    c = malloc(sizeof(pp));
    c->expon = -1;
    lastC = c;
    do {
        switch (compare(a->expon, b->expon)) {
        case -1:
            attach(b->coef, b->expon, lastC);
            b = b->link;
            break;

        case 0:
            if (startA == a)
                done = TRUE;
            // 어차피 모든 노드는, 순회를 다 하고 나면
            // 자신의 헤더 노드로 돌아오게 되어있음.
            // 모든 헤더 노드는 expon이 -1이므로,
            // 항상 compare할 때 밀리기에
            // padding 작업이 끝나는 경우는
            // a 와 b가 모두 헤더노드를 가리키는 경우
            else {
                sum = a->coef + b->coef;
                if (sum)
                    attach(sum, a->expon, lastC);
                a = a->link;
                b = b->link;
            }
            break;
        case 1:
            attach(a->coef, a->expon, lastC);
            a = a->link;
            break;
        }
    } while(!done);
	lastC->link = c;
	free(lastC);
	return c;
}