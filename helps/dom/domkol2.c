#include <stdio.h>
#include <stdlib.h>

/*
o                       o  
   o                 o  o
      o           o  o  o
         o     o  o  o  o
o  o  o  o  o  o  o  o  o
o  o  o  o     o
o  o  o           o
o  o                 o
o                       o
*/

/*
    o - on diagonal 
    o - on reverse diagonal // i + j == n - 1
    o - where i + j >= n && i <= n/2 && j >= n/2 and  i + j <= n - 1 && i >= n/2  && j < n/2

*/
int main(void){
    int n;

    scanf("%d", &n);
    
    char **arr = (char **)malloc(sizeof(char*)*(unsigned)n);
    for (int i = 0; i < n; i++){
        arr[i] = (char *)malloc(sizeof(char)*(unsigned)n);
        for(int j = 0; j < n; j++){
            if (i == j || i + j == n - 1){
                arr[i][j] = 'o';
            } else {
                arr[i][j] = ' ';
            }

            if (i + j >= n && i <= n/2 && j >= n/2){
                arr[i][j] = 'o';
            }

            if (i + j <= n - 1 && i >= n/2  && j < n/2){
                arr[i][j] = 'o';
            }
        }
    }
    
    /*
        Print nicely :)
    */
    for (int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if (j + 1 == n){
                if (arr[i][j] == ' ') {
                    printf("   \n");
                } else if (arr[i][j] == 'o'){
                    printf("%c  \n", arr[i][j]);
                }
            }else {
                if (arr[i][j] == ' ') {
                    printf("   ");
                } else if (arr[i][j] == 'o'){
                    printf("%c  ", arr[i][j]);
                }
            }
        }
    }
    return 0;
}