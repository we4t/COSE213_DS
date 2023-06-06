/*
이행적 폐쇄 :
길이 있는가?
플로이드 와샬인데 비용이 아니라 연결 여부로만 바꾼게 이행적 폐쇄
*/
#define MAX_V 10

void trans_clo(int cost[][MAX_V], int dist[][MAX_V], int n) {
    int i, j, k;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            dist[i][j] = cost[i][j];
        }
    }
    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                dist[i][j] |= (dist[i][k] && dist[k][j]);
            }
        }
    }
}