#include <stdio.h>
#include <string.h>

int main()
{
    char* str1="0e0b213f26041e480b26217f27342e175d0e070a3c5b103e2526217f27342e175d0e077e263451150104"; // 13
    int i = 0;

    // for (int j = 1; j < 10 ;j++){
        for (i; i < strlen(str1); i++) {
            printf("%c", str1[i] ^ 8);
            }
        printf("\n");
    // }
    // printf("checksum: %d\n", sum);

    return 0;
}