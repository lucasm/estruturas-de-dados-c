/*
Exercício

Implementar uma Fila com Lista Encadeada com 1 Ponteiro no início e 1 Ponteiro no fim.

Criar função de enfileirar (inserir no fim) e desenfileirar (remover do início) aproveitando os ponteiros de início e fim.

Criar função de imprimir a Fila.
*/

typedef struct meuNO
{
  char dado;
  struct meuNO *ptr;
} NO;
