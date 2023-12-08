// 6. Escreva um programa que recebe caracteres de um usuário como entrada. O programa deve colocar esses caracteres em uma 'fila' até que o conjunto de caracteres 'COMPUTACAO' seja informado. Dica: Utilize uma pilha fixa de 10 caracteres na resolução do problema e uma fila convencional;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10

typedef struct
{
  char itens[MAX_SIZE];
  int topo;
} Pilha;

typedef struct
{
  char itens[MAX_SIZE];
  int frente, tras;
} Fila;

void inicializarPilha(Pilha *p)
{
  p->topo = -1;
}

int estaVaziaPilha(Pilha *p)
{
  return p->topo == -1;
}

int estaCheiaPilha(Pilha *p)
{
  return p->topo == MAX_SIZE - 1;
}

void empilhar(Pilha *p, char item)
{
  if (estaCheiaPilha(p))
  {
    printf("Erro: a pilha está cheia\n");
    return;
  }
  p->itens[++(p->topo)] = item;
}

char desempilhar(Pilha *p)
{
  if (estaVaziaPilha(p))
  {
    printf("Erro: a pilha está vazia\n");
    return '\0';
  }
  return p->itens[(p->topo)--];
}

void inicializarFila(Fila *f)
{
  f->frente = 0;
  f->tras = -1;
}

int estaVaziaFila(Fila *f)
{
  return f->tras < f->frente;
}

int estaCheiaFila(Fila *f)
{
  return f->tras == MAX_SIZE - 1;
}

void enfileirar(Fila *f, char item)
{
  if (estaCheiaFila(f))
  {
    printf("Erro: a fila está cheia\n");
    return;
  }
  f->itens[++(f->tras)] = item;
}

char desenfileirar(Fila *f)
{
  if (estaVaziaFila(f))
  {
    printf("Erro: a fila está vazia\n");
    return '\0';
  }
  return f->itens[(f->frente)++];
}

int main()
{
  Pilha pilha;
  Fila fila;

  inicializarPilha(&pilha);
  inicializarFila(&fila);

  char entrada;
  char sequencia[] = "COMPUTACAO";
  int indice_sequencia = 0;

  printf("Digite os caracteres (max. 10) ou 'COMPUTACAO' para encerrar:\n");

  do
  {
    scanf(" %c", &entrada);
    enfileirar(&fila, entrada);

    if (entrada == sequencia[indice_sequencia])
    {
      empilhar(&pilha, entrada);
      indice_sequencia++;
    }
    else
    {
      indice_sequencia = 0;
      while (!estaVaziaPilha(&pilha))
      {
        char removido = desempilhar(&pilha);
        enfileirar(&fila, removido);
      }
    }

    if (indice_sequencia == strlen(sequencia))
    {
      printf("Sequencia 'COMPUTACAO' encontrada!\n");
      break;
    }
  } while (!estaCheiaFila(&fila));

  printf("Conteudo da fila: ");
  while (!estaVaziaFila(&fila))
  {
    printf("%c ", desenfileirar(&fila));
  }
  printf("\n");

  return 0;
}
