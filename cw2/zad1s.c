#include <stdio.h>
#include <math.h>


int main (void) {
    int a, b;
    printf("Podaj pierwsza liczbe: ");
    scanf ("%d", &a);
    printf("Podaj druga liczbe: ");
    scanf ("%d", &b);

    int liczba, suma, licznik = 0;

    printf ("Liczby doskonale w przedziale od %d do %d:\n", a, b);
    for (liczba = a; liczba <= b; liczba++) {
        suma = 0;
        for(int i = 1; i < liczba; i++) {
            if (liczba % i == 0) {
                suma += i;
            }
        }

        if (suma == liczba ) {
            printf("%d\n", liczba);
            licznik += 1;
        }
    }
    printf("Wszystkie doskonale: %d", licznik);

    return 0;
}