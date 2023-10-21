// Função que recebe o tempo em minutos, retorna em horas e minutos, usar Struct para armazenar as horas e minutos

#include <stdio.h>

struct Data
{
  int dia;
  int mes;
  int ano;
};

int teste(struct Data d)
{

  d.dia = 5;
  if (d.dia == 2)
  {
    return (1);
  }
}

int main()
{

  struct Data hoje;
  int flag;
  hoje.dia = 2;
  hoje.mes = 3;
  hoje.ano = 2013;

  flag = teste(hoje);

  printf("%i \n", hoje.dia);

  // if (flag != 1)
  // {
  //   printf("Erro ! \n");
  // }

  return 0;
}