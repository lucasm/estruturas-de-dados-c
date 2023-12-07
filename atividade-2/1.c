// 1. Sejam duas listas encadeadas, desenvolva uma função que recebe duas listas encadeadas e retorne a lista encadeada resultante da concatenação.

#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura da lista
typedef struct lista
{
  int info;
  struct lista *prox;
} Lista;

// Função que concatena duas listas
Lista *concatena(Lista *l1, Lista *l2)
{
  Lista *p = l1;
  while (p->prox != NULL)
  {
    p = p->prox;
  }
  p->prox = l2;
  return l1;
}

// Função que imprime a lista
void imprime(Lista *l)
{
  Lista *p = l;
  while (p != NULL)
  {
    printf("%d ", p->info);
    p = p->prox;
  }
  printf("\n");
}

// Função que insere um elemento na lista
Lista *insere(Lista *l, int i)
{
  Lista *novo = (Lista *)malloc(sizeof(Lista));
  novo->info = i;
  novo->prox = l;
  return novo;
}

int main()
{
  Lista *l1 = NULL;
  Lista *l2 = NULL;

  l1 = insere(l1, 1);
  l1 = insere(l1, 2);
  l1 = insere(l1, 3);
  l2 = insere(l2, 4);
  l2 = insere(l2, 5);
  l2 = insere(l2, 6);

  imprime(l1);
  imprime(l2);

  Lista *l3 = concatena(l1, l2);
  imprime(l3);

  return 0;
}