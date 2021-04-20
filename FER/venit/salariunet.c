#include <stdio.h>
#include <stdbool.h>

/*=====================
     Variabile predefinite
     ======================*/
float FAM(float venit)
{
    return (float)9 / 100 * venit;
};
int SP = 2100;
int SiP = 375;
float IV(float VI)
{
    printf("IV = VI * 12%c \n", '%');
    float iv = (float)12 / 100 * VI;
    printf("IV = %.2f * 0.12= %.2f\n", VI, iv);
    return iv;
}
//=============== end

float get_VB(int o)
{
    int ore;
    float salariu_ora, VB;
    if (o == -1)
    {
        printf("salariul pe ora: ");
        scanf("%f", &salariu_ora);
        VB = 22 * 8 * salariu_ora;
        printf("VB = %.2f", VB);
        return VB;
    }
    if (o == -2)
    {
        printf("numarul de ore lucrate pe saptamana: ");
        scanf("%d", &ore);
        printf("salariul pe ora: ");
        scanf("%f", &salariu_ora);
        VB = 4 * ore * salariu_ora;
        printf("VB = %.2f", VB);
        return VB;
    }
    return o;
}

float get_VI(float VB, bool *SP_used, bool *SiP_used)
{
    float fam = FAM(VB);
    float VI = VB - fam;
    printf("VI = VB - FAM -SP - SiP\n");
    if (*SP_used)
        printf("SP - deja utilizata\n");
    if (*SiP_used)
        printf("SiP - utilizat sa nu beneficiaza\n");
    printf("VI = %.2f - %.2f", VB, fam);
    if (!*SP_used)
    {
        *SP_used = true;
        VI -= SP;
        printf(" - %d", SP);
    }

    if (!*SiP_used)
    {
        *SiP_used = true;
        VI -= SiP;
        printf(" - %d = %.2f", SiP, VI);
    }
    printf(" = %.2f\n", VI);
    return VI;
}
float get_VN(float VB, bool *SP_used, bool *SiP_used)
{
    float iv = IV(get_VI(VB, SP_used, SiP_used));
    float fam = FAM(VB);
    float vn = VB - iv - fam;
    printf("VN = VB - IV - FAM\n");
    printf("VN = %.2f - %.2f - %.2f = %.2f\n", VB, iv, fam, vn);

    return vn;
}
int main()
{
    printf("Legenda: \n");
    printf("VB - venit bru\n");
    printf("VI - venit impozitabil\n");
    printf("IV - impozit pe venit\n");
    printf("FMA - fondul de asigurare medicala\n");
    printf("SP - scutirea personala\n");
    printf("SiP - scutirea pentru persoana intretinuta\n");
    bool SP_used = false, SiP_used = true;
    float VB, VI, SN;
    printf("\npersoana beneficiaza de scutirea pentru persoana intretinuta? [ d / n ]   ");
    char c;
    c = getc(stdin);
    if (c == 'd')
        SiP_used = false;
    c = 'd';
    while (c == 'd')
    {
        printf("\nOptiuni de introducere a salariului brut:\n");
        printf("Lunar. - valoarea daca este cunoscuta\n");
        printf("-1. salariu ora pentru 22 zile 8 ore\n");
        printf("-2. ore lucrate pe saptamana si salariul pe ora\n");
        int optiunea;
        scanf("%d", &optiunea);

        get_VN(get_VB(optiunea), &SP_used, &SiP_used);
        printf("persoana mai beneficiaza si de alte surse de venit? [d / n]   ");
        scanf(" %c", &c);
    }

    return 0;
}
