#include <stdio.h>
#define MAX_TERMS 101

typedef struct
{
	float coef;
	int expon;
} poplynomial;

int avail = 0;
poplynomial a[] = { {8, 3}, {7, 1}, {1, 0}, {10, 3}, {3, 2}, {1, 0}};
// 배열 하나에 여러 다항식을 표현할 수 있음.

void attach(float coefficient, int exponent){
	/*
		if (avail >= MAX_TERMS){
			fprintf(stderr, "항이 많음");
			exit(1);
		}
		terms[avail].coef = coefficient;
		terms[avail++].expon = exponent
	*/
}

void adding(int starta, int finisha, int startb, int finishb, int *startd, int *finishd){
	// starta : terms 배열의 다항식 a의 시작 인덱스
	// finisha : terms 배열의 다항식 a의 끝 인덱스
	// startb : terms 배열의 다항식 b의 시작 인덱스
	// finishb : terms 배열의 다항식 b의 끝 인덱스
	// available : 새로 저장하기 시작할 수 있는 빈 배열 인덱스
	// stack의 top과 비슷한 느낌.
	// *startd : 다항식 d의 시작 포인터
	// *finishd : 다항식 d의 끝 포인터

	/*
	float coefficient;
	*startd = avail;
	while( starta <= finisha && startb <= finishb){
		switch( Compare(terms[startb].expon, terms[startb].expon)){
			case -1: // b 최고차수이 a 최고차수보다 클 때
				attach(terms[startb].coef, terms[startb].expon);
				startb++;
				break;
			case 0: //  b 최고차수과 a 최고차수이 같을 때
				coefficient = terms[starta].coef + terms[startb].coef;
				if( coefficient ){
					attach( coefficient, terms[starta].expon);
					starta++;
					startb++;
					break;
				}
			case 1: // a의 최고차수가 b의 최고차수보다 클 때
				attach(terms[starta].coef, terms[starta].expon);
				starta++;
		}

		for(; starta <= finisha; starta++){
			attach(terms[starta].coef, terms[starta].expon);
		}

		for(; startb <= startb; startb++){
			attach(terms[startb].coef, terms[startb].expon);
		}
		*finishd = avail-1;
	}
	*/
}


int main(int argc, char *argv[]) {

	
    return 0;
}