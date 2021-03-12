#include<stdio.h>    
#include<stdlib.h>  

int convertToBinary(int n);
int convertToBinary(int n){
    int binary[31], i;
    for (i = 0; n > 0; i++){
        binary[i] = n % 2;
        n /= 2;
    }
    for (i = i - 1; i >= 0; i--){
        printf("%d", binary[i]);
    }
}

int main(void){
    int n;
    system ("cls");
    printf("Enter the number to convert: ");
    scanf("%d\n", &n);
    convertToBinary(n);
    // printf("%d", 5&4);
    return 0;  
}  

