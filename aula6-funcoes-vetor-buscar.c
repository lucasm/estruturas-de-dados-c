// Pede para usuário inserir um vetor de 10 número, e encontrar o valor informado

#include <stdio.h>

int buscarValorVetor(int vetorA[], int valor)
{

  int encontrado;

  // buscar valor no vetor A
  for (int i = 1; i < 10; i++)
  {
    if (vetorA[i] == valor)
    {
      encontrado = 1;
    }
  }

  if (encontrado == 1)
  {
    printf("Valor %i encontrado \n", valor);
  }
  else
  {
    printf("Valor %i não encontrado \n", valor);
  }

  return 0;
}

int main()
{

  int A[10], i, valor;

  printf("Informe 10 valores numéricos: \n");

  for (i = 1; i < 10; i++)
  {
    scanf("%i", &A[i]);
  }

  printf("Informe um valor para buscar: \n");
  scanf("%i", &valor);

  buscarValorVetor(A, valor);

  return 0;
}