#include <stdio.h>
#include <stdlib.h>

int isPrime(int number){
    for (int i = 2; i < number; i++){
        if(number % i == 0){
            return 0;
            break;
        }
    }
    return 1;
}

int main(void){
    int n, currentPrime, rest, sum = 0, counter = 0;

    //User input
    printf("range: ");
    scanf("%d", &n);

    //Gener primes at given range
    printf("Primes with not descending orders of nums:\n");
    for (int i = 2; i <= n; i++){
        if (isPrime(i) == 1) {

            //If prime, check if numbers are in NOT descending order ex. 125, 1556 is ok 1554 not ok.
            // printf("%d PRIME\n", i);
            
            currentPrime = i;
            while (currentPrime != 0){
                rest = currentPrime % 10;
                currentPrime = currentPrime / 10;

                // printf("rest: %d, next num: %d\n", rest, currentPrime);
                if (rest >= currentPrime%10){
                    counter += 1;
                }else {
                    counter = 0;
                    break;
                }
            }
            
            if(counter != 0){
                printf("%d, ", i);
            }
        }
    }

}