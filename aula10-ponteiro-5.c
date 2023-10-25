/*

Ponteiro 5

Criar duas variáveis e inverter os valores delas por meio de ponteiros.

Conceito de desreferência.

*/

#include <stdio.h>

int main()
{
  int a = 10;
  int b = 20;
  // criando variáveis simples

  printf("O valor de a é: %i\n", a);
  printf("O valor de b é: %i\n", b);

  int *p1 = &a;
  int *p2 = &b;
  // criando ponteiros para as variáveis

  int aux = *p1;
  *p1 = *p2;
  *p2 = aux;
  // invertendo os valores das variáveis por meio dos ponteiros

  printf("O valor de a é: %i\n", a);
  printf("O valor de b é: %i\n", b);

  return 0;
}