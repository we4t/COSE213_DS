#include <stdio.h>

int main(int argc, char *argv[]) {
  int arr[3] = {1, 2, 3};  
  int *p = arr;
  printf("%d\n", sizeof(arr));
  printf("%d\n", sizeof(p));
  printf("%d\n", *(p+2));

  return 0;
}