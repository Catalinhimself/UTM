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
int n = 0;

const char numeFisier[15] = "lab.txt";

const char name[][30] = {"Catalin", "Marius", "Daniel", "Mirela", "Alex", "Colea", "Sandu", "Ion", "Maximo", "Melissa", "Petru", "Stas", "Vlad", "Crstian", "Ion", "Mihail", "Victor", "Vladislav", "Maria", "Vitalie", "Nicoleta", "Sam"};
const char type[][30] = {"Apartament", "Birou", "Fabrica", "Magazin", "Mol", "Hotel", "Cladire Istorica", "Teren gol", "Restaurant"};
const char addres[][30] = {"Strada Albisoara", "Strada Alexandru Bernardazzi", "Strada Alexandru cel Bun", "Strada Alexei Mateevici", "Strada Armeneasca", "Strada Bucuresti", "Strada Calea Iesilor", "Strada Mihail Kogalniceanu"};

FILE *f;

void Menu(int *m);
IB *Creation();
void Demo();
void ScanStruct(int i);
void scanMatrix();
void printMatrix();
void Order();
void Insert();
void Edit();
int Search();
void Remove();
void Free();

void FR()
{
    f = fopen(numeFisier, "rb");
    if (!f)
    {
        printf("nu s-a putut deschide acest fisier\n");
    }
    else
    {
        n = getw(f);
        printf("%d", n);
        imobile = (IB *)malloc(n * sizeof(IB));
        for (int i = 0; i < n; i++)
        {
            int tempSize;
            tempSize = getw(f);
            imobile[i].proprietar = (char *)malloc(tempSize);
            fread(imobile[i].proprietar, tempSize, 1, f);
            tempSize = getw(f);
            imobile[i].tip = (char *)malloc(tempSize);
            fread(imobile[i].tip, tempSize, 1, f);
            tempSize = getw(f);
            imobile[i].adresa = (char *)malloc(tempSize);
            fread(imobile[i].adresa, tempSize, 1, f);
            fread(&imobile[i].suprafata, sizeof(float), 1, f);
            fread(&imobile[i].costul, sizeof(float), 1, f);
        }
        printMatrix();
        printf("citirea s-a efectuat cu succes\n");
    }
    fclose(f);
}
void FW()
{
    f = fopen(numeFisier, "wb");
    if (!f)
    {
        printf("nu s-a putut deschide acest fisier\n");
    }
    else
    {
        if (n)
        {
            putw(n, f);
            for (int i = 0; i < n; i++)
            {
                putw(strlen(imobile[i].proprietar) + 1, f);
                fwrite(imobile[i].proprietar, strlen(imobile[i].proprietar) + 1, 1, f);
                putw(strlen(imobile[i].tip) + 1, f);
                fwrite(imobile[i].tip, strlen(imobile[i].tip) + 1, 1, f);
                putw(strlen(imobile[i].adresa) + 1, f);
                fwrite(imobile[i].adresa, strlen(imobile[i].adresa) + 1, 1, f);
                fwrite(&imobile[i].suprafata, sizeof(float), 1, f);
                fwrite(&imobile[i].costul, sizeof(float), 1, f);
            }
            printf("scrierea s-a efectuat cu succes\n");
        }
        else
            printf("matricea este goala nu avem ce scrie in fisier\nmai gandestete..\n");
    }
    fclose(f);
}

void RM()
{
    remove(numeFisier);
    printf("fisierul a fost sters cu succes\n");
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
        case 22:
            FR();
            break;
        case 33:
            FW();
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
        case 666:
            RM();
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
void Menu(int *m)
{
    printf("\n22. Citirea din fisier.");
    printf("\n33. Scrierea in fisier.");
    printf("\n666. Sterge fisierul.\n");
    printf("\n1. Alocarea dinamica a memoriei pentru tabloul de structuri.");
    printf("\n2. Introducerea elementelor tabloului de la tastatura.\n999. pentru Demo ( umplerea matricii cu elemente aleatorii )");
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
        strcpy(str, name[rand() % 22]);
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
    if (totalMem >= 1024 * 1024)
        printf("\nmemoria utilizata de matrice %d MB\n", (int)totalMem / (1024 * 1024));
    else if (totalMem >= 1024)
        printf("\nmemoria utilizata de matrice %d KB\n", (int)totalMem / 1024);
    else
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