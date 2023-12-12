#include <stdio.h>

// função criar um heap máximo
void heapify(int arr[], int n, int i)
{
  // inicializa o maior como raiz do heap
  int largest = i;       // raiz
  int left = 2 * i + 1;  // filho da esquerda
  int right = 2 * i + 2; // filho da direita

  // filho esquerda > raiz atual
  if (left < n && arr[left] > arr[largest])
  {
    largest = left; // troca raiz
  }

  // filho direita > raiz atual
  if (right < n && arr[right] > arr[largest])
  {
    largest = right; // troca raiz
  }

  // maior não for a raiz atual
  if (largest != i)
  {
    int temp = arr[i]; // troca a raiz com o maior
    arr[i] = arr[largest];
    arr[largest] = temp;
    heapify(arr, n, largest); // chama recursivamente para a subárvore afetada
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
    int temp = arr[0];  // move a raiz atual para o final
    arr[0] = arr[i];    // troca o primeiro elemento com o último
    arr[i] = temp;      // coloca o maior elemento na parte de trás
    heapify(arr, i, 0); // chama a função heapify na heap reduzida
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
