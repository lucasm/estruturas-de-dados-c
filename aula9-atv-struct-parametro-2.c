/*

Escreva um programa que o usuário deve informar idade e nome de 3 indivíduos e o programa deve imprimir o nome e a idade do mais velho e do mais novo.

Deve ter uma função para cadastrar e encontrar tais indivíduos.
Utilize vetores e estruturas.

*/

#include <stdio.h>

struct PESSOA
{
  int idade;
  char nome[50];
};

void cadastrar(struct PESSOA Y[3])
{

  for (int i = 0; i < 3; i++)
  {
    printf("***  Pessoa %d *** \n", i + 1);

    printf("Nome: ");
    scanf("%s", Y[i].nome);
    // nome já é um vetor, então não precisa declarar o &Y[i].nome

    printf("Idade: ");
    scanf("%i", &Y[i].idade);
  }
}

int posicaoMaiorIdade(struct PESSOA Y[3])
{
  int tempIdade = 0, posicaoMaior;

  for (int i = 0; i < 3; i++)
  {
    if (Y[i].idade > tempIdade)
    {
      tempIdade = Y[i].idade;
      posicaoMaior = i;
    }
  }

  return (posicaoMaior);
}

int posicaoMenorIdade(struct PESSOA Y[3])
{
  int tempIdade = 200, posicaoMaior;

  for (int i = 0; i < 3; i++)
  {
    if (Y[i].idade < tempIdade)
    {
      tempIdade = Y[i].idade;
      posicaoMaior = i;
    }
  }

  return (posicaoMaior);
}

int main()
{
  struct PESSOA X[3];

  cadastrar(X);

  int maior = posicaoMaiorIdade(X);
  int menor = posicaoMenorIdade(X);

  printf("\n\n***  Pessoa mais velha *** \n %s, %i", X[maior].nome, X[maior].idade);
  printf("\n\n***  Pessoa mais nova *** \n %s, %i", X[menor].nome, X[menor].idade);

  return 0;
}