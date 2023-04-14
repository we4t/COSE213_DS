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

void adding(){

	// pseudo code of adding to polynomials
	/* 
	d = zero(); // 초기값 배열
	while(!isZero(a) ** !isZero(b)){
		switch Compare(lead_exp(a), lead_exp(b)) {
			case -1: // b가 a보다 차수 클 떄
				d = attach(d, Coef(b, lead_exp(b)), lead_exp(b));
				b = remove(b, lead_exp(b));
				break;
			case 0: // b 최고차항 == a 최고차항
				sum = Coef(a, lead_exp(a)) + Coef(b, lead_exp(b));
				if(sum){
					attach(d, sum, lead_exp(a));
				}
				a = remove(a, lead_exp(a));
				b = remove(b, lead_exp(b));
				break;
			case 1:
				d = attach(d, Coef(a, lead_exp(a)), lead_exp(a));
				a = remove(a, lead_exp(a));
		}
	}
	*/
}


int main(int argc, char *argv[]) {

	
    return 0;
}