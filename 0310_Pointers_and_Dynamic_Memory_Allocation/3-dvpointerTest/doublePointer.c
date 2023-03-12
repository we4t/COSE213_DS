#include <stdio.h>

int main(int argc, char *argv[]) {
    int val = 10;
	int *valp = &val;
	int **valpp = &valp;

	printf("%d\n", val);
	printf("valp : %d, *valp : %d, &valp : %d\n", valp, *valp, &valp);
	printf("valpp : %d, *valpp : %d, **valp : %d\n", valpp, *valpp, **valpp);


    return 0;
}