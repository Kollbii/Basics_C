#include <stdio.h>
#include <stdlib.h>


int main(void){
    unsigned int n, m;
    int look, counter_equal = 0, counter_less = 0;
    printf("n and m: ");
    scanf("%d %d", &n, &m);

    printf("number to search: ");
    scanf("%d", &look);

    int **arr = (int**)malloc(sizeof(int*)*n);

	for (int i = 0; i < n; i++) {
		arr[i] = (int*)malloc(sizeof(int)*m);
        //Error handling
		if (arr[i] == NULL) {
			printf("Error\n");
			return 1;
		}

		for (int j = 0; j < m; j++){
			arr[i][j] = rand()%10;
            printf("%d  ", arr[i][j]);

            if (arr[i][j] == look){
                counter_equal++;
            }
            if (arr[i][j] < look && arr[i][j] >= 0){
                counter_less++;
            }
        }
        printf("\n");
	}

    printf("Numbers equal to looking number: %d\n", counter_equal);
    printf("Numbers less than looking number: %d\n", counter_less);
}

