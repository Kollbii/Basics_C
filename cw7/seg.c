#include <stdio.h>
#include <stdlib.h>

/*
Dla danych wejsciowych:
5 2
8 1 0 1 0
2 3 4 7 1
2 7 4 0 1
1 8 5 1 4
0 1 6 3 9
poprawna odpowiedzia jest:
17
*/
void printArr(int *arr[], int n);
int getValueOfIndex(int *arr[], int n, int i, int j, int k);

void printArr(int *arr[], int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            j + 1 == n ? printf("%d\n", arr[i][j]) : printf("%d ", arr[i][j]);
        }
    }
}

int getValueOfIndex(int *arr[], int n, int i, int j, int k){
    int sum_max = 0, sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0;

    /*  Check Horizontal*/
    
    for (int x = 0; x < k; x++){
        
        sum1 += arr[x][j];
    }
}

int main(void){
    int n, k;

    printf(">");
    scanf("%d %d", &n, &k);
    int **arr = (int **)malloc(sizeof(int*)*(unsigned)n);
    for (int i = 0; i < n; i++){
        arr[i] = (int*)malloc(sizeof(int)*(unsigned)n);
        for (int j = 0; j < n; j++){
            scanf("%d", &arr[i][j]);
        }
    }
    printf("\n");
    printArr(arr, n);

    int max = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            max = getValueOfIndex(arr, n, i, j, k);
        }
    }
}   