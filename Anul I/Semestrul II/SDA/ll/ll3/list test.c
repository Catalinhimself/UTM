
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void printList(struct Node *n)
{
    while (n != NULL)
    {
        printf("%x %d %x\n", n, n->data, n->next);
        n = n->next;
    }
}
int main()
{
    struct Node *head = NULL;

    head = (struct Node *)malloc(sizeof(struct Node));

    head->data = 1;
    head->next = NULL;
    struct Node *temp = head;

    for (int i = 0; i < 10; i++)
    {
        struct Node *next = NULL;
        next = (struct Node *)malloc(sizeof(struct Node));
        next->data = i;
        next->next = NULL;
        temp->next = next;
        temp = next;
    }
    printf("head %d %x\n", head->data, head->next);
    printList(head);
    return 0;
}
