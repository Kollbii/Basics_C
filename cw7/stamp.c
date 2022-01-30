#include <stdio.h>
#include <stdlib.h>

/*
Dla danych wejsciowych:
5 2 2
5 1 0 1 0
2 3 4 7 1
2 7 4 0 1
1 8 5 1 9
0 1 6 3 0
0 1
1 0
poprawna odpowiedzia jest:
12

Dla danych wejsciowych:
5 1 3
5 1 0 1 0
2 3 4 7 1
2 7 4 0 1
1 8 5 1 9
0 1 6 3 0
1 1 1
poprawna odpowiedzia jest:
15

Dla danych wejsciowych:
5 3 3
5 1 0 1 0
2 3 4 7 1
2 7 4 0 1
1 8 5 1 9
0 1 6 3 0
1 1 1
0 1 0
1 1 1
poprawna odpowiedzia jest:
32
*/

void printArr(int *arr[], int n);
int checkSubArr(int x, int y, int n, int k, int l, int *T[], int *P[]);


void printArr(int *arr[], int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            j + 1 == n ? printf("%d\n", arr[i][j]) : printf("%d ", arr[i][j]);
        }
    }
}

int checkSubArr(int x, int y, int n, int k, int l, int *T[], int *P[]){
    int sum = 0;
    for (int i = 0; i < k; i++){
        for (int j = 0; j < l; j++){
            if (P[i][j] == 1)
                sum += T[x + i][y + j];
        }
    }
    return sum;
}

int main(void){
    int n, k, l;
    
    printf(">");
    scanf("%d %d %d",&n, &k, &l);

    int **T = (int **)malloc(sizeof(int*)*(unsigned)n);
    for (int i = 0; i < n; i++){
        T[i] = (int *)malloc(sizeof(int)*(unsigned)n);
        for (int j = 0; j < n; j++){
            scanf("%d", &T[i][j]);
        }
    }

    int **P = (int **)malloc(sizeof(int*)*(unsigned)k);
    for (int i = 0; i < k; i++){
        P[i] = (int *)malloc(sizeof(int)*(unsigned)k);
        for (int j = 0; j < l; j++){
            scanf("%d", &P[i][j]);
        }
    }

    printf("\n");
    printf("\n");
    
    /*  For each index check it's max sum*/
    int sum_max = 0, sum_current = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            sum_current = 0;

            if (i + k > n || j + l > n)
                continue;
            
            sum_current = checkSubArr(i, j, n, k, l, T, P);
            if (sum_current > sum_max)
                sum_max = sum_current;
        }
    }

    printf("Max stamp: %d", sum_max);
}