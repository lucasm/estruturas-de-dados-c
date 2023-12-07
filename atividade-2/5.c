// 5. Escreva um programa que recebe uma cadeia de caracteres (string) do usuário e apresente a string em ordem reversa. Utilize uma pilha para realizar esta tarefa;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Definição da estrutura da pilha
struct Stack
{
  int top;
  unsigned capacity;
  char *array;
};

// Função para criar uma nova pilha
struct Stack *createStack(unsigned capacity)
{
  struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
  stack->capacity = capacity;
  stack->top = -1;
  stack->array = (char *)malloc(stack->capacity * sizeof(char));
  return stack;
}

// Função para verificar se a pilha está cheia
int isFull(struct Stack *stack)
{
  return stack->top == stack->capacity - 1;
}

// Função para verificar se a pilha está vazia
int isEmpty(struct Stack *stack)
{
  return stack->top == -1;
}

// Função para empilhar um elemento na pilha
void push(struct Stack *stack, char item)
{
  if (isFull(stack))
    return;
  stack->array[++stack->top] = item;
}

// Função para desempilhar um elemento da pilha
char pop(struct Stack *stack)
{
  if (isEmpty(stack))
    return '\0';
  return stack->array[stack->top--];
}

// Função para inverter a string usando pilha
void reverseString(char *string)
{
  int length = strlen(string);
  struct Stack *stack = createStack(length);

  // Empilhando os caracteres da string na pilha
  for (int i = 0; i < length; i++)
  {
    push(stack, string[i]);
  }

  // Desempilhando e reconstruindo a string invertida
  for (int i = 0; i < length; i++)
  {
    string[i] = pop(stack);
  }

  free(stack->array);
  free(stack);
}

int main()
{
  char input[MAX_SIZE];

  printf("Digite uma string: ");
  fgets(input, MAX_SIZE, stdin);

  // Removendo o caractere de nova linha (se houver)
  input[strcspn(input, "\n")] = '\0';

  printf("String invertida: ");
  reverseString(input);
  printf("%s\n", input);

  return 0;
}
