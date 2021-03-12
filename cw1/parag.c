#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main(void) {
   double a, p; //cena jednostkowa, podatek
   int x; //ilosc

   system("cls");
   printf("Podaj cene jednostkowa netto: ");
   scanf("%lf", &a);
   printf("Liczba sztuk: ");
   scanf("%d", &x);
   printf("Podatek VAT [%%]: ");
   scanf("%lf", &p);
   
   system("cls");

   printf("|=======================|\n");
   printf("|     Kollbi Paragons   |\n", x);
   printf("|                       |\n", x);
   printf("| Ilosc: %d              |\n", x);
   printf("| Cena za szt.: %.2lf   |\n", a);
   printf("| Opodatkowanie: %.2lf%% |\n", p);
   printf("|                       |\n");
   printf("| Kwota brutto: %.2lf   |\n", (a*x)*(1+(p/100)));
   printf("| Kwota netto: %.2lf    |\n", a*x);
   printf("|                       |\n");
   printf("| NIP: 123 234 345 543  |\n");
   printf("|=======================|\n");
}
