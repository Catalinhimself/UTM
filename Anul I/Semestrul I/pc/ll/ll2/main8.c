#include <stdio.h>

int main()
{
    int a, b;
    int suma = 0, sumb = 0;

    printf("Introduceti doua numere");

    printf("\nNr a = ");
    scanf("%d", &a);

    printf("\nNr b = ");
    scanf("%d", &b);

    for (int i = 1; i < a; i++)
    {
        if (a % i == 0)
        {
            //printf("divizor a %d\n", i);
            suma += i;
        }
    }
    for (int i = 1; i < b; i++)
    {
        if (b % i == 0)
        {
            //printf("divizor b %d\n", i);
            sumb += i;
        }
    }
    printf("sum div a %d\nsum div b %d\n", suma, sumb);
    if (suma == b && sumb == a)
    {
        printf("Numerele a si b sunt prietene");
    }
    else
    {
        printf("Numerele a si b nu sunt prietene");
    }
    return 0;
}