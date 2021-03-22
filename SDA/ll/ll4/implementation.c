#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <errno.h>

#include "header.h"
#include "const.h"

void get_struct_info(imobil *struct_ptr)
{
    long int total = sizeof(imobil);
    printf("__struct_info__\n");
    printf("# marimea structurii: %ldB\n", total);
    printf("## marimea pointerului next: %ldB\n", sizeof(struct _imobil *));
    printf("## variabile float: 2 x %ldB\n", sizeof(float));
    printf("### costul %-10f\n", struct_ptr->costul);
    printf("### adresa %-10f\n", struct_ptr->suprafata);
    printf("## pointeri la char: 3 x %ldB\n", sizeof(char *));
    if (struct_ptr)
    {
        if (struct_ptr->proprietar)
        {
            printf("### proprietar str: %ldB\n#### ", strlen(struct_ptr->proprietar));
            puts(struct_ptr->proprietar);
            total += strlen(struct_ptr->proprietar);
        }
        if (struct_ptr->adresa)
        {
            printf("### adresa str: %ldB\n#### ", strlen(struct_ptr->adresa));
            puts(struct_ptr->adresa);
            total += strlen(struct_ptr->adresa);
        }
        if (struct_ptr->tip)
        {
            printf("### tip str: %ldB\n#### ", strlen(struct_ptr->tip));
            puts(struct_ptr->tip);
            total += strlen(struct_ptr->tip);
        }

        printf("total: %ldB\n", total);
    }
}

imobil *citeste_element(int ord)
{
    errno = 0;
    imobil *q = (imobil *)malloc(sizeof(imobil));
    if (errno)
    {
        printf("exit code %d: %s\n", errno, strerror(errno));
        exit(errno);
    }
    printf("Citirea elementului %d din lista.\n", ord);
    q->next = NULL;

    char str[255];
    printf("proprietar: ");
    scanf(" %s", str);
    q->proprietar = (char *)malloc((strlen(str) + 1) * sizeof(char));
    strcpy(q->proprietar, str);
    printf("tip: ");
    scanf(" %s", str);
    q->tip = (char *)malloc((strlen(str) + 1) * sizeof(char));
    strcpy(q->tip, str);
    printf("adresa: ");
    scanf(" %s", str);
    q->adresa = (char *)malloc((strlen(str) + 1) * sizeof(char));
    strcpy(q->adresa, str);
    printf("suprafata : ");
    scanf(" %f", &q->suprafata);
    printf("costul : ");
    scanf(" %f", &q->costul);

    return q;
}

imobil *creaza_lista()
{
    imobil *cap = NULL, *t = NULL;
    errno = 0;
    cap = (imobil *)malloc(sizeof(imobil));
    if (errno)
    {
        printf("exit code %d: %s\n", errno, strerror(errno));
        exit(errno);
    }

    int ord = 1;
    cap = citeste_element(ord++);
    t = cap;

    char input = 'c';
    printf("continua / termina [c/t]\n");
    scanf(" %c", &input);
    while (input != 't')
    {
        t->next = citeste_element(ord++);
        t = t->next;
        printf("continua / termina [c/t]\n");
        scanf(" %c", &input);
    };

    return cap;
}

imobil *creaza_lista_demo(int nr)
{
    srand(time(NULL));
    imobil *cap = NULL,
           *t = NULL;
    errno = 0;
    cap = (imobil *)malloc(sizeof(imobil));
    if (errno)
    {
        printf("exit code %d: %s\n", errno, strerror(errno));
        exit(errno);
    }

    errno = 0;
    imobil *q = (imobil *)malloc(sizeof(imobil));
    if (errno)
    {
        printf("exit code %d: %s\n", errno, strerror(errno));
        exit(errno);
    }

    q->next = NULL;
    char str[255];

    strcpy(str, NAME[rand() % NAME_COUNT]);
    q->proprietar = (char *)malloc((strlen(str) + 1) * sizeof(char));
    strcpy(q->proprietar, str);
    strcpy(str, TYPE[rand() % TYPE_COUNT]);
    q->tip = (char *)malloc((strlen(str) + 1) * sizeof(char));
    strcpy(q->tip, str);
    strcpy(str, ADDRESS[rand() % ADDRESS_COUNT]);
    q->adresa = (char *)malloc((strlen(str) + 1) * sizeof(char));
    strcpy(q->adresa, str);
    q->suprafata = ((float)(rand() % 300) + (float)11 / ((rand() % 9) + 1)) + 16;
    q->costul = q->suprafata * (rand() % 1500);
    cap = q;
    t = cap;
    for (int i = 1; i < nr; i++)
    {
        errno = 0;
        q = (imobil *)malloc(sizeof(imobil));
        if (errno)
        {
            printf("exit code %d: %s\n", errno, strerror(errno));
            exit(errno);
        }

        q->next = NULL;
        char str[255];

        strcpy(str, NAME[rand() % NAME_COUNT]);
        q->proprietar = (char *)malloc((strlen(str) + 1) * sizeof(char));
        strcpy(q->proprietar, str);

        strcpy(str, TYPE[rand() % TYPE_COUNT]);
        q->tip = (char *)malloc((strlen(str) + 1) * sizeof(char));
        strcpy(q->tip, str);

        strcpy(str, ADDRESS[rand() % ADDRESS_COUNT]);
        q->adresa = (char *)malloc((strlen(str) + 1) * sizeof(char));
        strcpy(q->adresa, str);

        q->suprafata = ((float)(rand() % 300) + (float)11 / ((rand() % 9) + 1)) + 16;
        q->costul = q->suprafata * (rand() % 21) / ((rand() % 16) + 1) * 1000 + q->suprafata * (rand() % 500);
        t->next = q;
        t = t->next;
    }
    return cap;
}

void afiseaza_lista(imobil *cap)
{
    if (cap == NULL)
    {
        printf("Lista nu este valida sau este NULL-a\n");
        return;
    }
    imobil *t = cap;
    printf("| Nr.| Proprietar|%15stip|%26sadresa|     suprafata|%8scostul|%8s( POINTER | NEXT )\n", "", "", "", "");
    int i = 1;
    while (t != NULL)
    {

        printf("|%-3d |%10s |%17s | %-30s |%9.2f m^2 |%12.2f $| ( %p | %p )\n", i++, t->proprietar, t->tip, t->adresa, t->suprafata, t->costul, t, t->next);
        t = t->next;
    }
}

void cauta_structura(imobil *cap)
{
    if (cap == NULL)
    {
        printf("lista este invalida\nincercati sa introduceti o lista inainte de a cauta ceva in ea\n");
        return;
    }
    printf("\ncautarea in lista\n");
    int optiune = afiseaza_meniu_cautare();
    imobil *t;
    switch (optiune)
    {
    case 1:
    case 2:
    case 3:
    {
        char text[25];
        if (optiune == 1)
            strcpy(text, "proprietarul");
        if (optiune == 2)
            strcpy(text, "tipul");
        if (optiune == 3)
            strcpy(text, "adresa");
        printf("Introduceti %s imobilului cautat: ", text);
        char str[50];
        fflush(stdin);
        gets(str);
        gets(str);
        t = cap;
        int gasit = 0, i = 1;
        printf("Lista imobilelor %s \"%s\":\n", text, str);
        printf("| Nr.| Proprietar|%15stip|%26sadresa|     suprafata|%8scostul|%8s( POINTER | NEXT )\n", "", "", "", "");
        while (t)
        {
            switch (optiune)
            {
            case 1:
                if (!strcasecmp(t->proprietar, str))
                {
                    printf("|%-3d |%10s |%17s | %-30s |%9.2f m^2 |%12.2f $| ( %p | %p )\n", i, t->proprietar, t->tip, t->adresa, t->suprafata, t->costul, t, t->next);
                    gasit = 1;
                }
                break;
            case 2:
                if (!strcasecmp(t->tip, str))
                {
                    printf("|%-3d |%10s |%17s | %-30s |%9.2f m^2 |%12.2f $| ( %p | %p )\n", i, t->proprietar, t->tip, t->adresa, t->suprafata, t->costul, t, t->next);
                    gasit = 1;
                }
                break;
            case 3:
                if (!strcasecmp(t->adresa, str))
                {
                    printf("|%-3d |%10s |%17s | %-30s |%9.2f m^2 |%12.2f $| ( %p | %p )\n", i, t->proprietar, t->tip, t->adresa, t->suprafata, t->costul, t, t->next);
                    gasit = 1;
                }
                break;
            }

            t = t->next;
            i++;
        }
        if (gasit == 0)
            printf("Imobilele cu %s \"%s\" nu exista in lista data.\n", text, str);
        break;
    }
    case 4:
    case 5:
    {
        printf("Introduceti tipul imobilului cautat: ");
        char str[50];
        fflush(stdin);
        gets(str);
        gets(str);

        t = cap;
        int gasit = 0, i = 1;
        printf("Lista imobilelor de tipul \"%s\":\n", str);
        printf("| Nr.| Proprietar|%15stip|%26sadresa|     suprafata|%8scostul|%8s( POINTER | NEXT )\n", "", "", "", "");
        while (t)
        {

            if (!strcasecmp(t->tip, str))
            {
                printf("|%-3d |%10s |%17s | %-30s |%9.2f m^2 |%12.2f $| ( %p | %p )\n", i, t->proprietar, t->tip, t->adresa, t->suprafata, t->costul, t, t->next);
                gasit = 1;
            }
            t = t->next;
            i++;
        }
        if (gasit == 0)
            printf("Proprietarilor cu numele \"%s\" nu exista in lista data.\n", str);
        break;
    }
    }
}

// int main()
// {
//     imobil *cap = NULL;

//     printf("__testing_place__\n");

//     // cap = creaza_lista();
//     cap = creaza_lista_demo();
//     afiseaza_lista(cap);
//     cauta_structura();
//     // get_struct_info(cap);
// }
