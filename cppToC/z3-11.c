#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

void drawTab(int arr[], int size){
    for (int i = 0; i < size; i++){
        if ( i == size - 1){
            printf("%d ", arr[i]);
        } else {
            printf("%d, ", arr[i]);
        }
    }
}

int main(){
    // Clear console at each start
    system("cls");

    // Initialize array at 0, then get user input
    int size = 0;
    int arr[size];
    printf("Array size: ");
    scanf("%d", &size);

    for (int i = 0; i < size ; i++){
        printf("Insert element %d: ", i+1);
        scanf("%d", &arr[i]);
    }
    
    drawTab(arr, size);
    
    int counter = 0;
    for (int i = 0; i < size; i++){
        bool duplicate = false;
        for (int j = 0; j < size; j++){
            if (i != j && arr[i] == arr[j]) duplicate = true;
        }
        if (duplicate == false){
            printf("\nUnique element %d", arr[i]);
            counter++;
        }
    }

    printf("\nTotal unique elements: %d", counter);
}