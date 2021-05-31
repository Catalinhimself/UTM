#include "./headers/header.h"

int main()
{
    imobil *cap = NULL;
    int nr = 0;
    printf("__main_program__\n");

    int meniu = 999;
    do
    {
        meniu = afiseaza_meniu();
        switch (meniu)
        {
        case 1:
        {
            elibereaza_memoria_listei(&cap);
            cap = creaza_lista();
        }
        break;
        case 2:
        {
            elibereaza_memoria_listei(&cap);
            printf("dati numarul de elemente in lista: ");
            int elemente;
            scanf("%d", &elemente);
            cap = creaza_lista_demo(elemente);
        }
        break;
        case 3:
        {
            nr = afiseaza_lista(cap);
        }
        break;
        case 4:
        {
            cauta_structura(cap);
        }
        break;
        case 5:
        {
            modifica_structura(cap);
        }
        break;
        case 6:
        {
            determina_ultimul_pointer(cap);
        }
        break;
        case 7:
        {
            nr = afiseaza_lista(cap);
            printf("numarul de elemente din lista de mai sus este: %d\n", nr);
        }
        break;
        case 8:
        {
            nr = afiseaza_lista(cap);
            cap = interschimba_2_elemente(cap, nr);
        }
        break;
        case 9:
        {
            sorteaza_lista(cap);
        }
        break;
        case 10:
        {
            elibereaza_memoria_listei(&cap);
        }
        break;
        case 11:
        {
            imobil *temp = cap;
            int B = 0;
            while (temp)
            {
                B += get_struct_info(temp);
                temp = temp->next;
            }
            int KB = B / 1024;
            B -= KB * 1024;
            int MB = KB / 1024;
            KB -= MB * 1024;
            printf("Memoria ocupata %d MB %d KB %d B\n", MB, KB, B);
        }
        break;
        case 0:
        {
            exit(0);
        }
        break;
        default:
            break;
        }
    } while (meniu);
    return 0;
}