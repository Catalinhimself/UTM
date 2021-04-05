#ifndef FRIED_EGG_JELLYFISH
#define FRIED_EGG_JELLYFISH

#include <stdlib.h>
#include <stdio.h>

void bin_test();

typedef struct node
{
    int data;
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
#endif
