#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct listNode node;
typedef struct listNode {
    int data;
    node *link;
};

int main() {
    int n, i, j;
    node *x, *top, *y;
    printf("입력 범위 입력 : ");
    scanf("%d", &n);

    node *seq[n];
    int out[n];
    // seq는 스택형식으로 작동.
    // seq가 가르키는건 top.
    // out은 boolean 배열

    for (i = 0; i < n; i++) {
        seq[i] = NULL;
        out[i] = TRUE;
    }

    printf("동치쌍 입력 (-1 -1 to quit)");
    scanf("%d %d", i, j);
    while (i >= 0 && j >= 0) {
        x = malloc(sizeof(node));
        x->data = j;
        x->link = seq[i];
        seq[i] = x;
        free(x);

        x = malloc(sizeof(node));
        x->data = i;
        x->link = seq[j];
        seq[j] = x;
        free(x);

        printf("동치쌍 입력 (-1 -1 to quit)");
        scanf("%d %d", i, j);
    }

    for(i = 0; i < n; i++){
		if(out[i]){
			printf("\n new class : %5d", i);
			out[i] = FALSE;
			x = seq[i];
			top = NULL;

			for(;;){
				while(x){
					j = x->data;
					if(out[j]){
						printf("%5d", j);
						out[j] = FALSE;
						y = x->link;
						x->link = top;
						top = x;
						x = y;
					}
					else x = x -> link;
				}
				if(!top) break;
				x = seq[top->data];
				top = top->link;
			}
		}
	}
}