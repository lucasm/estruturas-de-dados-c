/*

Construa a árvore binária de busca utilizando os valores fornecidos: 50, 30, 70, 20, 40, 60, 80.

Liste os valores dos nós na árvore em ordem utilizando o percurso em ordem (in-order traversal).

Qual é a altura da árvore construída?

Implemente uma função para verificar se um valor específico, por exemplo, 40, está presente na árvore.

Escreva uma função para contar o número total de nós na árvore.

Seja possível remover um nó da árvore, implemente uma função para remover um nó específico, por exemplo, remova o nó com valor 30 da árvore.

Adicione o valor 90 na árvore.

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

// Função para realizar o percurso em ordem na árvore
void inOrderTraversal(struct Node *node)
{
  if (node != NULL)
  {
    inOrderTraversal(node->left);
    printf("%d ", node->data);
    inOrderTraversal(node->right);
  }
}

// Função para calcular a altura da árvore
int treeHeight(struct Node *node)
{
  if (node == NULL)
  {
    return -1;
  }
  else
  {
    int leftHeight = treeHeight(node->left);
    int rightHeight = treeHeight(node->right);

    if (leftHeight > rightHeight)
    {
      return leftHeight + 1;
    }
    else
    {
      return rightHeight + 1;
    }
  }
}

// Função para verificar se um valor está presente na árvore
int searchValue(struct Node *node, int value)
{
  if (node == NULL)
  {
    return 0;
  }

  if (node->data == value)
  {
    return 1;
  }

  if (value < node->data)
  {
    return searchValue(node->left, value);
  }
  else
  {
    return searchValue(node->right, value);
  }
}

// Função para contar o número de nós na árvore
int countNodes(struct Node *node)
{
  if (node == NULL)
  {
    return 0;
  }

  return 1 + countNodes(node->left) + countNodes(node->right);
}

// Função para encontrar o nó mínimo na subárvore direita
struct Node *findMinRight(struct Node *node)
{
  while (node->left != NULL)
  {
    node = node->left;
  }
  return node;
}

// Função para remover um nó específico da árvore
struct Node *removeNode(struct Node *root, int value)
{
  if (root == NULL)
  {
    return root;
  }

  if (value < root->data)
  {
    root->left = removeNode(root->left, value);
  }
  else if (value > root->data)
  {
    root->right = removeNode(root->right, value);
  }
  else
  {
    // Nó com apenas um filho ou sem filhos
    if (root->left == NULL)
    {
      struct Node *temp = root->right;
      free(root);
      return temp;
    }
    else if (root->right == NULL)
    {
      struct Node *temp = root->left;
      free(root);
      return temp;
    }

    // Nó com dois filhos: encontrar o menor nó na subárvore direita
    struct Node *temp = findMinRight(root->right);

    // Copiar o valor do nó mínimo encontrado para o nó atual
    root->data = temp->data;

    // Remover o nó mínimo da subárvore direita
    root->right = removeNode(root->right, temp->data);
  }
  return root;
}

// Função para inserir um novo nó na árvore
struct Node *insertNode(struct Node *root, int value)
{
  if (root == NULL)
  {
    return createNode(value);
  }

  struct Node *current = root;
  struct Node *parent = NULL;

  while (current != NULL)
  {
    parent = current;

    if (value < current->data)
    {
      current = current->left;
    }
    else if (value > current->data)
    {
      current = current->right;
    }
    else
    {
      // Valor já existe na árvore
      return root;
    }
  }

  if (value < parent->data)
  {
    parent->left = createNode(value);
  }
  else
  {
    parent->right = createNode(value);
  }

  return root;
}

int main()
{
  struct Node *root = NULL;
  int elements[] = {50, 30, 70, 20, 40, 60, 80};
  int numElements = sizeof(elements) / sizeof(elements[0]);

  // Inserindo elementos na árvore
  for (int i = 0; i < numElements; i++)
  {
    root = insert(root, elements[i]);
  }

  // (7) Inserindo o valor 90 na árvore
  int valueToInsert = 90;
  printf("7. Inserindo o valor %d na árvore\n", valueToInsert);
  root = insertNode(root, valueToInsert);

  // (1) Imprimindo a árvore em ordem
  printf("1. Árvore em ordem: ");
  inOrderTraversal(root);
  printf("\n");

  // (2) Calculando e imprimindo a altura da árvore
  printf("2. Altura da árvore: %d\n", treeHeight(root));

  // (3) Verificando a presença do valor 40 na árvore
  int valueToSearch = 40;
  printf("3. O valor %d está presente na árvore? %s\n", valueToSearch, searchValue(root, valueToSearch) ? "Sim" : "Não");

  // (4) Contando o número de nós na árvore
  printf("4. Número total de nós na árvore: %d\n", countNodes(root));

  // (5) Removendo o nó com valor 30
  int nodeToRemove = 30;
  root = removeNode(root, nodeToRemove);
  printf("5. Removendo o nó com valor %d\n", nodeToRemove);

  // (6) Imprimindo a árvore em ordem após a remoção
  printf("6. Árvore em ordem após a remoção: ");
  inOrderTraversal(root);
  printf("\n");

  return 0;
}
