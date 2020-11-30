#include <stdio.h>
#include <math.h>

int main()
{
    float a, b, c, x, F;
    int afis = 1;//true
    printf("Introduceti 4 numere reale: ");
    scanf("%f %f %f %f",&a, &b, &c, &x);
    if(c + b < 0 && a != 0)
        F = (a * a *x - c) / (b * b + cos(x));
    else if(c + b > 0 && a == 0)
        F = (a * x + sin(b * x)) / (b * b + c * x);
    else
        if(x <= 0){
            printf("Logaritm din numar mai mic sau egal cu zero nu exista!\n");
            afis = 0;//false
        }else
            F = (3 * log(x) + 2 * x) / (a * a + c - b * x);
    if(afis == 1)//daca afis == true
        printf("F= %f",F);

    return 0;
}
