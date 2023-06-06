#include <stdio.h>
#define MAX_VERTICES 10

typedef struct node np;
typedef struct node {
    int vertex;
    np *link;
};

typedef struct hdnodes {
    int cnt;
    np *link;
} hdnodes;

hdnodes *graph[MAX_VERTICES];

void topsort(hdnodes *graph[], int n) {
    int i, j, k, top;
    np *ptr;
    top = -1;
    // 논리 스택이 있다 생각함
    for (i = 0; i < n; i++) {
        if (!graph[i]->cnt) {
            graph[i]->cnt = top;
            top = i;
            // 스택에 넣은 상태..
            // cnt에 top 값을 대입.
        }
    }

    for (i = 0; i < n; i++) {
        if (top == -1) {
            printf("\n Network has a cycle. \n");
        } else {
            j = top;               // j : 선행자 없는 마지막 정점.
            top = graph[top]->cnt; // 스택에서 pop.
            // 다음 edge로 top 전달.
            printf("%d, ", i);

            for (ptr = graph[j]->link; ptr; ptr = ptr->link) {
                k = ptr->vertex;
                graph[j]->cnt--;
                if (!graph[k]->cnt) {
                    graph[k]->cnt = top;
                    top = k;
                }
            }
        }
    }
}
