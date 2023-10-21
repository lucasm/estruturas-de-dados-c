// array

#include <stdio.h>

int main()
{
  int val[10];
  int i;

  val[0] = 197;
  val[2] = 100;
  val[5] = 350;
  val[3] = val[0] + val[5];
  val[9] = val[5] / 10;
  --val[2];

  for (i = 0; i < 10; i++)
  {
    printf("valor [%i] = %i \n", i, val[i]);
  }

  printf("valor 2 = %i \n", val[2]);

  return 0;
}