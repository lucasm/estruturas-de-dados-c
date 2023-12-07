// Implementação de uma pilha em C:

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct
{
  int items[MAX_SIZE];
  int top;
} Stack;

void initializeStack(Stack *stack)
{
  stack->top = -1;
}

int isFull(Stack *stack)
{
  return stack->top == MAX_SIZE - 1;
}

int isEmpty(Stack *stack)
{
  return stack->top == -1;
}

void push(Stack *stack, int value)
{
  if (isFull(stack))
  {
    printf("Erro: Pilha cheia\n");
    return;
  }
  stack->top++;
  stack->items[stack->top] = value;
}

int pop(Stack *stack)
{
  if (isEmpty(stack))
  {
    printf("Erro: Pilha vazia\n");
    return -1;
  }
  int value = stack->items[stack->top];
  stack->top--;
  return value;
}

int peek(Stack *stack)
{
  if (isEmpty(stack))
  {
    printf("Erro: Pilha vazia\n");
    return -1;
  }
  return stack->items[stack->top];
}

int main()
{
  Stack stack;
  initializeStack(&stack);

  push(&stack, 10);
  push(&stack, 20);
  push(&stack, 30);

  printf("Topo da pilha: %d\n", peek(&stack));

  printf("Desempilhando itens: %d, %d\n", pop(&stack), pop(&stack));

  printf("Topo da pilha após desempilhar: %d\n", peek(&stack));

  return 0;
}
