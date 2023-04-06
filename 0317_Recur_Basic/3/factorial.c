#include <stdio.h>

int fibo(int fiboIndex){
	if(fiboIndex == 0){
		return 0;
	}
	else if(fiboIndex == 1){
		return 1;
	}
	else{
		return fibo(fiboIndex - 1) + fibo(fiboIndex - 2);
	}
}

int main(int argc, char *argv[]) {
	int loopSize = 19;
	// total loop time : 2^(loopSize)
	for(int i = 1; i <= loopSize; i++){
		printf("%d ", fibo(i - 1));

		if(i % 5 == 0 && i != loopSize){
			printf("\n");
		}
	}
	printf("\n");

    return 0;
}