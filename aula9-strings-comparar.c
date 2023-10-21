/*

Escreva programa que recebe duas strings e verifica se são iguais.

1. Comparar o tamanho das strings
2. Comparar cada caractere das strings
3. Imprimir se são iguais ou não

*/

#include <stdio.h>

int main()
{
  char recebido1[50];
  char recebido2[50];

  printf("Digite uma string: ");
  fgets(recebido1, 50, stdin);

  printf("Digite outra string: ");
  fgets(recebido2, 50, stdin);

  int i = 0;
  while (recebido1[i] != '\0' && recebido2[i] != '\0')
  {
    if (recebido1[i] != recebido2[i])
    {
      printf("As strings são diferentes \n");
      return 0;
    }
    i++;
  }

  printf("As strings são iguais \n");

  return 0;
}