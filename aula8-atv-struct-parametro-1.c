/*

Estrutura de 3 variáveis inteiras, soma a e b e na terceira variável c guarda o resultado e imprime no corpo abaixo da chamada da função.

Definir o tipo da estrutura como parâmetro da função

- Vetores: são passados por referencia
- Valores int: são passados como cópia do valor

*/

#include <stdio.h>

struct VALORES
{
  int a;
  int b;
  int c;
};

int cadastrar(struct VALORES Y[4])
{

  for (int i = 0; i < 4; i++)
  {
    printf("Informe o A: ");
    scanf("%d", &Y[i].a);

    printf("Informe o B: ");
    scanf("%d", &Y[i].b);

    printf("Informe o C: ");
    scanf("%d", &Y[i].c);
  }

  return 0;
}

int somar(struct VALORES Y[4])
{

  for (int i = 0; i < 4; i++)
  {
    Y[i].c = Y[i].a + Y[i].b;
  }

  return 0;
}

int main()
{
  struct VALORES X[4];

  cadastrar(X);
  somar(X);

  for (int i = 0; i < 4; i++)
  {
    printf("O valor de C %d é = %d \n", i, X[i].c);
  }

  return 0;
}