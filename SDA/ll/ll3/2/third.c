// Pentru un concurs de admitere se generează un fișier cu numele „concurs.txt"
// care conține numele candidaților împreună cu notele la matematică, limba română, informatică, precum și media.
// Se cere programul pentru afișarea pe ecran a acestui fișier.
//  Să se afișeze pe ecran o înregistrare a unui candidat identificată prin numărul ei de ordine în fișier.
#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *f = NULL;
    f = fopen("concurs.txt", "r");
    char name[50];
    int m, r, i;
    float med;

    while (fscanf(f, "%s %d %d %d %f", name, &m, &r, &i, &med) > 0)
    {
        printf("%s %d %d %d %.1f\n", name, m, r, i, med);
    }

    fclose(f);
    return 0;
}