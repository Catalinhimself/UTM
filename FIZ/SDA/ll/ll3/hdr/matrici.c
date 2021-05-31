void printeazaMatrice(int n, int m, int **matrice)
{
    printf("%d %d\n", n, m);
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            printf("%d ", matrice[i][j]);

        printf("\n");
    }
    printf("\n");
}
int **creareMatrice(int n, int m)
{
    int **matrice = NULL;
    matrice = (int **)calloc(n, sizeof(int *));
    for (int i = 0; i < n; i++)
        matrice[i] = (int *)calloc(m, sizeof(int));
    return matrice;
}
int **multiplicareaMatricilor(int n, int m, int p, int **M1, int **M2)
{
    int **M = creareMatrice(n, p);
    for (int i = 0; i < n; i++)
        for (int k = 0; k < p; k++)
            for (int j = 0; j < m; j++)
                M[i][k] += M1[i][j] * M2[j][k];

    return M;
}
int **citireaMatrice(int *n, int *m)
{
    printf("dati nr. de randuri ");
    scanf("%d", n);
    printf("dati nr. de coloane ");
    scanf("%d", m);
    int **M = creareMatrice(*n, *m);
    for (int i = 0; i < *n; i++)
        for (int j = 0; j < *m; j++)
        {
            printf("elementul [%d][%d] = ", i + 1, j + 1);
            scanf("%d", &M[i][j]);
        }
    return M;
}
void freeMatrice(int **matrice, int n)
{
    for (int i = 0; i < n; i++)
        free(matrice[i]);
    free(matrice);
    matrice = NULL;
}