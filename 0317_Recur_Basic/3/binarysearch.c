#include <stdio.h>

int comp = 0;

int bs_csk(int arr[], int left, int right, int key) {
    int ret = -1;
	comp++;
	printf("left : %d, right : %d\n", left, right);
	
    if (left <= right) {
        int middle = (left + right) / 2;
		if(arr[middle] == key){
			ret = middle;
			printf("key founded! \n");
		}
		else if(arr[middle] > key){
			right = middle - 1;
			ret = bs_csk(arr, left, right, key);
		}
		else{
			left = middle + 1;
			ret = bs_csk(arr, left, right, key);
		}
    }
	return ret;
}

void my_bs(int arr[], int lo, int hi, int key) {}

int main() {
    int arr_size, key;
    printf("Enter array size: ");
    scanf("%d", &arr_size);

    int arr[arr_size];
    for (int i = 0; i < arr_size; i++) {
        arr[i] = i + 1;
    }

    printf("Enter the key : ");
    scanf("%d", &key);

    bs_csk(arr, 0, arr_size - 1, key); // [lo, hi)
    // my_bs(arr, 0, arr_size, key);      // [lo, hi)

    printf("comp size : %d\n", comp);

    return 0;
}
