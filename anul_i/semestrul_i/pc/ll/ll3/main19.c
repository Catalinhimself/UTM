//ce am de facut :
//1 se citeste n marimea sirului V
// 2 se citeste sirul de numere (cred ca doar intregi) V
// 3 nr de elemente negative mai mic ca elementul maximal
// 4 produsul elementelor pozitive mai mari ca elemenul minimal

#include <stdio.h>

int main(void)
{
    printf("de la tastatura se va citi numarul n \n care reprezinta marimea sirului\nn= ");
    int n;
    scanf("%d", &n);
    int tablou2d[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &tablou2d[i]);
    }
    int min = tablou2d[0];
    int max = tablou2d[0];
    //select the lowest and hightest value
    for (int i = 0; i < n; i++)
    {
        if (min > tablou2d[i])
            min = tablou2d[i];
        if (max < tablou2d[i])
            max = tablou2d[i];
    }
    //count negative , produsul elementelor mai mari
    int nr_elem_negative_mici = 0;
    int prod_elem_poz_mari = 1;
    printf("\numarul de elemente negative mai mici ca maximul %d\n", max);
    for (int i = 0; i < n; i++)
    { // elemente negative mai mici ca max
        if ((max > tablou2d[i]) && (tablou2d[i] < 0))
        {
            printf("%d + ", tablou2d[i]);
            nr_elem_negative_mici += 1;
        }
    }
    printf("\nprodusul elementelor pozitive mai mari ca minimul %d\n", min);
    for (int i = 0; i < n; i++)
    {
        //elemente pozitive mai mari ca min
        if ((min < tablou2d[i]) && (tablou2d[i]) > 0)
        {
            printf("%d * ", tablou2d[i]);
            prod_elem_poz_mari *= tablou2d[i];
        }
    }
    printf("\nnr minim : %d, nr maxim : %d\n", min, max);
    printf("\nnr elementelor negative < %d : %d,\nprodusul elentelor pozitive mai mari ca %d : %d", min, nr_elem_negative_mici, max, prod_elem_poz_mari);
    return 0;
}