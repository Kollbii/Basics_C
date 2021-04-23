#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int lines = 0;

void heapsort(int *arr, int n);
void build_max_heap(int *arr, int n);
void heapify(int *arr, int n, int parent);
void print_and_heap(int *arr, int n);
void max_heap_insert(int *arr, int n, int key);
void heap_increase_key(int *arr, int i, int key);

void heapsort(int *arr, int n){
    build_max_heap(arr, n);
    int len = n;
    for (int i = len - 1; i > 0; i--){
        int tmp;
        tmp = arr[0];
        arr[0] = arr[i];
        arr[i] = tmp;
        n = n - 1;
        heapify(arr, n, 0);
    }
}

void build_max_heap(int *arr, int n){
    lines = 0;
    for (int i = (int)floor((n / 2)) - 1; i > -1; i--){
        heapify(arr, n, i);
    }
}

void heapify(int *arr, int n, int parent){
    int max = parent;
    int l = 2* parent;
    int r = 2* parent + 1;

    if (l < n && arr[l] > arr[parent]){
        max = l;
    }

    if (r < n && arr[r] > arr[max]){
        max = r;
    }

    if (max != parent){
        int tmp;
        tmp = arr[parent];
        arr[parent] = arr[max];
        arr[max] = tmp;
        // for (int i = n - 1; i >-1  ; i--){
        //     i - 1 == -1 ? printf("%d\n", arr[i]) : printf("%d ", arr[i]);
        // }
        printf("%d.\t", ++lines);
        for (int i = 0; i < n; i++){
            i + 1 == n ? printf("%d\n", arr[i]) : printf("%d ", arr[i]);
        }
        heapify(arr, n, max);
    }
}

int heap_extract_max(int *arr, int n){
    int max = arr[n-1];
    if (n < 1){
        return -1;
    }
    arr[n-1] = arr[0];
    heapify(arr, 0, n - 1);
    return max;
}

void print_and_heap(int *arr, int n){
    lines = 0;
    heapsort(arr, n);

    for (int i = n - 1; i >= 0 ; i--){
        i - 1 == -1 ? printf("%d\n", arr[i]) : printf("%d ", arr[i]);
    }

    for (int i = 0; i < n ; i++){
        i + 1 == n ? printf("%d\n", arr[i]) : printf("%d ", arr[i]);
    }
}

void max_heap_insert(int *arr, int n, int key){
    arr[n] = key;
    printf("Element added at the end of ARR\n");
    for (int l = 0; l <= n + 1; l++){
        l + 1 == n + 1 ? printf("%d\n", arr[l]) : printf("%d ", arr[l]);
    }
    heap_increase_key(arr, n, key);
}

void heap_increase_key(int *arr, int i, int key){
    if (key < arr[i]){
        printf("New key is smaller than current key");
    }
    arr[i] = key;
    while (i > 0 && arr[(i/2) - 1] < arr[i]){
        int tmp;
        tmp = arr[i];
        arr[i] = arr[i/2 - 1];
        arr[i/2 - 1] = tmp;
        i = i/2 - 1;
        for (int l = 0; l < i + 1; l++){
            l + 1 == i + 1 ? printf("%d\n", arr[l]) : printf("%d ", arr[l]);
        }
    }
}

int main(void){
    //Driver code
    system("cls");
    int arr0[9] = {5, 13, 2, 25, 7, 17, 20, 8, 4};
    int arr1[12] = {1,3,1,2,7,9,1,6,1,0,4,2};
    int arr2[21] = {15,3,99,1,25,7,9,9,1,100,6,1,0,12,4,2,9,0,87,122,54};
    int arr3[14] = {0,12,4,2,9,0,87,122,54,1,2,11,55,99};
    int arr4[12] = {15, 13, 9, 5, 12,8,7,4,0,6,2,1};

   
    print_and_heap(arr0, 9);
    printf("\n\n");
    print_and_heap(arr1, 12);
    printf("\n\n");
    print_and_heap(arr2, 21);
    printf("\n\n");
    print_and_heap(arr3, 14);
    printf("\n\n");
    print_and_heap(arr4, 12);
}