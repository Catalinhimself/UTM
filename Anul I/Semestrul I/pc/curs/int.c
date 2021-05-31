#include <stdio.h>

int main(void){
    int age = 0;
    printf("Whats your age ?\n");
    scanf("%i",&age);
    printf("You are at least %i days old",age*365);
    return 0;
}