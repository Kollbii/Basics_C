#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <unistd.h>

int i, j, height= 30, width = 30, gameover = 0, score;
int x, y, fruitx, fruity, flag;
void draw() {
    system("cls");
    printf("\t\t\t SCORE %d");
    for (i = 0; i < height; i++){
        for (j = 0; j < width; j++){
            if (i == 0 || i == width - 1 || j == 0 || j == height - 1){
                printf("#");
            }else{
                if(i == x && j == y){
                    printf("$");
                }else if(i == fruitx && j == fruity){
                    printf("@");
                }else{
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
}

void setup(){
    gameover = 0;
    x = height/2;
    y = width/2;
    label1:
        fruitx= rand()%20;
        if(fruitx == 0)
            goto label1;
    label2:
        fruity = rand()%20;
        if(fruity == 0)
            goto label2;
    score = 0;
}

void input(){
    if(kbhit()){
        switch(getch()){
            case 'w':
                flag = 1;
                break;
            case 'a':
                flag = 2;
                break;
            case 's':
                flag = 3; 
                break;
            case 'd':
                flag = 4;
                break;
            case 'x':
                gameover = 1;
                break;
        }
    }
}

void logic(){
    sleep(0.7);
    switch(flag){
        case 1:
            x--;
            break;
        case 2:
            y--;
            break;
        case 3:
            x++;
            break;
        case 4:
            y++;
            break;
        default:
            break;
    }

    if (x < 0 || x > height || y < 0 || y > width ){
        gameover = 1;
    }
    if (x == fruitx && y == fruity){
        label3:
            fruitx = rand()%20;
            if(fruitx == 0)
                goto label3;
        label4:
            fruity = rand()%20;
            if(fruity == 0)
                goto label4;
        score += 10;
    }
}
int main(void){
    int m,n;
    system("cls");
    
    setup();
    
    // if(kbhit()){
    //     switch(getch()){
    //         case 'w':
    //             flag = 1;
    //             break;
    //         case 'a':
    //             flag = 2;
    //             break;
    //         case 's':
    //             flag = 3; 
    //             break;
    //         case 'd':
    //             flag = 4;
    //             break;
    //         case 'x':
    //             gameover = 1;
    //             break;
    //     }
    // }
    

    while(gameover != 1){
        draw();
        input();
        logic();
    }


    printf("Lost and gained %d points", score);

    return 0;
}