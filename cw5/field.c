#include <stdio.h>
#include <stdlib.h>

void calculateMaxField(int **arr, int i, int j, int n);
int checkRightCap(int **arr, int i, int j, int n);

int checkRightCap(int **arr, int i, int j, int n){
    for (int k = 0; k < n; k++){
        if (arr[i][j + k] == 1 || (j + k) == n){
            return (j + k);
        }
    }
}

void calculateMaxField(int **arr, int i, int j, int n){
    int right_cap = n;
    int max = 0;
/*
Iterate down and find first 1.
Find lowest right_cap.
Multiply.
*/
    int dy = 0, dx = n;
    for (int k = 0; k < n; k++){
        if ((i+k) < n){
            if (arr[i+k][j] != 1){
                dy++;
                right_cap = checkRightCap(arr, i+k, j, n);
                if (right_cap - j <= dx){
                    dx = right_cap - j;
                }
            } else {
                dy = 0;
                break;
            }           
        }

        if(dx*dy > max){
            max = dx*dy;
        }
    }
    arr[i][j] = max;
}

int main(void){
    int n, max = 1;

    printf("Insert n and array\n>");
    scanf("%d",&n);

    int **arr = (int**)malloc(sizeof(int*)*(unsigned)n);
    for (int i = 0; i < n; i++){
        arr[i] = (int*)malloc(sizeof(int)*(unsigned)n);
        for(int j = 0; j < n; j++){
            scanf("%d", &arr[i][j]);
        }
    }

    printf("\n");
/*
Print matrix with max field of submatrix at given index
Take max element from it.
*/
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (arr[i][j] != 1){
                calculateMaxField(arr, i, j, n);
            }
            if(arr[i][j] > max){
                max = arr[i][j];
            }
        }
    }

    printf("%d", max);
}