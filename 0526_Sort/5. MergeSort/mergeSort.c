/*
병합 정렬 :
2개의 각각 정렬된 숫자들을 하나의 정렬된 숫자로 합치는 것.

merge : 두 개 합치는 메서드
mergepass : s짜리로 끊어서 각각 merge 시키는 메서드

*/
#define MAX_SIZE 10

typedef struct {
    int key;
} element;

void merge(element init[], element merged[], int i, int m, int n) {
    // i : 		첫 번째 시작
    // m :		첫 번째 끝
    // m + 1: 	두 번째 시작
    // n : 		두 번째 끝
    int j, k, t; // t : for loop
    j = m + 1;   // index for second sublist
    k = i;       // index for merged list

    while (i <= m && j <= n) {
        if (init[i].key <= init[j].key) {
            merged[k++] = init[i++];
        } else {
            merged[k++] = init[j++];
        }
    }
    if (i > m) {
        // j 쪽이 남음 : merged[k:n] = init[j:n]
        // k == j
        for (t = j; t <= n; t++) {
            merged[t] = init[t];
        }
    } else {
        // i 쪽이 남음 : merged[k:n] = init[i:m]
        for (t = i; t <= m; t++) {
            merged[k + t - i] = init[t];
        }
    }
}

void mergePass(element init[], element merged[], int n, int s) {
    int i, j;
    for (i = 1; i < n - 2 * s + 1; i += 2 * s) {
        // 크기가 s인 리스트를 두 개씩 병합.
        merge(init, merged, i, i + s - 1, i + 2 * s - 1);
    }
    if (i + s - 1 < n) {
        // i + s - 1이 n보다 작다 :
        // 두 짝 남음
        merge(init, merged, i, i + s - 1, n);
    } else {
        // 한 짝 남음. 그대로 옮김.
        for (j = i; j <= n; j++) {
            merged[j] = init[j];
        }
    }
}

void mergeSort(element init[], int n) {
    int s = 1;
    element merged[MAX_SIZE];
    while (s < n) {
        mergePass(init, merged, n, s);
        s *= 2;
        mergePass(merged, init, n, s);
        s *= 2;
    }
    // init, merged 순서 바꾸는 이유는
    // init에 다 저장하기 위해서
}
// listMerge, rMerge는 몰라도 됨.

int listMerge(element a[], int link[], int start1, int start2) {
    int last1, last2, lastResult = 0;
    for (last1 = start1, last2 = start2; last1 && last2;) {
        if (a[last1].key <= a[last2].key) {
            link[lastResult] = last1;
            lastResult = last1;
            last1 = link[last1];
        } else {
            link[lastResult] = last2;
            lastResult = last2;
            last2 = link[last2];
        }
    }
    if (last1 == 0)
        link[lastResult] = last2;
    else
        link[lastResult] = last1;
    return link[0];
}

int rMerge(element list[], int link[], int left, int right) {
    int mid;
    if (left >= right)
        return left;
    mid = (left + right) / 2;
    return listMerge(list, link, rMerge(list, link, left, mid),
                     rMerge(list, link, mid + 1, right));
}
/*
주어진 리스트인 `list`와 리스트의 연결 정보를 저장하는 
`link` 배열을 활용하여 정렬을 수행합니다.

`listMerge` 함수는 두 개의 정렬된 리스트를 병합하는 역할을 합니다. 
`start1`과 `start2`는 각각 첫 번째 리스트와 두 번째 리스트의 
시작 위치를 나타냅니다. `last1`과 `last2`는 현재 각 리스트에서 
처리 중인 원소의 위치를 나타냅니다.
`lastResult`는 병합한 결과 리스트에서 
현재 처리 중인 원소의 위치를 나타냅니다.

`for` 루프에서는 `last1`과 `last2`가 모두 0이 아닐 때까지 
두 리스트의 원소를 비교하여 작은 원소를 결과 리스트에 삽입합니다. 
작은 원소의 `link` 값을 `lastResult`에 저장하고, 해당 원소를 
처리한 후에는 `last1` 또는 `last2`를 갱신합니다. 
이 과정을 반복하면서 두 리스트를 순회하게 됩니다.

`for` 루프가 종료되면 한 리스트의 원소를 모두 처리한 것이므로, 
남은 리스트의 나머지 원소들을 결과 리스트에 추가합니다. 
마지막으로, 남은 리스트의 첫 번째 원소의 `link` 값을 결과 
리스트의 마지막 원소로 설정해줍니다.

`rMerge` 함수는 재귀적으로 리스트를 반으로 나누고, 
각각을 정렬한 뒤 `listMerge`를 호출하여 두 개의 정렬된 리스트를 병합합니다. 
`left`와 `right`는 현재 정렬할 리스트의 범위를 나타냅니다. 
`left`와 `right`가 같거나 `left`가 `right`보다 크거나 같으면 이
미 정렬된 상태이므로 해당 위치를 반환합니다. 그렇지 않은 경우 
`left`부터 `right`까지의 범위를 반으로 나눈 뒤, 재귀적으로 
`rMerge`를 호출하여 두 개의 부분 리스트를 정렬하고 병합합니다. 
마지막으로 정렬된 전체 리스트의 첫 번째 원소의 위치를 반환합니다.

이러한 방식으로 `rMerge` 함수를 호출하면 전체 리스트가 순환 병합 
정렬에 의해 정렬되어 반환됩니다.*/