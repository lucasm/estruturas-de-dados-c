#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct N {
        int key;
        int height;
        int position;
        bool marked;
        struct N *left_child;
        struct N *right_child;
        struct N *parent;
} NODE;

typedef struct T 
{
        int amount_of_nodes;
        NODE *root;
} TREE;


NODE * initialize_node(int k)
{
        NODE *p;

        p              = malloc(sizeof(NODE));
        p->key         = k;
        p->marked      = false;
        p->left_child  = NULL;
        p->right_child = NULL;
        p->parent      = NULL;

        return p;
}


TREE * initialize_tree()
{
        TREE *p;
        
        p = malloc(sizeof(TREE));

        return p;
}

void update_height(NODE *n)
{
        bool only_has_left_child  = n->left_child != NULL && n->right_child == NULL; 
        bool only_has_right_child = n->left_child == NULL && n->right_child != NULL; 
        bool has_both_children    = n->left_child != NULL && n->right_child != NULL; 
        bool has_parent           = n->parent     != NULL; 

        if (only_has_left_child) { 
                n->height = n->left_child->height + 1;
        }

        if (only_has_right_child) {
                n->height = n->right_child->height + 1;
        }

        if (has_both_children) {
                if (n->left_child->height >= n->right_child->height) {
                        n->height = n->left_child->height + 1;
                } else {
                        n->height = n->right_child->height + 1;
                }
        }

        if (has_parent){
                update_height(n->parent);
        }
}


void insert(TREE *t, NODE *n1, int k) 
{
        if (t->amount_of_nodes == 0) {
                t->root = initialize_node(k);
                
                t->amount_of_nodes++;
        
                return;
        }

        if (n1->key > k) {
                if (n1->left_child != NULL) {
                        insert(t, n1->left_child, k);
                } else {
                        n1->left_child         = initialize_node(k);
                        n1->left_child->parent = n1;
                }

        } else {
                if (n1->right_child != NULL) {
                        insert(t, n1->right_child, k);
                } else {
                        n1->right_child         = initialize_node(k);
                        n1->right_child->parent = n1;
                }
        }

        update_height(n1);
        t->amount_of_nodes++;
        t->height = t->root->height;
}

/*
void print_children(NODE *n, int l) 
{
        bool has_left_child  = n->left_child  != NULL; 
        bool has_right_child = n->right_child != NULL; 
        
        if (l > 0 && has_left_child) {
               print_children(l - 1); 
        } else {
                n->left_child->printed = true;
        }
       
        if (l == 0 && has_right_child) {
                n->right_child->printed = true;
        }
}
*/

void calculate_node_position(NODE *n){
        int d = 0;

        NODE *tmp;

        if (n->parent->key > n->key){
                tmp = n->right_child;
        
                while(true){
                        if (tmp == NULL) {
                                break;
                        }
                
                        tmp = tmp->right_child;

                        d--;
                }
        } else {
                tmp = n->left_child;
        
                while(true){
                        if (tmp == NULL) {
                                break;
                        }
                
                        tmp = tmp->left_child;

                        d++;
                }
        }

        n->position = n->parent->position + d;
}


void print_tree(TREE *t)
{
        int canvas_width = 2 ** t->height - 1;
        
        NODE nodes[t->height + 1][canvas_width];

        NODE * tmp = t->root;

        while (!(t->root->marked)) 
                if (tmp->left_child != NULL && !tmp->left_child->marked) {
                        tmp = t->left_child;
                
                        continue;
                } 
                
                if () {
                        tmp 
                }
                NODE *parent = t->root;
                
                print_children(parent);


        }
}

int main()
{
        TREE *p_tree;

        p_tree = initialize_tree();

        insert(p_tree, p_tree->root, 200);
        insert(p_tree, p_tree->root, 100);
        insert(p_tree, p_tree->root, 300);
        insert(p_tree, p_tree->root, 150);

        printf("nodes: %d\n", p_tree->amount_of_nodes);
       
        /*
        printf("%d\n", p_tree->root->key);
        printf("%d\n", p_tree->root->left_child->key);
        printf("%d\n", p_tree->root->right_child->key);
        printf("%d\n", p_tree->root->left_child->right_child->key);
        */

        printf("%d\n", p_tree->root->height);
        
        return 0;
}

