#include <stdio.h>
#define MAX_VERTICES 10

typedef struct edge ep;
typedef struct edge {
	short int marked;
	int v1, v2;
	ep *p1, *p2;
};

ep *graph[MAX_VERTICES]; // vertex
// 포인터 배열