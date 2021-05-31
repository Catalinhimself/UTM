// ecran a următorului meniu de opțiuni:
// Tabloul demonstrativ de n elemente (5<= n <=20).
// 2. Tabloul cu valori aleatorii (n=10000, n=100000, n=1000000).
// 3. Tabloul sortat crescător (n=10000, n=100000, n=1000000).
// 4. Tabloul sortat descrescător (n=10000, n=100000, n=1000000).
// 5. Ieșire din program

// Sortare Shell în ordine descendentă.

// Analiza empirică a algoritmului constă în:
// a) determinarea timpului de rulare, numărului de comparații, numărului de
// schimbări (sau deplasări) de elemente pentru tablouri  cu 3  diferite  seturi  de  valori și  cu  3  diferite
// volume  de  elemente;
// b) compararea și  analiza  rezultatelor  obținute utilizândfuncția creată
// și  funcția  din biblioteca standard a limbajului C;
// c) tragerea concluziilor.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

long long int comparatii = 0;
long long int schimbari = 0;

int *genereaza_mi_tabloul(int n)
{
    srand(time(NULL));
    int *tablou = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        tablou[i] = rand() % 20001 - 10000;
    }
    return tablou;
}
void printeaza_mi_tablou(int *tablou, int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", tablou[i]);
    printf("\n");
}
void shell_sorteaza_mi_descrescator(int *tablou, int n)
{
    comparatii = 0;
    schimbari = 0;
    for (int interval = n / 2; interval > 0; interval /= 2)
    {
        for (int i = interval; i < n; i += 1)
        {
            ++comparatii;
            int temp = tablou[i];
            int j;
            for (j = i; j >= interval && tablou[j - interval] < temp; j -= interval, ++comparatii)
            {

                tablou[j] = tablou[j - interval];
                ++schimbari;
            }
            tablou[j] = temp;
        }
    }
}
int comparare(const void *a, const void *b)
{
    ++comparatii;
    return (*(int *)b - *(int *)a);
}
int *duplicare_mi_tabloul(int *tablou, int n)
{
    int *duplicare = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        duplicare[i] = tablou[i];
    }
    return duplicare;
}
void compara_sortarea(int *arr, int n)
{
    int *arr2 = duplicare_mi_tabloul(arr, n);
    clock_t start, sfarsit;
    printf("########## N = %d | 10^%d ##########\n", n, (int)log10(n));
    printf("SHELL SORT:\n");
    start = clock();
    shell_sorteaza_mi_descrescator(arr, n);
    sfarsit = clock();
    printf("timpului de rulare: %f secunde\n", (double)(sfarsit - start) / CLOCKS_PER_SEC);
    printf("comparatii: %lld\n", comparatii);
    printf("schimbari: %lld\n", schimbari);
    printf("QSORT (stdlib)\n");
    comparatii = 0;
    start = clock();
    qsort(arr2, n, sizeof(int), comparare);
    sfarsit = clock();
    printf("timpului de rulare: %f secunde\n", (double)(sfarsit - start) / CLOCKS_PER_SEC);
    printf("comparatii: %lld\n", comparatii);
    printf("\n");
}
int main()
{
    printf("======================\n");
    printf("60 sec = 1 min\n");
    printf("0.001 sec = 1 milisec\n");
    printf("======================\n");
    srand(time(NULL));
    int *arr = NULL, n = (rand() % 16) + 5;
    arr = genereaza_mi_tabloul(n);
    int *arr2 = duplicare_mi_tabloul(arr, n);
    printf("################################\n");
    printf("Tabloul demonstrativ de %d elemente\n", n);
    printf("tablou initial:\n");
    printeaza_mi_tablou(arr, n);
    printf("################################\n");
    printf("SHELL SORT:\n");
    shell_sorteaza_mi_descrescator(arr, n);
    printeaza_mi_tablou(arr, n);
    printf("timpului de rulare: nesemnificativ\n");
    printf("comparatii: %lld\n", comparatii);
    printf("schimbari: %lld\n", schimbari);
    printf("################################\n");
    printf("QSORT (stdlib):\n");
    comparatii = 0;
    qsort(arr2, n, sizeof(int), comparare);
    printeaza_mi_tablou(arr2, n);
    printf("timpului de rulare: nesemnificativ\n");
    printf("comparatii: %lld\n", comparatii);

    int N[] = {10000, 100000, 1000000, 10000000, 100000000, 1000000000};
    for (int i = 0; i < sizeof(N) / sizeof(int); i++)
    {
        free(arr);
        arr = genereaza_mi_tabloul(N[i]);
        compara_sortarea(arr, N[i]);
    }
    return EXIT_SUCCESS;
}