#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int randomNumbersInRange(int n, int m, int count){
   int num;
   for (int i = 0; i < count; i++){
      num = (rand() % (n - m + 1)) + n;
   }
   return num;
}

int main() {
   // Console clear at each run
   system("cls");

   srand(time(NULL));
   int random = randomNumbersInRange(1, 100, 5);
   printf("Genereted random number: %d\n", random);

   // Get user input
   int guess;
   int counter = 1;

  while (guess != random){
      printf("Guess the number: ");
      scanf("%d", &guess);
      if (guess < random){
         counter++;
         printf("Your number is to low...\n");
      } else if (guess > random){
         counter++;
         printf("Your number is to high...\n");
      } else {
         printf("You guessed! The number was \e[32m%d\e[0m\n", random);
         printf("You guessed at \e[31m%d\e[0m time\n", counter);
      }
  }
}