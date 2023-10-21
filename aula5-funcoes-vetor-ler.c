// Pede para usuário inserir um vetor A, e encontrar o valor informado

#include <stdio.h>

int gerarVetorB(int vetorA[10])
{
  int vetorB[10], i;

  for (i = 1; i < 10; i++)
  {
    vetorB[i] = vetorA[i] * 2;
  }

  // vetor A
  printf("Vetor A: \n");

  for (i = 1; i < 10; i++)
  {
    printf("%i ", vetorA[i]);
  }

  // vetor B
  printf("\nVetor B: \n");

  for (i = 1; i < 10; i++)
  {
    printf("%i ", vetorB[i]);
  }

  return 0;
}

int main()
{

  int A[10], i;

  printf("Informe 10 valores: \n");

  for (i = 1; i < 10; i++)
  {
    scanf("%i", &A[i]);
  }

  gerarVetorB(A);

  return 0;
}