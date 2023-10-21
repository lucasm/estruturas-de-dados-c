// Struct

#include <stdio.h>

int converterMinutosEmHorasMinutos()
{

  int tempoEmMinutos;

  typedef struct Tempo
  {
    int horas;
    int minutos;
  } TEMPO;

  TEMPO convert;

  printf("Informe o tempo em minutos: \n");
  scanf("%i", &tempoEmMinutos);

  convert.horas = tempoEmMinutos / 60;
  convert.minutos = tempoEmMinutos % 60;

  printf("%i minutos corresponde a %i horas e %i minutos \n", tempoEmMinutos, convert.horas, convert.minutos);

  return 0;
}

int main()
{

  converterMinutosEmHorasMinutos();

  return 0;
}