#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRSIZE 255

void reverse(int arr[], int n);
void printarr(int arr[], int n);
int one_two(int[], int, int[], int, int[]);
void quick_sort(int arr[ARRSIZE], int floor, int roof);
int remove_duplicates(int arr[], int n);

void printarr(int arr[], int n){
    for(int i = 0; i < n; i++ ){
        i == n - 1 ? printf("%d\n", arr[i]) : printf("%d ", arr[i]);
    }
}

void reverse(int arr[], int n){
    for (int i = n  ; i > 0 ; i--){
        i - 1 == 0 ? printf("%d\n", arr[i - 1]) : printf("%d ", arr[i - 1]);
    }
}

int one_two(int t1[], int n1, int t2[], int n2, int out[ARRSIZE]){
    int i, counter = 0;
    for(i = 0; i <= n1 + n2 ; i++){
        if (i < n1){
            out[i] = t1[i];            
        }else{
            out[i] = t2[i - n1];
        }
    }

    for(i = 0; i < (n2 + n1); i++){
        // printf("%d ", out[i]);
        counter++;
    }
    return counter;
}

void quick_sort(int arr[ARRSIZE], int floor, int roof){
    int i, j, pivot, tmp;
    if(floor < roof){
        pivot = floor;
        i = floor;
        j = roof;

        while (i < j){
            while (arr[i] <= arr[pivot] && i < roof) i++;
            while (arr[j] > arr[pivot]) j--;
            if (i < j) {
                tmp = arr[j];
                arr[j] = arr[i];
                arr[i] = tmp;
            }
        }
    
        tmp = arr[pivot];
        arr[pivot] = arr[j];
        arr[j] = tmp;
        quick_sort(arr, floor, j - 1);
        quick_sort(arr, j + 1, roof);
    }
    // printarr(arr, roof);
}

int remove_duplicates(int arr[], int n){
    int j = 0, i;
    if (n < 2){
        return n;
    }
    for (i=0; i < n-1; i++){
        if (arr[i] != arr[i+1]){
            arr[j] = arr[i];
            j++;
        }
    }
    arr[j++] = arr[n-1];
    return j;
}

int main(void){
    int n1, n2, nout;
    int t1[ARRSIZE], t2[ARRSIZE], out[ARRSIZE];

    time_t tim;
    srand((unsigned long)time(&tim));

    // USER INPUT
    system("cls");
    printf("Insert size for t1[]: ");
    scanf("%d", &n1);
    printf("Insert size for t2[]: ");
    scanf("%d", &n2);

    printf("Generating random numbers for t1...\n");
    for (int i = 0; i < n1; i++){
        t1[i] = rand()%10; 
    }

    printf("Arr 1: \n");
    printarr(t1, n1);
    printf("Inverse of arr 1: \n");
    reverse(t1, n1);

    printf("Generating random numbers for t2...\n");
    for (int i = 0; i < n2; i++){
        t2[i] = rand()%10; 
    }

    printf("Arr 2: \n");
    printarr(t2, n2);
    printf("Inverse of arr 2: \n");
    reverse(t2, n2);

    printf("Sorted t1: \n");
    quick_sort(t1, 0, n1 - 1);
    printarr(t1, n1);

    printf("Sorted t2: \n");
    quick_sort(t2, 0, n2 - 1);
    printarr(t2, n2);
    
    nout = one_two(t1, n1, t2, n2, out);
    printf("\nMerged array of size %d\n", nout);
    printarr(out, nout);
    printf("\nSorted array of size %d\n", nout);
    quick_sort(out, 0, nout - 1);
    printarr(out, nout);
    printf("\nDeleted duplicates\n");
    nout = remove_duplicates(out, nout);
    printarr(out, nout);
    printf("Size of final array -> %d", nout);

    return 0;
}