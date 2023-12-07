// 3. Altere o código de uma lista encadeada simples para funcionar como uma lista duplamente encadeada;

#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura da lista
typedef struct lista
{
  int info;
  struct lista *ant;
  struct lista *prox;
} Lista;

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
  novo->prox = NULL;
  novo->ant = NULL;

  if (l == NULL)
  {
    // Se a lista estiver vazia, o novo elemento será o primeiro e o último
    l = novo;
  }
  else
  {
    Lista *aux = l;
    while (aux->prox != NULL)
    {
      aux = aux->prox;
    }
    // Conecta o novo elemento ao último elemento da lista
    aux->prox = novo;
    novo->ant = aux;
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
}
