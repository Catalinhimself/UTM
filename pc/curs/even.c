#include <stdio.h>

int main(void){
    int n ;
    printf("n : ");
    scanf("%i",&n);
    if(n%2==0){
        printf("%i even",n);
    }else{
        printf("%i odd",n);
    }
    return 0;
}