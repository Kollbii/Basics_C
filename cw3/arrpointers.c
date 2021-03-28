#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRSIZE 10

void printingArr(int arr[ARRSIZE], int index, int mode);

void printingArr(int arr[ARRSIZE], int index, int mode){
    if (mode == 0){
        printf("Printing array from index %d forward...\n", index);
        for(int i = index; i < ARRSIZE + index; i++){
            if (i >= 10){
                printf("%d ", arr[i - ARRSIZE]);
            }else{            
                printf("%d ",arr[i]);
            }
        }
    }else{
        printf("Printing array from index %d backward...\n", index);
        for (int i = index; i >= 0; i--){
            printf("%d ", arr[i]);
        }
        for(int i = ARRSIZE - 1; i > index; i--){
            printf("%d ", arr[i]);
        }
    }
}

int main(void){
    int arr[ARRSIZE], index, mode;

    time_t tim;
    srand((unsigned long)time(&tim));

    printf("Your array: ");
    for(int i = 0; i < ARRSIZE; i++){
        arr[i] = rand()%100;
        printf("%d ", arr[i]);
    }

    printf("\nInsert index to start [0;10) --> ");
    scanf("%d", &index);

    printf("Specify type of listing:\n0 - forward\n1 - backward\n>");
    scanf("%d", &mode);

    printingArr(arr, index,  mode);

    return 0;
}