typedef struct _imobil
{ //aranjate haotic ar ocupa mai multa memorie(
    //structure padding
    struct _imobil *next;
    float suprafata;
    float costul;
    char *proprietar;
    char *tip;
    char *adresa;

} imobil;

int afiseaza_meniu();
void get_struct_info(imobil *info);