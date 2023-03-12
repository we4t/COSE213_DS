#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int a = 7, b = 1;
  printf("address of a : %d\n", &a);
  printf("address of b : %d\n", &b);
  int *p;
  p = (int *) malloc( 3*sizeof(int) );
  printf("value of p : %d\n", p);
  printf("value of *p : %d\n", *p);
  p = &a;
  printf("value of p : %d\n", p);
  printf("value of *p : %d\n", *p);
  int *q;
  q = p+1;
  printf("value of q : %d\n", q);
  printf("value of *q : %d\n", *q);
  q = &b;
  printf("value of q : %d\n", q);
  printf("value of *q : %d\n", *q);
  
  printf("value of p+1 : %d\n", (p+1));
  printf("value of *(p+1) : %d\n", *(p+1));
  return 0;
}