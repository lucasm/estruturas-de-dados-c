/*

Receba um carácter e verifica se é um digito na tabela ASCII ou nao.

*/

#include <stdio.h>

void verificarSeDigito(char a)
{
  if (a >= 48 && a <= 57)
  {
    printf("É um digito");
  }
  else
  {
    printf("Não é um digito");
  }
}

int main()
{
  char recebido;

  printf("Digite um caracter: ");
  scanf("%c", &recebido);
  verificarSeDigito(recebido);

  return 0;
}