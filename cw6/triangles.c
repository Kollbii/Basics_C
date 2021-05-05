#include <stdio.h>
#include <stdlib.h>

/*
Wejscie:
6 9
1 2
2 3
2 5
1 4
1 6
3 4
4 5
5 6
3 6
Wyjscie:
2
*/

int main(void){
    int points, lines, nonSameColors = 0;

    printf(">");
    scanf("%d %d", &points, &lines);

    int **arr = (int **)malloc(sizeof(int*)*(unsigned)(points + 1));
    for (int i = 0; i <= points; i++){
        arr[i] = (int *)malloc(sizeof(int)*2);
        for (int j = 0; j < 2; j++){
            arr[i][j] = 0;
        }
    }

    int x, y;
    for (int i = 0; i < lines; i++){
        scanf("%d %d", &x, &y);
        arr[x][0] += 1;
        arr[y][0] += 1;
    }

    for (int i = 0; i < points; i++){
        // printf("line %d: %d %d\n", i + 1, arr[i][0], arr[i][1])
        nonSameColors += arr[i + 1][0]*(points - arr[i + 1][0] - 1);
    }

    printf("same color triangles: %d\n", (points*(points-1)*(points - 2)/(3*2)) - nonSameColors/2);
    return 0;
}