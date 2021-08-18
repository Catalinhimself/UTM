//Varianta 18. Să se determine prima și ultima literă din fiecare cuvânt. 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char s[255];
    int index = 0,mind = 0, max = 0;
    printf("dati un sir\n");
    gets(&s);
    puts(s);
    printf("\n");
    //de utilizat strtok
  char *tok;
  printf ("Splitting string \"%s\" into tokens:\n",s);
  tok = strtok(s, " ,.-!?'/\\+\"=;");
  while (tok != NULL)
  {
    printf ("%s %d\n",tok,strlen(tok));
    index++;
    if (strlen(tok)>max){
        max = strlen(tok);
        mind = index;
    }
    tok = strtok (NULL, " ,.-!?'/\\+\"=;");
  }
  printf("cel mai lung cuvant are indexul %d si are %d litere", mind, max);s
  return 0;
}
