#include <stdio.h>

int main(void){
    char answer[20];
    printf("Your name - ");
    scanf("%s",answer);
    printf("Hello %s\n",answer);
        if (answer == "catalin")
            printf("congratulations\n");
    return 0;
}