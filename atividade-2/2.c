// 2.  Altere o código de uma lista encadeada simples para funcionar como uma lista encadeada circular;

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
  int valor;
  struct Node *prox;
} Node;

// Criar novo nó
Node *criaNode(int valor)
{
  Node *node = (Node *)malloc(sizeof(Node));
  node->valor = valor;
  node->prox = NULL;
  return node;
}

// Imprimir elementos da lista
void imprimir(struct Node *head)
{
  struct Node *temp = head;
  if (head != NULL)
  {
    do
    {
      printf("%d -> ", temp->valor);
      temp = temp->prox;
    } while (temp != head);
    printf("%d\n", temp->valor);
  }
}

int main()
{
  // criando nós
  Node *head = criaNode(111);
  Node *segundo = criaNode(222);
  Node *terceiro = criaNode(333);

  // ligando nós
  head->prox = segundo;
  segundo->prox = terceiro;
  terceiro->prox = head; // tornando a lista circular

  printf("Lista encadeada circular: ");
  imprimir(head);

  // provando que a lista é circular
  printf("\nValor do terceiro elemento: %d", terceiro->valor);
  printf("\nTerceiro elemento aponta para elemento de valor: %d\n", terceiro->prox->valor);

  return 0;

  /*

  Aprendizado:

  Uma lista encadeada circular é quando o último elemento aponta para o primeiro elemento, logo, para provar que a lista é circular, basta verificar se o último aponta para o primeiro

  */
}
