// Livro: nome, autor, ISBN, preço. Usuário cadastra 10 livros. Solicita numero ISBN e deve buscar no cadastro. Se for encontrado apresentar os dados.

#include <stdio.h>

int numeroBuscado;
int resultadoBusca = 0;

typedef struct Livro
{
  char titulo[50];
  char autor[50];
  int isbn;
  int preco;
} LIVRO;

LIVRO biblioteca[10]; // array de 10 estruturas do tipo LIVRO

int cadastrarLivros()
{

  // preencher array com livros
  for (int i = 0; i < 10; i++)
  {
    printf("Digite o título do livro %d: ", i + 1);
    scanf(" %[^\n]", biblioteca[i].titulo);

    printf("Digite o autor do livro %d: ", i + 1);
    scanf(" %[^\n]", biblioteca[i].autor);

    printf("Digite o ISBN do livro %d: ", i + 1);
    scanf("%d", &biblioteca[i].isbn);
    getchar(); // consumir o caractere de nova linha deixado pelo scanf
  }

  return 0;
}

int buscarLivro()
{
  printf("Informe o ISBN a ser buscado: \n");
  scanf("%i", &numeroBuscado);

  // iterar array para buscar
  for (int i = 0; i < 10; i++)
  {
    if (biblioteca[i].isbn == numeroBuscado)
    {
      printf("Livro com ISBN %i encontrado! \n", numeroBuscado);
      printf("Livro: %d\n", i + 1);
      printf("Título: %s\n", biblioteca[i].titulo);
      printf("Autor: %s\n", biblioteca[i].autor);
      printf("Ano: %d\n", biblioteca[i].isbn);
      resultadoBusca = 1;
    }
  }

  if (!resultadoBusca)
  {
    printf("Livro não encontrado! \n");
  }

  return 0;
}

int main()
{

  cadastrarLivros();
  buscarLivro();

  return 0;
}