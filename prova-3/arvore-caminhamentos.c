/*

Considere uma árvore binária de busca com os seguintes valores: 50, 30, 70, 20, 40, 60, 80.

Implemente um código em C para realizar os três tipos de percurso na árvore:

- pré-ordem
- ordem
- pós-ordem

*/

#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node *left;
  struct Node *right;
};

// Função para criar um novo nó
struct Node *createNode(int value)
{
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = value;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

// Função para inserir um novo nó na árvore
struct Node *insert(struct Node *node, int value)
{
  if (node == NULL)
  {
    return createNode(value);
  }

  if (value < node->data)
  {
    node->left = insert(node->left, value);
  }
  else if (value > node->data)
  {
    node->right = insert(node->right, value);
  }

  return node;
}

// Função para percorrer a árvore em pré-ordem
void preOrderTraversal(struct Node *node)
{
  if (node != NULL)
  {
    printf("%d ", node->data);
    preOrderTraversal(node->left);
    preOrderTraversal(node->right);
  }
}

// Função para percorrer a árvore em ordem
void inOrderTraversal(struct Node *node)
{
  if (node != NULL)
  {
    inOrderTraversal(node->left);
    printf("%d ", node->data);
    inOrderTraversal(node->right);
  }
}

// Função para percorrer a árvore em pós-ordem
void postOrderTraversal(struct Node *node)
{
  if (node != NULL)
  {
    postOrderTraversal(node->left);
    postOrderTraversal(node->right);
    printf("%d ", node->data);
  }
}

int main()
{
  struct Node *root = NULL;
  int elements[] = {50, 30, 70, 20, 40, 60, 80};

  for (int i = 0; i < sizeof(elements) / sizeof(elements[0]); i++)
  {
    root = insert(root, elements[i]);
  }

  printf("Percurso Pré-ordem: ");
  preOrderTraversal(root);
  printf("\n");

  printf("Percurso Em ordem: ");
  inOrderTraversal(root);
  printf("\n");

  printf("Percurso Pós-ordem: ");
  postOrderTraversal(root);
  printf("\n");

  return 0;
}
