#include "DrawObjects.h"

void drawMovingObjects(uint8_t enemySize, uint8_t moveDirection, struct drawItems *drawValues, struct player *player, struct enemy *enemy){
    //Draw player
    ShipSelection(moveDirection, 1, player, drawValues);

    //updates enemy position and draws enemy
    for(uint8_t i = 0; i < enemySize; i++){
        if(enemy[i].show == 1){
            if(enemy[i].xVelocity != 0){
                drawEnemy(2, enemy[i].xPos, enemy[i].yPos, enemy[i].xPosPrevious, enemy[i].yPosPrevious, drawValues);
            } else {
                drawEnemy(1, enemy[i].xPos, enemy[i].yPos, enemy[i].xPosPrevious, enemy[i].yPosPrevious, drawValues);
            }
            enemy[i].xPosPrevious = enemy[i].xPos;
            enemy[i].yPosPrevious = enemy[i].yPos;
        } else if(enemy[i].xPos != 1 && enemy[i].yPos != 1){
            drawEnemy(0, enemy[i].xPos, enemy[i].yPos, enemy[i].xPosPrevious, enemy[i].yPosPrevious, drawValues);
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


void drawEnemy(uint8_t control, uint16_t xPos, uint8_t yPos, uint16_t xPPos, uint8_t yPPos, struct drawItems *drawValues){
    //defines chartype
    char charType[] = {'\0','\0','\0','\0','\0','\0','\0','\0','\0'};

    uint16_t x[] = {xPos - 1, xPos    , xPos + 1, xPos - 1, xPos , xPos + 1, xPos - 1, xPos    , xPos + 1};
    uint8_t y[] =  {yPos - 1, yPos - 1, yPos - 1, yPos    , yPos , yPos    , yPos + 1, yPos + 1, yPos + 1};

    //makes an array with every position around the players previous position (3x3)
    uint16_t xP[] = {xPPos - 1, xPPos    , xPPos + 1, xPPos - 1, xPPos , xPPos + 1, xPPos - 1, xPPos    , xPPos + 1};
    uint8_t yP[] =  {yPPos - 1, yPPos - 1, yPPos - 1, yPPos    , yPPos , yPPos    , yPPos + 1, yPPos + 1, yPPos + 1};

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
            case 3:{
                charType[0] = 0xB3; charType[1] = 0xFF; charType[2] = 0xB3; charType[3] = 0xCC; charType[4] = 0x4F; charType[5] = 0xB9; charType[6] = 0xB3; charType[7] = 0xFF; charType[8] = 0xB3;
                break;
            }
            case 4:{
                charType[0] = 0xC4; charType[1] = 0xCB; charType[2] = 0xC4; charType[3] = 0xFF; charType[4] = 0x4F; charType[5] = 0xFF; charType[6] = 0xC4; charType[7] = 0xCA; charType[8] = 0xC4;
                break;
            }
            default:
                break;
        }

        //sets the enemy previous position (3x3) to 0xFF (empty) in the drawer que
        for(uint8_t i = 0; i<=(8); i++){
            DrawingSetValues(drawValues, xP[i], yP[i], xP[i], yP[i], 0xFF);
        }
        //sets the enemy current position (3x3) to the right character in the drawer que
        for(uint8_t i = 0; i<=(8); i++){
            DrawingSetValues(drawValues, x[i], y[i], x[i], y[i], charType[i]);
        }
    } else {
        //sets the enemy previous position (3x3) to 0xFF (empty) in the drawer que
        for(uint8_t i = 0; i<=(8); i++){
            DrawingSetValues(drawValues, xP[i], yP[i], xP[i], yP[i], 0xFF);
        }
    }
}

