#include <stdio.h>
#define MAX_TERMS 101
#define MAX_COL 50

typedef struct {
    int row;
    int col;
    int value;
} term;

term a[MAX_TERMS];
term b[MAX_TERMS];

// term[0] : <row, col, total_values_num>
// term[1] ~ : row, col 오름차순

void transpose(term a[], term b[]) {
    int n, i, j, currentb;
    b[0].col = a[0].row;
    b[0].row = a[0].col;
    b[0].value = b[0].value;
    n = a[0].value;

    if (n > 0) { // is a non-zero matrix?
        currentb = 1;
        for (i = 0; i < a[0].col; i++) {
            // a의 col이 작은 것 부터 b에 넣기
            // column 만큼의 iteration
            for (j = 1; j <= n; j++) {
                // a에 속해있는 모든 원소의 개수를 전부 순회하면서
                // 탐색을 할 예정
                // O(columns * values)
                if (a[j].col == i) {
                    b[currentb].row = a[j].col;
                    b[currentb].col = a[j].row;
                    b[currentb].value = a[j].value;
                    currentb++;
                }
            }
        }
    }
}

void fastTranspose(term a[], term b[]) {
    // rowTerms : b의 row 값에 대응하는 원소의 개수.
    // 예를 들어서, a의 nonzero 항 중에서
    // col이 2인 것들이 3개 있으면
    // rowTerms[2] = 3

    // startingPos : b의 row 값이 시작하는
    // 인덱스 시작점.

    // fastTranspose의 특징은
    // a의 column을 매핑시키고 이를 이용해서
    // b의 triple들의 시작 위치를 직접 계산하는 방식.

    int rowTerms[MAX_COL], startingPos[MAX_COL];
    int i, j;
    int numCol, numTerms;
    b[0].col = a[0].row;
    numCol = b[0].row = a[0].col;
    numTerms = b[0].value = a[0].value;

    if (numTerms > 0) {
        for (i = 0; i < numCol; i++) {
            rowTerms[i] = 0;
        }

        for (i = 1; i <= numTerms; i++) {
            rowTerms[a[i].col]++;
        }

        startingPos[0] = 1;
        for (i = 1; i < numCol; i++) {
            startingPos[i] = startingPos[i - 1] + rowTerms[i - 1];
        }

        for (i = 1; i <= numTerms; i++) {
            j = startingPos[a[i].col]++;
            // 후위 연산자, a[i].col에 속하는 다음 값의
            // starting position을 할당한 후 증가시킴.

            b[j].row = a[i].col;
            b[j].col = a[i].row;
            b[j].value = a[i].value;
        }
    }
}

void mmult(term a[], term b[], term d[]) {
    // d = a*b

    int i, j, column;
    int rowsA = a[0].row;
    int colsA = a[0].col;
    int colsB = b[0].col;
    int totalA = a[0].value;
    int totalB = b[0].value;
    int totalD = 0;

    int rowBegin = 1, row, sum = 0;
    term newB[MAX_TERMS];

    if (colsA != b[0].row) {
        fprintf(stderr, "연산불가\n");
    }

    fastTranspose(b, newB);

    a[totalA + 1].row = rowsA;
    newB[totalB + 1].row = colsB;
    newB[totalB + 1].col = 0;
    newB[totalB + 1].value = 0;
    row = a[1].row;

    for (i = 1; i <= totalA;) {
        column = newB[1].row;
        for (j = 1; j <= totalB + 1;) {
            if (a[i].row != row) {
                storesum(d, &totalD, row, column, &sum);
                i = rowBegin;
                for (; newB[j].row == column; j++) {
                    column = newB[j].row;
                }
            } else if (newB[j].row != column) {
                storesum(d, &totalD, row, column, &sum);
                i = rowBegin;
                column = newB[j].row;
            } else {
                switch (COMPARE(a[i].col, newB[j].col)) {
                case -1:
                    i++;
                    break;
                case 0:
                    sum += (a[i++].value * newB[j++].value);
                    break;
                case 1:
                    j++;
                }
            }
            for (; a[i].row == row; i++)
                ;
            rowBegin = i;
            row = a[i].row;
        }
        d[0].row = rowsA;
        d[0].col = colsB;
        d[0].value = totalD;
    }
}

void mmult(term a[], term b[], term d[]) {
    int i, j, column;
    int rowsA = a[0].row;
    int colsA = a[0].col;
    int colsB = b[0].col;
    int totalA = a[0].value;
    int totalB = b[0].value;
    int totalD = 0;
    int rowBegin = 1, row, sum = 0;
    terms newb[MAX_TERMS];
    if (colsA != b[0].row) {
        printf("연산불가");
    }
    fastTranspose(b, newB);
    a[totalA + 1].row = rowsA;
    newb[totalB + 1].row = colsB;
    newb[totalB + 1].col = 0;
    newb[totalB + 1].value = 0;
    row = a[1].row;
    for (i = 1; i <= totalA;) {
        column = newB[1].row;
        for (j = 1; j <= totalB + 1l;) {
            if (a[i].row != row) {
                storesum(d, &totalD, row, column, &sum);
                i = rowBegin;
                for (; newB[j].row == column; j++)
                    ;
                column = newB[j].row;
            }
			else if(newB[j].row != column){
				storesum(d, &totalD, row, column &sum);
				i = rowBegin;
				column = newB[j].row;
			}
			else{
				switch(compare(a[i].col, newB[j].col)){
					case -1:
						i++;
						break;
					case 0:
						sum += a[i++].value*newB[j++.value];
						break;
					case 1:
						j++;
				}
			}
        }
		for(; a[i].row == row; i++);
		rowBegin = i;
		row = a[i].row;
    }
	d[0].row = rowsA;
	d[0].col = colsB;
	d[0].value = totalD;
}