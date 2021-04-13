#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void printArr2D(int **arr, int n){
    for (int i = 0; i < n ; i++){
        for (int j = 0; j < n; j++){
            j + 1 == n ? printf("%d  \n", arr[i][j]) : printf("%d  ", arr[i][j]);
        }
    }
}

int sumOfNeighbours(int **arr, int i, int j, int r, int n){
    int sum = 0;
    for (int k = (i - r); k < (r + i + 1); k++){
        for (int l = (j - r); l < (r + j + 1); l++){
            if (k >= 0 && k < n && l >= 0 && l < n){
                if(arr[k][l] == 1){
                    sum += 1;
                }
            }
        }
    }
    return sum;
}

int main(void){
    unsigned int n;
    int r, num, option;
	printf("\n");
	printf("N r: ");
	scanf("%d %d", &n, &r);

    if (r >= n){
        printf("ERROR: r must be r < n ");
        return 1;
    }

    time_t t;
    srand((unsigned long)time(&t));

    printf(" Press 1 for random matrix of {0, 1}\n Press 2 to input matrix\n>");
    scanf("%d", &option);

	int **arr = (int**)malloc(sizeof(int*)*n);

	for (int i = 0; i < n; i++) {
		arr[i] = (int*)malloc(sizeof(int)*n);
		if (arr[i] == NULL) {
			printf("Error\n");
			return 1;
		}
		for (int j = 0; j < n; j++){
            if (option == 1){
			    arr[i][j] = rand()%2;
            } else if (option == 2) {
                scanf("%d", &num);
                arr[i][j] = num;
            }
        }
	}

    printf("\nArray with random placed {0, 1} of size %d\n\n", (int)n);
    printArr2D(arr, (int)n);

    printf("\n\nCalculated neighbours\n\n");

    int **sum_of_neighbours = (int**)malloc(sizeof(int*)*n);

    for (int i = 0; i < n; i++){
        sum_of_neighbours[i] = (int*)malloc(sizeof(int)*n);
        for (int j = 0; j < n; j++){
            sum_of_neighbours[i][j] = sumOfNeighbours(arr, i, j, r, (int)n);
            printf("%d  ", sum_of_neighbours[i][j]);
        }
        printf("\n");
    }

    free(arr);
    free(sum_of_neighbours);
}