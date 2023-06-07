/*
분할 정복 알고리즘.
pivot을 기준으로 분할.
pivot보다 작은 숫자들은 왼쪽에,
pivot보다 큰 숫자들을은 오른쪽에 배치하는 방식.
Average Case : 
퀵 정렬에서 n 개의 레코드 정렬의 시간 : T(n)
T(n) <= cn + 2T(n/2) // 절반으로 쪼갬
T(n/2) <= cn + 2T(n/4)
-> T(n) <= 2cn + 4T(n/4)
...
T(n) <= k * cn + 2^kT(n/2^k)
sum : 
T(n) <= logn * cn + nT(1) = O(nlogn)
Worst Case : 
T(n)이 절반으로 안 쪼개짐.
하나씩 빠짐.
-> T(n) <= n*n-1 -> O(n^2)
*/
typedef struct {
    int key;
} element;

void quickSort(element a[], int left, int right) {

    // left ~ right 까지 정렬.
    // pivot : left
    int pivot, i, j;
    element tmp;
    tmp.key = -1;
    if (left < right) {
        i = left;
        j = right;
        pivot = a[left].key;
        while (i < j) {
            while (a[i].key <= pivot) {
                i++;
            }
            while (a[j].key > pivot) {
                j--;
            }
			// i : pivot보다 크면서 제일 왼쪽에 있는 숫자.
			// j : pivot보다 작거나 같으면서 가장 오른쪽에 있는 숫자.
			// 만약 i < j 이면
			// pivot을 기준으로 잘 섞이지 않은 것.
			// 만약 i > j이면, 즉 
			// i보다 작은 원소들은 모두 pivot보다 작음.
			// j보다 큰 원소들은 모두 pivot보다 큼.
			// j와 left를 스왑
            if (i < j) {
                swap(&a[i], &a[j], tmp);
            }
        }
        swap(&a[left], &a[j], tmp);
		quickSort(a, left, j-1);
		quickSort(a, j+1, right);
    }
}

