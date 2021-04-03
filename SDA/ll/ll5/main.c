#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node
{
    int number;
    struct node *next;
};

typedef struct node list;

#define RED(string) "\x1b[31m" string "\x1b[0m"
#define GREEN(string) "\x1b[32m" string "\x1b[0m"

list *forge_node(int number)
{
    list *node = (list *)malloc(sizeof(list));
    node->number = number;
    node->next = NULL;
    return node;
}

int random_range(int min, int max)
{
    int number = rand() % (max - min + 1) + min;
    return number;
}

void pirnt_list(list *head)
{
    if (!head)
    {
        printf("lista este vida\n");
        return;
    }
    list *temp = head;
    while (temp)
    {
        printf("%d ", temp->number);
        temp = temp->next;
    }
    printf("\n");
}

void find_limits(list *head, list **min, list **max)
{
    list *temp = head;
    int first = 0;
    (*min) = head;
    (*max) = head;
    while (temp)
    {
        if (first == 0)
        {
            if (temp->number > (*max)->number)
            {
                (*max) = temp;
                first = 1;
            }
            if (temp->number < (*min)->number)
            {
                (*min) = temp;
                first = -1;
            }
        }
        if (first == 1)
        {
            if (temp->number > (*max)->number)
                (*max) = temp;
            if (temp->number <= (*min)->number)
                (*min) = temp;
        }
        if (first == -1)
        {
            if (temp->number >= (*max)->number)
                (*max) = temp;
            if (temp->number < (*min)->number)
                (*min) = temp;
        }
        temp = temp->next;
    }
}

list *get_inner_list(list *head, list *min, list *max)
{
    list *sub_head = NULL;
    list *aux = NULL;
    list *temp = head;
    int inside = 0;
    while (temp)
    {
        if (inside == 1)
            if (sub_head == NULL)
            {
                sub_head = forge_node(temp->number);
                aux = sub_head;
            }
            else
            {
                aux->next = forge_node(temp->number);
                aux = aux->next;
            }
        if (temp == max || temp == min)
            inside += 1;
        temp = temp->next;
        if ((temp == max || temp == min) && inside == 1)
            break;
    }
    return sub_head;
}
list *reverse_list(list **head)
{
    list *prev = NULL;
    list *current = *head;
    list *next = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}
int count_nodes(list *head)
{
    list *temp = head;
    int count = 0;
    while (temp)
    {
        count += 1;
        temp = temp->next;
    }
    return count;
}
list **divide_in_n_lists_a(list *head, int n)
{
    list **aux = (list **)malloc(n * sizeof(list *));
    list **liste = (list **)malloc(n * sizeof(list *));
    for (int i = 0; i < n; i++)
        liste[i] = NULL;
    list *temp = head;
    int cycle = 0;
    while (temp)
    {
        if (cycle == n)
            cycle = 0;
        if (liste[cycle] == NULL)
        {
            liste[cycle] = forge_node(temp->number);
            aux[cycle] = liste[cycle];
        }
        else
        {
            aux[cycle]->next = forge_node(temp->number);
            aux[cycle] = aux[cycle]->next;
        }
        temp = temp->next;
        cycle++;
    }
    return liste;
}
list **divide_in_n_lists_b(list *head, int n)
{
    list **aux = (list **)malloc(n * sizeof(list *));
    list **liste = (list **)malloc(n * sizeof(list *));
    for (int i = 0; i < n; i++)
        liste[i] = NULL;
    list *temp = head;
    int nodes = count_nodes(head);
    int count[n];
    int remainder = nodes - (nodes / n) * n;
    for (int i = 0; i < n; i++)
    {
        count[i] = nodes / n;
        if (remainder > 0)
        {
            count[i] += 1;
            remainder -= 1;
        }
    }
    int cycle = 0;
    int curent_list = 0;
    while (temp)
    {
        if (cycle == count[curent_list])
        {
            curent_list++;
            cycle = 0;
        }
        if (liste[curent_list] == NULL)
        {
            liste[curent_list] = forge_node(temp->number);
            aux[curent_list] = liste[curent_list];
        }
        else
        {
            aux[curent_list]->next = forge_node(temp->number);
            aux[curent_list] = aux[curent_list]->next;
        }
        temp = temp->next;
        cycle++;
    }

    return liste;
}

int menu()
{
    printf("__Program_la_SDA__\n");
    printf("1. Cititi o lista de la tastatura\n");
    printf("2. Generati o lista aleatoare\n");
    int i;
    scanf("%d", &i);
    return i;
}
int get_num(int n)
{
    printf("dati elementul %d: ", n);
    scanf("%d", &n);
    return n;
}
void print_n_lists(list **lists, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("lista %d: \n", i + 1);
        pirnt_list(lists[i]);
        printf("contine : %d elemente\n\n", count_nodes(lists[i]));
    }
}

int main(int argc, char const *argv[])
{
    srand(time(NULL));

    int option = menu();
    printf("dati numarul de elemente ale listei\n");
    int range;
    scanf("%d", &range);
    // citirea
    int node;
    int z = 1;
    int abs = 500;
    if (option == 1)
        node = get_num(z);
    if (option == 2)
        node = random_range(-abs, abs);
    list *head = forge_node(node);
    list *t = head;
    for (int i = 1; i < range; i++)
    {
        z++;
        if (option == 1)
            node = get_num(z);
        if (option == 2)
            node = random_range(-abs, abs);
        t->next = forge_node(node);
        t = t->next;
    }
    //determinarea min si max
    list *max = NULL;
    list *min = NULL;
    find_limits(head, &min, &max);
    // afisarea
    printf("Lista citita:\n");
    if (!head)
    {
        printf("lista este vida\n");
        return 0;
    }
    list *temp = head;
    while (temp)
    {
        if (temp == min || temp == max)
            printf(GREEN("%d "), temp->number);
        else if (temp->number == min->number || temp->number == max->number)
            printf(RED("%d "), temp->number);
        else
            printf("%d ", temp->number);
        temp = temp->next;
    }
    printf("\n");

    printf("contine : %d elemente\n", count_nodes(head));
    list *sub_list = get_inner_list(head, min, max);
    reverse_list(&sub_list);
    printf("MIN: %d\n", min->number);
    printf("MAX: %d\n", max->number);
    printf("\nsubconsecutivitatea inversa cuprinsa intre %d si %d:\n ", min->number, max->number);
    pirnt_list(sub_list);
    node = count_nodes(sub_list);
    printf("contine : %d elemente\n", node);
    int divide = 5;
    if (divide > node)
    {
        printf("nu se poate de divizat aceasta lista in %d liste fiind ca, contine doar %d\n", divide, node);
        return 0;
    }
    else
        printf("\ncele %d liste obtinute: \n\n", divide);
    list **lists;
    lists = divide_in_n_lists_b(sub_list, divide);
    print_n_lists(lists, divide);
    return 0;
}
