// Construindo Árvore Binária em C

#include <stdlib.h>
#include <stdio.h>

// Definir a estrutura da arvore
typedef struct cno
{
  char letra;
  struct cno *pesq;
  struct cno *pdir;
} NO;

void const_arvore(NO **p)
{
  NO *no1, *no2, *no3, *no4, *no5;
  no1 = malloc(sizeof(NO));
  no2 = malloc(sizeof(NO));
  no3 = malloc(sizeof(NO));
  no4 = malloc(sizeof(NO));
  no5 = malloc(sizeof(NO));

  no1->letra = '*';
  no1->pesq = no2;
  no1->pdir = no3;

  no2->letra = '+';
  no2->pesq = no4;
  no2->pdir = no5;

  no3->letra = 'C';
  no3->pesq = NULL;
  no3->pdir = NULL;

  no4->letra = 'A';
  no4->pesq = NULL;
  no4->pdir = NULL;

  no5->letra = 'B';
  no5->pesq = NULL;
  no5->pdir = NULL;

  *p = no1;
}

int main()
{
  NO *arvore = NULL;
  const_arvore(&arvore);

  // percorrer a árvore
  printf("%c\n", arvore->letra);
  printf("%c\n", arvore->pesq->letra);
  printf("%c\n", arvore->pdir->letra);
  printf("%c\n", arvore->pesq->pesq->letra);
  printf("%c\n", arvore->pesq->pdir->letra);

  return 0;
}