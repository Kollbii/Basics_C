// recursive function to return first odd number in given number or -1 if it has no even number
#include <stdio.h>
#include <stdlib.h>

int func(int x){
    if ((x%10)%2 != 0){
        return x%10;
    } else {
        if (x/10 == 0 ){
            return -1;
        } else {
            return func(x/10);
        }
    }
}

int main(void) {
    int x;
    printf("Insert num: ");
    scanf("%d", &x);
    
    printf("%d ",func(x));
}