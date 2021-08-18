//Varianta 18. Să se determine prima și ultima literă din fiecare cuvânt.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const inutil = "`~!@#$%^&*( )_+=-,.<>/?'\"|\\;:1234567890[]{}";
int main()
{
  char s[255];
  printf("dati un sir\n");
  gets(&s);
  char *ptr = strtok(s, inutil);
  int i = 0;
  while (ptr != NULL)
  {
    printf("cuvantul nr.%d : %s\n", ++i, ptr);
    printf("prima litera din cuvant - '%c' ultima litera din cuvant - '%c'\n", ptr[0], ptr[strlen(ptr) - 1]);
    ptr = strtok(NULL, inutil);
  }
  getch();
  return 0;
}
