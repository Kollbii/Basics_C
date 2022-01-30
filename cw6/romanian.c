#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Wejscie:
// CXXIII CCLVI
// Wyjscie:
// CCCLXXIX

#define ARRSIZE 10

int get_num_in_dec(char arr[]);
void convert_to_roman(int num);

int get_num_in_dec(char arr[]){
    int num = 0;
    for (int i = 0; i < ARRSIZE; i++){
        /*
        Input specified.
        Check only capital letters in alphabet.
        */
        if(arr[i] >= 65 && arr[i] <= 90){
            /*
            Watch out for CM, CD, XC, XL, IX, IV
            */
            switch((char)arr[i]){
                case 'M':
                    if (arr[i - 1] == 'C'){
                        break;
                    } else {
                        num += 1000;
                        break;
                    }
                case 'D':
                    if (arr[i -1] == 'C'){
                        break;
                    } else{
                        num += 500;
                        break;
                    }
                case 'C': 
                    if (arr[i+1] == 'M'){
                        num += 900;
                        break;
                    } else if (arr[i+1] == 'D'){
                        num += 400;
                        break;
                    } else if (arr[i - 1] == 'X'){
                        break;
                    } else{
                        num += 100;
                        break;
                    }
                case 'L':
                    if ( arr[i - 1] == 'X'){
                        break;
                    } else {
                        num += 50;
                        break;
                    }
                case 'X':
                    if (arr[i + 1] == 'L'){
                        num += 40;
                        break;
                    } else if (arr[i+1] == 'C'){
                        num += 90;
                        break;
                    } else if (arr[i - 1] == 'I') {
                        break;
                    }else {
                        num += 10;
                        break;
                    }
                case 'V':
                    if (arr[i - 1] == 'I'){
                        break;
                    } else {
                        num += 5;
                        break;
                    }
                case 'I':
                    if (arr[i+1] == 'X'){
                        num += 9;
                        break;
                    } else if (arr[i + 1] == 'V'){
                        num += 4;
                        break;
                    } else {
                        num += 1;
                        break;
                    }
            }
        }
    }
    return num;
}

void convert_to_roman(int num){
    /*Idea with array saved for future.*/
    int i = 0;
    while (num != 0){
        if (num >= 1000){
            printf("M");
            // arr[i] = 'M';
            num -= 1000;
            i++;
        } else if (num >= 900){
            printf("CM");
            // arr[i] = 'CM';
            num -= 900;
            i++;
        }else if (num >= 500){
            printf("D");
            // arr[i] = 'D';
            num -= 500;
            i++;
        }else if (num >= 400){
            printf("CD");
            // arr[i] = 'CD';
            num -= 400;
            i++;
        }else if (num >= 100){
            printf("C");
            // arr[i] = 'C';
            num -= 100;
            i++;
        }else if (num >= 90){
            printf("XC");
            // arr[i] = 'XC';
            num -= 90;
            i++;
        }else if (num >= 50){
            printf("L");
            // arr[i] = 'L';
            num -= 50;
            i++;
        }else if (num >= 40){
            printf("XL");
            // arr[i] = 'XL';
            num -= 40;
            i++;
        }else if (num >= 10){
            printf("X");
            // arr[i] = 'X';
            num -= 10;
            i++;
        }else if (num >= 9){
            printf("IX");
            // arr[i] = 'IX';
            num -= 9;
            i++;
        }else if (num >= 5){
            printf("V");
            // arr[i] = 'V';
            num -= 5;
            i++;
        }else if (num >= 4){
            printf("IV");
            // arr[i] = 'IV';
            num -= 4;
            i++;
        }else if (num >= 1){
            printf("I");
            // arr[i] = 'I';
            num -= 1;
            i++;
        }
    }
}

int main(void){
    char arr1[ARRSIZE];
    char arr2[ARRSIZE];
  
    printf("Your nums\n>");
    scanf("%s", arr1);
    scanf("%s", arr2);

    // printf("%s + %s = ", arr1, arr2);
    // printf("%d + %d = ", get_num_in_dec(arr1), get_num_in_dec(arr2));
    convert_to_roman(get_num_in_dec(arr1) + get_num_in_dec(arr2));
}