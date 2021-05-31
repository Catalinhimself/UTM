#include <stdio.h>

int main()
{

    int n, m;
    printf("dati nr de randuri - ");
    scanf("%d", &n);
    printf("dati nr de coloane - ");
    scanf("%d", &m);

    //citirea matricii
    int mat[n][m + 1];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("elementul %d %d : ", i, j);
            scanf("%d", &mat[i][j]);
        }
        mat[i][m] = 0;
    }

    //numararea de elemente negative
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {

            if (mat[i][j] < 0)
            {
                mat[i][m]++;
            }
        }
        printf("%d ", mat[i][m]);
    }

    //schimbarea randurilor
    int schimb;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
        }
    }

    return 0;
}