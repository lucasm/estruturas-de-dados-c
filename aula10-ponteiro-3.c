/*

Ponteiro 3

Pode apontar o ponteiro para qualquer tipo de variável, inclusive para outro ponteiro, desde que seja do mesmo tipo.

*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
  int i1 = NULL, i2 = NULL, *p1 = NULL, *p2 = NULL;

  i1 = 5;
  p1 = &i1;
  i2 = *p1 / 2 + 10;
  p2 = p1;

  printf("i1 = %i, i2 = %i, *p1 = %i, *p2 = %i\n", i1, i2, *p1, *p2);
  return 0;
}