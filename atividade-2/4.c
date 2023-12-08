// 4. Escreva uma função que realize uma busca por um elemento. Ao encontrar o elemento, a função deve remover o nó da direita desse elemento;

#include <stdio.h>
#include <stdlib.h>

typedef struct lista
{
  int data;
  struct lista *prox;
} Lista;

// insere um elemento no início da lista
Lista *inserir(Lista *l, int i)
{
  Lista *novo = (Lista *)malloc(sizeof(Lista));
  novo->data = i;
  novo->prox = l;
  return novo;
}

void imprimir(Lista *l)
{
  Lista *p = l;
  while (p != NULL)
  {
    printf("%d ", p->data);
    p = p->prox;
  }
  printf("\n");
}

// busca um elemento e remove o nó à direita
Lista *buscarRemover(Lista *l, int i)
{
  Lista *p = l;

  while (p != NULL)
  {
    if (p->data == i && p->prox != NULL) // se elemento existe e com nó na direita
    {
      Lista *temp = p->prox; // armazena o nó da direita
      p->prox = temp->prox;  // conecta o elemento atual ao próximo do nó da direita
      free(temp);            // libera nó da direita
      return l;
    }
    p = p->prox;
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

  l = buscarRemover(l, 4);

  imprimir(l);

  return 0;

  /*

  Aprendizados:

  Criei a função buscaRemover() que itera a lista até encontrar o alvo. Ao encontrar, verifica se existe nó na direita. Se existir, conecta o elemento atual ao próximo do elemento da direita e libera o nó da direita que ficou isolado. Senão retorna a lista original.

  *** free(temp) é a função nativa do C para liberar memória em uso.

  */
}