// Plesu Catalin
// Un om dorește să urce o scară cu N trepte.
// El poate urca la un moment dat una sau două trepte.
// Precizați în câte moduri poate urca omul scara.

// n!/(n-r)!
// r - numarul minim de elemente diferite
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ENDL printf("\n")

int count = 0;

unsigned factorial(unsigned n)
{
    if (n == 1 || n == 0)
        return 1;
    else
        return n * factorial(n - 1);
}
unsigned formula(int n, int r)
{
    return factorial(n) / (factorial(r) * factorial(n - r));
}
int greedi_invers(int N)
{
    int unu = N, doi = 0, total = 0;
    while (1)
    {
        printf("unu %d; doi %d;  ", unu, doi);

        int comb = formula(unu + doi, unu);
        total += comb;
        printf("%d \n", comb);

        doi++;
        unu -= 2;
        if (unu < 0)
            break;
    }
    return total;
}

void print_arr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

bool swapp(int arr[], int start, int curr)
{
    for (int i = start; i < curr; i++)
        if (arr[i] == arr[curr])
            return 0;
    return 1;
}
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
void permutations(int **arr, int index, int n)
{
    if (index >= n)
    {
        ++count;
        printf("%-3d:|  ", count);
        print_arr(*arr, n);
        return;
    }

    for (int i = index; i < n; i++)
    {

        bool check = swapp(*arr, index, i);
        if (check)
        {
            swap(&(*arr)[index], &(*arr)[i]);
            permutations(arr, index + 1, n);
            swap(&(*arr)[index], &(*arr)[i]);
        }
    }
}

int brute_force(int N)
{
    int unu = N, doi = 0;
    int *arr = (int *)malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++)
        arr[i] = 1;
    permutations(&arr, 0, unu + doi);
    ENDL;
    while (unu > 1)
    {
        unu -= 2;
        ++doi;
        int j = 0;
        arr = (int *)realloc(arr, sizeof(int) * (unu + doi));
        for (j; j < doi; j++)
            arr[j] = 2;
        for (j; j < unu; j++)
            arr[j] = 1;
        permutations(&arr, 0, unu + doi);
        ENDL;
    }
    printf("oml poate urca scara in %d moduri\n", count);
}

int main()
{

    for (int i = 0; i < 10; i++)
    {
        printf("total %d \n", greedi_invers(i));
        count = 0;
        brute_force(i);
    }
    return EXIT_SUCCESS;
}
