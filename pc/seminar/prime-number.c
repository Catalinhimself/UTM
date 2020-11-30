#include <stdio.h>

int main()
{
    int a, b;
    int i = 3, count, c;

    printf("Dati inceputul sirului si sfarsitul : a , b : ");
    scanf("%d %d", &a, &b);
    if (a <= 2)
        printf("2 ");
    // iteration for n prime numbers
    // i is the number to be checked in each iteration starting from 3
    for (count = 2; count <= b; i++)
    {
        // iteration to check c is prime or not
        for (c = 2; c < i; c++)
        {
            if (i % c == 0)
                break;
        }

        if (c == i) // c is prime
        {
            if ((c >= a) && (c <= b))
            {
                /* code */ printf("%d ", i);
            }

            count++; // increment the count of prime numbers
        }
    }
    return 0;
}