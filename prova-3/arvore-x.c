#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node *left;
  struct Node *right;
};

struct Node *createNode(int value)
{
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = value;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

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

void inOrderTraversal(struct Node *node)
{
  if (node != NULL)
  {
    inOrderTraversal(node->left);
    printf("%d ", node->data);
    inOrderTraversal(node->right);
  }
}

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

int countNodes(struct Node *node)
{
  if (node == NULL)
  {
    return 0;
  }

  return 1 + countNodes(node->left) + countNodes(node->right);
}

int minValue(struct Node *node)
{
  struct Node *current = node;

  while (current->left != NULL)
  {
    current = current->left;
  }

  return current->data;
}

int countNodesWithOneOrNoChild(struct Node *node)
{
  if (node == NULL)
  {
    return 0;
  }

  if (node->left == NULL || node->right == NULL)
  {
    return 1 + countNodesWithOneOrNoChild(node->left) + countNodesWithOneOrNoChild(node->right);
  }
  else
  {
    return countNodesWithOneOrNoChild(node->left) + countNodesWithOneOrNoChild(node->right);
  }
}

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

    struct Node *temp = root->right;
    while (temp->left != NULL)
    {
      temp = temp->left;
    }

    root->data = temp->data;
    root->right = removeNode(root->right, temp->data);
  }
  return root;
}

int main()
{
  struct Node *root = NULL;
  int elements[] = {50, 30, 70, 20, 40, 60, 80, 35, 45};

  for (int i = 0; i < sizeof(elements) / sizeof(elements[0]); i++)
  {
    root = insert(root, elements[i]);
  }

  printf("Árvore em ordem: ");
  inOrderTraversal(root);
  printf("\n");

  printf("Altura da árvore: %d\n", treeHeight(root));

  int valueToSearch = 40;
  printf("O valor %d está presente na árvore? %s\n", valueToSearch, searchValue(root, valueToSearch) ? "Sim" : "Não");

  printf("Número total de nós na árvore: %d\n", countNodes(root));

  printf("Valor mínimo na árvore: %d\n", minValue(root));

  printf("Número de nós com um ou nenhum filho: %d\n", countNodesWithOneOrNoChild(root));

  int nodeToRemove1 = 20;
  int nodeToRemove2 = 60;
  root = removeNode(root, nodeToRemove1);
  root = removeNode(root, nodeToRemove2);

  printf("Árvore em ordem após a remoção de 20 e 60: ");
  inOrderTraversal(root);
  printf("\n");

  return 0;
}
