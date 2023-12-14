/*
Considere a seguinte sequência de números: 25, 15, 30, 10, 20, 27, 35, 5, 12.

(a) Construa uma árvore binária de busca utilizando os números dados na sequência.

(b) Em que ordem os números serão visitados utilizando o percurso pré-ordem?

(c) Implemente uma função em C para encontrar o nó com o valor 20 na árvore e imprima o valor do nó pai desse nó encontrado.


*/

#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó da árvore
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

// Função para realizar o percurso pré-ordem na árvore
void preOrderTraversal(struct Node *node)
{
  if (node != NULL)
  {
    printf("%d ", node->data);
    preOrderTraversal(node->left);
    preOrderTraversal(node->right);
  }
}

// Função para encontrar o nó com valor 20 na árvore e imprimir o valor do nó pai
void findAndPrintParent(struct Node *node, int target)
{
  if (node == NULL)
  {
    printf("Nó não encontrado na árvore.\n");
    return;
  }

  if ((node->left != NULL && node->left->data == target) || (node->right != NULL && node->right->data == target))
  {
    printf("O nó pai de %d é: %d\n", target, node->data);
    return;
  }

  if (target < node->data)
  {
    findAndPrintParent(node->left, target);
  }
  else
  {
    findAndPrintParent(node->right, target);
  }
}

int main()
{
  struct Node *root = NULL;
  int elements[] = {25, 15, 30, 10, 20, 27, 35, 5, 12};
  int numElements = sizeof(elements) / sizeof(elements[0]);

  // Inserindo elementos na árvore
  for (int i = 0; i < numElements; i++)
  {
    root = insert(root, elements[i]);
  }

  printf("Árvore em pré-ordem: ");
  preOrderTraversal(root);
  printf("\n");

  // Encontrando o nó com valor 20 na árvore e imprimindo o valor do nó pai
  findAndPrintParent(root, 20);

  return 0;
}

/*

Resolução (a): A árvore binária de busca construída com os números fornecidos seria:

          25
        /    \
      15      30
     /  \    /  \
    10  20  27  35
   /     \
  5      12

Resolução (b): A ordem de visita dos números utilizando o percurso pré-ordem seria: 25, 15, 10, 5, 12, 20, 30, 27, 35.

Resolução (c): O nó com valor 20 na árvore tem como nó pai o valor 15.

*/