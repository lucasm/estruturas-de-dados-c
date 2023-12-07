// 2.  Crie uma lista encadeada circular;

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
  int data;
  struct Node *next;
} Node;

Node *criarNo(int data)
{
  Node *novoNo = (Node *)malloc(sizeof(Node));
  novoNo->data = data;
  novoNo->next = NULL;
  return novoNo;
}

void adicionarNo(Node **cabeca, int data)
{
  Node *novoNo = criarNo(data);
  if (*cabeca == NULL)
  {
    *cabeca = novoNo;
    novoNo->next = *cabeca; // Aponta de volta para si mesmo, pois é o único nó na lista
  }
  else
  {
    Node *temp = *cabeca;
    while (temp->next != *cabeca)
    {
      temp = temp->next;
    }
    temp->next = novoNo;
    novoNo->next = *cabeca; // Faz o último nó apontar de volta para o primeiro
  }
}

void imprimirLista(Node *cabeca)
{
  Node *temp = cabeca;
  if (cabeca != NULL)
  {
    do
    {
      printf("%d ", temp->data);
      temp = temp->next;
    } while (temp != cabeca);
  }
  printf("\n");
}

int main()
{
  Node *cabeca = NULL;

  adicionarNo(&cabeca, 1);
  adicionarNo(&cabeca, 2);
  adicionarNo(&cabeca, 3);
  adicionarNo(&cabeca, 4);
  adicionarNo(&cabeca, 5);

  imprimirLista(cabeca);

  return 0;
}
