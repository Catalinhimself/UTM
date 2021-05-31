#include <stdio.h>
#include <math.h>

int main()
{
    //declar variabilele necesare de tip float
    float a = 9, b = 0, c = 0, x = 0, F = 0;
    //informez utilizatorul despre conditiile programului
    printf("formule care vor fi aplicate numerelor introduse :\n");
    printf("1. pentru x < b sau c != 0\n");
    printf("(sin(x) + 1) / (b - x - c)\n");
    printf("2. pentru x > b si c = 0\n");
    printf("(a * x^2 - b * x * c) / sin(x)\n");
    printf("3. in celelalte cazuri\n");
    printf("(ln(x) + c) / (2 * b)\n");
    //cer datle de intrare
    printf("Introduceti 4 ( a, b, c, x ) numere reale: ");
    //datele de intrare sunt inregistrare in adresele variabilelor respective
    scanf("%f %f %f %f", &a, &b, &c, &x);
    int error = 0;
    if (x < b || c != 0)
    {
        printf("Fprmula aplicata : F = ( sin( %.2f ) + 1 ) / ( %.2f - %.2f - %.2f )) \n", x, b, x, c);
        float numarator = (b - x - c);
        if (numarator != 0)
        {
            F = (sin(x) + 1) / numarator;
        }
        else
        {
            printf("inpartirea la 0 nu are sens");
            error = 1;
        }
    }
    else if (x > b && c == 0)
    {
        printf("Fprmula aplicata : F = ( %.2f * %.2f ^2 - %.2f * %.2f * %.2f) / sin( %.2f )) \n", a, x, b, x, c, x);
        if (sin(x) != 0)
        {
            F = (a * pow(x, 2) - b * x * c) / sin(x);
        }
        else
        {
            printf("sin din 0 nu are sens ,\ninpartirea de asemenea");
            error = 1;
        }
    }
    else
    {
        printf("Fprmula aplicata : F = ( ln( %.2f ) + %.2f ) / ( 2 * %.2f )) \n", x, c, b);
        float numarator = (2 * b);
        if (numarator != 0)
        {
            if (x != 0)
            {
                F = (log(x) + c) / numarator;
            }
            else
            {
                printf("ln din 0 nu are sens");
                error = 1;
            }
        }
        else
        {
            printf("inpartirea la 0 nu are sens");
            error = 1;
        }
    };
    if (!error)
        printf("F= %f", F);

    return 0;
}