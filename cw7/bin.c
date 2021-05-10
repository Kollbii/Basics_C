#include <stdio.h>
#include <stdlib.h>

void printArr(int arr[], int n);
int addOne(int arr[], int n);
int check(int n);

void printArr(int arr[], int n){
    for (int i = 0; i < n; i++){
        i + 1 == n ? printf("%d\n", arr[i]) : printf("%d ", arr[i]);
    }
}

int check(int n){
    /* Fibo sequence */
    int x = 1,y = 1,z = 1;
    for (int i = 0 ; i < n; i++){
        z = x + y;
        x = y;
        y = z;
    }
    return z;
}

int addOne(int arr[], int n){
    int k = n - 1;

    while (arr[k] == 1){
        arr[k] = 0;
        k--;
    }
    arr[k] = 1;

    /* Also check if it is correct to print here */

    for (int i = 0; i < n; i++){
        if (arr[i] == 1 && arr[i+1] == 1){
            return 1;
        }
    }
    return 0;
}

int main(void){
    int n, k;

    printf(">");
    scanf("%d %d", &n, &k);

    int *arr = (int*)malloc(sizeof(int)*(unsigned)n);
    for (int i = 0; i < n; i++){
        arr[i] = 0;
    }

    /* Check if it is possible to make k elements. */
    if (check(n) < k){
        printf("-1");
        return -1;
    }
    
    /* Print initial array with 0's */
    printArr(arr, n);

    int flag = 0;
    while ((k-- - 1)){
        flag = addOne(arr, n);
        if(flag == 1){
            k++;
        }

        if (flag == 0){
            printArr(arr, n);
        }
    }
}