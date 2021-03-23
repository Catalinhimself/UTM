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
    if (struct_ptr)
    {
        printf("### costul %-10f\n", struct_ptr->costul);
        printf("### adresa %-10f\n", struct_ptr->suprafata);
    }
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

        q->suprafata = ((float)(rand() % 100) + (rand() % 100) + (rand() % 100) + (float)11 / ((rand() % 9) + 1)) + 16;
        q->costul = q->suprafata * (rand() % 21) / ((rand() % 16) + 1) * 1000 + q->suprafata * (rand() % 500);
        t->next = q;
        t = t->next;
    }
    return cap;
}

int afiseaza_lista(imobil *cap)
{
    if (cap == NULL)
    {
        printf("Lista nu este valida sau este NULL-a\n");
        return 0;
    }
    imobil *t = cap;
    printf("| Nr.| Proprietar|%15stip|%26sadresa|     suprafata|%8scostul|%8s( POINTER | NEXT )\n", "", "", "", "");
    int i = 0;
    while (t != NULL)
    {

        printf("|%-3d |%10s |%17s | %-30s |%9.2f m^2 |%12.2f $| ( %p | %p )\n", ++i, t->proprietar, t->tip, t->adresa, t->suprafata, t->costul, t, t->next);
        t = t->next;
    }
    return i;
}

void cauta_structura(imobil *cap)
{
    if (cap == NULL)
    {
        printf("lista este invalida\nincercati sa introduceti o lista inainte de a cauta ceva in ea\n");
        return;
    }
    printf("\ncautarea in lista\n");
    int optiune = afiseaza_submeniu_criterii();
    if (!optiune)
        return;
    imobil *t;

    char text[25];
    if (optiune == 1)
        strcpy(text, "proprietarul");
    if (optiune == 2)
        strcpy(text, "tipul");
    if (optiune == 3)
        strcpy(text, "adresa");
    if (optiune == 4)
        strcpy(text, "suprafata");
    if (optiune == 5)
        strcpy(text, "cost");
    char str[50];
    float min, max;
    int gasit = 0, i = 1;
    t = cap;
    switch (optiune)
    {
    case 1:
    case 2:
    case 3:
        printf("Introduceti %s imobilului cautat: ", text);
        // gets(str);
        // gets(str);
        scanf("%c", &str[0]); // curata bufferul
        scanf("%[^\n]", str);
        printf("Lista imobilelor %s \"%s\":\n", text, str);
        break;
    case 4:
    case 5:
        printf("Introduceti intervalul de %s pentru imobil\n", text);
        printf("%s minim: ", text);
        scanf("%f", &min);
        printf("%s maxim: ", text);
        scanf("%f", &max);
        if (min > max)
        {
            min += max;
            max = min - max;
            min = min - max;
        }
        break;
    }

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
        case 4:
            if (t->suprafata > min && t->suprafata < max)
            {
                printf("|%-3d |%10s |%17s | %-30s |%9.2f m^2 |%12.2f $| ( %p | %p )\n", i, t->proprietar, t->tip, t->adresa, t->suprafata, t->costul, t, t->next);
                gasit = 1;
            }
            break;
        case 5:
            if (t->costul > min && t->costul < max)
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
        if (optiune == 1 || optiune == 2 || optiune == 3)
            printf("Imobilele cu %s \"%s\" nu exista in lista data.\n", text, str);
    if (optiune == 4 || optiune == 5)
        printf("Imobilele cu %s cu valori pe intervalul %f - %f nu exista in lista data.\n", text, min, max);
}
void modifica_structura(imobil *cap)
{
    if (cap == NULL)
    {
        printf("lista este invalida\nincercati sa introduceti o lista inainte de a modifica ceva\n");
        return;
    }
    int id = 0;
    printf("\nDati id-ul imobilului pe care doriti sa-l modificati: ");
    scanf("%d", &id);
    imobil *t = cap;
    int i = 0, modificat = 0;
    while (t)
    {
        i++;
        if (i == id)
        {
            char str[50];
            float val;
            modificat = 1;
            printf("daca nu doriti sa modificati un camp dati [ENTER]\n");
            printf("proprietarul vechi: %s\nproprietarul nou: ", t->proprietar);
            scanf("%c", &str[0]); // curata bufferul
            scanf("%[^\n]", str);
            if (strcmp(str, "\n"))
            {
                t->proprietar = realloc(t->proprietar, strlen(str));
                strcpy(t->proprietar, str);
            }
            else
                printf("ramane nemodificat\n");
            printf("tipul vechi: %s\ntipul nou: ", t->tip);
            scanf("%c", &str[0]); // curata bufferul
            scanf("%[^\n]", str);
            if (strcmp(str, "\n"))
            {
                t->tip = realloc(t->tip, strlen(str));
                strcpy(t->tip, str);
            }
            else
                printf("ramane nemodificat\n");
            printf("adresa veche: %s\nadresa noua: ", t->adresa);
            scanf("%c", &str[0]); // curata bufferul
            scanf("%[^\n]", str);
            if (strcmp(str, "\n"))
            {
                t->adresa = realloc(t->adresa, strlen(str));
                strcpy(t->adresa, str);
            }
            else
                printf("ramane nemodificat\n");
            printf("suprafata veche: %f\nsuprafata noua: ", t->suprafata);
            scanf("%c", &str[0]); // curata bufferul
            scanf("%[^\n]", str);
            if (strcmp(str, "\n"))
            {
                t->suprafata = atof(str);
            }
            else
                printf("ramane nemodificat\n");
            printf("costul vechi: %f\ncostul nou: ", t->costul);
            scanf("%c", &str[0]); // curata bufferul
            scanf("%[^\n]", str);
            if (strcmp(str, "\n"))
            {
                t->costul = atof(str);
            }
            else
                printf("ramane nemodificat\n");
            break;
        }
        t = t->next;
    }
    if (!modificat)
        printf("Nu exista un imobil cu asa id deci nu poate fi modificat\n");
    else
        printf("|%-3d |%10s |%17s | %-30s |%9.2f m^2 |%12.2f $| ( %p | %p )\n", id, t->proprietar, t->tip, t->adresa, t->suprafata, t->costul, t, t->next);
}

imobil *determina_ultimul_pointer(imobil *cap)
{
    if (cap == NULL)
    {
        printf("lista este invalida\nincercati sa introduceti o lista pentru a avea un ultim pointer\n");
        return NULL;
    }
    imobil *t = cap;
    while (t->next)
    {
        t = t->next;
    }
    printf("ultima adresa: %p\n", t);
    return t;
}
imobil *interschimba_2_elemente(imobil *cap, int limita)
{
    printf("__INTERSCHIMBAREA__\n");
    if (cap == NULL)
    {
        printf("lista este invalida\nincercati sa introduceti o lista inainte de a modifica ceva\n");
        return cap;
    }
    printf("dati id-urile a doua elemente pe care doriti sa le interschimbati: ");
    int a, b;
    scanf("%d %d", &a, &b);
    if (a < 1 || a > limita || b < 1 || b > limita)
    {
        printf("ati iesit din limitele listei :/\n");
        return cap;
    }
    if (a == b)
    {
        printf("numerele sunt egale, nu avem ce schimba\n");
        return cap;
    }
    if (a > b)
    {
        int temp = b;
        b = a;
        a = temp;
    }
    imobil *t = cap, *a0 = NULL, *a1, *b0 = NULL, *b1;
    int i = 0;
    while (t)
    {
        i++;
        if (i == a - 1)
            a0 = t;
        if (i == a)
            a1 = t;
        if (i == b - 1)
            b0 = t;
        if (i == b)
            b1 = t;
        t = t->next;
    }
    printf("%p %p %p %p\n", a0, a1, b0, b1);
    if (!a0)
    {
        if (a + 1 == b)
        {
            a1->next = b1->next;
            b1->next = a1;
            cap = b1;
        }
        else
        {
            imobil *t = b1->next;
            b1->next = a1->next;
            cap = b1;
            a1->next = t;
            b0->next = a1;
        }
    }
    else
    {
        if (a + 1 == b)
        {
            a1->next = b1->next;
            b1->next = a1;
            a0->next = b1;
        }
        else
        {
            imobil *t = b1->next;
            b1->next = a1->next;
            a0->next = b1;
            a1->next = t;
            b0->next = a1;
        }
    }
    return cap;
}

void sorteaza_lista(imobil *cap)
{
    printf("__SORTARE__\n");
    if (cap == NULL)
    {
        printf("lista este invalida\nincercati sa introduceti o lista inainte de a modifica ceva\n");
        return;
    }
    int optiune = afiseaza_submeniu_criterii();
    imobil *t = cap;
    imobil *p, *q = (imobil *)malloc(sizeof(imobil));
    int sortat; //bool
    printf("1. sortarea crescator\n2.sortarea descrescator\n");
    int s;
    scanf("%d", &s);
    do
    {
        sortat = 1;
        p = cap;
        int i = 0;

        while (p->next)
        {
            i++;
            if (s == 1)
            {
                if (optiune == 1 && strcmp(p->proprietar, p->next->proprietar) > 0 ||
                    optiune == 2 && strcmp(p->tip, p->next->tip) > 0 ||
                    optiune == 3 && strcmp(p->adresa, p->next->adresa) > 0 ||
                    optiune == 4 && p->suprafata > p->next->suprafata ||
                    optiune == 5 && p->costul > p->next->costul)
                {
                    char str[255];
                    strcpy(str, p->next->proprietar);
                    p->next->proprietar = (char *)realloc(p->next->proprietar, strlen(p->proprietar) + 1);
                    strcpy(p->next->proprietar, p->proprietar);
                    p->proprietar = (char *)realloc(p->proprietar, strlen(str) + 1);
                    strcpy(p->proprietar, str);

                    strcpy(str, p->next->tip);
                    p->next->tip = (char *)realloc(p->next->tip, strlen(p->tip) + 1);
                    strcpy(p->next->tip, p->tip);
                    p->tip = (char *)realloc(p->tip, strlen(str) + 1);
                    strcpy(p->tip, str);

                    strcpy(str, p->next->adresa);
                    p->next->adresa = (char *)realloc(p->next->adresa, strlen(p->adresa) + 1);
                    strcpy(p->next->adresa, p->adresa);
                    p->adresa = (char *)realloc(p->adresa, strlen(str) + 1);
                    strcpy(p->adresa, str);

                    float num;
                    num = p->suprafata;
                    p->suprafata = p->next->suprafata;
                    p->next->suprafata = num;

                    num = p->costul;
                    p->costul = p->next->costul;
                    p->next->costul = num;

                    sortat = 0;
                }
            }
            if (s == 2)
            {
                if (optiune == 1 && strcmp(p->proprietar, p->next->proprietar) < 0 ||
                    optiune == 2 && strcmp(p->tip, p->next->tip) < 0 ||
                    optiune == 3 && strcmp(p->adresa, p->next->adresa) < 0 ||
                    optiune == 4 && p->suprafata < p->next->suprafata ||
                    optiune == 5 && p->costul < p->next->costul)
                {
                    char str[255];
                    strcpy(str, p->next->proprietar);
                    p->next->proprietar = (char *)realloc(p->next->proprietar, strlen(p->proprietar) + 1);
                    strcpy(p->next->proprietar, p->proprietar);
                    p->proprietar = (char *)realloc(p->proprietar, strlen(str) + 1);
                    strcpy(p->proprietar, str);

                    strcpy(str, p->next->tip);
                    p->next->tip = (char *)realloc(p->next->tip, strlen(p->tip) + 1);
                    strcpy(p->next->tip, p->tip);
                    p->tip = (char *)realloc(p->tip, strlen(str) + 1);
                    strcpy(p->tip, str);

                    strcpy(str, p->next->adresa);
                    p->next->adresa = (char *)realloc(p->next->adresa, strlen(p->adresa) + 1);
                    strcpy(p->next->adresa, p->adresa);
                    p->adresa = (char *)realloc(p->adresa, strlen(str) + 1);
                    strcpy(p->adresa, str);

                    float num;
                    num = p->suprafata;
                    p->suprafata = p->next->suprafata;
                    p->next->suprafata = num;

                    num = p->costul;
                    p->costul = p->next->costul;
                    p->next->costul = num;

                    sortat = 0;
                }
            }

            p = p->next;
        }

    } while (sortat == 0);
}

void elibereaza_memoria_listei(imobil **cap)
{
    imobil *t = *cap, *q;
    while (t)
    {
        q = t->next;
        free(t->proprietar);
        free(t->tip);
        free(t->adresa);
        t->next = NULL;
        free(t);
        t = q;
    }
    *cap = NULL;
}