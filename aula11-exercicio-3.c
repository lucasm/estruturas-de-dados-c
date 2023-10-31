/*

Atividade 3 - Concessionária

Crie uma estrutura para descrever os carros de uma determinada revendedora, contendo os seguintes campos:

- marca: string de tamanho 15
- ano: inteiro
- cor: string de tamanho 10
- preço: real

a) Escrever a definição da estrutura carro.

b) Declarar o vetor com nome vetcarros do tipo acima, global de tamanho 20 (*** mudei para 6 para ficar mais fácil de testar ***).

Crie um menu para:

c) Função para inserir dados no vetor vetcarros.

d) Função que receba um preço e imprima os carros (marca, cor e ano) que tenham preço igual ou menor ao preço recebido.

e) Função que leia a marca de um carro e imprima as informações de todos os carros dessa marca (preço, ano e cor).

f) Função que leia uma marca, ano e cor e informe se existe ou não um carro com essas características. Se existir, informar o preço.

*/

#include <stdio.h>
#include <string.h>

// Definir a estrutura carro
struct Carro
{
  char marca[15];
  int ano;
  char cor[10];
  float preco;
};
// Declarar vetor global "vetcarros" com a estrutura para concessionária
struct Carro vetcarros[6];

// Inserir dados no vetor "vetcarros"
void inserirDados()
{
  for (int i = 0; i < 6; i++)
  {
    printf("\n->>> CADASTRO DE CARRO %i <<<-\n", i + 1);

    printf("Marca: ");
    scanf("%s", &vetcarros[i].marca);
    getchar();

    printf("Ano: ");
    scanf("%i", &vetcarros[i].ano);
    getchar();

    printf("Cor: ");
    scanf("%s", &vetcarros[i].cor);
    getchar();

    printf("Preço: ");
    scanf("%f", &vetcarros[i].preco);
    getchar();
  }
}

// Imprimir carros com preço igual ou menor ao preço recebido
void imprimirCarros(float preco)
{
  for (int i = 0; i < 6; i++)
  {
    if (vetcarros[i].preco <= preco)
    {
      printf("\n->>> CARRO %i <<<-\n", i + 1);

      printf("Marca: %s\n", vetcarros[i].marca);
      printf("Ano: %i\n", vetcarros[i].ano);
      printf("Cor: %s\n", vetcarros[i].cor);
      printf("Preço: %.2f\n", vetcarros[i].preco);
    }
  }
}

// Imprimir carros com marca recebida
void imprimirCarrosMarca(char marca[15])
{
  for (int i = 0; i < 6; i++)
  {
    if (strcmp(vetcarros[i].marca, marca) == 0)
    {
      printf("\n->>> CARRO %i <<<-\n", i + 1);

      printf("Marca: %s\n", vetcarros[i].marca);
      printf("Ano: %i\n", vetcarros[i].ano);
      printf("Cor: %s\n", vetcarros[i].cor);
      printf("Preço: %.2f\n", vetcarros[i].preco);
    }
  }
}

// Imprimir carros com marca, ano e cor recebidos
void imprimirCarrosMarcaAnoCor(char marca[15], int ano, char cor[10])
{
  for (int i = 0; i < 6; i++)
  {
    if (strcmp(vetcarros[i].marca, marca) == 0 && vetcarros[i].ano == ano && strcmp(vetcarros[i].cor, cor) == 0)
    {
      printf("\n->>> CARRO %i <<<-\n", i + 1);

      printf("Marca: %s\n", vetcarros[i].marca);
      printf("Ano: %i\n", vetcarros[i].ano);
      printf("Cor: %s\n", vetcarros[i].cor);
      printf("Preço: %.2f\n", vetcarros[i].preco);
    }
  }
}

// Menu para a concessionária
void menu()
{
  int opcao;
  float preco;
  char marca[15];
  int ano;
  char cor[10];

  do
  {
    printf("\n->>> CONCESSIONÁRIA <<<-\n");
    printf("1. Inserir dados\n");
    printf("2. Imprimir carros com preço igual ou menor ao preço recebido\n");
    printf("3. Imprimir carros com marca recebida\n");
    printf("4. Imprimir carros com marca, ano e cor recebidos\n");
    printf("5. Sair\n");
    printf("Opção: ");
    scanf("%i", &opcao);
    getchar();

    switch (opcao)
    {
    case 1:
      inserirDados();
      break;
    case 2:
      printf("Preço: ");
      scanf("%f", &preco);
      getchar();
      imprimirCarros(preco);
      break;
    case 3:
      printf("Marca: ");
      scanf("%s", &marca);
      getchar();
      imprimirCarrosMarca(marca);
      break;
    case 4:
      printf("Marca: ");
      scanf("%s", &marca);
      getchar();
      printf("Ano: ");
      scanf("%i", &ano);
      getchar();
      printf("Cor: ");
      scanf("%s", &cor);
      getchar();
      imprimirCarrosMarcaAnoCor(marca, ano, cor);
      break;
    case 5:
      printf("Saindo...\n");
      break;
    default:
      printf("Opção inválida!\n");
      break;
    }
  } while (opcao != 5);

  // preciso estudar melhor o do wile em C (!)
}

int main()
{

  menu();

  return 0;
}