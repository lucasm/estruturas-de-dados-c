// Criar uma estrutura simples de Fila em C

// Definir a estrutura Fila
struct Fila
{
  int inicio;
  int fim;
  int tamanho;
  int elementos[5];
};

// Inicializar a Fila
void inicializarFila(struct Fila *fila)
{
  fila->inicio = 0;
  fila->fim = -1;
  fila->tamanho = 0;
}

// Verificar se a Fila está vazia
int filaVazia(struct Fila *fila)
{
  if (fila->tamanho == 0)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

// Verificar se a Fila está cheia
int filaCheia(struct Fila *fila)
{
  if (fila->tamanho == 5)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

// Inserir elemento na Fila
void inserirElemento(struct Fila *fila, int elemento)
{
  if (filaCheia(fila) == 1)
  {
    printf("A fila está cheia!\n");
  }
  else
  {
    fila->fim = (fila->fim + 1) % 5;
    fila->elementos[fila->fim] = elemento;
    fila->tamanho++;
  }
}

// Remover elemento da Fila
int removerElemento(struct Fila *fila)
{
  if (filaVazia(fila) == 1)
  {
    printf("A fila está vazia!\n");
    return -1;
  }
  else
  {
    int elemento = fila->elementos[fila->inicio];
    fila->inicio = (fila->inicio + 1) % 5;
    fila->tamanho--;
    return elemento;
  }
}

// Imprimir elementos da Fila
void imprimirFila(struct Fila *fila)
{
  if (filaVazia(fila) == 1)
  {
    printf("A fila está vazia!\n");
  }
  else
  {
    printf("Elementos da fila:\n");
    for (int i = 0; i < fila->tamanho; i++)
    {
      printf("%i\n", fila->elementos[(fila->inicio + i) % 5]);
    }
  }
}

// Menu para a Fila
void menu()
{
  int opcao;
  int elemento;
  struct Fila fila;

  inicializarFila(&fila);

  do
  {
    printf("\n->>> FILA <<<-\n");
    printf("1. Inserir elemento\n");
    printf("2. Remover elemento\n");
    printf("3. Imprimir fila\n");
    printf("4. Sair\n");
    printf("Digite uma opção: ");
    scanf("%i", &opcao);

    switch (opcao)
    {
    case 1:
      printf("Digite um elemento: ");
      scanf("%i", &elemento);
      inserirElemento(&fila, elemento);
      break;
    case 2:
      removerElemento(&fila);
      break;
    case 3:
      imprimirFila(&fila);
      break;
    case 4:
      printf("Saindo...\n");
      break;
    default:
      printf("Opção inválida!\n");
      break;
    }
  } while (opcao != 4);
}

// Função principal
int main()
{
  menu();
  return 0;
}