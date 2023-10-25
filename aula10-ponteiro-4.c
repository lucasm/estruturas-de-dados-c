/*

Ponteiro 4

Passar o endereço de uma variável pra função, ou seja, passando por referência.
*/

#include <stdio.h>

void soma(int *a, int *b)
{
  // Sempre que passar um endereço quem recebe é um ponteiro.

  *a = 30;
}

int main()
{
  int a = 10;
  int b = 20;

  printf("O valor de a é: %i\n", a);

  soma(&a, &b);

  printf("O valor de a é: %i\n", a);
  return 0;
}