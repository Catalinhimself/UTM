#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#include <errno.h>

#include "header.h"

int main()
{
    imobil *cap = NULL;

    printf("__main_program__\n");
    // afiseaza_meniu();
    // cap = creaza_lista();
    cap = creaza_lista_demo(30);
    afiseaza_lista(cap);

    cauta_structura(cap);

    // get_struct_info(cap);
    return 0;
}