// Faça um código em C onde dado o número inteiro (base 10), imprime o
// corresponde em base binária

#include <stdio.h>

void soma(int a, int b)
{

  printf("%i + %i = %i \n", a, b, a + b);
  a = 50;
}

int main()
{

  int x, y;
  x = 5;
  y = 10;

  soma(x, y);

  return 0;
}