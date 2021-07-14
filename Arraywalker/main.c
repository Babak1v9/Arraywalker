#include <stdio.h>
#include <stdlib.h>

struct labyrinth{
    char field[10][10];
    char step;
    struct player player;
};

struct player{
    int x;
    int y;
};

struct labyrinth buildLabyrinth(){
    struct labyrinth lab;
    for(int n = 0; n < 10; n++)
        for(int m = 0; m < 10; m++)
            lab.field[n][m] = '.';

    lab.field[0][0] = 'A';
    lab.step = 'B';

    lab.player.x = 0;
    lab.player.y = 0;
    return lab;
}

void printLabyrinth(struct labyrinth* lab){
    for(int y = 0; y < 10; y++){
        for(int x = 0; x < 10; x++){
            printf("%c", lab->field[x][y]);
        }
        printf("\n");
    }
}

void moveTo(struct labyrinth* lab, int x, int y){

    lab->player.x = x;
    lab->player.y = y;
    lab->field[x][y] = lab->step;
    lab->step++;

    if(lab->step>'Z'){
        lab->step = 'A';
    }
}

int main(){

    struct labyrinth lab = buildLabyrinth();
    printLabyrinth(&lab);

    char input = '';

    while(input != 'x'){
        printf("Enter command: ");
        scanf(" %c", &input);
        int check = 0;

        switch(input){
            case 'w':
                if(check = (lab.player.y > 0 && lab.field[lab.player.x][lab.player.y-1]=='.')){
                    moveTo(&lab, lab.player.x, lab.player.y-1);
                }
            break;
            case 's':
                if(check = (lab.player.y < 9 && lab.field[lab.player.x][lab.player.y+1]=='.')){
                    moveTo(&lab, lab.player.x, lab.player.y+1);
                }
            break;
            case 'd':
                if(check = (lab.player.x < 9 && lab.field[lab.player.x+1][lab.player.y]=='.')){
                    moveTo(&lab, lab.player.x+1, lab.player.y);
                }
            break;
            case 'a':
                if(check = (lab.player.x > 0 && lab.field[lab.player.x-1][lab.player.y]=='.')){
                    moveTo(&lab, lab.player.x-1, lab.player.y);
                }
        }
        if(!check) {
            printf("You can't move this way!\n");
        }else{
            printLabyrinth(&lab);
        }
    }
    return 0;
}
