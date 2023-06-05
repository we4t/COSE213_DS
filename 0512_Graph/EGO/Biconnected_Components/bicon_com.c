#include <stdio.h>
#define min(x, y) (x < y ? x : y)
#define false 0
#define true 1
#define MAX_VERTICES 10

int dfn[MAX_VERTICES];
int low[MAX_VERTICES];
int visited[MAX_VERTICES];
int num = 0;

void init() {
    int i;
    for (i = 0; i < MAX_VERTICES; i++) {
        visited[i] = false;
        dfn[i] = low[i] = -1;
    }
    num = 0;
}

typedef struct node np;
typedef struct node {
    int vertex;
    np *link;
};

np *graph[MAX_VERTICES];

void dfnlow(int u, int v) {
    // 자식, 부모
    // u에서 dfs search, v : u의 parent
    // initial call : dfnlow(root, -1)

    np *ptr;
    int w;
    dfn[u] = low[u] = num++;

    for (ptr = graph[u]; ptr; ptr = ptr->link) {
        w = ptr->vertex;  // w : 자식
        if (dfn[w] < 0) { // u의 자식이 방문 안 되었을 때
            dfnlow(w, u); // u의 자식으로 low 구하기.
            low[u] = min(low[u], low[w]);
            // 자식 w의 low 구했으니, u의 low도 업뎃.
        } else if (w != v) {
            // 이미 갔다 옴. 자식 관계 아님.
            // 백엣지 존재.
            low[u] = min(low[u], dfn[w]);
        }
    }
}

void bicon(int u, int v) {
    // 		자식, 부모 관계
    // 		v는 u의 부모
	// dfnlow의 진화 버전.
	// low 갱신함과 동시에 이중 결합 요소 부분 출력까지 함.
    np *ptr;
    int w, x, y;
    dfn[u] = low[u] = num++;
    for (ptr = graph[u]; ptr; ptr = ptr->link) {
        // u와 연결된 정점들 확인.
        w = ptr->vertex;
        if (v != w && dfn[w] < dfn[u]) {
            // 연결된 정점이 부모가 아니고
            // 방문 안 함.
            add(u, w); // edge(u, w)를 스택에.
            if (dfn[w] < 0) {
                bicon(w, u);
                low[u] = min(low[u], low[w]);
                if (low[w] >= dfn[u]) {
                    printf("new biconnected component : ");
                    do {
                        delete (&x, &y);
                        printf("<%d, %d>", x, y);
                    } while (!(x == u) && (y == w));
					printf("\n");
                }
            }
			else if(w != v) // 이전에 방문했음. 백엣지임.
				low[u] = min(low[u], dfn[w]);
        }
    }
}