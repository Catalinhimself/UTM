// Plesu Catalin
// Un om dorește să urce o scară cu N trepte.
// El poate urca la un moment dat una sau două trepte.
// Precizați în câte moduri poate urca omul scara.

// n!/(n-r)!
// r - numarul minim de elemente diferite
#include <stdio.h>
#include <stdlib.h>

#define ENDL printf("\n")

unsigned factorial(unsigned n)
{
    if (n == 1)
        return 1;
    else
        return n * factorial(n - 1);
}
unsigned formula(int n, int r)
{
    return factorial(n) / factorial(n - r);
}
int greedi_invers(int N)
{
    int unu = N, doi = 0, total = 0;
    while (1)
    {
        printf("unu %d; doi %d;  ", unu, doi);
        if (unu > doi)
        {
            int comb = formula(unu + doi, doi);
            total += comb;
            printf("%d \n", comb);
        }
        else
        {
            int comb = formula(unu + doi, unu);
            total += comb;
            printf("%d \n", comb);
        }
        doi++;
        unu -= 2;
        if (unu < 0)
            break;
    }
    return total;
}
int main()
{
    int N = 5;
    printf("total %d \n", greedi_invers(N));
    for (int i = 0; i++ < 10;)
        printf("total %d \n", greedi_invers(i));
    return EXIT_SUCCESS;
}