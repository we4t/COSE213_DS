#define MAX_V 10
/*
비용 인접 행렬 이용.
A_k[i][j] : 정점 k를 통과하는 i~j의 최단 경로의 비용.
k : 경유 정점의 수.
k보다 작은 정점에 대한 결과 또한 포함.

A_k[i][j] = min{A_k-1[i][j], A_k-1[i][k] + A_k-1[k][j]}
모든 점을 경유점으로 해서
모든 경우의 수를 다 따지는 알고리즘..간단하다!
*/

void floyd(int cost[][MAX_V], int dist[][MAX_V], int n) {
    int i, j, k;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
			dist[i][j] = cost[i][j];
		}
    }
	for(k = 0; k < n; k++){
		for(i = 0; i < n; i++){
			for(j = 0; j < n; j++){
				if(dist[i][k] + dist[k][j] < dist[i][j]){
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}
}

// O(n^3)