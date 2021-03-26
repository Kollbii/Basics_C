#include <stdio.h>
#include <string.h>

int main(void){
    
    // printf ("%c, %c", a, b);

    char string[255];
    gets(string);
    // scanf("%s", &string);
    // fgets(string, sizeof(string), stdin);

    // scanf ("%[^\n]%*c", string);
    // scanf("%[^\n]s",&string);

    char a,b;
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
    // puts(string);
    printf ("%s", string);
    return 0;


}