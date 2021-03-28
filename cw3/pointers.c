#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRSIZE 10

int main(void){
    int arrInt[ARRSIZE], *pointerInt;
    double arrDouble[ARRSIZE], *pointerDouble;
    
    time_t tim;
    srand((unsigned long)time(&tim));

    printf("ArrInt:\n");
    for (int i = 0; i < ARRSIZE; i++){
        arrInt[i] = rand()%20;
        pointerInt = &arrInt[i];
        i + 1 == ARRSIZE ? printf("%d \t-> %p\n\n", arrInt[i], pointerInt) : printf("%d \t-> %p\n", arrInt[i], pointerInt);
    }
    printf("ArrDouble:\n");
    for (int i = 0; i < ARRSIZE; i++){
        arrDouble[i] = (double)(rand()%20);
        pointerDouble = &arrDouble[i];
        i + 1 == ARRSIZE ? printf("%.1f \t-> %p\n\n", arrDouble[i], pointerDouble) : printf("%.1f \t-> %p\n", arrDouble[i], pointerDouble);
    }
    return 0;
}