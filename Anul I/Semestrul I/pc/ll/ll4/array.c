#include <stdio.h>

int main()
{
    int conditiesatisfacuta = 0;
    int n, m;
    printf("nr de randuri = ");
    scanf("%d", &n);
    printf("nr de coloane = ");
    scanf("%d", &m);
    int tablou[n][m];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            printf("enementul [%d %d] = ", i, j);
            scanf("%d", &tablou[i][j]);
        }

    //printeaza tabloul / matricea
    for (int i = 0; i < n; i++)
    {
        printf("\n");
        for (int j = 0; j < m; j++)
        {
            printf("%d \t", tablou[i][j]);
        }
    }
    return 0;
}