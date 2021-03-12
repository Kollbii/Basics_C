#include <stdio.h>
#include <stdlib.h>

//Napisz program, który znajduje wszystkie liczby doskonałe w zadanym przedziale oraz ich liczbę.

int main(void){
    int a, b, counter, sum; // a,b - range

    system ("cls");
    printf("range [ ");
    scanf("%d", &a);
    printf("range [ %d , ", a);
    scanf("%d", &b);
    system ("cls"); 
    printf("range [ %d , %d ]\n", a, b);

    for (int i = a ; i <= b; i++){
        sum = 0;
        for (int j = 1 ; j < i; j++){
            if(i % j == 0){
                sum += j;
            }
        }
        if(sum == i){
            printf("%d PERFECT\n", i);
            counter += 1;
        }//else{
            // printf("%d NOT PERFECT\n", i); //Optional print
        // }
    }
    printf("Total perfect numbers: %d", counter);
    return 0;
}