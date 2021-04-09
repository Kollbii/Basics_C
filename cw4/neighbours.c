#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define ARRMAX 256 

void printArr2D(int **arr, int n){
    for (int i = 0; i < n ; i++){
        for (int j = 0; j < n; j++){
            j + 1 == n ? printf("%d  \n", arr[i][j]) : printf("%d  ", arr[i][j]);
        }
    }
}

int sumOfNeighbours(int **arr, int i, int j, int r, int n){
    int res;
    res = rand()%20;
    return res;
}

int main(void){
    unsigned int n;
    int r;
	printf("\n");
	printf("N r: ");
	scanf("%d %d", &n, &r);

    if (r >= n){
        printf("ERROR: r must be r < n ");
        return 1;
    }

    time_t t;
    srand((unsigned long)time(&t));

	int **arr = (int**)malloc(sizeof(int*)*n);
	int *len = (int*)malloc(sizeof(int)*n);

	for (int i = 0; i < n; i++) {
        //Error handling (?)
		arr[i] = (int*)malloc(sizeof(int)*n);
		if (arr[i] == NULL) {
			printf("Error\n");
			return 1;
		}
		for (int j = 0; j < n; j++){
			arr[i][j] = rand()%2;
        }
	}

    printf("Array with random placed {0, 1} of size %d\n\n", (int)n);
    printArr2D(arr, (int)n);

    int **sum_of_neighbours = (int**)malloc(sizeof(int*)*n);
	int *len_of_neighbours = (int*)malloc(sizeof(int)*n);
    int sum, start_i, start_j;
    for (int i = 0; i < n; i++){
        sum_of_neighbours[i] = (int*)malloc(sizeof(int)*n);
        for (int j = 0; j < n; j++){
            // for each element <arr[i][j]> calculate sum of all 1
            // find first index that is ok to iterate, then sum
            start_i = i - r;
            start_j = j - r;
            if ( (start_i > 0 && start_i < n) && (start_j > 0 && start_j < n)){
                sum += arr[start_i][start_j];
                // printf(" %d", sum);
            }
            
            // sum_of_neighbours[i][j] = sumOfNeighbours(arr, i, j, r, (int)n);
            sum_of_neighbours[i][j] = sum;
        }
    }

    printf("Calculated neighbours\n\n");
    printArr2D(sum_of_neighbours, (int)n);

    free(arr);
    free(len);

    free(sum_of_neighbours);
    free(len_of_neighbours);
}