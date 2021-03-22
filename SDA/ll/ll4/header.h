
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

// functii care nu returneaza nimic
void get_struct_info(imobil *struct_ptr);
void afiseaza_lista(imobil *cap);
void cauta_structura(imobil *cap);

// meniuri
int afiseaza_meniu();
int afiseaza_meniu_cautare();
