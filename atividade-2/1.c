// 1. Sejam duas listas encadeadas, desenvolva uma função que recebe duas listas encadeadas e retorne a lista encadeada resultante da concatenação;

#include <stdio.h>
#include <stdlib.h>

// Estrutura do nó
typedef struct Node
{
  int valor;
  struct Node *prox;
} Node;

// Adicionar elemento no final da lista
void append(Node **head_ref, int new_data)
{
  Node *new_node = (Node *)malloc(sizeof(Node));
  Node *last = *head_ref;

  new_node->valor = new_data;
  new_node->prox = NULL;

  if (*head_ref == NULL)
  {
    *head_ref = new_node;
    return;
  }

  while (last->prox != NULL)
  {
    last = last->prox;
  }

  last->prox = new_node;
}

// Concatenar duas listas encadeadas
Node *concatenar(Node *l1, Node *l2)
{

  Node *current = l1;
  while (current->prox != NULL)
  {
    current = current->prox;
  }

  current->prox = l2;
  return l1;
}

// Imprimir lista encadeada
void imprimir(Node *node)
{
  while (node != NULL)
  {
    printf("%d ", node->valor);
    node = node->prox;
  }
  printf("\n");
}

int main()
{
  Node *l1 = NULL;
  Node *l2 = NULL;

  append(&l1, 1);
  append(&l1, 2);
  append(&l1, 3);
  append(&l2, 4);
  append(&l2, 5);
  append(&l2, 6);

  printf("Lista 1: ");
  imprimir(l1);
  printf("Lista 2: ");
  imprimir(l2);

  l1 = concatenar(l1, l2);

  printf("Lista concatenada: ");
  imprimir(l1);

  return 0;

  /*

  Aprendizado: Concatenar listas encadeadas

  Usei uma função "append" convencional para inserir itens no final da lista encadeada. Logo, concatenar listas encadeadas fica fácil, basta percorrer a lista 1 até o último nó e fazer esse último nó apontar para o primeiro nó da lista 2.

  *** Colocar o asterisco (*) no início da declaração de função indica que a função retorna um ponteiro para um nó. Nesse caso é o primeiro nó da lista concatenada, que é o primeiro nó da então lista 1.

  *** malloc() é a função nativa do C que aloca memória dinamicamente.  Recebe como parâmetro o tamanho da memória que será alocada. Nesse caso, o tamanho da memória é o tamanho da estrutura Node.
  */
}
