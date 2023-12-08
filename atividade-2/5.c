// 5. Escreva um programa que recebe uma cadeia de caracteres (string) do usuário e apresente a string em ordem reversa. Utilize uma pilha para realizar esta tarefa;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// estrutura da PILHA
typedef struct Stack
{
  int top;
  unsigned capacity;
  char *array;
} Stack;

// Criar nova pilha
Stack *createStack(unsigned capacity)
{
  Stack *stack = (Stack *)malloc(sizeof(Stack));
  stack->capacity = capacity;
  stack->top = -1;
  stack->array = (char *)malloc(stack->capacity * sizeof(char));
  return stack;
}

// Função para verificar se a pilha está cheia
int isFull(Stack *stack)
{
  return stack->top == stack->capacity - 1;
}

//  vazia
int isEmpty(Stack *stack)
{
  return stack->top == -1;
}

// empilhar elemento na pilha
void push(Stack *stack, char item)
{
  if (isFull(stack))
    return;
  stack->array[++stack->top] = item;
}

// desempilhar elemento da pilha
char pop(Stack *stack)
{
  if (isEmpty(stack))
    return '\0';
  return stack->array[stack->top--];
}

// inverter string usando pilha
void reverseString(char *string)
{
  int length = strlen(string);
  Stack *stack = createStack(length);

  // empilhando os caracteres da string na pilha
  for (int i = 0; i < length; i++)
  {
    push(stack, string[i]);
  }

  // desempilhando e reconstruindo a string invertida
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

  // removendo o caractere de nova linha (se houver)
  input[strcspn(input, "\n")] = '\0';

  printf("String invertida: ");
  reverseString(input);
  printf("%s\n", input);

  return 0;

  /*

  Aprendizados:

  Crie uma pilha, que é uma estrutura de dados que segue o princípio LIFO (Last In, First Out), ou seja, o último elemento a entrar é o primeiro a sair!!!

  Para inverter a string, basta empilhar os caracteres da string e desempilhá-los em ordem inversa, reconstruindo a string invertida.

  *** MAX_SIZE é uma constante que define o tamanho máximo da string, que é 100.

  *** fgets(input, MAX_SIZE, stdin) é uma função que lê uma string do usuário e armazena na variável input.

  *** stdin é um ponteiro para o arquivo de entrada padrão, que é o teclado.

  */
}
