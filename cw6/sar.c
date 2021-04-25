#include <stdio.h>
#include <stdlib.h>

/*
1 2
2 3
1 6
3 4
5 6
3 6
*/

int main(void){
    int n, m, a, b;
    int licznik = 0;
    // "stopnie czerwoności" wierzchołków; na początku tablica wyzerowana


    printf("Podaj liczbe wierzcholkow: ");
    scanf("%d", &n);

    int *red = (int*)malloc(sizeof(int)*(unsigned)(n+1));

    printf("Podaj liczbe czerwonych krawedzi: ");
    scanf("%d", &m);

    for(int i = 0; i<n+1; i++){
        red[i]=0;
    }

    printf("Podaj miedzy czym maja byc czerwone krawedzie: \n");
    while(m--) {
        scanf("%d", &a);
        scanf("%d", &b);
        red[a] += 1;
        red[b] += 1;
    }

    for(int i = 1; i <= n; i++){ 
        licznik += red[i]*(n-1-red[i]);
    }

    printf("\nIlosc trojkatow jednobarwnych: ");
    printf("%d", (n*(n-1)*(n-2)/6)-licznik/2);
}