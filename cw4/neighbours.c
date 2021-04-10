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
    int sum = 0;
    // printf("%d %d executed with\n", i, j);
    for (int k = (i - r); k < (r + i + 1); k++){
        for (int l = (j - r); l < (r + j + 1); l++){
            // printf("%d %d\t",k , l);
            if (k >= 0 && k < n && l >= 0 && l < n){
                // printf("added\n");
                if(arr[k][l] == 1){
                    sum += 1;
                }
                // printf("current sum %d\n", sum);
            }
        }
    }
    // return rand()%10; //test
    return sum;
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

    printf("\nArray with random placed {0, 1} of size %d\n\n", (int)n);
    printArr2D(arr, (int)n);

    printf("\n\nCalculated neighbours\n\n");

    int **sum_of_neighbours = (int**)malloc(sizeof(int*)*n);
	int *len_of_neighbours = (int*)malloc(sizeof(int)*n);

    for (int i = 0; i < n; i++){
        sum_of_neighbours[i] = (int*)malloc(sizeof(int)*n);
        for (int j = 0; j < n; j++){
            sum_of_neighbours[i][j] = sumOfNeighbours(arr, i, j, r, (int)n);
            printf("%d  ", sum_of_neighbours[i][j]);
        }
        printf("\n");
    }

    free(arr);
    free(len);

    free(sum_of_neighbours);
    free(len_of_neighbours);
}