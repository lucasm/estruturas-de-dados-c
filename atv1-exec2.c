// dado o número inteiro informa o fatorial, se o número for negativo, deve solicitar novo valor

// dado o número inteiro informa o fatorial, se o número for negativo, deve
// solicitar novo valor

#include <stdio.h>

int main()
{
  int i, n, acumula = 1;

  printf("Digite um numero: \n");
  scanf("%i", &n);

  if (n == 0)
    printf("O FAT de 0 = %i", n + 1);
  else if (n > 0)
  {
    for (i = n, i > 0; i--)
    {
      acumula = acumula * i;
    }
    else
    {
      printf("Não existe FAT para esse número \n");
    }
    if (acumula > 1)
    {
      printf(O fatorial de % i = % i, n, acumula)
    }
  }

  return 0;
}