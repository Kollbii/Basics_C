#include <stdio.h>
#include <stdlib.h>

void printArr2D(int *arr, int n);

void printArr2D(int *arr, int n){
    for (int i = 0; i < n ; i++){
        for (int j = 0; j < n; j++){
            j + 1 == n ? printf(" \t%d\n", *((arr + i*n) + j)) : printf(" \t%d", *((arr + i*n) + j));
        }
    }
}

int main(void){
    int N;

    printf("Insert size of arr: ");
    scanf(" %d", &N);

    int arr[N][N];
    int left = 0, top = 0, right = N - 1, down = N - 1;
    int num = 0;
    for (int i  = 0 ; i < N; i++) {
        for (int j = 0 ; j < N; j ++){
            if (left > right){
            break;
            }

            for (int k = top; k <= down; k++){
                arr[top][k] = ++num;
            }
            top++;

            if (top > down) {
                break;
            }

            for (int k = top; k <= down; k++) {
                arr[k][right] = ++num;
            }
            right--;
    
            if (left > right) {
                break;
            }
        
            for (int k = right; k >= left; k--) {
                arr[down][k] = ++num;
            }
            down--;
    
            if (top > down) {
                break;
            } 

            for (int k = down; k >= top; k--) {
                arr[k][left] = ++num;
            }
            left++;
        }
    }
    printArr2D((int *)arr, N);
}