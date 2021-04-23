#include <stdio.h>
#include <stdlib.h>

/*
Wejscie:
2
-1 -2 1 2
-2 -1 2 1
Wyjscie:
8

Wejscie:
2
-1 -2 -1 3
-2 -2 1 2
Wyjscie:
9

Wejscie:
3
-1 -2 1 2
-2 -1 2 1
-2 1 2 2
Wyjscie:
8
*/

int main(void){
    int rectangles;
    int x1,x2,y1,y2;

    printf(">");
    scanf("%d", &rectangles);
    

    int **arrOfPoints = (int**)malloc(sizeof(int*)*(unsigned)100); // 100 x 100 possible points with x and y cooridinates
	for (int i = 0; i < 100; i++) {
		arrOfPoints[i] = (int*)malloc(sizeof(int));
    }

    int j = 0;
    for (int i = 0; i < rectangles; i++){
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        for (int x = x1; x <=  x2 ; x++){
            for (int y = y1; y <= y2; y++){
                if (x == 0 || y == 0){
                    continue;
                }

                arrOfPoints[j][0] = x;
                arrOfPoints[j][1] = y;
                j++;   
            }
        }
    }

    for (int i = 0; i < j; i++){
            printf("arr[%d] = (%d, %d)\n", i, arrOfPoints[i][0], arrOfPoints[i][1]);
    }

    int duplicate;
    int blacks = 0;
    for (int i = 0; i < j; i++){
        duplicate = 0;
        for (int k = 0; k < j; k++){
            if (i != k && arrOfPoints[i][0] == arrOfPoints[k][0] && arrOfPoints[i][1] == arrOfPoints[k][1]){
                duplicate += 1; 
            }
        }
        if (duplicate%2 == 0){
            printf("arr[%d] = (%d, %d)\n", i, arrOfPoints[i][0], arrOfPoints[i][1]);
            blacks++;
        }
    }

    printf("black squares: %d", blacks);
}