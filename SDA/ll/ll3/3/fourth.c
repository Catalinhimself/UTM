#include <stdio.h>
#include <stdlib.h>

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

    printf(" frequency count character in string:\n");
    f = fopen("out.txt", "w");
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
            printf(" '%c' = %d %.2f\n", s[i], count, (float)count / n);
            fprintf(f, "%c %d %.2f\n", s[i], count, (float)count / n);
        }
    }

    fclose(f);
    return 0;
}