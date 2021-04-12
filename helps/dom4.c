#include <stdio.h>
#include <stdlib.h>

int func(int n, int size){
    int arrOfNums[size];

    for(int i = size - 1; i >= 0; i--){
        arrOfNums[i] = n %10;
        n = n / 10;
    }

    for (int i = 0 ; i < size; i++){
        printf("%d ", arrOfNums[i]);
    }
    return 1;
}

int main(void){
    int n, num;
    int numArr[128];
    int count = 0;


    printf("Enter int number: ");
    scanf("%d", &n);

    while (n < 0){
        printf("Must be > 0\nEnter number: ");
        scanf("%d", &n);
    }

    while (n != 0){
        n /= 10;
        count++;
    }
    printf("%d ", count);

    printf(func(n, count));

}