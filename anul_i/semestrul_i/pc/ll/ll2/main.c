#include <stdio.h>
// calculează suma numerelor pare și produsul numerelor impare din intervalul [a; b]
int main()
{
    int a = 0, b = 0, sum = 0;
    //pentru ca int este prea scurt
    double prod = 1;
    printf("programul dat va calcula\n1. suma numerelor pare \n2. pordusul numerelor inpare\npe intervalul [a; b] care vor fi citite de la tastaturab\n");
    printf("a = ");
    scanf("%d", &a);
    printf("b = ");
    scanf("%d", &b);
    printf("a = %d b=%d\n", a, b);

    if (a > b)
    {
        a = a + b;
        b = a - b;
        a = a - b;
    }
    printf("\npe intervalul [%d ; %d]\n", a, b);
    printf("suma numerelor pare :\n");
    for (int i = a; i <= b; i++)
    {
        if (i % 2 == 0)
        {
            sum += i;
            printf("%d +\n", i);
        }
    }
    printf("produsul numerelor inpare :\n");
    for (int i = a; i <= b; i++)
    {
        if (i % 2 != 0)
        {
            prod *= i;
            printf("%d *\n", i);
        }
    }

    printf("suma = %d\nprodusul = %.0f", sum, prod);

    return 0;
}