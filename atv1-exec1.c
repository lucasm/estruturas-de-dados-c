// dado o número inteiro positivo n, imprime pares até n

#include <stdio.h>

int main()
{
  int n;

  printf("Digite um numero: \n");
  scanf("%d", &n);

  for (int i = 0; i < n; i++)
  {
    if (i % 2 == 0)
    {
      printf("é par %d\n", i);
    }

    // else {
    //   printf("é impar %d\n", i);
    // }
  }

  return 0;
}