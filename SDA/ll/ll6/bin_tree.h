#ifndef FRIED_EGG_JELLYFISH
#define FRIED_EGG_JELLYFISH

#include <stdlib.h>
#include <stdio.h>

void bin_test();
typedef struct
{
    char owner[30],type[20],adress[30];
    float surface,price;
}realty;
typedef struct node
{
    int data;
    realty immovable;
    struct node *parent, *left, *right;
}tree;

typedef struct list
{
    tree* node;
    int level;
    struct list* next;
}list;


tree* forge_node(tree* parent, int data);
void print_node(tree* node);
void grow_tree(tree** root,int data);
void inorder(tree* root);
void preorder(tree* root);
void postorder(tree* root);
tree* search_node(tree* node, int data);
void modify_node(tree* node);
void append_to_queue(tree* node, int level, list** tail);
void levels(list* head, list** tail);
int print_levels(tree* root);
int menu();
int count_list_nodes(list*head);
void free_list(list** head);
int isnt_tree_root(tree* root);
int read_node(int order);

#endif
