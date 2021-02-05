#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char nume[50];
    int varsta;
} persoana;
persoana *citeste(int n)
{
    persoana *persoane = malloc(n * sizeof(persoana));
    for (int i = 0; i < n; i++)
    {
        printf("Numele : ");
        scanf("%s", &persoane[i].nume);
        printf("Varsta");
        scanf("%d", persoane[i].varsta);
    }
    return persoane;
}
int main()
{
    printf("numarul de persoane:");
    int n;
    scanf("%d", &n);
    persoana *persoane = malloc(n * sizeof(persoana));
    persoane = citeste(n);
    return 0;
}
