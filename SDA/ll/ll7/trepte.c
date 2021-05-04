// Plesu Catalin
// Un om dorește să urce o scară cu n trepte.
// El poate urca la un moment dat una sau două trepte.
// Precizați în câte moduri poate urca omul scara.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

unsigned factorial(unsigned n)
{
    if (n == 1 || n == 0)
        return 1;
    else
        return n * factorial(n - 1);
}

int fibonacci(int n)
{
    int f1 = 0, f2 = 1, next;
    if (n < 1)
        return -1;
    for (int i = 1; i <= n; i++)
    {
        next = f1 + f2;
        f1 = f2;
        f2 = next;
    }
    return next;
}

unsigned combinare(int n, int r)
{
    return factorial(n) / (factorial(r) * factorial(n - r));
}

int divide_conquer_add_repeat(int n)
{
    int unu = n, doi = 0, total = 0;
    while (1)
    {
        printf("unu %d; doi %d;  ", unu, doi);

        int comb = combinare(unu + doi, unu);
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
void permutations(int **arr, int index, int n, int *count)
{
    if (index >= n)
    {
        ++(*count);
        printf("%-3d:|  ", (*count));
        print_arr(*arr, n);
        return;
    }

    for (int i = index; i < n; i++)
    {

        bool check = swapp(*arr, index, i);
        if (check)
        {
            swap(&(*arr)[index], &(*arr)[i]);
            permutations(arr, index + 1, n, count);
            swap(&(*arr)[index], &(*arr)[i]);
        }
    }
}

int brute_force(int n, int *count)
{
    int unu = n, doi = 0;
    int *arr = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
        arr[i] = 1;
    permutations(&arr, 0, unu + doi, count);
    printf("\n");
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
        permutations(&arr, 0, unu + doi, count);
        printf("\n");
    }
    return *count;
}

int meniu()
{
    int o;
    printf("numarul dat poate fi calculat prin:\n");
    printf("1. forta bruta \n");
    printf("2. divide and conquer (limita 13)\n");
    printf("3. programare dinamica (fibonacci) (limita 47)\n");
    printf("4. alt numar de scari\n");
    printf("0. iesire\n");
    printf("optiunea - ");
    scanf("%d", &o);
    return o;
}

int main()
{
    printf("SDA LAB7 - calcularea modurilor de a parcurge o scara de N trepte\n");
    printf("dati N - ");
    int N;
    scanf("%d", &N);
    int o;
    int moduri;
    while (o = meniu())
    {
        moduri = 0;
        if (N < 1)
        {
            printf("asa scara nu exista\n");
            o = 4;
        }
        if (N > 47)
        {
            printf("modurile de urcare nu incap in tipul integer\ndati alt numar: ");
            o = 4;
        }
        clock_t begin, end;
        switch (o)
        {
        case 1:
            begin = clock();
            moduri = brute_force(N, &moduri);
            end = clock();
            break;
        case 2:
            begin = clock();
            moduri = divide_conquer_add_repeat(N);
            end = clock();
            break;
        case 3:
            begin = clock();
            moduri = fibonacci(N);
            end = clock();
            break;
        case 4:
            printf("numarul nou de trepte - ");
            scanf("%d", &N);
            break;
        default:
            break;
        }
        printf("scara poate fi urcata in %d moduri\n", moduri);
        printf("timpul de executie: %f sec.\n\n", (float)(end - begin) / CLOCKS_PER_SEC);
    }

    return EXIT_SUCCESS;
}
