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
    int nr = 0;
    printf("__main_program__\n");
    // afiseaza_meniu();
    // cap = creaza_lista();
    cap = creaza_lista_demo(100);
    nr = afiseaza_lista(cap);
    printf("numarul de elemente ale liste: %d\n", nr);
    // cauta_structura(cap);
    // modifica_structura(cap);
    // determina_ultimul_pointer(cap);
    // cap = interschimba_2_elemente(cap, nr);
    // sorteaza_lista(cap);
    // afiseaza_lista(cap);
    elibereaza_memoria_listei(&cap);
    printf("%p", cap);
    afiseaza_lista(cap);
    // get_struct_info(determina_ultimul_pointer(cap));
    // get_struct_info(cap);
    return 0;
}