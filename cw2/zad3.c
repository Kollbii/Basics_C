#include <stdio.h>
#include <stdlib.h>

void printArr(int arr[], int len){
    for (int i = 0; i < len ; i++){
        i == len - 1 ? printf("%d\n\n", arr[i]) : printf("%d, ", arr[i]);
    }
}

int main(void){
    int a,b,n, next, fibo[40] = {};
    system("cls");
    
    //Gener fibo. seq. first 40 numbers
    a = 0;
    b = 1;
    for (int i = 1; i <= 40; i++){
        if(i <= 1){
            next = i;
        }else{
            next = a + b;
            a = b;
            b = next;
        }
        fibo[i-1] = a;
    }
    printArr(fibo, 40);

    //User input
    printf("Type number to check: ");
    scanf("%d", &n);

    //Check if multilication of 2 ints
    for (int i = 1; i < 40 ; i++){
        fibo[i-1] * fibo[i] == n ? printf("This number is multiplication of %d * %d = %d\n", fibo[i-1], fibo[i], n) : printf("");
    }
    return 0;
}