#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int value;
  struct Node *link;
} N;

int main(int argc, char *argv[]) {
  /*
    N n1, n2;
    n1.value = 7;
    n1.link = &n2;
    n2.value = 5;
    n2.link = &n1;
  */

  N *n1, *n2;
  N *head;

  n1 = (N *)malloc(sizeof(N));
  n1->value = 10;
  n1->link = n2;

  n2 = (N *)malloc(sizeof(N));
  n2->value = 11;
  n2->link = NULL;

  head = n1;
  while(head != NULL)
  {
    printf("%d\n", head->value);
    head = head->link;
  }

  return 0;
}