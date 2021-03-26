#include <stdio.h>

int main(){
    int number;
    int list[40] = {0, 1};
    int i=1;

    printf("Podaj cyfre: \n");
    scanf("%d", &number);
    printf("%d \n", number);

    do{
        if(list[i-1]*list[i] == number){
            printf("Ta cyfra jest multiplikacja dwoch kolejnych wyrazow ciagu tego typa z wloch: %d i %d ", list[i-1], list[i]);
            return 0;
        }
        printf("%d \n", number);
        i+=1;
        list[i]=list[i-2]+list[i-1];
        printf("%d, %d, %d\n", list[i-1], list[i], number);
        printf("%d \n", number);
    }while(list[i-1]+list[i]<number); /* ale sztosik kodzik */

    printf("Sorka, nie ma takiej multiplikacji :(");
    return 0;
}