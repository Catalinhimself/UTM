#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *f;

    f = fopen("one.txt", "r");
    int n1 = 0;
    fscanf(f, "%d", &n1);
    int arr1[n1];
    for (int i = 0; i < n1; i++)
        fscanf(f, "%d", &arr1[i]);
    fclose(f);

    f = fopen("two.txt", "r");
    int n2 = 0;
    fscanf(f, "%d", &n2);
    int arr2[n2];
    for (int i = 0; i < n2; i++)
        fscanf(f, "%d", &arr2[i]);
    fclose(f);
    int max = 0;
    for (int i = 0; i < n1; i++)
    {
        printf("%d ", arr1[i]);
        if (arr1[i] > max)
            max = arr1[i];
    }
    printf("\n");
    for (int i = 0; i < n2; i++)
    {
        printf("%d ", arr2[i]);
        if (arr2[i] > max)
            max = arr2[i];
    }

    printf("\n");
    printf("max %d\n", max);
    int *magic = NULL;
    magic = (int *)calloc(max + 1, sizeof(int));
    for (int i = 0; i < n1; i++)

        magic[arr1[i]] = arr1[i];

    for (int i = 0; i < n2; i++)
        magic[arr2[i]] = arr2[i];

    int count = 0;
    for (int i = 1; i <= max; i++)
        if (magic[i] == i)
        {
            printf("%d\n", magic[i]);
            count++;
        }
    printf("count %d\n", count);

    f = fopen("thre.txt", "w");
    fprintf(f, "%d\n", count);
    for (int i = 1; i <= max; i++)
        if (magic[i] == i)
        {
            fprintf(f, "%d\n", magic[i]);
        }
    fclose(f);
    return 0;
}
