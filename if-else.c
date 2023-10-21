#include <stdio.h>

int main()
{
  int num, resto;

  printf("Informe o número a ser testado: ");
  scanf(" %i", &num);

  resto = num % 2;

  if (resto == 0)
  {
    printf("O número é par");
  }
  else
  {
    printf("O número é ímpar");
  }

  return 0;
}
