#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN(a,b) (((a)<(b))?(a):(b))

void recursive_selection_sort(int a[], int n, int index);
int index_min(int a[], int i, int j);
void print_arr(int arr[], int n);


int index_min(int a[], int i, int j){
    if (i == j) return i;
  
    int k = index_min(a, i + 1, j);

    return (a[i] < a[k])? i : k;
}

void recursive_selection_sort(int a[], int n, int index){
    if (index == n)
       return;
  
    int k = index_min(a, index, n-1);
  
    if (k != index){
        int temp = a[k];
        a[k] = a[index];
        a[index] = temp;
    }
  
    recursive_selection_sort(a, n, index + 1);
}

void print_arr(int arr[], int n){
    for (int i = 0; i < n; i++){
        i + 1 == n ? printf("%d\n",arr[i]) : printf("%d ", arr[i]);
    }
}

int test_recursive_sort(int n){
    int *arr = (int*)malloc(sizeof(int)*(unsigned)n); // I know unsigned it not good but gcc compiler for win. is freaking off at this point
    for (int i = 0; i < n; i++){
        arr[i] = rand() % 20 + 1; //Operand modulo 20 gives ints in range (0, 19). Need to +1. 
    }
    print_arr(arr, n);
    recursive_selection_sort(arr, n, 0);
    print_arr(arr, n);
    return 0;
}

int main(void){
    int n;
    int arr[10] = {4,5,6,7,-2,-4,2,-6,5,11};

    time_t t;
    srand((unsigned long)time(&t));

    printf("Insert n in range [1;20]\n>");
    scanf("%d", &n);

    print_arr(arr, 10);
    recursive_selection_sort(arr, 10, 0);
    print_arr(arr, 10);

    test_recursive_sort(n);

    return 0;
}