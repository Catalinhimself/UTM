#ifndef MIRELA
#define MIRELA

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

void bin_test();
typedef struct
{
    char *owner, *type, *address;
    int surface,price;
}realty;
typedef struct node
{
    int key;
    realty immovable;
    struct node *left, *right;
}tree;

typedef struct list
{
    tree* node;
    int level;
    struct list* next;
}list;


tree* forge_node(int key, realty immovable);
void print_node(tree* node);
void grow_tree(tree** root,int key, realty immovable);
void inorder(tree* root);
void preorder(tree* root);
void postorder(tree* root);
tree* search_node(tree* node, int key);
void modify_node(tree* node);
void append_to_queue(tree* node, int level, list** tail);
void levels(list* head, list** tail);
int print_levels(tree* root);
int menu();
int count_list_nodes(list*head);
void free_list(list** head);
int isnt_tree_root(tree* root);
void get_string(char** var,const char *message);
realty get_realty(int order);
void put_realty(realty immovable);
realty generate_realty(int order);
tree* postorder_free(tree* node);
#endif
