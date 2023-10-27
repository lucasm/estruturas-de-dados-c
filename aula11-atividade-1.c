/*

Atividade 1 - Supermercado

Crie um algoritmo para controlar os produtos do estoque de um supermercado.

Para cada produto, tem-se os seguintes campos:

  nome: string de tamanho 15
  setor: carácter
  quantidade: inteiro
  preço: real //preço por unidade do produto

a) Defina a estrutura produto acima.

b) Declare o vetor estoque do tipo da estrutura definida acima, de tamanho 100 e global.

Crie um menu para (opção 1, 2, 3 etc):

c) Definir um bloco de instruções com função cadastrar para inserir dados no vetor estoque.

d) Definir um bloco de instruções que receba um setor e devolva os produtos desse setor.

e) Definir um bloco de instruções que calcule e devolva o total de capital investido em produtos do supermercado.

f) Sair do Programa.

*/

#include <stdio.h>
#include <string.h>

// Limitar a quantidade de produtos a cadastrar
int quantidadeCadastro = 0;

// Definir a estrutura produto
struct Produto
{
  char nome[15];
  char setor[50];
  int quantidade;
  float preco;
};

struct Produto Estoque[100];

// Cadastrar produtos
void cadastrar()
{

  printf("Quantos produtos deseja cadastrar? ");
  scanf("%i", &quantidadeCadastro);

  for (int i = 0; i < quantidadeCadastro; i++)
  {
    printf("\n->>> CADASTRO DE PRODUTO %i <<<-\n", i + 1);

    printf("Nome: ");
    scanf("%s", &Estoque[i].nome);
    getchar();

    printf("Setor: ");
    scanf("%s", &Estoque[i].setor);
    getchar();

    printf("Quantidade: ");
    scanf("%i", &Estoque[i].quantidade);
    getchar();

    printf("Preço: ");
    scanf("%f", &Estoque[i].preco);
    getchar();
  }
}

// Listar produtos por setor
void listarPorSetor()
{
  char setor[50];

  printf("\n->>> LISTAR PRODUTOS POR SETOR <<<-\n");

  printf("Qual setor deseja exibir? ");
  scanf("%s", &setor);

  for (int i = 0; i < quantidadeCadastro; i++)
  {
    if (strcmp(Estoque[i].setor, setor) == 0)
    {
      printf("\n->>> PRODUTO %i <<<-\n", i + 1);

      printf("Nome: %s\n", Estoque[i].nome);
      printf("Setor: %s\n", Estoque[i].setor);
      printf("Quantidade: %i\n", Estoque[i].quantidade);
      printf("Preço: %.2f\n", Estoque[i].preco);
    }
  }
}

// Calcular o total de capital investido em produtos
void calcularTotalCapitalInvestido()
{
  float total = 0;

  for (int i = 0; i < quantidadeCadastro; i++)
  {
    total += Estoque[i].preco * Estoque[i].quantidade;
  }

  printf("Total de capital investido: %.2f", total);
}

// Criar menu para o programa
void menu()
{
  int opcao;

  do
  {
    printf("\n### MENU ###\n");

    printf("1 - Cadastrar produtos\n");
    printf("2 - Listar produtos por setor\n");
    printf("3 - Calcular total de capital investido\n");
    printf("4 - Sair\n");

    printf("Digite uma opção: ");
    scanf("%i", &opcao);
    getchar();

    switch (opcao)
    {
    case 1:
      cadastrar();
      break;
    case 2:
      listarPorSetor();
      break;
    case 3:
      calcularTotalCapitalInvestido();
      break;
    case 4:
      printf("Saindo...");
      break;
    default:
      printf("Opção inválida!");
      break;
    }
  } while (opcao != 4);
}

int main()
{
  menu();

  return 0;
}