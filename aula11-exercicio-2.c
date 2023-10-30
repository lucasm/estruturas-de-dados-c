/*

Atividade 1 - Condomínio

Sistema destinado a controlar despesas e dados de um condomínio de apartamentos.

Os dados de cada apartamento são armazenados em um vetor de estruturas, onde para cada apartamento tem-se os seguintes dados:

- nome do responsável
- número do apartamento
- área (em m2)
- número de moradores
- valor (a ser pago no mês)

1. Definir a estrutura acima.

2. Declarar um vetor de estruturas (global), suponde que o condomínio tem 6 apartamentos.

3. Crie um menu para:

    a. Função para inserir dados no vetor acima, exceto campo valor

    b. Função que retorna a área total do condomínio

    c. Função que calcula o valor a ser pago no mês para cada apartamento. O valor é proporcional a área do apartamento. Leia o total de despesas do condomínio e calcule a relação entre a área total do condomínio.

    d. Função para imprimir os dados do apartamento que tem o maior número de moradores (em caso de haver mais de um, imprimir todos)

    e. Função para sair do programa

*/

#include <stdio.h>
#include <string.h>

// Definir a estrutura apartamento
struct Apartamento
{
  char responsavel[50];
  int numero;
  float area;
  int moradores;
  float valor;
};

// Declarar vetor de estruturas global para condomínio com 6 apartamentos
struct Apartamento Condominio[6];

// Inserir dados no vetor de estruturas, exceto campo valor
void inserirDados()
{
  for (int i = 0; i < 6; i++)
  {
    printf("\n->>> CADASTRO DE APARTAMENTO %i <<<-\n", i + 1);

    printf("Responsável: ");
    scanf("%s", &Condominio[i].responsavel);
    getchar();

    printf("Número: ");
    scanf("%i", &Condominio[i].numero);
    getchar();

    printf("Área (em m2): ");
    scanf("%f", &Condominio[i].area);
    getchar();

    printf("Número de moradores: ");
    scanf("%i", &Condominio[i].moradores);
    getchar();
  }
}

// Retorna a área total do condomínio
float areaTotal()
{
  float areaTotal = 0;

  for (int i = 0; i < 6; i++)
  {
    areaTotal += Condominio[i].area;
  }

  return areaTotal;
}

void calcularValor(float areaTotal)
{
  float valorTotalDespesas, valorPago;

  printf("Total de despesas do condomínio: ");
  scanf("%f", &valorTotalDespesas);
  getchar();

  for (int i = 0; i < 6; i++)
  {
    valorPago = (Condominio[i].area / areaTotal) * valorTotalDespesas;

    printf("\n->>> APARTAMENTO %i <<<-\n", i + 1);

    printf("Responsável: %s\n", Condominio[i].responsavel);
    printf("Número: %i\n", Condominio[i].numero);
    printf("Área (em m2): %.2f\n", Condominio[i].area);
    printf("Número de moradores: %i\n", Condominio[i].moradores);
    printf("Valor: %.2f\n", valorPago);
  }
}

// Imprime os dados do apartamento que tem o maior número de moradores (em caso de haver mais de um, imprime todos)
void imprimirMaiorNumeroMoradores()
{
  int maiorNumeroMoradores = 0;

  for (int i = 0; i < 6; i++)
  {
    if (Condominio[i].moradores > maiorNumeroMoradores)
    {
      maiorNumeroMoradores = Condominio[i].moradores;
    }
  }

  for (int i = 0; i < 6; i++)
  {
    if (Condominio[i].moradores == maiorNumeroMoradores)
    {
      printf("\n->>> APARTAMENTO %i <<<-\n", i + 1);

      printf("Responsável: %s\n", Condominio[i].responsavel);
      printf("Número: %i\n", Condominio[i].numero);
      printf("Área (em m2): %.2f\n", Condominio[i].area);
      printf("Número de moradores: %i\n", Condominio[i].moradores);
      printf("Valor: %.2f\n", Condominio[i].valor);
    }
  }
}

// Menu
void menu()
{
  int opcao;

  do
  {
    printf("\n->>> MENU <<<-\n");
    printf("1. Inserir dados dos apartamento\n");
    printf("2. Ver área total do condomínio\n");
    printf("3. Calcular valor a ser pago\n");
    printf("4. Ver apartamento com maior número de moradores\n");
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
      printf("Área total do condomínio: %.2f", areaTotal());
      break;
    case 3:
      calcularValor(areaTotal());
      break;
    case 4:
      imprimirMaiorNumeroMoradores();
      break;
    case 5:
      printf("Saindo...");
      break;
    default:
      printf("Opção inválida!");
      break;
    }
  } while (opcao != 5);
}

int main()
{
  menu();

  return 0;
}