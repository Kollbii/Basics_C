#include <stdio.h>
#include <string.h>

int main(void){

    char string[255],a, b;
    gets(string);
    
    scanf("%c %c",&a, &b);

    for (int i = 0; i < 255; i++){
        if ( a == string[i] ){
            string[i] = b;
        }
        else if ( b == string[i] ){
            string[i] = a;
        }
        else {
            continue;
        }
    }
    printf ("%s", string);
    return 0;


}