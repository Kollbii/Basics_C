#include <stdio.h>
#include <stdlib.h>

int main(void){
    char c; char string[255];
    int num;

    // Ta druga opcja ze scanfem i jakimś regexem

    // printf("String by scanf: ");

    // scanf("%s", &string);
    // scanf("%[^\n]%*c", &string);
    // printf("Input: %s",string);
    printf("Your text: ");
    gets(string);
    printf("%s\n\n", string);

    printf("Num and letter: ");
    scanf("%d %c", &num, &c);
    printf("For each %d letters place %c\n\n", num, c);

    printf("Before: %s\n", string);
    for (int i = 0; i < 255; i++){
        if (i % num == 0) {
            if (string[i] != 0 && string[i] != ' '){
                string[i] = c;  
            }
        }
    }
    printf("After: %s\n", string);
}