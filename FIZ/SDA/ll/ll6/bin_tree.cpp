#include "bin_tree.h"
#include "const.h"

void bin_test()
{
    printf("__bin_tree__\n");
}

tree *forge_node(realty immovable)
{
    tree *node = (tree *)malloc(sizeof(tree));
    node->immovable = immovable;

    node->left = NULL;
    node->right = NULL;

    return node;
}

void print_node(tree *node)
{
    //printf("\n");
    //printf("parent: %p\n",node->parent);
    //printf("adress: %p\n",node);
    put_realty(node->immovable);
    //printf("left: %p\n",node->left);
    //printf("right: %p\n",node->right);
}

void grow_tree(tree **root, realty immovable)
{
    if ((*root) == NULL)
    {
        (*root) = forge_node(immovable);
        return;
    }

    tree *temp = (*root);
    while (1)
    {
        if (immovable.price <= temp->immovable.price)
        {
            if (temp->left == NULL)
            {
                temp->left = forge_node( immovable);
                break;
            }
            else
                temp = temp->left;
        }
        if (immovable.price > temp->immovable.price)
        {
            if (temp->right == NULL)
            {
                temp->right = forge_node(immovable);
                break;
            }
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

void preorder(tree *node)
{
    if (!node)
        return;
    print_node(node);
    preorder(node->left);
    preorder(node->right);
}

void postorder(tree *node)
{
    if (!node)
        return;
    postorder(node->left);
    postorder(node->right);
    print_node(node);
}

tree *search_node(tree *node, int key)
{
    if (!node)
        return NULL;
    if (node->immovable.price == key)
        return node;
    if (node->left)
        if(node->left->immovable.price == key)
            return node;
    if (node->right)
        if (node->right->immovable.price == key)
            return node;

    if (node->immovable.price >= key)
        return search_node(node->left, key);
    else
        return search_node(node->right, key);
}

void modify_node(tree *node)
{
    char c;
    printf("modifica proprietarul? (%s) [y/n]\n",node->immovable.owner);
    scanf(" %c", &c);
    if (c == 'y')
        get_string(&node->immovable.owner, "proprietar nou");
    
    printf("modifica tipul? (%s) [y/n]\n",node->immovable.type);
    scanf(" %c", &c);
    if (c == 'y')
        get_string(&node->immovable.type, "tipul");
    printf("modifica adresa? (%s) [y/n]\n",node->immovable.address);
    scanf(" %c", &c);
    if (c == 'y')
        get_string(&node->immovable.address, "adresa");
    printf("modifica suprafata? (%d) [y/n]\n",node->immovable.surface);
    scanf(" %c", &c);
    if (c == 'y'){
        printf("suprafata : ");
        scanf(" %d", &node->immovable.surface);}
    printf("modifica pretul? (%d) [y/n]\n",node->immovable.price);
    scanf(" %c", &c);
    if (c == 'y'){
    printf("costul : ");
    scanf(" %d", &node->immovable.price);}
}

void append_to_queue(tree *node, int level, list **tail)
{
    list *element = (list *)malloc(sizeof(list));
    element->node = node;
    element->level = level; element->next = NULL;
    if (!(*tail))
        (*tail) = element;
    else
    {
        (*tail)->next = element;
        (*tail) = element;
    }
}

void levels(list *node, list **tail)
{
    if (!node)
        return;
    if (node->node->left)
        append_to_queue(node->node->left, node->level + 1, tail);
    if (node->node->right)
        append_to_queue(node->node->right, node->level + 1, tail);
    levels(node->next, tail);
}

int print_levels(tree *root)
{
    list *tail = NULL;
    append_to_queue(root, 0, &tail);
    list *head = tail;
    levels(head, &tail);

    int current_level = -1;
    while (head)
    {
        if (head->level != current_level)
        {
            printf("\nnivelul curent: %d\n", head->level);
            printf("numarul maxim de noduri posibile: %d\n",(int) pow(2,head->level));
            current_level = head->level;
        }
        print_node(head->node);
        head = head->next;
    }
    printf("\n");
    return current_level;
}

int menu()
{   printf("\n");
    printf("%-20s %-15s\n","1. adauga nod","3. cautarea");
    printf("%-20s %-15s\n","11. genereaza nod","4. modificarea");
    printf("%-20s %-15s\n","Afisarea:","5. numarul de elemente");
    printf("%-20s %-15s\n","21. inordine","6. inaltimea arborelui");
    printf("%-20s %-15s\n","22. preordine","7. eliberarea");
    printf("%-20s %-15s\n","23. postordine","0. iesirea");
    printf("%-20s\n","2. pe nivele");
    int option;
    printf("Optiunea - ");
    scanf(" %d", &option);

    return option;
}

int count_list_nodes(list *head)
{
    int count = 0;
    while (head)
    {
        count++;
        head = head->next;
    }
    return count;
}

void free_list(list **head)
{
    list *next;
    while ((*head))
    {
        next = (*head)->next;
        free((*head));
        (*head)=NULL;
        (*head) = next;
    }
}

int isnt_tree_root(tree *root)
{
    if (!root)
    {
        printf("radacina arborelui este %p\n", root);
        return 1;
    }
    return 0;
}

void get_string(char **var, const char *message)
{
    char str[250];
    printf("%s:  ", message);
    scanf(" %[^\n]", str);
    (*var) = strdup(str);
}

realty get_realty(int order)
{
    printf("citirea imobilului %d\n", order);
    realty immovable;
    get_string(&immovable.owner, "proprietar");
    get_string(&immovable.type, "tipul");
    get_string(&immovable.address, "adresa");

    printf("suprafata : ");
    scanf(" %d", &immovable.surface);
    printf("costul : ");
    scanf(" %d", &immovable.price);

    return immovable;
}

void put_realty(realty immovable)
{
    printf("%-15s ", immovable.owner);
    printf("%-20s ", immovable.type);
    printf("%-30s ", immovable.address);
    printf("%9d m^2 ", immovable.surface);
    printf("%9d $\n", immovable.price);
}

realty generate_realty(int order)
{
    printf("imobilului %d, este generat:\n", order);
    realty immovable;

    immovable.owner = strdup(NAME[rand() % NAME_COUNT]);
    immovable.type = strdup(TYPE[rand() % TYPE_COUNT]);
    immovable.address = strdup(ADDRESS[rand() % ADDRESS_COUNT]);
    immovable.surface = (rand() % 100) + 16;
    immovable.price = immovable.surface * ((rand() % 1000) + 100);
    printf("proprietarul: %s\n", immovable.owner);
    printf("tipul: %s\n", immovable.type);
    printf("adresa: %s\n", immovable.address);
    printf("suprafata: %d m^2\n", immovable.surface);
    printf("costul: %d $\n", immovable.price);
    return immovable;
}


void postorder_free(tree** node)
{
    if (!(*node))
        return;
    postorder_free(&(*node)->left);
    postorder_free(&(*node)->right);
    free((*node)->immovable.owner);
    free((*node)->immovable.type);
    free((*node)->immovable.address);
    free((*node));
    (*node)=NULL;
}

void preorder_grow(tree** root, tree *node)
{
    if (!node)
        return;
    grow_tree(root,node->immovable);
    preorder_grow(root,node->left);
    preorder_grow(root,node->right);
}

void postorder_free_lite(tree** node)
{
    if (!(*node))
        return;
    postorder_free_lite(&(*node)->left);
    postorder_free_lite(&(*node)->right);
    free((*node));
    (*node)=NULL;
}
