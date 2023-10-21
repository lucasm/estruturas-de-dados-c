/*

Escreva um função que recebe uma string e imprime o numero de caracteres da string.

*/

#include <stdio.h>

int main()
{
  char recebido[50];

  printf("Digite uma string: ");
  fgets(recebido, 50, stdin);

  int i = 0;
  while (recebido[i] != '\0')
  {
    i++;
  }
  printf("O numero de caracteres da string é: %d \n", i - 1);

  return 0;
}