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

Dla danych wejsciowych:
5 1
8 1 0 1 0
2 3 4 7 1
2 7 4 0 1
1 8 5 1 4
0 1 6 3 9
poprawna odpowiedzia jest:
9

Dla danych wejsciowych:
6 3
8 1 0 1 0 9
2 3 4 7 1 1
2 7 4 0 1 2
1 8 5 1 4 3
0 1 6 3 9 4
5 5 5 5 5 9
poprawna odpowiedzia jest:
26
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
    int sum_max = 0, current_sum = 0;
    /*  Check all ways  */
    for (int x = 0; x < 8; x++){
        int index_i, index_j;
        switch(x){
            case 0:
                /*Top*/
                current_sum = 0;
                for (int y = 0; y < k; y++){
                    if(i - y < 0){
                        current_sum += arr[i + n - y][j];
                    }else{
                        current_sum += arr[i - y][j];
                    }
                }

                if (current_sum > sum_max){
                    sum_max = current_sum;
                }
                break;
            case 1:
                /*Upper right*/
                current_sum = 0;
                for (int y = 0; y < k; y++){
                    if(i - y < 0 ){
                        index_i = i + n - y;
                    }else {
                        index_i = i - y;
                    }
                    
                    if (j + y >= n){
                        index_j = j - n + y;
                    }else {
                        index_j = j + y;
                    }

                    current_sum += arr[index_i][index_j];
                }

                if (current_sum > sum_max){
                    sum_max = current_sum;
                }
                break;

            case 2:
                /*Right*/
                current_sum = 0;
                for (int y = 0; y < k; y++){
                    if(j + y >= n){
                        current_sum += arr[i][j - n + y];
                    }else{
                        current_sum += arr[i][j + y];
                    }
                }

                if (current_sum > sum_max){
                    sum_max = current_sum;
                }
                break;

            case 3:
                /*Down right*/
                current_sum = 0;
                for (int y = 0; y < k; y++){
                    if(i + y >= n ){
                        index_i = i - n + y;
                    }else {
                        index_i = i + y;
                    }
                    
                    if (j + y >= n){
                        index_j = j - n + y;
                    }else {
                        index_j = j + y;
                    }

                    current_sum += arr[index_i][index_j];
                }

                if (current_sum > sum_max){
                    sum_max = current_sum;
                }
                break;

            case 4:
                /*Down*/
                current_sum = 0;
                for (int y = 0; y < k; y++){
                    if(i + y >= n){
                        current_sum += arr[i + y - n][j];
                    }else{
                        current_sum += arr[i + y][j];
                    }
                }

                if (current_sum > sum_max){
                    sum_max = current_sum;
                }
                break;

            case 5:
                /*Down left*/
                current_sum = 0;
                for (int y = 0; y < k; y++){
                    if(i + y >= n ){
                        index_i = i - n + y;
                    }else {
                        index_i = i + y;
                    }
                    
                    if (j - y < 0){
                        index_j = j + n - y;
                    }else {
                        index_j = j - y;
                    }

                    current_sum += arr[index_i][index_j];
                }

                if (current_sum > sum_max){
                    sum_max = current_sum;
                }
                break;
                
            case 6:
                /*Left*/
                current_sum = 0;
                for (int y = 0; y < k; y++){
                    if(j - y < 0){
                        current_sum += arr[i][j + n - y];
                    }else{
                        current_sum += arr[i][j - y];
                    }
                }

                if (current_sum > sum_max){
                    sum_max = current_sum;
                }
                break;
            case 7:
                /*Upper Left*/
                current_sum = 0;
                for (int y = 0; y < k; y++){
                    if(i - y < 0 ){
                        index_i = i + n - y;
                    }else {
                        index_i = i - y;
                    }
                    
                    if (j - y < 0){
                        index_j = j + n - y;
                    }else {
                        index_j = j - y;
                    }

                    current_sum += arr[index_i][index_j];
                }

                if (current_sum > sum_max){
                    sum_max = current_sum;
                }
                break;
            default:
                break;
        }
    }
    return sum_max;
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

    int max = 0, max_current;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            max_current = getValueOfIndex(arr, n, i, j, k);
            if (max_current > max){
                max = max_current;
            }
        }
    }

    printf("Max length: %d", max);
}   