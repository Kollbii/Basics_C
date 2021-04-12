#include <stdio.h>
#include <stdlib.h>

int main(void){
    int n, k, space;

    printf("Number: ");
    scanf("%d", &n);

    while (n % 2 == 0){
        printf("Must be odd number!\n");
        printf("Type odd number: ");
        scanf("%d", &n);
    }

    for (int i = 1; i <= n / 2 + 1; ++i, k = 0) {
      for (space = 1; space <= n - i; ++space) {
         printf("  ");
      }
      while (k != 2 * i - 1) {
         printf("o ");
         ++k;
      }
    printf("\n");
    }

    for (int i = n / 2; i >= 1; --i) {
      for (space = 0; space < n - i; ++space)
         printf("  ");
      for (int j = i; j <= 2 * i - 1; ++j)
         printf("o ");
      for (int j = 0; j < i - 1; ++j)
         printf("o ");
      printf("\n");
    }
}