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

void shift(int k, LINKED_LIST *l) {
	NODE *p;
	
	p      = malloc(sizeof(NODE));
	p->key = k;
	
	if(l->first == NULL){
		l->first = p;
	}

	if(l->first != NULL){
		p->next  = l->first;
		l->first = p;
	} 
}

void insert_at(int position, int k, LINKED_LIST *l){
	int l_position = 0;

	NODE *p_temp, *p;
	p_temp = l->first;

	if(p_temp == NULL){
		add(k, l);

		return;
	}

	if(position == 0){
		shift(k, l);
	}

	while(true){
		if(p_temp == NULL){
			break;
		}

		if((l_position + 1) == position){
			p            = malloc(sizeof(NODE));
			p->key       = k;
			p->next      = p_temp->next;
			p_temp->next = p;

			break;
		}

		l_position++;

		p_temp = p_temp->next;
	}
}

void delete(int k, LINKED_LIST *l){
        NODE *tmp1;

        tmp1 = l->first;

        if(l->first->key == k){
                free(l->first);

                l->first = tmp1->next;

                return;
        }

        while(true){
                if(tmp1->next == NULL){
                        break;
                }

                if(tmp1->next->key == k){
                        NODE *tmp2;

                        tmp2       = tmp1->next;
                        tmp1->next = tmp1->next->next;
                        
                        free(tmp2);

                        break;
                }

                tmp1 = tmp1->next;
        }
}

void insert_after(LINKED_LIST *l, int j, int k){
	NODE *tmp, *n;

	tmp = l->first;

	while(tmp != NULL){
                if(tmp->key == j){
                        n = initialize_node(k);

                        n->next   = tmp->next;    
                        tmp->next = n;
                        
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
	
        insert_after(pl, 3, 4);

        show(pl);
        
        return 0;
}
