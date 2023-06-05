#include <stdio.h>
#define MAX_VERTICES 10
#define FALSE 0
#define TRUE 1

short int visited[MAX_VERTICES];

typedef struct node np;
typedef struct node{
	int vertex; // vertex number
	np *link; // 다음 vertex link
};

np *graph[MAX_VERTICES];

void dfs(int v){
	np *w;
	visited[v] = TRUE;
	printf("%d", v);
	for(w = graph[v]; w; w = w->link){
		if(!visited[w->vertex]){
			dfs(w->vertex);
		}
	}
}

// adjacency list : O(n+e)
// adjacency matrix : O(n^2)

