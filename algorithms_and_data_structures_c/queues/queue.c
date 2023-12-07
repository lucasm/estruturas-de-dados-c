#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
	int key;
	struct node *next;
} NODE;

typedef struct linked_list {
	NODE *first;
	NODE *last;
} LINKED_LIST;

NODE * initialize_node(int k){
	NODE *p;
	
	p      = malloc(sizeof(NODE));
	p->key = k;

        return p;
}

void show(LINKED_LIST *l){
	NODE *tmp;

	tmp = l->first;

	while(tmp != NULL){
		printf("%d ", tmp->key);

		tmp = tmp->next;
	}

        printf("\n");
}

int size(LINKED_LIST *l){
        int n = 0;
	
        NODE *tmp;
        
	tmp = l->first;

	while(tmp != NULL){
		tmp = tmp->next;

                n++;
	}

        return n;
}

void push(int k, LINKED_LIST *l) {
	NODE *p;
	
	p = initialize_node(k);
	
	if(l->last == NULL){
		l->first = p;
		l->last  = p;
	} else {
                l->last->next = p;
                l->last       = p;
        }
}

void pop(LINKED_LIST *l){
        NODE *tmp1;

        tmp1 = l->first;

        l->first = tmp1->next;

        free(tmp1);
}

int main(){
	LINKED_LIST *pl;

	pl = malloc(sizeof(LINKED_LIST));

	push(2, pl);
	push(3, pl);
	push(5, pl);
	push(7, pl);
	
        show(pl);
	
        pop(pl);

        show(pl);
	
        return 0;
}
