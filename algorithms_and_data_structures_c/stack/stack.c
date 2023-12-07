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

void add(int k, LINKED_LIST *l) {
	NODE *p;
	
	p      = malloc(sizeof(NODE));
	p->key = k;
	
	if(l->first == NULL){
		l->first = p;
	}

	if(l->last != NULL){
		l->last->next = p;
		l->last	      = p;
	} else {
		l->last = p;
	}
}

void delete(LINKED_LIST *l){
        NODE *tmp;

        tmp = l->first;

        if(l->first == NULL){
                return;
        }

        if(l->first->next == NULL){
                l->first = NULL;
                l->last  = NULL;
                free(tmp);
                
                return;
        }

        while(tmp->next != NULL){
                if(tmp->next->next == NULL){
                        free(tmp->next);

                        tmp->next = NULL;
                        
                        break;
                }
                
                tmp = tmp->next;
        }
}

int main(){
	LINKED_LIST *pl;

	pl = malloc(sizeof(LINKED_LIST));

	add(2, pl);
	add(3, pl);
	add(5, pl);
	add(7, pl);
	
        show(pl);
	
        delete(pl);

        show(pl);

	return 0;
}
