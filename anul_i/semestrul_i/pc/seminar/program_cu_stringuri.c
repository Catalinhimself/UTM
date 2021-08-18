#include <stdio.h>
#include <stdlib.h>
#include <conio.h>//daca nu intelege ce ii gets
#include <string.h> // pentru functii cu stringuri

int main()
{
    char s[255];
    printf("scrieti un sir de cuvinte\n");
    fflush(stdin);//ca tat sa fie rovna cand citesti cu gets
    gets(&s);

  char* tok; 
   tok = strtok(s, " "); 
  
    // Checks for delimeter 
    while (tok != 0) { 
        printf(" %s\n", tok); 
  
        // Use of strtok 
        // go through other tokens 
        tok = strtok(0, s); 
    } 

    return 0;
}
