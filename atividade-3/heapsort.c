#include <stdio.h>

// função criar um heap máximo
void heapify(int arr[], int n, int i)
{
  // inicializa o maior como raiz
  int largest = i;
  int left = 2 * i + 1;  // filho da esquerda
  int right = 2 * i + 2; // filho da direita

  // se o filho da esquerda for maior que a raiz
  if (left < n && arr[left] > arr[largest])
    largest = left;

  // se o filho da direita for maior que a raiz
  if (right < n && arr[right] > arr[largest])
    largest = right;

  // se o maior não for a raiz
  if (largest != i)
  {
    int temp = arr[i];
    arr[i] = arr[largest];
    arr[largest] = temp;
    heapify(arr, n, largest);
    // chama a função recursivamente para o subárvore afetado
  }
}

// função ordenar array usando heapsort
void heapSort(int arr[], int n)
{
  // constrói o heap
  for (int i = n / 2 - 1; i >= 0; i--)
  {
    heapify(arr, n, i); // chama a função heapify para cada nó não folha
  }

  // extrai um elemento por vez do heap
  for (int i = n - 1; i > 0; i--)
  {
    // move a raiz atual para o final
    int temp = arr[0];
    // troca o primeiro elemento com o último
    arr[0] = arr[i];
    // coloca o maior elemento na parte de trás
    arr[i] = temp;
    // chama a função heapify na heap reduzida
    heapify(arr, i, 0);
  }
}

// função imprimir array
void printArray(int arr[], int n)
{
  for (int i = 0; i < n; ++i)
    printf("%d ", arr[i]);
  printf("\n");
}

int main()
{
  int arr[] = {12, 11, 13, 5, 6, 7};
  // cria um array de inteiros

  int n = sizeof(arr) / sizeof(arr[0]);
  // cacula a quantidade de elementos do array

  printf("Array original:\n");
  printArray(arr, n);

  heapSort(arr, n);

  printf("Array ordenado:\n");
  printArray(arr, n);

  return 0;
}
