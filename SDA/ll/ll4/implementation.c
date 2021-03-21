#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "header.h"

const char NAME[][30] = {"Catalin", "Marius", "Daniel", "Mirela", "Alex", "Colea", "Sandu", "Ion", "Maximo", "Melissa", "Petru", "Stas", "Vlad", "Crstian", "Ion", "Mihail", "Victor", "Vladislav", "Maria", "Vitalie", "Nicoleta", "Sam"};
const char TYPE[][30] = {"Apartament", "Birou", "Fabrica", "Magazin", "Mol", "Hotel", "Cladire Istorica", "Teren gol", "Restaurant"};
const char ADDRESS[][30] = {"Strada Albisoara", "Strada Alexandru Bernardazzi", "Strada Alexandru cel Bun", "Strada Alexei Mateevici", "Strada Armeneasca", "Strada Bucuresti", "Strada Calea Iesilor", "Strada Mihail Kogalniceanu"};

int afiseaza_meniu()
{
    printf("\n1.  Crearea listei în memoria dinamică.");
    printf("\n2.  Introducerea informației despre elementele listei de la tastatură");
    printf("\n3.  Afișarea informației despre elementele listei la ecran.");
    printf("\n4.  Căutarea elementuluiîn listă.");
    printf("\n5.  Modificarea câmpurilor unui element din listă.");
    printf("\n6.  Determinarea adresei ultimului element din listă.");
    printf("\n7.  Determinarea lungimii listei (numărul de elemente).");
    printf("\n8.  Interschimbareaa două elemente indicate în listă.");
    printf("\n9.  Sortarea listei.");
    printf("\n10. Eliberarea memoriei alocate pentru listă.");
    printf("\n0.  Ieșire din program");
    printf("\nOptiunea - ");
    int m;
    scanf("%d", &m);
    return m;
}

void get_struct_info(imobil *info)
{
    printf("__struct_info__\n");
    printf("marimea structurii: %ldB\n", sizeof(imobil));
    printf("  marimea pointerului next: %ldB\n", sizeof(struct _imobil *));
    printf("  variabile float: 2 x %ldB\n", sizeof(float));
    printf("    costul %-10f\n", info->costul);
    printf("    adresa %-10f\n", info->suprafata);
    printf("  pointeri la char: 3 x %ldB\n", sizeof(char *));
    if (info)
    {
        printf("    proprietar str: %ldB\n      ", strlen(info->proprietar));
        puts(info->proprietar);
        printf("    adresa str: %ldB\n      ", strlen(info->adresa));
        puts(info->adresa);
        printf("    tip str: %ldB\n      ", strlen(info->tip));
        puts(info->tip);
        printf("total: %ldB\n", sizeof(imobil) + strlen(info->proprietar) + strlen(info->adresa) + strlen(info->tip));
    }
}

imobil *creaza_lista()
{
    imobil *cap = NULL;
    errno = 0;
    cap = (imobil *)malloc(sizeof(imobil));
    if (errno)
    {
        printf("exit code%d: %s\n", errno, strerror(errno));
        exit(errno);
    }

    return cap;
}

int main()
{
    imobil *cap = NULL;
    // cap = (imobil *)malloc(sizeof(imobil));
    // cap->costul = 12;
    // cap->suprafata = 123;
    // cap->proprietar = "asdaslfkdjasldfkf";
    // cap->adresa = "laskdf";
    // cap->tip = "alsdfkj";

    printf("__testing_place__\n");
    // get_struct_info(cap);
    cap = creaza_lista();
}
