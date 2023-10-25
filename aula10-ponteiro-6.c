/*

Ponteiro 5

Função que recebe como argumento duas variáveis inteiras por referência e troca os valores entre eles.

*/

#include <stdio.h>

void troca(int *a, int *b)
{
  int aux = *a;
  *a = *b;
  *b = aux;
}

int main()
{
  int a = 10;
  int b = 20;
  // criando variáveis simples

  printf("O valor de a é: %i\n", a);
  printf("O valor de b é: %i\n", b);

  troca(&a, &b);
  // chamando a função troca e passando os endereços das variáveis, ou seja, passando por referência

  printf("O valor de a é: %i\n", a);
  printf("O valor de b é: %i\n", b);

  return 0;
}