/*

Ponteiro 2

*/

#include <stdio.h>

int main()
{
  int *p1 = NULL;

  int a = 70;

  p1 = &a;

  printf("O end. do ponteiro P1 = %p \n", (void *)p1);

  printf("O endereço da var 'a' = %p \n", (void *)&a);

  int b = 10;

  printf("O endereço do ponteiro B é = %p \n", (void *)&b);
  printf("O valor de B é = %p \n", b);

  p1 = &b;

  printf("O endereço do ponteiro P1 é = %p \n", (void *)p1);

  return 0;
}