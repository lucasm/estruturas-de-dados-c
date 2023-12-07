// 6. Escreva um programa que recebe caracteres de um usuário como entrada. O programa deve colocar esses caracteres em uma 'fila' até que o conjunto de caracteres 'COMPUTACAO' seja informado. Dica: Utilize uma pilha fixa de 10 caracteres na resolução do problema e uma fila convencional;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STACK_SIZE 10
#define QUEUE_SIZE 100

// Definição da estrutura de pilha
typedef struct
{
  char items[STACK_SIZE];
  int top;
} Stack;

// Definição da estrutura de fila
typedef struct
{
  char items[QUEUE_SIZE];
  int front, rear;
} Queue;

// Função para inicializar a pilha
void initializeStack(Stack *stack)
{
  stack->top = -1;
}

// Função para verificar se a pilha está vazia
int isStackEmpty(Stack *stack)
{
  return (stack->top == -1);
}

// Função para verificar se a pilha está cheia
int isStackFull(Stack *stack)
{
  return (stack->top == STACK_SIZE - 1);
}

// Função para empilhar um caractere na pilha
void push(Stack *stack, char value)
{
  if (isStackFull(stack))
  {
    printf("Erro: Pilha cheia\n");
  }
  else
  {
    stack->items[++(stack->top)] = value;
  }
}

// Função para desempilhar um caractere da pilha
char pop(Stack *stack)
{
  if (isStackEmpty(stack))
  {
    printf("Erro: Pilha vazia\n");
    return '\0';
  }
  else
  {
    return stack->items[(stack->top)--];
  }
}

// Função para inicializar a fila
void initializeQueue(Queue *queue)
{
  queue->front = queue->rear = -1;
}

// Função para verificar se a fila está vazia
int isQueueEmpty(Queue *queue)
{
  return (queue->front == -1);
}

// Função para verificar se a fila está cheia
int isQueueFull(Queue *queue)
{
  return ((queue->rear + 1) % QUEUE_SIZE == queue->front);
}

// Função para enfileirar um caractere na fila
void enqueue(Queue *queue, char value)
{
  if (isQueueFull(queue))
  {
    printf("Erro: Fila cheia\n");
  }
  else
  {
    if (isQueueEmpty(queue))
    {
      queue->front = 0;
    }
    queue->rear = (queue->rear + 1) % QUEUE_SIZE;
    queue->items[queue->rear] = value;
  }
}

// Função para desenfileirar um caractere da fila
char dequeue(Queue *queue)
{
  char value;
  if (isQueueEmpty(queue))
  {
    printf("Erro: Fila vazia\n");
    return '\0';
  }
  else
  {
    value = queue->items[queue->front];
    if (queue->front == queue->rear)
    {
      queue->front = queue->rear = -1;
    }
    else
    {
      queue->front = (queue->front + 1) % QUEUE_SIZE;
    }
    return value;
  }
}

int main()
{
  Stack stack;
  Queue queue;
  char input;

  initializeStack(&stack);
  initializeQueue(&queue);

  printf("Digite os caracteres (insira 'COMPUTACAO' para encerrar): \n");

  do
  {
    scanf(" %c", &input);

    if (!isStackFull(&stack))
    {
      push(&stack, input);
    }
    else
    {
      enqueue(&queue, input);
      char removed = pop(&stack);
      enqueue(&queue, removed);
    }

    if (!isQueueEmpty(&queue))
    {
      char removed_from_queue = dequeue(&queue);
      printf("%c", removed_from_queue);
      if (removed_from_queue == 'C')
      {
        char peek_stack = stack.items[stack.top];
        if (peek_stack == 'O')
        {
          char output;
          for (int i = stack.top; i >= 0; --i)
          {
            output = pop(&stack);
            printf("%c", output);
            if (output == 'C')
            {
              break;
            }
          }
          printf("\n");
          break;
        }
      }
    }
  } while (1);

  return 0;
}
