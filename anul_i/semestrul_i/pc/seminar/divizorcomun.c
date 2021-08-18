#include <stdio.h>

void main()
{
    int a, b;
    printf("dati numarul a si b : ");
    scanf("%d %d", &a, &b);
    if (a > b)
    {
        a += b;
        b = a - b;
        a -= b;
    }
    printf("%d %d\n", a, b);
    for (int i = a; i > 0; i--)
    {
        if ((a % i != 0) || (b % i != 0))
        {
            //divizor comun
            printf("%d", i + 1);
            break;
        }
        /* code */
    }
}