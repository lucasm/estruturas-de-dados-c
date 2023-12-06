// Construindo Árvore Binária em C com Função

#include <stdlib.h>
#include <stdio.h>

// Definir a estrutura da árvore
typedef struct arvore
{
  char carac;
  struct cno *pesq;
  struct cno *pdir;
} NOARVORE;

// Função criar árvore vazia
NOARVORE *criarArvVazia(void)
{
  return NULL;
}

// Função criar árvore
NOARVORE *criarArv(char c, NOARVORE *sae, NOARVORE *sad)
{
  NOARVORE *p = malloc(sizeof(NOARVORE));
  p->carac = c;
  p->pesq = sae;
  p->pdir = sad;

  return p;
}

int main()
{
  NOARVORE *arv0, *arv1, *arv2, *arv3, *arv4, *arv;

  // ramo da Esquerda
  arv0 = criarArv('5', criarArvVazia(), criarArvVazia());
  arv1 = criarArv('2', arv0, criarArvVazia());
  arv2 = criarArv('3', criarArvVazia(), criarArvVazia());
  arv3 = criarArv('+', arv1, arv2);

  // ramo da Direita
  arv4 = criarArv('7', criarArvVazia(), criarArvVazia());

  // raiz
  arv = criarArv('*', arv3, arv4);

  // percorrer a árvore

  return 0;
}