/*
 Recebe um valor e calcula fatorial
*/

#include <stdio.h>

void fatorial(int n)
{

  int fat;

  for (fat = 1; n > 1; n = n - 1)
  {
    fat = fat * n;
  }

  printf("fatorial de %i é: %i \n", n, fat);
}

int main()
{

  fatorial(10);

  return 0;
}