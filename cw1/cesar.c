#include<stdio.h>    
#include<stdlib.h>  

int main(void){  
    char string[256], currentChar;
    int key;
    
    system ("cls");  
    printf("\nEnter string to SUPER ENCRYPT IT: ");
    scanf("%s", &string);
    printf("\nKey: ");
    scanf("\n%d", &key);

    system ("cls");  
    printf("String to encrpyt: %s\nKey: %d\n", string, key);

    for (int i = 0; string[i] != '\0' ; i++){
        printf("%d ", string[i]);
        currentChar = string[i];

        if (string[i] >= 65 && string[i] <= 90){
            currentChar = ( currentChar + key - 65 ) % 26 + 65;
        } else if (string[i] >= 97 && string[i] <= 122){
            currentChar = ( currentChar + key - 97 ) % 26 + 97;
        }
        string[i] = currentChar;
    }

    printf("\nEncrypted: %s", string, key);
    return 0;  
}  

