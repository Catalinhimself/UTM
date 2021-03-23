
typedef struct _imobil
{
    // aranjate haotic ar ocupa mai multa memorie(
    // structure padding
    float suprafata;
    float costul;
    char *proprietar;
    char *tip;
    char *adresa;
    // adaugat pentru lista liniara
    struct _imobil *next;
} imobil;

// functii care returneaza pointeri la imobil
imobil *citeste_element(int ord);
imobil *creaza_lista();
imobil *creaza_lista_demo(int nr);
imobil *determina_ultimul_pointer(imobil *cap);
imobil *interschimba_2_elemente(imobil *cap, int limita);

// functii care nu returneaza nimic
void get_struct_info(imobil *struct_ptr);
void cauta_structura(imobil *cap);
void modifica_structura(imobil *cap);
void sorteaza_lista(imobil *cap);
void elibereaza_memoria_listei(imobil **cap);
// int return
int afiseaza_lista(imobil *cap);

// meniuri
int afiseaza_meniu();
int afiseaza_submeniu_criterii();
