// 벨만 포드는 음수 가중치를 허용하는 케이스.
#define MAX_VERTICES 10
void bf(int n, int v, int dist[], int cost[][MAX_VERTICES]){
	int i, k;
	for(i = 0; i < n; i++){
		dist[i] = cost[v][i];
	}

	for(k = 2; k <= n-1; k++){
		// k개의 간선을 거쳐 갈 수 있는 경로를 갱신.
		// 처음 : 2개 간선 써서 갈 수 있는 경로 갱신.
		// 다음 : 3개 간선 써서 갈 수 있는 경로 갱신.
		for(int u = able_vertex(v); u; u = next_able_vertex(v)){
			// v에서 u로 갈 수 있는 경로가 적어도 하나 존재할 때
			for(int i = incident_vertex(u);i;i = next_incident_vertex(u)){
				// u에 연결된 인접한 vertex
				if(dist[i] + cost[i][u] < dist[u]){
					dist[u] = dist[i] + cost[i][u];
				}
			}
		}
	}
}

// 인접행렬 : 각 for 마다 n번 반복 : O(n^3)
// 인접 리스트 : O(n) * O(e) : O(ne)

// 다음의 과정을 (V(=정점) - 1)번 반복한다.
// 모든 간선 E개를 하나씩 확인한다.
// 각 간선을 거쳐 다른 노드로 가는 비용을 계산하여 최단 거리 테이블을 갱신한다.