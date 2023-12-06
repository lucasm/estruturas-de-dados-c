// Construindo Árvore Binária em C com Recursividade

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

// Função imprime árvore
int arvore_vazia(NOARVORE *pno)
{
  return (pno == NULL);
}

void imp_arvore(NOARVORE *parv)
{
  printf('<');
  if (!arvore_vazia(parv))
  {
    printf('% c', parv->carac);
    imp_arvore(parv->pesq);
    imp_arvore(parv->pdir);
  }
  printf('>');
}

int main()
{
  NOARVORE *arv0, *arv1, *arv2, *arv3, *arv4, *arv;

  // raiz
  criarArv('*',
           // ramo da esquerda
           criarArv('+',
                    criarArv('2', criarArvVazia(), criarArvVazia()),
                    criarArv('3', criarArvVazia(), criarArvVazia())),
           // ramo da direita
           criarArv('7',
                    criarArvVazia(),
                    criarArvVazia()));

  // imprimir árvore
  imp_arvore(arv);

  return 0;
}