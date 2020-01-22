#include "DrawObjects.h"

void drawMovingObjects(uint8_t enemySize, uint8_t moveDirection, struct drawItems *drawValues, struct player *player, struct enemy *enemy, uint8_t ship){
    //Draw player
    ShipSelection(moveDirection, ship, player, drawValues);

    //updates enemy position and draws enemy
    for(uint8_t i = 0; i < enemySize; i++){
        if(enemy[i].show == 1){
            if(enemy[i].xVelocity != 0){
                if(enemy[i].xPos != enemy[i].xPosPrevious){
                    drawEnemy(2, enemy, drawValues, i);
                }
            } else {
                if(enemy[i].yPos != enemy[i].yPosPrevious){
                    drawEnemy(1, enemy, drawValues, i);
                }
            }
            enemy[i].xPosPrevious = enemy[i].xPos;
            enemy[i].yPosPrevious = enemy[i].yPos;
        } else if(enemy[i].xPos != 1 && enemy[i].yPos != 1){
            drawEnemy(0, enemy, drawValues, i);
            enemy[i].xPos = 1;
            enemy[i].yPos = 1;
        }
    }

    //Forloop for all 3 bullets
    for(int8_t i = 0; i < 3; i++){
        //set draw of bullet in queue
        if((*player).shots[i].show == 1 && ((*player).shots[i].xPos - (*player).shots[i].xVelocity != (*player).xPos || (*player).shots[i].yPos - (*player).shots[i].yVelocity != (*player).yPos)){
            DrawingSetValues(drawValues,(*player).shots[i].xPos - (*player).shots[i].xVelocity,(*player).shots[i].yPos - (*player).shots[i].yVelocity,(*player).shots[i].xPos - (*player).shots[i].xVelocity,(*player).shots[i].yPos - (*player).shots[i].yVelocity,0xFF);
            DrawingSetValues(drawValues,(*player).shots[i].xPos,(*player).shots[i].yPos,(*player).shots[i].xPos,(*player).shots[i].yPos,'o');
        } else if((*player).shots[i].show == 0 && (*player).shots[i].xPos != 2 && (*player).shots[i].xPos != 2){
            DrawingSetValues(drawValues,(*player).shots[i].xPos - (*player).shots[i].xVelocity,(*player).shots[i].yPos - (*player).shots[i].yVelocity,(*player).shots[i].xPos - (*player).shots[i].xVelocity,(*player).shots[i].yPos - (*player).shots[i].yVelocity,0xFF);
            (*player).shots[i].xPos = 2;
            (*player).shots[i].yPos = 2;
        }
    }

    //updates player previous position to current position
    player->xPosPrevious = (*player).xPos;
    player->yPosPrevious = (*player).yPos;


    //Draws everything (Enemy->Bullets->Player)
    DrawEverything(drawValues);
}


void drawEnemy(uint8_t control, struct enemy *enemy, struct drawItems *drawValues, uint8_t i){
    //defines chartype
    char charType[] = {'\0','\0','\0','\0','\0','\0','\0','\0','\0'};

    if(control != 0){
        switch (control){
            case 1:{
                charType[0] = 0xB3; charType[1] = 0xFF; charType[2] = 0xB3; charType[3] = 0xCC; charType[4] = 0x4F; charType[5] = 0xB9; charType[6] = 0xB3; charType[7] = 0xFF; charType[8] = 0xB3;
                break;
            }
            case 2:{
                charType[0] = 0xC4; charType[1] = 0xCB; charType[2] = 0xC4; charType[3] = 0xFF; charType[4] = 0x4F; charType[5] = 0xFF; charType[6] = 0xC4; charType[7] = 0xCA; charType[8] = 0xC4;
                break;
            }
            default:
                break;
        }
        //sets the enemy previous position (3x3) to 0xFF (empty) in the drawer que
        if(enemy[i].xVelocity > 0){
            printf("%c[%u;%u%c%c%c[%u;%u%c%c%c[%u;%u%c%c",0x1B,enemy[i].yPosPrevious-1,enemy[i].xPosPrevious-1,0x48,0xFF,0x1B,enemy[i].yPosPrevious,enemy[i].xPosPrevious-1,0x48,0xFF,0x1B,enemy[i].yPosPrevious+1,enemy[i].xPosPrevious-1,0x48,0xFF);
        } else if (enemy[i].xVelocity < 0){
            printf("%c[%u;%u%c%c%c[%u;%u%c%c%c[%u;%u%c%c",0x1B,enemy[i].yPosPrevious-1,enemy[i].xPosPrevious+1,0x48,0xFF,0x1B,enemy[i].yPosPrevious,enemy[i].xPosPrevious+1,0x48,0xFF,0x1B,enemy[i].yPosPrevious+1,enemy[i].xPosPrevious+1,0x48,0xFF);
        } else if (enemy[i].yVelocity > 0){
            printf("%c[%u;%u%c%c%c%c",0x1B,enemy[i].yPosPrevious-1,enemy[i].xPosPrevious-1,0x48,0xFF,0xFF,0xFF);
        } else if (enemy[i].yVelocity < 0){
            printf("%c[%u;%u%c%c%c%c",0x1B,enemy[i].yPosPrevious+1,enemy[i].xPosPrevious-1,0x48,0xFF,0xFF,0xFF);
        }

        //sets the enemy current position (3x3) to the right character in the drawer que
        printf("%c[%u;%u%c%c%c%c%c[%u;%u%c%c%c%c%c[%u;%u%c%c%c%c",0x1B,enemy[i].yPos-1,enemy[i].xPos-1,0x48,charType[0],charType[1],charType[2],0x1B,enemy[i].yPos,enemy[i].xPos-1,0x48,charType[3],charType[4],charType[5],0x1B, enemy[i].yPos+1,enemy[i].xPos-1,0x48, charType[6],charType[7],charType[8]);
        //%c[%u;%u%c,ESC,y,x,0x48

    } else {
        //sets the enemy previous position (3x3) to 0xFF (empty) in the drawer que
        printf("%c[%u;%u%c%c%c%c%c[%u;%u%c%c%c%c%c[%u;%u%c%c%c%c",0x1B,enemy[i].yPosPrevious-1,enemy[i].xPosPrevious-1,0x48,0xFF,0xFF,0xFF,0x1B,enemy[i].yPosPrevious,enemy[i].xPosPrevious-1,0x48,0xFF,0xFF,0xFF,0x1B, enemy[i].yPosPrevious+1,enemy[i].xPosPrevious-1,0x48, 0xFF,0xFF,0xFF);
        printf("%c[%u;%u%c%c%c%c%c[%u;%u%c%c%c%c%c[%u;%u%c%c%c%c",0x1B,enemy[i].yPosPrevious-1,enemy[i].xPosPrevious-1,0x48,0xFF,0xFF,0xFF,0x1B,enemy[i].yPosPrevious,enemy[i].xPosPrevious-1,0x48,0xFF,0xFF,0xFF,0x1B, enemy[i].yPosPrevious+1,enemy[i].xPosPrevious-1,0x48, 0xFF,0xFF,0xFF);

    }
}

