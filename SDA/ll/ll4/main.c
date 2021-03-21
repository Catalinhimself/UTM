#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "header.h"

int main()
{

    for (int i = 0; i < 135; i++)
        printf("%d : %s\n", i, strerror(i));
    
    fprint();
    
    return 0;
}
