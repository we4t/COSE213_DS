#include <stdio.h>
#include <stdlib.h>
int MAX_VERTICES;

typedef struct node np;
typedef struct node {
    int vertex;
    int duration;
    np *link;
};

typedef struct hdnodes {
    int cnt;
    np *link;
} hdnodes;

void forward(hdnodes *graph[], int n, int e[]) {
    int i, j, k, top;
    np *ptr;
    top = -1;
    for (i = 0; i < n; i++) {
        if (!graph[i]->cnt) {
            graph[i]->cnt = top;
            top = i;
        }
    }

    for (i = 0; i < n; i++) {
        if (top == -1) {
            printf("\n Network has a cycle. \n");
        } else {
            j = top;
            top = graph[top]->cnt;
            printf("%-3d", j);

            for (ptr = graph[j]->link; ptr; ptr = ptr->link) {
                k = ptr->vertex;
                if (e[k] < e[j] + ptr->duration)
                    e[k] = e[j] + ptr->duration;

                graph[k]->cnt--;
                if (!graph[k]->cnt) {
                    graph[k]->cnt = top;
                    top = k;
                }
            }
        }
    }
}

void backward(hdnodes *graph[], int n, int l[]) {
    int i, j, k, top;
    np *ptr;
    top = -1;
    for (i = 0; i < n; i++) {
        if (!graph[i]->cnt) {
            graph[i]->cnt = top;
            top = i;
        }
    }

    for (i = 0; i < n; i++) {
        if (top == -1) {
            printf("\n Network has a cycle. \n");
        } else {
            j = top;
            top = graph[top]->cnt;
            printf("%-3d", j);

            for (ptr = graph[j]->link; ptr; ptr = ptr->link) {
                k = ptr->vertex;
                if (l[k] > l[j] - ptr->duration) {
                    l[k] = l[j] - ptr->duration;
                }
                graph[k]->cnt--;
                if (!graph[k]->cnt) {
                    graph[k]->cnt = top;
                    top = k;
                }
            }
        }
    }
}

int main() {
    int i, j, tmp;
	printf("max vertices : ");
    scanf("%d", &MAX_VERTICES);
	printf("adj matrix : \n");

    hdnodes *ingraph[MAX_VERTICES], *outgraph[MAX_VERTICES];
    int earlist[MAX_VERTICES], latest[MAX_VERTICES];
    for (i = 0; i < MAX_VERTICES; i++) {
        hdnodes *tmp1, *tmp2;
        tmp1 = malloc(sizeof(hdnodes));
        tmp1->cnt = 0;
        tmp1->link = NULL;
        tmp2 = malloc(sizeof(hdnodes));
        tmp2->cnt = 0;
        tmp2->link = NULL;
        ingraph[i] = tmp1;
        outgraph[i] = tmp2;
        earlist[i] = 0;
    }
    for (i = 0; i < MAX_VERTICES; i++) {
        for (j = 0; j < MAX_VERTICES; j++) {
            scanf("%d", &tmp);
            if (tmp) {
                ingraph[j]->cnt++;
                outgraph[i]->cnt++;

                np *tmp1, *tmp2;
                if (ingraph[i]->link) {
                    tmp1 = ingraph[i]->link;
                    while (tmp1->link) {
                        tmp1 = tmp1->link;
                    }
                    np *t;
                    t = malloc(sizeof(np));
                    t->link = NULL;
                    t->vertex = j;
                    t->duration = tmp;
                    tmp1->link = t;
                } else {
                    tmp1 = malloc(sizeof(np));
                    tmp1->link = NULL;
                    tmp1->vertex = j;
                    tmp1->duration = tmp;
                    ingraph[i]->link = tmp1;
                }
                if (outgraph[j]->link) {
                    tmp2 = outgraph[j]->link;
                    while (tmp2->link) {
                        tmp2 = tmp2->link;
                    }
                    np *t;
                    t = malloc(sizeof(np));
                    t->link = NULL;
                    t->vertex = i;
                    t->duration = tmp;
                    tmp2->link = t;
                } else {
                    tmp2 = malloc(sizeof(np));
                    tmp2->link = NULL;
                    tmp2->vertex = i;
                    tmp2->duration = tmp;
                    outgraph[j]->link = tmp2;
                }
            }
        }
    }

    printf("ingraph topsort : \n");
    forward(ingraph, MAX_VERTICES, earlist);
    printf("\nearlist : \n");
    for (i = 0; i < MAX_VERTICES; i++) {
		printf("%-3d", earlist[i]);
		latest[i] = earlist[MAX_VERTICES - 1];
    }
    printf("\noutgraph topsort : \n");
    backward(outgraph, MAX_VERTICES, latest);
	printf("\nlatest : \n");
    for (i = 0; i < MAX_VERTICES; i++) {
		printf("%-3d", latest[i]);
    }
	printf("\n");

    return 0;
}