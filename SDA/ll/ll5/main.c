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
    printf("%d %d", remainder, nodes / n);
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
int main(int argc, char const *argv[])
{
    srand(time(NULL));
    int range = random_range(20, 50);
    printf("%d\n", range);
    list *head = forge_node(random_range(-1000, 1000));
    list *t = head;
    for (int i = 1; i < range; i++)
    {
        t->next = forge_node(random_range(-1000, 1000));
        t = t->next;
    }
    pirnt_list(head);
    printf("total : %d nodes", count_nodes(head));
    list *max = NULL;
    list *min = NULL;
    find_limits(head, &min, &max);
    printf("\nmax %d\nmin %d\n", max->number, min->number);
    list *sub_list = get_inner_list(head, min, max);
    pirnt_list(sub_list);
    printf("total : %d nodes\n\n", count_nodes(sub_list));
    reverse_list(&sub_list);
    pirnt_list(sub_list);
    int divide = 5;
    list **liste = divide_in_n_lists_a(sub_list, divide);
    for (int i = 0; i < divide; i++)
    {
        printf("lista %d: ", i);
        pirnt_list(liste[i]);
        printf("total : %d nodes\n", count_nodes(liste[i]));
    }
    pirnt_list(sub_list);
    liste = divide_in_n_lists_b(sub_list, divide);
    for (int i = 0; i < divide; i++)
    {
        printf("lista %d: ", i);
        pirnt_list(liste[i]);
        printf("total : %d nodes\n", count_nodes(liste[i]));
    }
    return 0;
}
