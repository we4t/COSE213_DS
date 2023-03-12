#include <stdio.h>

enum levels { a, b, c }; // 0, 1, 2
union student{
  int num;
  double gd;
};

int main(int argc, char *argv[]) {
  enum levels grade;
  grade = a;
  printf("%d\n", grade);
  union student s = {10};
  s.gd = 3.14;
  printf("%d\n", s.num);
  printf("%f\n", s.gd);

  return 0;
}