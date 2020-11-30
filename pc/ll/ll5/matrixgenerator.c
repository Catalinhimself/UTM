//varianta 18 labul 5
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int meniu(int *n,int *m);
int printm(int **tablou, int n, int m);
int scanm(int **tablou, int n, int m);
int killmatrix(int **tablou, int n);
int randm(int **tablou, int n, int m);

int main()
{
    int n, m;
    printf("\n\n\t\t\t");
    //functia mea care scrie conditiile programului si citeste dimensiunile matricii
    meniu(&n,&m);
    // alocarea dinamica a unui tablou de pointeri
    int **tablou = (int **)malloc(n * sizeof(int *));
    //tabloului de pointeri de mai sus i se aloca alt tablou
    for (int i=0; i<n; i++) 
         tablou[i] = (int *)malloc(m * sizeof(int)); 

    //citeste matricea
      if ( randm(tablou, n, m))
      {
          scanm(tablou, n, m);
      }
      

 

    //printeaza tabloul / matricea
    printf("matricea initiala");
     printm(tablou, n, m);
    //elibereaza memoria matricii
    killmatrix(tablou, n);
    return 0;
}
int meniu(int *n,int *m){
 printf("Lucrarea de laborator nr. 5 Varianta 18\n\n\n");
    printf("Acest program va citi o matrice si va calcula :\nsuma elementelor pozitive din liniile pare si\nprodusul elementelor mai mici ca 5 din coloanele impare\n");
    printf("nr de randuri = ");
    scanf("%d", n);
    printf("nr de coloane = ");
    scanf("%d", m);
}
int scanm(int **tablou, int n,int m) {

  for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            printf("elementul [%d %d] = ", i + 1, j + 1);
            scanf("%d", &tablou[i][j]);
        }
}
int printm(int **tablou, int n,int m) {

     for (int i = 0; i < n; i++)
     {
         printf("\n");
         for (int j = 0; j < m; j++)
         { 
         printf("%6d ", tablou[i][j]);
         }
    }
}
int killmatrix(int **tablou, int n) {
    for (int i=0; i<n; i++)
        free(tablou[i]);
    free(tablou);
}
int randm(int **tablou, int n, int m){
    srand(time(NULL));
   int b;
    printf("Daca doriti sa introduceti matricea tastati - 1 \ndaca doriti o matrice umpluta cu elemente aleatorii tastati - 0\noptiunea aleasa - ");
    scanf("%d", &b);
   for (int i = 0; i < n; i++)
    {
        printf("\n");
        for (int j = 0; j < m; j++){
            tablou[i][j] = rand() % 100 - 50;
        }
    }
    return b;
}
