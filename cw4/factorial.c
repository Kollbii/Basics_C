#include <stdio.h>
#include <stdlib.h>

#define ARRMAX 256

int main(void){
    int arr[ARRMAX], n, len = 0, tmp;
    arr[0] = 1;

    printf("Factorial of: ");
    scanf(" %d", &n);

    for ( int i = n; i > 1 ; i--){
        tmp = 0;
        for (int j = 0; j <= len; j++){
            tmp = (arr[j]*i) + tmp;
            arr[j] = tmp%10;
            tmp /= 10;
        }

        while(tmp > 0){
            len+=1;
            arr[len] = tmp%10;
            tmp /=  10;
        }
    }

    for (int i = len; i >= 0 ;i--) {
        printf("%d", arr[i]);
    }
}