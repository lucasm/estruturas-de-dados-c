// implementação de uma lista encadeada em C

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
  int data;
  struct Node *next;
} Node;

typedef struct
{
  Node *head;
} LinkedList;

void initializeList(LinkedList *list)
{
  list->head = NULL;
}

void insertFront(LinkedList *list, int value)
{
  Node *newNode = (Node *)malloc(sizeof(Node));
  if (newNode == NULL)
  {
    printf("Erro: Falha na alocação de memória\n");
    return;
  }
  newNode->data = value;
  newNode->next = list->head;
  list->head = newNode;
}

void displayList(LinkedList *list)
{
  Node *current = list->head;
  if (current == NULL)
  {
    printf("Lista vazia\n");
    return;
  }
  printf("Elementos da lista: ");
  while (current != NULL)
  {
    printf("%d ", current->data);
    current = current->next;
  }
  printf("\n");
}

int main()
{
  LinkedList list;
  initializeList(&list);

  insertFront(&list, 30);
  insertFront(&list, 20);
  insertFront(&list, 10);

  displayList(&list);

  return 0;
}
