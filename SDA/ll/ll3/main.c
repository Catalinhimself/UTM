#include <stdio.h>
#include <stdlib.h>

#include "hdr/fisiere.c"
#include "hdr/matrici.c"

// Scopul: Programarea algoritmilor de prelucrare a fișierelor text prin utilizarea funcțiilor, pointerilor, alocării dinamice a memoriei în limbajul C.
//1. Să se scrie programul care creează un fişier text în care se memorează două matrice,
// 2. astfel: pe prima linie numărul de linii şi numărul de coloane ale primei matrice, separate printr-un spaţiu; pe fiecare din liniile următoare, în ordine, elementele fiecărei linii din matrice, separate prin câte un spaţiu; în continuare a doua matrice, în aceeaşi formă.
//3. Să se scrie programul care înmulţeşte matricele din acest fişier.
//4.Rezultatul se va memora în alt fişier, în aceeaşi formă.
//5. Dacă înmulţirea nu e posibilă, se va scrie ca rezultat un mesaj de eroare.
//6. Matricele sunt suficient de mici pentru a putea fi încărcate în memorie (n, m =5).

int main()
{
    int n1, n2, m1, m2;
    int **M1 = NULL, **M2 = NULL;
    printf("Program la SDA, lab 3 varianta 18\n");
    printf("Citirea a 2 matrici dintr-un fisier si scrierea produsului lor in alt fisier\n");
    int optiune = 123;
    while (optiune)
    {
        printf("(1) Citirea matricilor de la tastatura\n");
        printf("(2) Importarea matricilor din fisier\n");
        printf("(0) pentru a iesi din program\n");
        scanf("%d", &optiune);
        switch (optiune)
        {
        case 1:
            printf("matricea 1\n");
            M1 = citireaMatrice(&n1, &m1);
            printf("matricea 2\n");
            printf("nr de randuri trebuie sa fie egal cu %d!!!\n", m1);
            M2 = citireaMatrice(&n2, &m2);
            sciereaInFisier(n1, n2, m1, m2, M1, M2);
            break;
        case 2:
            dimensiunileMatricilor(&n1, &m1, &n2, &m2);
            M1 = creareMatrice(n1, m1);
            M2 = creareMatrice(n2, m2);
            citireaMatricilor(M1, M2);
            break;
        default:
            break;
        }
        printf("matricea 1\n");
        printeazaMatrice(n1, m1, M1);
        printf("matricea 2\n");
        printeazaMatrice(n2, m2, M2);
        int **M = NULL;
        if (m1 == n2)
        {
            M = multiplicareaMatricilor(n1, n2, m2, M1, M2);
            printf("produsul matricilor\n");
            printeazaMatrice(n1, m2, M);
        }
        else
            printf("nu poate fi calculat produsul\n");

        scriereProdus(n1, n2, m1, m2, M);
    }

    return 0;
}