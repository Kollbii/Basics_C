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
-3 -3 1 3
-4 2 2 4
-1 -5 -1 5
Wyjscie:
26
*/

int main(void){
    int rectangles;
    int x1,x2,y1,y2;
    int k = 0, blacks = 0;

    printf(">");
    scanf("%d", &rectangles);
    
    /*
        I translate the (0,0) to (n/2,n/2) [lines 57-61]
        in order to maintain >= 0 indexes in array.
    */

    int **arrOfPoints = (int**)malloc(sizeof(int*)*(unsigned)200);
	for (int i = 0; i < 200; i++) {
		arrOfPoints[i] = (int*)malloc(sizeof(int)*(unsigned)200);
        for (int j = 0; j < 200; j++){
            arrOfPoints[i][j] = 0; // initialize with white squares as 0
        }
    }

    for (int i = 0; i < rectangles; i++){
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        for (int x = x1; x <=  x2 ; x++){
            for (int y = y1; y <= y2; y++){
                if (x == 0 || y == 0){
                    continue;
                }

                if (arrOfPoints[x + 100][y + 100] == 0){
                    arrOfPoints[x + 100][y + 100] += 1; // if white square change to black again
                } else if (arrOfPoints[x + 100][y + 100] == 1){
                    arrOfPoints[x + 100][y + 100] -= 1; // if black square change to white again
                }
                k++;   
            }
        }
    }

    for (int i = 0; i < 200; i++) {
        for (int j = 0; j < 200; j++){
            if (arrOfPoints[i][j] == 1){
                blacks += 1;
            }
        }
    }

    printf("black squares: %d", blacks);
    return 0;
}