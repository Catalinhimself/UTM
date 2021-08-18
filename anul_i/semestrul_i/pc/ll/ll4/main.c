#include <stdio.h>

int main()
{
    int n, m;
    printf("\n\n\t\t\t");
    printf("Lucrarea de laborator nr. 4 Varianta 18\n\n\n");
    printf("Acest program va citi o matrice si va calcula :\nsuma elementelor pozitive din liniile pare si\nprodusul elementelor mai mici ca 5 din coloanele impare\n");
    printf("nr de randuri = ");
    scanf("%d", &n);
    printf("nr de coloane = ");
    scanf("%d", &m);
    int tablou[n][m];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            printf("elementul [%d %d] = ", i + 1, j + 1);
            scanf("%d", &tablou[i][j]);
        }

    //varianta 18
    //cerinte
    //1 suma elementelor pozitive din liniile pare
    //2 produsul elementelor < 5 din coloanele impare

    for (int i = 0; i < n; i++)
    {
        if ((i + 1) % 2 == 0)
        { //operatiile pentru rand par
            int conditiesatisfacuta = 0;
            printf("\nrand par %d :\n", i + 1);
            int sum = 0;
            for (int j = 0; j < m; j++)
            {
                if (tablou[i][j] > 0)
                {
                    sum += tablou[i][j];
                    conditiesatisfacuta = 1;
                }
                printf("%d  ", tablou[i][j]);
            }
            if (!conditiesatisfacuta)
                printf("\nnici un numare > 0");
            else
                printf("\nsum = %d", sum);
        }
        printf("\n");
    }

    for (int i = 0; i < m; i++)
    {
        int conditiesatisfacuta = 0;
        if ((i + 1) % 2 == 1)
        { //operatiile pentru coloana impara
            printf("\ncoloana impara %d :", i + 1);
            int prod = 1;
            for (int j = 0; j < n; j++)
            {
                if (tablou[j][i] < 5)
                {
                    prod *= tablou[j][i];
                    conditiesatisfacuta = 1;
                }
                printf("\n%d", tablou[j][i]);
            }
            if (!conditiesatisfacuta)

                printf("\nconditie nesatisfacuta 0 elemente < 5");

            else
                printf("\nprod = %d", prod);
        }
        printf("\n");
    }

    //printeaza tabloul / matricea
    printf("matricea initiala");
    for (int i = 0; i < n; i++)
    {
        printf("\n");
        for (int j = 0; j < m; j++)
        {
            printf("%6d ", tablou[i][j]);
        }
    }
    return 0;
}