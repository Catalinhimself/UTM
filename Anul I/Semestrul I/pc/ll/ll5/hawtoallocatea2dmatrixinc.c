#include <stdio.h>
#include <stdlib.h>

int functie(int a[],int x){
    printf("\n");
    for (int i = 0; i < x; i++)
    {
        printf("%d ", a[i]++);
    }
}
int main() {
 //   int a[] = {1, 2, 3, 4,7,9};
//functie(a,6);
//functie(a,6);

// de la profesor
 int n = 2, m = 2;
 int **M = (int **)malloc(n * sizeof(int *));
 for (int i = 0; i < n; i++)
 {
     M[i] = (int *)malloc(m * sizeof(int));
}
for (int i = 0; i < n; i++)
for (int j = 0; i < m; j++)
{
    M[i][j] = i + j;
}
 


 int r = 3, c = 4; 
    int *arr = (int *)malloc(r * c * sizeof(int)); 
  
    int i, j, count = 0; 
    for (i = 0; i <  r; i++) 
      for (j = 0; j < c; j++) 
         *(arr + i*c + j) = ++count; 
  
    for (i = 0; i <  r; i++) {
        printf("\n");
      for (j = 0; j < c; j++) 
         printf("%d ", *(arr + i*c + j)); 
    }
    printf("\n%p", arr);
    for (i = 0; i <  r; i++) {
        printf("\n");
      for (j = 0; j < c; j++) 
         printf("%p ", (arr + i*c + j)); 
    }
    free(arr);
    return 0;
}