#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    FILE *f = NULL;
    f = fopen("in.txt", "r");
    char s[1000];
    fscanf(f, "%[^\n]", s);
    printf("%s\n", s);
    fclose(f);
    int i, j, k, count = 0, n;
    int T = 0;
    for (j = 0; s[j]; j++)
        ;
    n = j;

    for (i = 0; i < n; i++)
    {
        count = 1;
        if (s[i])
        {

            for (j = i + 1; j < n; j++)
            {

                if (s[i] == s[j])
                {
                    count++;
                    s[j] = '\0';
                }
            }
            T += count;
            for (int z = 0; z <= 9; z++)
            {
                char g[10];
                sprintf(g, "%d", z);
                if (g[0] == s[i])
                    printf("cifra %c apare de %d ori\n", s[i], count);
            }
        }
    }

    return 0;
}