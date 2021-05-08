// Tabloul demonstrativ de n elemente (5<= n <=20).
// 2. Tabloul cu valori aleatorii (n=10000, n=100000, n=1000000).
// 3. Tabloul sortat crescător (n=10000, n=100000, n=1000000).
// 4. Tabloul sortat descrescător (n=10000, n=100000, n=1000000).
// 5. Ieșire din program

// Sortare Shell în ordine descendentă.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

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
    for (int interval = n / 2; interval > 0; interval /= 2)
    {

        for (int i = interval; i < n; i += 1)
        {
            int temp = tablou[i];
            int j;
            for (j = i; j >= interval && tablou[j - interval] < temp; j -= interval)
            {
                tablou[j] = tablou[j - interval];
            }
            tablou[j] = temp;
        }
    }
}
int main()
{
    int *arr = NULL, n = 10;
    arr = genereaza_mi_tabloul(n);
    printeaza_mi_tablou(arr, n);
    shell_sorteaza_mi_descrescator(arr, n);
    printeaza_mi_tablou(arr, n);

    time_t begin, end;
    clock_t start, sfarsit;
    int N[] = {10000, 100000, 1000000, 10000000};
    for (int i = 0; i < sizeof(N) / sizeof(int); i++)
    {
        free(arr);
        arr = genereaza_mi_tabloul(N[i]);
        time(&begin);
        start = clock();
        shell_sorteaza_mi_descrescator(arr, N[i]);
        time(&end);
        sfarsit = clock();
        printf("numarul de elemente -  %d\n", N[i]);
        printf("durata executiei -  %ld sau %f\n", end - begin, (double)(sfarsit - start) / CLOCKS_PER_SEC);
    }
    return EXIT_SUCCESS;
}