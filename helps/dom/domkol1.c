#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN(a,b) (((a)<(b))?(a):(b))

void recursive_selection_sort(int arr[], int n, int index);
int index_min(int arr[], int i, int j);
void print_arr(int arr[], int n);
int is_divisable_by_two_and_three(int **arr, int n);

int index_min(int arr[], int i, int j){
    if (i == j) return i;
  
    int k = index_min(arr, i + 1, j);

    return (arr[i] < arr[k])? i : k;
}

void recursive_selection_sort(int arr[], int n, int index){
    if (index == n)
       return;
  
    int k = index_min(arr, index, n-1);
  
    if (k != index){
        int temp = arr[k];
        arr[k] = arr[index];
        arr[index] = temp;
    }
  
    recursive_selection_sort(arr, n, index + 1);
}

void print_arr(int arr[], int n){
    for (int i = 0; i < n; i++){
        i + 1 == n ? printf("%d\n",arr[i]) : printf("%d ", arr[i]);
    }
}

int test_recursive_sort(int n){
    int *arr = (int *)malloc(sizeof(int)*(unsigned)n); // I know unsigned it not good but gcc compiler for win. is freaking off at this point
    for (int i = 0; i < n; i++){
        arr[i] = rand() % 20 + 1; //Operand modulo 20 gives ints in range (0, 19). Need to +1. 
    }
    print_arr(arr, n);
    recursive_selection_sort(arr, n, 0);
    print_arr(arr, n);
    return 0;
}

int is_divisable_by_two_and_three(int **arr, int n){
    int div_sum = 0;


    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (arr[i][j] % 2 == 0 || arr[i][j] % 3 == 0) div_sum++;
        }
    }

    // printf("sum of divisable by 2 and 3 -> %d\n", div_sum);
    return div_sum;
}

int test_divide(int n){
    int **T = (int **)malloc(sizeof(int*)*(unsigned)n);
    for (int i = 0; i < n; i++){
        T[i] = (int *)malloc(sizeof(int)*(unsigned)n);
        for (int j = 0; j < n; j++){
            if ( (i + j) % 2 != 0){
                T[i][j]
            }
            T[i][j] = rand() % 101; 
        }
    }

    return 0;
}

int main(void){
    int n,m;
    int arr[10] = {4,5,6,7,-2,-4,2,-6,5,11};

    time_t t;
    srand((unsigned long)time(&t));

    printf("Insert n in range [1;20]\n>");
    scanf("%d", &n);

    print_arr(arr, 10);
    recursive_selection_sort(arr, 10, 0);
    print_arr(arr, 10);

    test_recursive_sort(n);


    printf("Insert matrix size T[m][m]\n>");
    scanf("%d", &m);


    int **T = (int **)malloc(sizeof(int*)*(unsigned)m);
    for (int i = 0; i < m; i++){
        T[i] = (int *)malloc(sizeof(int)*(unsigned)m);
        for (int j = 0; j < m; j++){
            T[i][j] = rand() % 101; // it gives [0,100] range
        }
    }

    printf("Sum of divisable by 2 and 3 -> %d\n", is_divisable_by_two_and_three(T, m));
    return 0;
}