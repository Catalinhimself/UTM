const char fisier1[20] = "lab3_in.txt";
const char fisier2[20] = "lab3_out.txt";
void sciereaInFisier(int n1, int n2, int m1, int m2, int **M1, int **M2)
{
    FILE *fisier = NULL;
    fisier = fopen(fisier1, "w");
    if (!fisier)
    {
        printf("nu s-a putut deschde acest fisier\n");
        return;
    }
    fprintf(fisier, "%d %d\n", n1, m1);
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < m1; j++)
            fprintf(fisier, "%d ", M1[i][j]);

        fprintf(fisier, "\n");
    }
    fprintf(fisier, "%d %d\n", n2, m2);
    for (int i = 0; i < n2; i++)
    {
        for (int j = 0; j < m2; j++)
            fprintf(fisier, "%d ", M2[i][j]);

        fprintf(fisier, "\n");
    }

    fclose(fisier);
}

void dimensiunileMatricilor(int *n1, int *m1, int *n2, int *m2)
{
    FILE *fisier = NULL;
    fisier = fopen(fisier1, "r");
    if (!fisier)
    {
        printf("in memorie nu exista nici un fisier\n");
        return;
    }
    fscanf(fisier, "%d %d", n1, m1);
    int M1[*n1][*m1];
    for (int i = 0; i < *n1; i++)
        for (int j = 0; j < *m1; j++)
            fscanf(fisier, "%d ", &M1[i][j]);

    fscanf(fisier, "%d %d", n2, m2);
    int M2[*n2][*m2];
    for (int i = 0; i < *n2; i++)
        for (int j = 0; j < *m2; j++)
            fscanf(fisier, "%d ", &M2[i][j]);
    fclose(fisier);
}
void citireaMatricilor(int **M1, int **M2)
{
    int n, m;
    FILE *fisier = NULL;
    fisier = fopen(fisier1, "r");
    if (!fisier)
    {
        printf("nu exista acest fisier\n");
        return;
    }

    fscanf(fisier, "%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            fscanf(fisier, "%d ", &M1[i][j]);

    fscanf(fisier, "%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            fscanf(fisier, "%d ", &M2[i][j]);
    fclose(fisier);
}
void scriereProdus(int n, int a, int b, int m, int **M)
{
    FILE *fisier = NULL;
    fisier = fopen(fisier2, "w");
    if (!fisier)
    {
        printf("nu s-a putut deschde acest fisier\n");
        return;
    }
    if (a != b)
    {
        fprintf(fisier, "Aceste matrici nu pot fi inmultite");
        fclose(fisier);
        return;
    }
    fprintf(fisier, "%d %d\n", n, m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            fprintf(fisier, "%d ", M[i][j]);

        fprintf(fisier, "\n");
    }

    fclose(fisier);
}