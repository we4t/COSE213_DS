#define MAX_VERTICES 10

int choose(int dist[], int n, short int found[]) {
    int i;
    int min, minpos;
    min = __INT_MAX__;
    minpos = -1;
    for (i = 0; i < n; i++) {
        if (!found[i] && dist[i] < min) {
            min = dist[i];
            minpos = i;
        }
    }
    return minpos;
    // 방문하지 않은 정점 중 최소비용인 정점을 고르는 메서드.
}

void dijkstra(int v, int cost[][MAX_VERTICES], int dist[], int n,
              short int found[]) {
    int i, u, w;
    for (i = 0; i < n; i++) { // O(n)
        found[i] = 0;
        dist[i] = cost[v][i];
    }
    found[v] = 1;
    dist[v] = 0;

    for (i = 0; i < n - 2; i++) {
		// 출발점에서 n-1개의 경로 찾기.
        u = choose(dist, n, found);
        found[u] = 1; // 중간 정점 선택하기.
        for (w = 0; w < n; w++) {
			// w 까지의 최소비용 다시 검사.
            if (!found[w]) {
			// w 최단경로 안 구해졌으면
                if (dist[u] + cost[u][w] < dist[w]) {
                    dist[w] = dist[u] + cost[u][w];
					// 경유하는 경로로 비용 갱신.
				}
            }
        }
    }
}

// O(n^2)