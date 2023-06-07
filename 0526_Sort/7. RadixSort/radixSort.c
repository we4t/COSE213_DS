typedef struct {
    int key;
} element;

// 동작 방식을 이해하자

int radixSort(element a[], int link[], int d, int r, int n) {
    // d : MAX_DIGIT  (3)
    // r : RADIX_SIZE (10)
    r = 10;
    d = 3;
    int front[r] = {0};
    int rear[r] = {0};

    int i, bin, current, first, last;
    first = 1;
    for (i = 1; i < n; i++)
        link[i] = i + 1;
    link[n] = 0;

    for (i = d - 1; i >= 0; i--) {
        for (bin = 0; bin < r; bin++)
            front[bin] = 0;
        for (current = first; current; current = link[current]) {
            bin = digit(a[current], i, r);
            // bin = digit(179, 2, 10) = 9
            if (front[bin] == 0)
                front[bin] = current;
            else
                link[rear[bin]] = current;
            rear[bin] = current;
        }
        for (bin = 0; !front[bin]; bin++)
            ;
        first = front[bin];
        last = rear[bin];

        for (bin++; bin < r; bin++) {
            if (front[bin]) {
                link[last] = front[bin];
                last = rear[bin];
            }
        }
        link[last] = 0;
    }
    return first;
}