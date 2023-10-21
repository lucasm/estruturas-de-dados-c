/*

Recebe dois caracteres e concatena eles em uma string.

Dica: \0 = nullo, indica final da string

*/

#include <stdio.h>

int main()
{
  char recebido1[50], recebido2[50], concatenado[100];

  printf("Digite a palavra 1: ");
  scanf("%s", recebido1);

  printf("Digite a palavra 2: ");
  scanf("%s", recebido2);

  for (int i = 0; i < 50; i++)
  {
    concatenado[i] = recebido1[i];
  }

  for (int i = 0; i < 50; i++)
  {
    concatenado[i + 50] = recebido2[i];
  }

  printf("A palavra concatenada é: %s \n", concatenado);

  return 0;
}