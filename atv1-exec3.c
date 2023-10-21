// Faça um código em C onde dado o número inteiro (base 10), imprime o
// corresponde em base binária

#include <stdio.h>

int main()
{
  int num, vetor[10], x = 0, i;

  printf("Digite um numero: \n");
  scanf("%d", &num);

  // Laço
  while (num > 0)
  {
    vetor[x] = num % 2;
    num = num / 2;
    x++;
  }

  // Imprimir o vetor
  printf("Vetor: ");
  for (i = x; i > 0; i--)
  {
    printf("%i ", vetor[i]);
  }

  return 0;
}