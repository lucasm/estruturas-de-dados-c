/*

Ponteiro

*/

#include <stdio.h>

int main()
{
  char c = 'U';

  char *ponteiro = &c;

  printf("O valor de c é: %c\n", c);
  printf("O valor de c é: %c\n", *ponteiro);
  printf("O endereço de c é: %p\n", &c);

  c = 'F';
  printf("O valor de c é: %c\n", c);

  *ponteiro = 'P';
  // * declara o ponteiro ou pega o valor de onde o ponteiro aponta
  printf("O valor de c é: %c\n", c);

  return 0;
}