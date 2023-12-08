/*

7. Considere a implementação de uma lista encadeada para armazenar números reais dada pelo registro abaixo:

typedef struct lista {
  float info;
  struct lista *prox.
}Lista;

Implementar uma função que, dada uma lista encadeada e um número inteiro não negativo n, remova da lista os seus n primeiros nós e retorne a lista resultante. Caso n seja maior que o comprimento da lista, todos os seus elementos deve ser removidos e o resultado da função deve ser uma lista vazia. Essa função deve obedecer ao seguinte protótipo:

Lista* retira_prefixo (Lista* l, int n) {
Lista* p; // variável auxiliar para percorrer a lista
Lista* q; // variável auxiliar
int m = 1; p = l;
while(p != NULL && m <= n) { m = m+1;
q = p->prox; free(p);
p = q;
}
return p; }

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct lista
{
  float info;
  struct lista *prox;
} Lista;

// Função para criar um novo nó na lista encadeada
Lista *criarNovoNo(float valor)
{
  Lista *novoNo = (Lista *)malloc(sizeof(Lista));
  if (novoNo != NULL)
  {
    novoNo->info = valor;
    novoNo->prox = NULL;
  }
  return novoNo;
}

// Função para inserir um novo nó no final da lista encadeada
Lista *inserirNoFinal(Lista *l, float valor)
{
  Lista *novoNo = criarNovoNo(valor);
  if (novoNo == NULL)
  {
    printf("Erro: falha na alocação de memória.\n");
    return l;
  }

  if (l == NULL)
  {
    return novoNo;
  }

  Lista *temp = l;
  while (temp->prox != NULL)
  {
    temp = temp->prox;
  }
  temp->prox = novoNo;
  return l;
}

// Função para imprimir os elementos da lista encadeada
void imprimirLista(Lista *l)
{
  printf("Lista: ");
  while (l != NULL)
  {
    printf("%.2f -> ", l->info);
    l = l->prox;
  }
  printf("NULL\n");
}

// Função para remover os primeiros 'n' nós da lista
Lista *retira_prefixo(Lista *l, int n)
{
  Lista *p = l; // Variável auxiliar para percorrer a lista
  Lista *q;     // Variável auxiliar
  int m = 1;

  // Percorre a lista até o n-ésimo nó ou até o fim da lista
  while (p != NULL && m < n)
  {
    m++;
    q = p;
    p = p->prox;
  }

  // Remove os nós da lista até o n-ésimo nó ou até o fim da lista
  while (p != NULL)
  {
    q = p->prox;
    free(p);
    p = q;
  }

  // Retorna a lista resultante (p pode ser NULL se n >= tamanho da lista)
  return q;
}

// Função para liberar a memória alocada para a lista encadeada
void liberarLista(Lista *l)
{
  Lista *temp;
  while (l != NULL)
  {
    temp = l;
    l = l->prox;
    free(temp);
  }
}

int main()
{
  Lista *lista = NULL;
  int i;

  // Inserindo elementos na lista
  for (i = 1; i <= 8; i++)
  {
    lista = inserirNoFinal(lista, i * 1.5);
  }

  printf("Lista inicial:\n");
  imprimirLista(lista);

  // Removendo os primeiros 'n' nós da lista e exibindo o resultado
  int n = 5;
  lista = retira_prefixo(lista, n);

  printf("\nApós remover os %d primeiros nós:\n", n);
  imprimirLista(lista);

  // Liberando a memória alocada para a lista
  liberarLista(lista);

  return 0;
}

/*

Aprendizado:

Criei a função inserirNoFinal pra inserir elementos na lista encadeada. A função retira_prefixo para remover os primeiros 'n' nós da lista e exibir o resultado antes e depois da remoção. Por fim, a função liberarLista é utilizada para liberar a memória alocada para a lista encadeada.


*/