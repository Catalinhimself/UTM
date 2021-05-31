#include <stdio.h>
#include "./../headers/header.h"

int afiseaza_meniu()
{
    printf("\n__Crearea listei in memoria dinamica__");
    printf("\n1. Introducerea informatiei despre elementele listei de la tastatura");
    printf("\n2. Genereaza o lista cu elemente aleatorii\n");
    printf("\n3. Afisarea informatiei despre elementele listei la ecran.");
    printf("\n4. Cautarea elementuluiin lista.");
    printf("\n5. Modificarea campurilor unui element din lista.");
    printf("\n6. Determinarea adresei ultimului element din lista.");
    printf("\n7. Determinarea lungimii listei (numarul de elemente).");
    printf("\n8. Interschimbareaa doua elemente indicate in lista.");
    printf("\n9. Sortarea listei.");
    printf("\n10. Eliberarea memoriei alocate pentru lista.");
    printf("\n11. Calculeaza memoria ocupata.");
    printf("\n0. Iesire din program");
    printf("\nOptiunea - ");
    int m;
    scanf("%d", &m);
    return m;
}

int afiseaza_submeniu_criterii()
{
    printf("Dupa proprietar%4d\n", 1);
    printf("Dupa tip%11d\n", 2);
    printf("Dupa adresa%8d\n", 3);
    printf("Dupa suprafata%5d\n", 4);
    printf("Dupa cost%10d\n", 5);
    printf("Anulare%12d\n", 0);
    int optiune;
    scanf("%d", &optiune);
    return optiune;
}