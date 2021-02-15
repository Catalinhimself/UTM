//varianta 18 labul 5
#include <stdio.h>
#include <stdlib.h>

void meniu(int *n, int *m);
void printm(int **tablou, int n, int m);
void scanm(int **tablou, int n, int m);
void killmatrix(int **tablou, int n);
void randparsum(int **tablou, int n, int m);
void colinparprod(int **tablou, int n, int m);
int randm(int **tablou, int n, int m);

int main()
{
    int n, m;
    printf("\n\n\t\t\t");
    //functia mea care scrie conditiile programului si citeste dimensiunile matricii
    meniu(&n, &m);
    // alocarea dinamica a unui tablou de pointeri
    int **tablou = (int **)malloc(n * sizeof(int *));
    //tabloului de pointeri de mai sus i se aloca alt tablou
    for (int i = 0; i < n; i++)
        tablou[i] = (int *)malloc(m * sizeof(int));

    //citeste matricea daca utilizatorului nu ii este lene
    if (randm(tablou, n, m))
    {
        scanm(tablou, n, m);
    }

    randparsum(tablou, n, m);

    colinparprod(tablou, n, m);

    //printeaza tabloul / matricea
    printf("matricea initiala");
    printm(tablou, n, m);
    //elibereaza memoria matricii
    killmatrix(tablou, n);
    getchar();
    return 0;
}
void meniu(int *n, int *m)
{
    printf("Lucrarea de laborator nr. 5 Varianta 18\n\n\n");
    printf("Acest program va citi o matrice si va calcula :\nsuma elementelor pozitive din liniile pare si\nprodusul elementelor mai mici ca 5 din coloanele impare\n");
    printf("nr de randuri = ");
    scanf("%d", n);
    printf("nr de coloane = ");
    scanf("%d", m);
}
void scanm(int **tablou, int n, int m)
{

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            printf("elementul [%d %d] = ", i + 1, j + 1);
            scanf("%d", &tablou[i][j]);
        }
}
void printm(int **tablou, int n, int m)
{

    for (int i = 0; i < n; i++)
    {
        printf("\n");
        for (int j = 0; j < m; j++)
        {
            printf("%6d ", tablou[i][j]);
        }
    }
}
void randparsum(int **tablou, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        int conditiesatisfacuta = 0;
        if ((i + 1) % 2 == 0)
        { //operatiile pentru rand par
            printf("rand par %d : ", i + 1);
            int sum = 0;
            for (int j = 0; j < m; j++)
            {
                if (tablou[i][j] > 0)
                {
                    sum += tablou[i][j];
                    conditiesatisfacuta = 1;
                }
            }
            if (!conditiesatisfacuta)
                printf(" nici un numare > 0");
            else
                printf(" sum = %d", sum);
        }
        printf("\n");
    }
}
void colinparprod(int **tablou, int n, int m)
{
    for (int i = 0; i < m; i++)
    {
        int conditiesatisfacuta = 0;
        if ((i + 1) % 2 == 1)
        { //operatiile pentru coloana impara
            printf("coloana impara %d : ", i + 1);
            int prod = 1;
            for (int j = 0; j < n; j++)
            {
                if (tablou[j][i] < 5)
                {
                    prod *= tablou[j][i];
                    conditiesatisfacuta = 1;
                }
            }
            if (!conditiesatisfacuta)

                printf(" conditie nesatisfacuta 0 elemente < 5");

            else
                printf(" prod = %d", prod);
        }
        printf("\n");
    }
}

void killmatrix(int **tablou, int n)
{
    for (int i = 0; i < n; i++)
        free(tablou[i]);
    free(tablou);
}

int randm(int **tablou, int n, int m)
{
    srand(time(NULL));
    int b, max, min;
    printf("Daca doriti sa introduceti matricea => tastati - 1 \ndaca doriti o matrice umpluta cu elemente aleatorii => tastati - 0\noptiunea aleasa - ");
    scanf("%d", &b);
    if (!b)
    {
        printf("dati limita de sus si jos");
        scanf("%d %d", &max, &min);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            tablou[i][j] = (rand() % (max - min + 1)) + min;
        }
    }
    return b;
}