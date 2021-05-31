void citireArc(arc *graf, int i, int x)
{
    int initial = 1;
    int terminal = 1;
    while (initial == terminal)
    {
        printf("pentru arcul %d\n", i + 1);
        printf("extremitatea initiala este - ");
        scanf("%d", &initial);
        if (initial < 1)
            initial = 1;
        if (initial > x)
            initial = x;
        printf("extremitatea terminala este - ");

        scanf("%d", &terminal);
        if (terminal < 1)
            terminal = 1;
        if (terminal > x)
            terminal = x;
        printf("ponderea este - ");
        int ponderea;
        scanf("%d", &ponderea);
        if (ponderea < 1)
            ponderea = 1;
        (graf + i)->extrInitiala = initial;
        (graf + i)->extrTerminala = terminal;
        (graf + i)->ponderea = ponderea;
    }
}
arc *citireGraf(int *x, int *u)
{
    arc *graf = NULL;
    printf("datin nr de varfuri si nr de arce: ");
    scanf("%d %d", x, u);

    graf = (arc *)malloc(*u * sizeof(arc));

    for (int i = 0; i < *u; i++)
        citireArc(graf, i, *x);
    return graf;
}
void priteazaGraf(arc *graf, int x, int u)
{
    printf("graful dat are %d varfuri si %d arce\n", x, u);
    for (int i = 0; i < u; i++)
        printf("%d ==(%d)==> %d\n", (graf + i)->extrInitiala, (graf + i)->ponderea, (graf + i)->extrTerminala);
}