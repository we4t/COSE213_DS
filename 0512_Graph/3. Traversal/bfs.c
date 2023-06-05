#include <stdio.h>
#define MAX_VERTICES 10
#define FALSE 0
#define TRUE 1

typedef struct queue qp;
typedef struct queue{
	int vertex;
	qp *link;
};

short int visited[MAX_VERTICES];
qp *graph[MAX_VERTICES];

void bfs(int v){
	qp *w;
	qp *front, *rear;
	front = rear = NULL;
	printf("%d", v);
	visited[v] = TRUE;
	addq(&front, &rear, v);
	while(front){
		v = deleteq(&front, &rear, v);
		for (w = graph[v]; w; w = w->link){
			if(!visited[w->vertex]){
				printf("%d ", w->vertex);
				addq(&front, &rear, w->vertex);
				visited[w->vertex] = TRUE;
			}
		}
	}
}

// 방문 순서대로 spanning tree
// adjacency list : O(n+e)
// adjacency matrix : O(n^2)