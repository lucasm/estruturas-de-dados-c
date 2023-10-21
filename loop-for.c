#include <stdio.h>

int main()
{
  int n, numero;
  numero = 0;

  for(n=1; n<=200; n=n+1) {
    numero = n;
  }
  printf("O número é: %i \n", numero);

  return 0;
}
