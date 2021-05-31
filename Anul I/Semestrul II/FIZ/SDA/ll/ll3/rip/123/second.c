#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void allinone(char *filename, int len)
{
    FILE *f1 = NULL;
    FILE *f2 = NULL;
    f1 = fopen(filename, "r");
    f2 = fopen("test_out.txt", "w");
    int bLen = 300;
    char *buffer = (char *)malloc(bLen);
    while (fgets(buffer, bLen, f1) != NULL)
    {
        int spaces = 0;
        for (int i = 0; i < strlen(buffer); i++)
        {
            if (buffer[i] == ' ')
                spaces++;
            if (buffer[i] == '\n')
                for (int j = i; j < strlen(buffer); j++)
                    buffer[j] = buffer[j + 1];
        }

        printf("%d len; :%s", strlen(buffer), buffer);
        if (strlen(buffer) > len)
        {
            printf("imposibil de adus linia \n%s\n prin insertie la lungime %d\n", buffer, len);
            fprintf(f2, "imposibil de adus linia \n%s\n prin insertie la lungime %d\n", buffer, len);
            return;
        }
        printf("\n%d spaces\n", spaces);
        int add = len - strlen(buffer);
        printf("%d\n", add);
        if (add > 0)
        {
            int mod = 0;
            int div = 0;
            printf("adaugare\n");
            div = add / spaces;
            mod = add % spaces;
            printf("%d div, %d mod\n", div, mod);
            printf("%d\n", (len - strlen(buffer)) / spaces);
            for (int i = 0; i < strlen(buffer); i++)
            {
                fprintf(f2, "%c", buffer[i]);
                if (buffer[i] == ' ')
                {
                    for (int j = 0; j < div; j++)
                    {
                        fprintf(f2, "%c", buffer[i]);
                    }
                    if (spaces == 1)
                    {
                        for (int j = 0; j < mod; j++)
                        {
                            fprintf(f2, "%c", buffer[i]);
                        }
                    }
                    spaces--;
                }
            }
        }
        else
            fputs(buffer, f2);
        fprintf(f2, "\n");
    }

    fclose(f1);
    fclose(f2);
}
void test()
{
    printf("test:\n");
    FILE *f = NULL;
    f = fopen("test_out.txt", "r");
    int bLen = 300;
    char *buffer = malloc(bLen);
    while (fgets(buffer, bLen, f))
    {
        for (int i = 0; i < strlen(buffer); i++)
        {
            if (buffer[i] == '\n')
            {
                for (int j = i; j < strlen(buffer); j++)
                    buffer[j] = buffer[j + 1];
            }
        }
        printf("%d len :%s\n", strlen(buffer), buffer);
    }
    fclose(f);
}
int main(int argc, char const *argv[])
{

    printf("fisierul - %s; lungimea dorita - %d\n", argv[1], atoi(argv[2]));
    allinone(argv[1], atoi(argv[2]));
    test();
    return 0;
}
