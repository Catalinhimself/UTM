//Să se determine valorile ultimului element minimal negativ și a
// primului element maximal negativ, și pozițiile acestora în tablou
#include <stdio.h> //varianta 18
int main(void)
{
    printf("\n\n\t\t\t");
    printf("Lucrarea de laborator nr. 3 Varianta 18\n\n\n");
    printf("de la tastatura se va citi numarul n \ncare reprezinta numarul de elemente al tabloului\nn= ");
    int n;
    scanf("%d", &n);
    int tablou[n];
    int success = 0;
    for (int i = 0; i < n; i++)
    {
        printf("\nelementul %d = ", i + 1);
        scanf("%d", &tablou[i]);
    }
    //printeaza elementele tabloului cu pozitia lor in format mai usor de inteles pentru oameni n+1
    for (int i = 0; i < n; i++)
    {
        printf("%d[%d] ", tablou[i], i + 1);
    }
    int firstspossitionmax = 0;
    int lastpossitionmin = 0;
    for (int i = 0; i < n; i++)
    { // cautam cel putin un element negativ pentru functionarea corecta a programului
        if (tablou[i] < 0)
        {
            success = 1;
            break; //pentru eficienta
        }
    }
    if (success)
    {
        for (int i = 0; i < n; i++)
        {
            if (tablou[firstspossitionmax] > 0)
            {
                firstspossitionmax = i;
            }
        }
        for (int i = 0; i < n; i++)
        {
            //selecteaza pozitia primului element maxim
            if ((tablou[firstspossitionmax] < tablou[i] && (tablou[i] < 0)))
            {
                firstspossitionmax = i;
            }
            //selecteaza pozitia ultimului element minimal
            if ((tablou[lastpossitionmin] >= tablou[i] && (tablou[i] < 0)))
            {
                lastpossitionmin = i;
            }
        }
        printf("\nprimul element maximal negativ %d la pozitia %d\nultimul element minimal negativ %d la pozitia %d", tablou[firstspossitionmax], firstspossitionmax + 1, tablou[lastpossitionmin], lastpossitionmin + 1);
    }
    else
    {
        printf("\nconditii nesatisfacute\nnici un element negativ");
    }
    return 0;
}