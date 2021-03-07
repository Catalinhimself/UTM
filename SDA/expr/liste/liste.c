#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char *words[30] = {"bad", "easy", "lol", "Hurt", "gay", "code", "hate", "kill", "ice", "fire", "icecream", "hangman", "destroy", "computer", "book", "dictionary", "technology", "power", "thunder", "controller", "dexterity", "keyboard", "thunderous", "blizzard", "hazardous", "algorithm", "destruction", "operation", "assignment", "despicable"};

typedef struct nod
{
    int index;
    char text[30];
    int data;
    struct nod *next;
} liste;
liste *cap = NULL;

void afisare();
char meinu();
liste *creare();

void inserare()
{
    printf("inserarea la un id dorit sau la sfarsit, dati id-ul - \n");
    int id;
    scanf("%d", &id);
    liste *p = (liste *)malloc(sizeof(liste));
    p->index = id;
    printf("dati textul din element:\n");
    scanf("%s", p->text);
    printf("dati numarul din element\n");
    scanf("%d", &p->data);
    p->next = NULL;
    liste *temp = cap;
    while (temp->next)
    {
        if (id <= 1)
        {
            id = 1;
            p->next = temp;
            while (temp->next)
            {
                temp->index = ++id;
                temp = temp->next;
            }
            cap = p;
            break;
        }
        if (id == temp->next->index)
        {

            p->next = temp->next;
            temp->next = p;

            while (temp->next)
            {
                temp = temp->next;
                temp->index = id++;
            }

            break;
        }
        temp = temp->next;
        // if (!temp->next)
        // {
        //     // id = temp->index;
        //     p->index = id;
        //     temp->next = p;
        //     printf("brocken");
        //     break;
        // }
    }
}

int main()
{
    char o = 'x';

    cap = creare();
    afisare();
    inserare();
    afisare();
    // do
    // {
    //     o = meinu();

    //     switch (o)
    //     {
    //     case '1':
    //         cap = creare();
    //         break;
    //     case '2':
    //         afisare();
    //         break;
    //     default:
    //         break;
    //     }
    // } while (o != '0');

    return 0;
}
char meinu()
{
    printf("\n\n\n\nCrearea listei...............1\n");
    printf("Afisarea listei..............2\n");
    printf("Adaugarea unei persoane......3\n");
    printf("Cautarea unei persoane.......4\n");
    printf("Sortarea listei..............5\n");
    printf("Eliminearea unei persoane....6\n");
    printf("Stergerea listei.............7\n");
    printf("Iesire din program...........0\n");
    char i;
    printf("optiunea . . . ");
    scanf(" %c", &i);
    return i;
}
void afisare()
{
    liste *t = cap;
    // printf("index\tadresa\t\ttext\tdata\tnext\n");
    if (!cap)
    {
        printf("lista invalida :pain:\n");
        return;
    }
    printf("index\ttext\t\tdata\n");
    while (t->next)
    {
        // printf("%5d %8p %10s %3d %8p\n", t->index, t, t->text, t->data, t->next);
        printf("%-7d %-16s %-3d\n", t->index, t->text, t->data);
        t = t->next;
    }
}
liste *creare()
{

    srand(time(NULL));

    liste *h = (liste *)malloc(sizeof(liste));
    int i = 1;
    h->index = i++;
    strcpy(h->text, words[rand() % 30]);
    h->data = (rand() % 201) - 100;
    liste *temp = h;
    char c = 'd';
    int z = 0;
    while (c == 'd')
    {
        liste *p = (liste *)malloc(sizeof(liste));
        p->index = i++;
        strcpy(p->text, words[rand() % 30]);
        p->data = (rand() % 201) - 100;
        p->next = NULL;
        temp->next = p;
        temp = p;
        // printf("doriti sa introduceti elementul %d? [d/n] ... ", i - 1);
        // scanf(" %c", &c);
        if (++z == rand() % 50 || z == rand() % 50 || z == 50)
            c = 'n';
    }
    return h;
}
