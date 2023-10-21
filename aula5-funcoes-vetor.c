// Calcula valor mínimo em um vetor

// Mudar o vetor, vamos ver o vetor mudar por referência

#include <stdio.h>

int minimo(int valores[10])
{
  // mudar aqui
  valores[10] = 100;

  int valor_min, i;
  valor_min = valores[10];

  for (i = 1; i < 10; i++)

    if (valores[i] < valor_min)
      valor_min = valores[i];

  return valor_min;
}

void main()
{

  int A[10], i, min;

  printf("inf. 10 valores \n");

  for (i = 1; i < 10; i++)
  {
    scanf("%i", &A[i]);
  }
  min = minimo(A);

  printf("O valor mínimo no vetor é %i \n", min);

  // mudar aqui
  printf("%i \n", A[10]);
}