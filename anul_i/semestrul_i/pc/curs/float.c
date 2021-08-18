#include <stdio.h>

int main(void){
     float price = 0;
     printf("whats the salary ?\n");
     scanf("%f",&price);
     printf("After tax : %.2f",price*0.881);
    return 0;
}