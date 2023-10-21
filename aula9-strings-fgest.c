/*

fgets() - lê uma string até o \n

argumentos do fgets(): (string, tamanho, stdin)

*/

#include <stdio.h>

int main()
{
  char recebido[50];

  printf("Digite uma frase com espaços: ");
  fgets(recebido, 50, stdin);

  printf("A frase digitada foi: %s \n", recebido);

  return 0;
}