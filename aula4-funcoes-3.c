/*
 Recebe data de aniversário em dd/mm/aaaa e retorna em dias
*/

#include <stdio.h>

void dataAniversarioEmDias(int d, int m, int a)
{

  int n = 1;
  printf("x é: %i \n", n);
}

int main()
{
  int d, m, a;

  scanf("Informe o dia de nascimento:  \n", d);
  scanf("Informe o mês de nascimento:  \n", m);
  scanf("Informe o ano de nascimento:  \n", a);

  dataAniversarioEmDias(d, m, a);

  return 0;
}