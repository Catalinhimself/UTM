#include "bin_tree.h"

void bin_test()
{
    printf("__bin_tree__\n");
}

tree* forge_node( int data, realty immovable)
{
    tree*node = (tree*)malloc(sizeof(tree));
    node->data = data;
    node->immovable = immovable;

    node->left = NULL;
    node->right = NULL;

return node;
}

void print_node(tree* node)
{       
    //printf("\n");
    //printf("parent: %p\n",node->parent);
    //printf("adress: %p\n",node);
//    printf("data: %d\n",node->data);
    put_realty(node->immovable);
    //printf("left: %p\n",node->left);
    //printf("right: %p\n",node->right);
}

void grow_tree(tree** root, int data, realty immovable)
{   
    if ((*root)==NULL)
    {
    (*root) = forge_node(data, immovable);
    return;
    }    

    tree* temp = (*root);
    while (1)
    {
        if (data <= temp->data)
        {
            if(temp->left==NULL)
                {temp->left = forge_node(data, immovable);
                break;}
            else
                temp = temp->left;    
        }
        if (data > temp->data)
        {
            if (temp->right == NULL)
                {temp->right = forge_node(data,immovable);
                break;}
            else
                temp = temp->right;
        }
    }
}


void inorder(tree *node)
{
    if (!node)
        return;
    inorder(node->left);
    print_node(node);
    inorder(node->right);
}

void preorder(tree* node)
{
    if (!node)
        return;
    print_node(node);
    preorder(node->left);
    preorder(node->right);
}

void postorder(tree* node)
{
    if (!node)
        return;
    postorder(node->left);
    postorder(node->right);
    print_node(node);
}

tree* search_node(tree* node, int data)
{
    if (!node)
        return NULL;
    if (node->data == data)
        return node;        
    if (node->data >= data)
        return search_node(node->left, data);
    else
        return search_node(node->right, data);
}

void modify_node(tree* node)
{
    printf("old data: %d\n",node->data);
    printf("modify? [y/n]\n");
    char c;
    scanf(" %c",&c);
    if (c =='y')
    {
    printf("new data: ");
    scanf("%d",&node->data);
    }
}

void append_to_queue(tree* node, int level, list** tail)
{
    list* element = (list*)malloc(sizeof(list));
    element->node = node;
    element->level = level;
    element->next = NULL;
    if(!(*tail))
        (*tail) = element;
    else
    {
        (*tail)->next = element;
        (*tail) = element;
    }
}

void levels(list* node, list** tail)
{   if (!node)
        return;
    if(node->node->left)
        append_to_queue(node->node->left, node->level+1, tail);
    if(node->node->right)
        append_to_queue(node->node->right, node->level+1, tail);
    levels(node->next, tail);    
}

int print_levels(tree* root)
{
   list* tail = NULL;
   append_to_queue(root, 0, &tail);
   list* head = tail;
   levels(head, &tail);


   int current_level = -1;
    while (head)
    {
        if (head->level != current_level)
        {
            printf("current level: %d\n",head->level);
            current_level = head->level;
        }
        print_node(head->node);
        head = head->next;
    }    
   return current_level; 
}

int menu()
{
    printf("1. Introducera unui arbore de la tastatura\n");
    printf("2. Afisarea nodurilor la ecran\n");
    printf("3. Cautarea nodului in arbore\n");
    printf("4. Modificarea unui nod din arbore\n");
    printf("5. Determinarea numarului de noduri\n");
    printf("6. Determinarea inaltimii arborelui\n");
    printf("7. Eliberarea memoriei alocate pentru lista\n");
    printf("0. Iesirea din program\n");
    int option;
    printf("Optiunea - ");
    scanf(" %d",&option);
    
    return option;
}

int count_list_nodes(list*head)
{
    int count = 0;
    while(head)
    {
        count++;
        head=head->next;
    }
    return count;
}

void free_list(list**head)
{
    list* next;
    while((*head))
    {    
        next=(*head)->next;
        free((*head));
        (*head)=next;
    }
}

int isnt_tree_root(tree* root)
{
    if(!root)
    {
        printf("radacina arborelui este %p\n",root);
        return 1;
    }
    return 0;
}

int read_node(int order)
{
    printf("introducerea nodului %d\n",order);
    int data;
    scanf(" %d",&data);
   return data;
}

void get_string(char** var,const char *message)
{
    char str[250];
    printf("%s:  ", message);
    scanf(" %[^\n]", str); 
    (*var) = strdup(str);
}

realty get_realty(int order)
{
    printf("citirea imobilului %d\n",order);
    realty immovable;
    get_string(&immovable.owner,"proprietar");
    get_string(&immovable.type,"tipul");
    get_string(&immovable.address,"adresa");
    
    printf("suprafata : ");
    scanf(" %f", &immovable.surface);
    printf("costul : ");
    scanf(" %f", &immovable.price);

    return immovable;
}

void put_realty(realty immovable)
{
    printf("%s ",immovable.owner);
    printf("%s ",immovable.type);
    printf("%s ",immovable.address);
    printf("%.1f m^2 ",immovable.surface);
    printf("%.1f $\n",immovable.price);
}

