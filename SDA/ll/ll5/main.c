#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node
{
    int number;
    struct node *next;
};

typedef struct node list;

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
    printf("\n");
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
    (*min) = head;
    (*max) = head;
    while (temp)
    {
        (*max) = temp->number > (*max)->number ? temp : (*max);
        (*min) = temp->number < (*min)->number ? temp : (*min);
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
int main(int argc, char const *argv[])
{
    srand(time(NULL));

    int option = menu();
    printf("dati numarul de elemente ale listei\n");
    int range;
    scanf("%d", &range);
    int node;
    int z = 1;
    if (option == 1)
        node = get_num(z);
    if (option == 2)
        node = random_range(-1000, 1000);
    list *head = forge_node(node);
    list *t = head;
    for (int i = 1; i < range; i++)
    {
        z++;
        if (option == 1)
            node = get_num(z);
        if (option == 2)
            node = random_range(-1000, 1000);
        t->next = forge_node(node);
        t = t->next;
    }
    printf("Lista citita:\n");
    pirnt_list(head);
    printf("contine : %d elemente\n", count_nodes(head));
    list *max = NULL;
    list *min = NULL;
    find_limits(head, &min, &max);
    printf("\nsubconsecutivitatea cuprinsa intre %d is %d este:", max->number, min->number);
    list *sub_list = get_inner_list(head, min, max);
    pirnt_list(sub_list);
    printf("contine : %d elemente\n\n", count_nodes(sub_list));
    reverse_list(&sub_list);
    printf("inversul acestei submultimi este: \n");
    pirnt_list(sub_list);
    printf("\naceasta lista poate fi divizata in 2 metode:\n1. cate un element va fi trecut in fiecare lista la rand\n2. un numar de elemente va fi trecut in fiecare lista\n");
    scanf("%d", &option);
    node = count_nodes(sub_list);
    printf("in cate liste doriti sa divizati? (aceata lista contine %d elemente)\n", node);
    int divide = 5;
    scanf("%d", &divide);
    if (divide > node)
    {
        printf("nu se poate de divizat aceasta lista in %d liste", divide);
        return 0;
    }
    list **liste;
    if (option == 1)
    {
        liste = divide_in_n_lists_a(sub_list, divide);
        for (int i = 0; i < divide; i++)
        {
            printf("lista %d: ", i + 1);
            pirnt_list(liste[i]);
            printf("contine : %d elemente\n", count_nodes(liste[i]));
        }
    }
    if (option == 2)
    {
        liste = divide_in_n_lists_b(sub_list, divide);
        for (int i = 0; i < divide; i++)
        {
            printf("lista %d: ", i + 1);
            pirnt_list(liste[i]);
            printf("contine : %d elemente\n", count_nodes(liste[i]));
        }
    }
    return 0;
}
