// Implementação de uma fila em C

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct
{
  int items[MAX_SIZE];
  int front;
  int rear;
  int size;
} Queue;

void initializeQueue(Queue *queue)
{
  queue->front = 0;
  queue->rear = -1;
  queue->size = 0;
}

int isFull(Queue *queue)
{
  return queue->size == MAX_SIZE;
}

int isEmpty(Queue *queue)
{
  return queue->size == 0;
}

void enqueue(Queue *queue, int value)
{
  if (isFull(queue))
  {
    printf("Erro: Fila cheia\n");
    return;
  }
  queue->rear = (queue->rear + 1) % MAX_SIZE;
  queue->items[queue->rear] = value;
  queue->size++;
}

int dequeue(Queue *queue)
{
  if (isEmpty(queue))
  {
    printf("Erro: Fila vazia\n");
    return -1;
  }
  int removed = queue->items[queue->front];
  queue->front = (queue->front + 1) % MAX_SIZE;
  queue->size--;
  return removed;
}

int peek(Queue *queue)
{
  if (isEmpty(queue))
  {
    printf("Erro: Fila vazia\n");
    return -1;
  }
  return queue->items[queue->front];
}

int main()
{
  Queue queue;
  initializeQueue(&queue);

  enqueue(&queue, 10);
  enqueue(&queue, 20);
  enqueue(&queue, 30);

  printf("Frente da fila: %d\n", peek(&queue));

  printf("Desenfileirando itens: %d, %d\n", dequeue(&queue), dequeue(&queue));

  printf("Frente da fila após desenfileirar: %d\n", peek(&queue));

  return 0;
}
