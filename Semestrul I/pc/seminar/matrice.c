#include <stdio.h>

int main()
{
    int n = 2, m = 2, k = 2;
    // int a[2][2] = {{2, 3}, {1, 4}};x
    // int b[2][2] = {{1, 4}, {5, 3}};

    printf("dati n m k care sunt randul coloana->rand coloana a doua matrici");
    scanf("%d %d %d", &n, &m, &k);

    int a[n][m], b[m][k], c[m][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("elementul %d %d : ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < k; j++)
        {
            printf("elementul %d %d : ", i, j);
            scanf("%d", &b[i][j]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int q = 0; q < k; q++)
        {
            int prod = 0;
            for (int j = 0; j < m; j++)
            {
                prod += a[i][j] * b[j][q];
            }
            c[i][q] = prod;
        }
    }

    printf("\n");
    for (int i = 0; i < n; i++)
    {
        for (int q = 0; q < m; q++)
        {

            printf("%d ", a[q][i]);
        }
        printf("\n");
    }

    printf("\n");
    for (int i = 0; i < m; i++)
    {
        for (int q = 0; q < k; q++)
        {

            printf("%d ", b[q][i]);
        }
        printf("\n");
    }

    printf("\n");
    for (int i = 0; i < n; i++)
    {
        for (int q = 0; q < k; q++)
        {

            printf("%d ", c[q][i]);
        }
        printf("\n");
    }

    return 0;
}