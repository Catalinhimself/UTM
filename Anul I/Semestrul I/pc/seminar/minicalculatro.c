#include <stdio.h>

int main()
{
    float a, b, rez;
    char oper;
    int erroare = 0;
    printf("Introduceti numar operatie numar prin spatiu : ");
    scanf("%f %c %f", &a, &oper, &b);
    switch (oper)
    {
    case '+':
        rez = a + b;
        break;
    case '-':
        rez = a - b;
        break;
    case '*':

    case '.':
        rez = a * b;
        break;
    case '/':
    case ':':

        if (b == 0)
            printf("eroare inpartirea la 0");
        else
            rez = a / b;
        break;

    default:
        printf("op necynoscuta");
        break;
    }
    printf("%f", rez);
    return 0;
}