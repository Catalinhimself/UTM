#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

typedef struct Imobil
{
    char *proprietar;
    char *tip;
    char *adresa;
    float suprafata;
    float costul;
} IB;
IB *imobile;
int n;
const char name[][30] = {"Catalin", "Dlinii", "Rita", "Alex", "Ion B", "R Leta", "R Sam", "Cristian", "danieL", "ioneltuc", "Maria", "Marius_01k"};
const char type[][30] = {"casa", "hotel", "spalatorie auto", "castel", "palat", "gradina zoo", "restaurant", "apartament", "pestera"};
const char addres[][30] = {"livezilor 12", "eminescu 23", "bul. moscovei 11", "studentilor 7/1", "strada 1", "strada 2", "starda 3", "botanica 23"};
void Menu(int *m)
{
    printf("\n1. Alocarea dinamica a memoriei pentru tabloul de structuri.");
    printf("\n2. Introducerea elementelor tabloului de la tastatura. Sau 999 pentru Demo");
    printf("\n3. Afisarea elementelor tabloului la ecran.");
    printf("\n4. Adaugarea unui element nou la sfarsit.");
    printf("\n5. Modificarea elementului tabloului.");
    printf("\n6. Cautarea elementului tabloului.");
    printf("\n7. Sortarea tabloului.");
    printf("\n8. Eliminarea elementului indicat din tablou.");
    printf("\n9. Eliberarea memoriei alocate pentru tablou");
    printf("\n0. Iesire din program.");
    printf("\nOptiunea - ");
    fflush(stdin);
    scanf("%d", m);
}

IB *Creation()
{
    printf("Dati numarul de imobile : ");
    scanf("%d", &n);
    if (n < 0)
    {
        while (n < 0)
        {
            printf("nu putem avea un numar negativ de imobile\ndati n : ");
            scanf("%d", &n);
        }
    }

    IB *imobile;
    imobile = (IB *)malloc(n * sizeof(IB));
    return imobile;
}

void Demo()
{
    srand(time(NULL));
    char str[255];
    for (int i = 0; i < n; i++)
    {
        strcpy(str, name[rand() % 12]);
        imobile[i].proprietar = (char *)malloc((strlen(str) + 1) * sizeof(char));
        strcpy(imobile[i].proprietar, str);
        strcpy(str, type[rand() % 9]);
        imobile[i].tip = (char *)malloc((strlen(str) + 1) * sizeof(char));
        strcpy(imobile[i].tip, str);
        strcpy(str, addres[rand() % 8]);
        imobile[i].adresa = (char *)malloc((strlen(str) + 1) * sizeof(char));
        strcpy(imobile[i].adresa, str);
        imobile[i].suprafata = ((float)(rand() % 300) + (float)11 / ((rand() % 9) + 1)) + 16;
        imobile[i].costul = imobile[i].suprafata * (rand() % 21) / ((rand() % 16) + 1) * 1000 + imobile[i].suprafata * (rand() % 500);
    }
    int totalMem = sizeof(IB) * n;
    for (int i = 0; i < n; i++)
    {
        totalMem += strlen(imobile[i].proprietar);
        totalMem += strlen(imobile[i].tip);
        totalMem += strlen(imobile[i].adresa);
    }

    printf("\nmemoria utilizata de matrice %d B\n", totalMem);
}
void ScanStruct(int i)
{
    char str[255];
    printf("Imobilul %d\n", i + 1);
    printf("proprietar: ");
    fflush(stdin);
    gets(str);
    imobile[i].proprietar = (char *)malloc((strlen(str) + 1) * sizeof(char));
    strcpy(imobile[i].proprietar, str);
    printf("tip: ");
    fflush(stdin);
    gets(str);
    imobile[i].tip = (char *)malloc((strlen(str) + 1) * sizeof(char));
    strcpy(imobile[i].tip, str);
    printf("adresa: ");
    fflush(stdin);
    gets(str);
    imobile[i].adresa = (char *)malloc((strlen(str) + 1) * sizeof(char));
    strcpy(imobile[i].adresa, str);
    printf("suprafata : ");
    scanf("%f", &imobile[i].suprafata);
    printf("costul : ");
    scanf("%f", &imobile[i].costul);
}
void scanMatrix()
{
    printf("\nCitirea imobilelor\n");
    for (int i = 0; i < n; i++)
    {
        ScanStruct(i);
    }
}
void printMatrix()
{
    if (n)
    {
        printf("| Nr.|\t\tProprietar\t| \t\ttip\t | \tadresa\t | \tsuprafata | costul |\n");
        for (int i = 0; i < n; i++)
        {
            printf("|%3d |%25s |%25s |%25s |%12.2f m^2 |%12.2f $ |\n", i + 1, imobile[i].proprietar, imobile[i].tip, imobile[i].adresa, imobile[i].suprafata, imobile[i].costul);
        }
    }
    else
    {
        printf("Matricea este goala\n");
    }
}
void Order()
{
    int option;
    printf("1. sortare dupa pret descrescator\n2. sortare dupa pret crescator\n3.sortare dupa suprafata descrescatoare\norice alt numar. sortare dupa suprafata crescatoare");
    scanf("%d", &option);
    IB temp;
    int sortat;
    switch (option)
    {
    case 1:
        do
        {
            sortat = 1;
            for (int i = 0; i < n - 1; i++)
                if (imobile[i].costul < imobile[i + 1].costul)
                {
                    sortat = 0;
                    temp = imobile[i];
                    imobile[i] = imobile[i + 1];
                    imobile[i + 1] = temp;
                }
        } while (sortat == 0);
        break;
    case 2:
        do
        {
            sortat = 1;
            for (int i = 0; i < n - 1; i++)
                if (imobile[i].costul > imobile[i + 1].costul)
                {
                    sortat = 0;
                    temp = imobile[i];
                    imobile[i] = imobile[i + 1];
                    imobile[i + 1] = temp;
                }
        } while (sortat == 0);
        break;
    case 3:
        do
        {
            sortat = 1;
            for (int i = 0; i < n - 1; i++)
                if (imobile[i].suprafata < imobile[i + 1].suprafata)
                {
                    sortat = 0;
                    temp = imobile[i];
                    imobile[i] = imobile[i + 1];
                    imobile[i + 1] = temp;
                }
        } while (sortat == 0);
        break;

    default:
        do
        {
            sortat = 1;
            for (int i = 0; i < n - 1; i++)
                if (imobile[i].suprafata > imobile[i + 1].suprafata)
                {
                    sortat = 0;
                    temp = imobile[i];
                    imobile[i] = imobile[i + 1];
                    imobile[i + 1] = temp;
                }
        } while (sortat == 0);
        break;
    }
    printf("Tabloul a fot sortat cu succes!\n");
}
void Insert()
{
    IB *tempImobile = realloc(imobile, ++n * sizeof(IB));
    if (tempImobile)
    {
        imobile = tempImobile;
    }
    else
    {
        printf("nu e posibil de inserat un element nou");
    }
    int i = n - 1;
    printf("Noul imobil\n");
    ScanStruct(i);
}
void Edit()
{

    int i;
    do
    {
        printf("dati numarul elementului pe care doriti sa il editati : ");
        scanf("%d", &i);
        if (i > n)
        {
            printf("numarul nu trebui sa depaseasca %d\n", n);
        }
    } while (i > n);
    i--;
    char str[255];
    printf("Editarea imobilului\n");
    printf("vechiul proprietar - %s\nnoul proprietar: ", imobile[i].proprietar);
    fflush(stdin);
    gets(str);
    imobile[i].proprietar = (char *)malloc((strlen(str) + 1) * sizeof(char));
    strcpy(imobile[i].proprietar, str);
    printf("vechiul tip - %s\nnoul tip: ", imobile[i].tip);
    fflush(stdin);
    gets(str);
    imobile[i].tip = (char *)malloc((strlen(str) + 1) * sizeof(char));
    strcpy(imobile[i].tip, str);
    printf("vechia adresa - %s\nnoua adresa: ", imobile[i].adresa);
    fflush(stdin);
    gets(str);
    imobile[i].adresa = (char *)malloc((strlen(str) + 1) * sizeof(char));
    strcpy(imobile[i].adresa, str);
    printf("vechia suprafata - %f\nnoua suprafata: ", imobile[i].adresa);
    scanf("%f", &imobile[i].suprafata);
    printf("vechiul cost - %f\nnoul cost: ", imobile[i].costul);
    scanf("%f", &imobile[i].costul);
    printf("%d", n);
}
int Search()
{
    printf("Ce pret va intereseaza : ");
    float price;
    scanf("%f", &price);
    float delta[n];
    for (int i = 0; i < n; i++)
    {
        if ((int)price == (int)imobile[i].costul)
        {
            return i;
        }
        delta[i] = abs(imobile[i].costul - price);
    }
    int ret = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (delta[i] <= delta[ret])
        {
            ret = i;
        }
    }
    printf("cel mai apropiat pret de pretul cautat este al imobilului %d\n", ret + 1);
    printf("detinut de %s si la pretul de %f", imobile[ret].proprietar, imobile[ret].costul);
    return ret;
}
void Remove()
{
    int x;
    printf("nr elementului pe care doriti sa il eliminati");
    scanf("%d", &x);
    x--;
    for (int i = x; i < n - 1; i++)
        imobile[i] = imobile[i + 1];
    n--;
    imobile = (IB *)realloc(imobile, n * sizeof(IB));
    printf("eliminare efectuata cu succes");
}
void Free()
{
    for (int i = 0; i < n; i++)
    {
        free(imobile[i].proprietar);
        free(imobile[i].tip);
        free(imobile[i].adresa);
    }
    free(imobile);
    n = 0;
}

int main()
{
    int m;
    do
    {
        Menu(&m);
        switch (m)
        {
        case 1:
            imobile = Creation();
            break;
        case 999:
            Demo();
            break;
        case 2:
            scanMatrix();
            break;
        case 3:
            printMatrix();
            break;
        case 4:
            Insert();
            break;
        case 5:
            Edit();
            break;
        case 6:
            Search();
            break;
        case 7:
            Order();
            break;
        case 8:
            Remove();
            break;
        case 9:
            Free();
            break;
        default:

            break;
        }
    } while (m);
    Free();
    return 0;
}