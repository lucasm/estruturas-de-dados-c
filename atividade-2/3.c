// 3. Altere o código de uma lista encadeada simples para funcionar como uma lista duplamente encadeada;

#include <stdio.h>
#include <stdlib.h>

typedef struct lista
{
  int valor;
  struct lista *ant;
  struct lista *prox;
} Lista;

void imprimir(Lista *l)
{
  Lista *p = l;
  while (p != NULL)
  {
    printf("%d ", p->valor);
    p = p->prox;
  }
  printf("\n");
}
void imprimirReverso(Lista *l)
{
  Lista *p = l;
  while (p->prox != NULL)
  {
    p = p->prox;
  }

  while (p != NULL)
  {
    printf("%d ", p->valor);
    p = p->ant;
  }
  printf("\n");
}

Lista *inserir(Lista *l, int i)
{
  Lista *novo = (Lista *)malloc(sizeof(Lista));
  novo->valor = i;
  novo->prox = NULL;
  novo->ant = NULL;

  if (l == NULL)
  {
    // se a lista for vazia, o novo elemento será o primeiro e o último
    l = novo;
  }
  else
  {
    Lista *aux = l;
    while (aux->prox != NULL)
    {
      aux = aux->prox;
    }
    // conecta o novo elemento ao último elemento da lista
    aux->prox = novo;
    novo->ant = aux;
  }

  return l;
}

int main()
{
  Lista *l = NULL;

  l = inserir(l, 1);
  l = inserir(l, 2);
  l = inserir(l, 3);
  l = inserir(l, 4);
  l = inserir(l, 5);
  l = inserir(l, 6);

  imprimir(l);
  imprimirReverso(l); // provando que a lista é duplamente encadeada (imprimindo de trás pra frente) usando o ponteiro ant
}
