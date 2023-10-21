#include <stdio.h>

int main() {
  int a = 50;
  int b = 5;
  int c = 25;
  int d = 3;
  int result;
  float e = 2.0005;

  result = a - b;
  printf("a - b = %i \n", result);

  result = b * c;
  printf("b * c = %i \n", result);

  result = a / b;
  printf("a / b = %i \n", result);

  result = a + b * c;
  printf("a + b * c = %i \n", result);

  printf("a * b + c * d = %i \n", a * b + c * d);
  printf("-a = %i \n", -a);
  printf("c / d * d = %i \n", c / d * d);

  printf("e + a = %f \n", e + a);

  return 0;
}
