#include <stdio.h>
#include <stdlib.h>
#include "hdr/arc.c"
#include "hdr/graf.c"
#include "hdr/meniu.c"

int main()
{
    int x = 0, u = 0;
    arc *graf = NULL;
    int o = 999999;
    while (o)
    {
        meniu();
        scanf("%d", &o);
        switch (o)
        {
        case 1:
            graf = citireGraf(&x, &u);
            break;
        case 2:
            if (x && o)
                priteazaGraf(graf, x, u);
            break;

        default:
            break;
        }
    }

    return 0;
}