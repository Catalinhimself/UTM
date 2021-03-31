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

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    int range = random_range(10, 30);
    printf("%d\n", range);
    list *head = forge_node(random_range(-1000, 1000));
    list *t = head;
    for (int i = 1; i < range; i++)
    {
        t->next = forge_node(random_range(-1000, 1000));
        t = t->next;
    }
    pirnt_list(head);
    list *max = NULL;
    list *min = NULL;
    find_limits(head, &min, &max);
    printf("\nmax %d\nmin %d\n", max->number, min->number);
    list *sub_list = get_inner_list(head, min, max);
    pirnt_list(sub_list);
    reverse_list(&sub_list);
    pirnt_list(sub_list);
    list *liste[5];
    liste[0] = forge_node(1);
    liste[0]->next = forge_node(23);
    liste[0]->next->next = forge_node(99);
    pirnt_list(liste[0]);
    return 0;
}
