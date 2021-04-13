#include <stdio.h>
#include <stdlib.h>

int answer;

int funkcja(int x){
    int a, b;
    a = x%10;
    b = x/10;
    if (a%2 != 0){
        answer = a;
        // return a;
    } else {
        funkcja(b);
    }
    return -1;
}

int main(void) {
    int x;
    printf("Podaj liczbe: ");
    scanf("%d", &x);
    
    funkcja(x);
    printf("%d", answer);
}