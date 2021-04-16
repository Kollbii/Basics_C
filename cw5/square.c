#include <stdio.h>
#include <stdlib.h>

void printArr(int **arr, int n);
int sumOnBorder(int **arr, int n, int i, int j, int radius);

void printArr(int **arr, int n){
    for (int i= 0; i < n; i++){
        for (int j = 0; j < n; j++){
            j + 1 == n ? printf("%d\n", arr[i][j]) : printf("%d ", arr[i][j]);
        }
    }
}

int sumOnBorder(int **arr, int n, int i, int j, int radius){
    // printf("good pass of radius = %d at center arr[%d][%d]\n", radius, i, j);
    int sum_on_border = 0;
    int left_limit, right_limit, up_limit, down_limit;

    /*
    Set border
    */
    left_limit = j - radius;
    right_limit = j + radius;
    up_limit = i - radius;
    down_limit = i + radius;

    for (int i = left_limit; i < right_limit; i++){
        sum_on_border += arr[up_limit][i];
        // printf("\tadding arr[%d][%d] current sum = %d\n",up_limit,i,sum_on_border);
    }

    for (int i = up_limit; i < down_limit; i++){
        sum_on_border += arr[i][right_limit];
        // printf("\tadding arr[%d][%d] current sum = %d\n",i,right_limit,sum_on_border);
    }

    for (int i = right_limit; i > left_limit; i--){
        sum_on_border += arr[down_limit][i];
        // printf("\tadding arr[%d][%d] current sum = %d\n",down_limit,i,sum_on_border);
    }

    for (int i = down_limit; i > up_limit; i--){
        sum_on_border += arr[i][left_limit];
        // printf("\tadding arr[%d][%d] current sum = %d\n",i,left_limit,sum_on_border);
    }

    return sum_on_border;
}


int main(void){
    int n, sum_to_find, counter = 0;
    int answer[128][2] = {};

    printf("Insert n and sum\n>");
    scanf("%d %d",&n, &sum_to_find);

    int **arr = (int**)malloc(sizeof(int*)*(unsigned)n);
    for (int i = 0; i < n; i++){
        arr[i] = (int*)malloc(sizeof(int)*(unsigned)n);
        for(int j = 0; j < n; j++){
            scanf("%d", &arr[i][j]);
        }
    }

    printf("\n");

    for (int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            /*
            Calculate for each possible radius in [1; ⌊n/2⌋]
            */
            for(int k = 1; k < n/2 + 1; k++){
                int sum;
                /*
                Pass only 'centers' that are in radius to sumOnBorder()
                */
                if (((i - k) >= 0) && ((i + k) < n) && ((j - k) >= 0) && ((j + k) < n)){
                    sum = sumOnBorder(arr, n, i, j, k);
                    // printf("Sum for arr[%d][%d] = %d\n",i,j,sum);
                    if(sum == sum_to_find){
                        answer[counter][0] = i;
                        answer[counter][1] = j;
                        counter++;
                        // printf("%d %d\n", i, j);
                    }
                }
            }
        }
    }

    printf("%d\n", counter);
    for (int i = 0; i < counter; i++){
        printf("%d %d\n", answer[i][0], answer[i][1]);
    }
}