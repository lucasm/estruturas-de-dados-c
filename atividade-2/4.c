// 4. Escreva uma função que realize uma busca por um elemento. Ao encontrar o elemento, a função deve remover o nó da direita desse elemento;

#include <stdio.h>
#include <stdlib.h>

typedef struct lista
{
  int info;
  struct lista *prox;
} Lista;

Lista *insere(Lista *l, int i)
{
  Lista *novo = (Lista *)malloc(sizeof(Lista));
  novo->info = i;
  novo->prox = l;
  return novo;
}

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

Lista *buscaRemove(Lista *l, int i)
{
  Lista *p = l;
  while (p != NULL)
  {
    if (p->info == i && p->prox != NULL) // Verifica se encontrou o elemento e se existe um nó à direita
    {
      Lista *temp = p->prox; // Armazena o nó à direita do elemento encontrado
      p->prox = temp->prox;  // Conecta o elemento atual ao próximo do elemento à direita
      free(temp);            // Libera o nó à direita do elemento encontrado
      return l;
    }
    p = p->prox;
  }
  return l;
}

int main()
{
  Lista *l = NULL;

  l = insere(l, 1);
  l = insere(l, 2);
  l = insere(l, 3);
  l = insere(l, 4);
  l = insere(l, 5);
  l = insere(l, 6);

  imprime(l);

  l = buscaRemove(l, 3);

  imprime(l);

  return 0;
}