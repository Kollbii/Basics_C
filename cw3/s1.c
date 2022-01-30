#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define size 100

void sortowanie(int arr[size], int n); //n - wielkosc tablicy
void wypisanie_tablicy(int arr[size] , int n);

void sortowanie(int arr[size], int n){
    int zmiana;
    for (int i = 0 ; i < n; i++) {
        for (int j = 0 ; j < n; j++){
            if (arr[j] > arr[j+1]){
                zmiana = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = zmiana;
            }
        }
    }
    printf("Posortowana tablica:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

}
void wypisanie_tablicy(int arr[size] , int n){
    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(void) {
    int tablica1[size],  tablica2[size],  wynik[size];
    int wielkosc1, wielkosc2, wielkosc_wynik;

    srand((unsigned int)time(0));

    printf("Podaj wielkosc pierwszej tablicy: ");
    scanf("%d", &wielkosc1);
    for (int i=0; i<wielkosc1; i++){
        tablica1[i] = rand()%10;
    }
    printf("Twoja pierwsza tablica: ");
    wypisanie_tablicy(tablica1, wielkosc1);

    printf("Podaj wielkosc drugiej tablicy: ");
    scanf("%d", &wielkosc2);
    for (int i=0; i<wielkosc2; i++){
        tablica2[i] = rand()%10;
    }
    printf("Twoja druga tablica: ");
    wypisanie_tablicy(tablica2, wielkosc2);
    
    return 0;
}