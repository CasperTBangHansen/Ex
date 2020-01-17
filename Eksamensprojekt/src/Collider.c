#include "Collider.h"
#define arraySize 1000


//THIS IS FOR TESTING ONLY
void initEverything(struct player *player, struct enemy *enemy){
    //Player and shots
    uint16_t xSTART = 80;
    uint16_t ySTART = 45;
    player->xPos = xSTART;
    player->yPos = ySTART;
    player->xPosPrevious = xSTART;
    player->yPosPrevious = ySTART;
    player->xVelocity = -1;
    player->yVelocity = 0;
    player->lives = 3;


    //bullets

    //Bullet 1
    xSTART = 10;
    ySTART = 15;
    player->shots[0].xPos = xSTART;
    player->shots[0].yPos = ySTART;
    player->shots[0].xPosPrevious = xSTART;
    player->shots[0].yPosPrevious = ySTART;
    player->shots[0].xVelocity = 0;
    player->shots[0].yVelocity = -1;
    player->shots[0].show = 1;

    //Bullet 2
    xSTART = 80;
    ySTART = 40;
    player->shots[1].xPos = xSTART;
    player->shots[1].yPos = ySTART;
    player->shots[1].xPosPrevious = xSTART;
    player->shots[1].yPosPrevious = ySTART;
    player->shots[1].xVelocity = -1;
    player->shots[1].yVelocity = 0;
    player->shots[1].show = 1;

    //Bullet 3
    xSTART = 40;
    ySTART = 40;
    player->shots[2].xPos = xSTART;
    player->shots[2].yPos = ySTART;
    player->shots[2].xPosPrevious = xSTART;
    player->shots[2].yPosPrevious = ySTART;
    player->shots[2].xVelocity = 0;
    player->shots[2].yVelocity = -2;
    player->shots[2].show = 1;

    //Enemys

    //Enemy 1
    xSTART = 55;
    ySTART = 45;
    enemy[0].xPos = xSTART;
    enemy[0].yPos = ySTART;
    enemy[0].xPosPrevious = xSTART;
    enemy[0].yPosPrevious = ySTART;
    enemy[0].xVelocity = 1;
    enemy[0].yVelocity = 0;
    enemy[0].show = 1;

    //Enemy 2
    xSTART = 60;
    ySTART = 40;
    enemy[1].xPos = xSTART;
    enemy[1].yPos = ySTART;
    enemy[1].xPosPrevious = xSTART;
    enemy[1].yPosPrevious = ySTART;
    enemy[1].xVelocity = -1;
    enemy[1].yVelocity = 0;
    enemy[1].show = 1;

    //Enemy 3
    xSTART = 10;
    ySTART = 10;
    enemy[2].xPos = xSTART;
    enemy[2].yPos = ySTART;
    enemy[2].xPosPrevious = xSTART;
    enemy[2].yPosPrevious = ySTART;
    enemy[2].xVelocity = 0;
    enemy[2].yVelocity = 2;
    enemy[2].show = 1;


}

static uint16_t xPosStart[arraySize];
static uint8_t yPosStart[arraySize];
static uint16_t xPosSlut[arraySize];
static uint8_t yPosSlut[arraySize];
static uint16_t sizeOfArrays = 0;


void setWallHitBox(struct drawItems *drawValues, uint16_t mapHitBoxSize){
    sizeOfArrays = mapHitBoxSize;
    for(uint16_t i = 0; i <= sizeOfArrays; i++){
        xPosStart[i] = drawValues[i].xStart;
        yPosStart[i] = drawValues[i].yStart;
        xPosSlut[i] = drawValues[i].xSlut;
        yPosSlut[i] = drawValues[i].ySlut;
    }
}

int16_t getWallHitBoxSize(){
    return sizeOfArrays;
}

void checkCollider(struct player *playerHitBox, struct enemy *enemies){
    for(int16_t i = 0; i <= getWallHitBoxSize(); i++){

        playerHitBox->xPos = checkColliderLeftToRight((*playerHitBox).xPos, (*playerHitBox).xPosPrevious, (*playerHitBox).yPos, (*playerHitBox).yPosPrevious, (*playerHitBox).xVelocity, (*playerHitBox).yVelocity, i);
        playerHitBox->xPos = checkColliderRightToLeft((*playerHitBox).xPos, (*playerHitBox).xPosPrevious, (*playerHitBox).yPos, (*playerHitBox).yPosPrevious, (*playerHitBox).xVelocity, (*playerHitBox).yVelocity, i);
        playerHitBox->yPos = checkColliderTopToBottom((*playerHitBox).xPos, (*playerHitBox).xPosPrevious, (*playerHitBox).yPos, (*playerHitBox).yPosPrevious, (*playerHitBox).xVelocity, (*playerHitBox).yVelocity, i);
        playerHitBox->yPos = checkColliderBottomToTop((*playerHitBox).xPos, (*playerHitBox).xPosPrevious, (*playerHitBox).yPos, (*playerHitBox).yPosPrevious, (*playerHitBox).xVelocity, (*playerHitBox).yVelocity, i);

        for(int8_t j = 0; j < 3; j++){
            if((*playerHitBox).shots[j].show == 1){
                (*playerHitBox).shots[j].xPos = checkColliderLeftToRight((*playerHitBox).shots[j].xPos, (*playerHitBox).shots[j].xPosPrevious, (*playerHitBox).shots[j].yPos, (*playerHitBox).shots[j].yPosPrevious, (*playerHitBox).shots[j].xVelocity, (*playerHitBox).shots[j].yVelocity, i);
                (*playerHitBox).shots[j].xPos = checkColliderRightToLeft((*playerHitBox).shots[j].xPos, (*playerHitBox).shots[j].xPosPrevious, (*playerHitBox).shots[j].yPos, (*playerHitBox).shots[j].yPosPrevious, (*playerHitBox).shots[j].xVelocity, (*playerHitBox).shots[j].yVelocity, i);
                (*playerHitBox).shots[j].yPos = checkColliderTopToBottom((*playerHitBox).shots[j].xPos, (*playerHitBox).shots[j].xPosPrevious, (*playerHitBox).shots[j].yPos, (*playerHitBox).shots[j].yPosPrevious, (*playerHitBox).shots[j].xVelocity, (*playerHitBox).shots[j].yVelocity, i);
                (*playerHitBox).shots[j].yPos = checkColliderBottomToTop((*playerHitBox).shots[j].xPos, (*playerHitBox).shots[j].xPosPrevious, (*playerHitBox).shots[j].yPos, (*playerHitBox).shots[j].yPosPrevious, (*playerHitBox).shots[j].xVelocity, (*playerHitBox).shots[j].yVelocity, i);
                if((*playerHitBox).shots[j].xPos == (*playerHitBox).shots[j].xPosPrevious && (*playerHitBox).shots[j].yPos == (*playerHitBox).shots[j].yPosPrevious){
                   (*playerHitBox).shots[j].show = 0;
                }
            }
        }
    }
    for(int8_t j = 0; j < 3; j++){
        if((*playerHitBox).shots[j].show == 1){
            for(uint8_t w = 0; w < 3; w++){
                if (checkColliderXEnemy((*playerHitBox).shots[j].xPos, (*playerHitBox).shots[j].xPosPrevious, (*playerHitBox).shots[j].yPos, (*playerHitBox).shots[j].yPosPrevious, (*playerHitBox).shots[j].xVelocity, (*playerHitBox).shots[j].yVelocity, enemies[w].xPos, enemies[w].yPos)){
                    (*playerHitBox).shots[j].show = 0;
                    enemies[w].show = 0;
                }
                if (checkColliderYEnemy((*playerHitBox).shots[j].xPos, (*playerHitBox).shots[j].xPosPrevious, (*playerHitBox).shots[j].yPos, (*playerHitBox).shots[j].yPosPrevious, (*playerHitBox).shots[j].xVelocity, (*playerHitBox).shots[j].yVelocity, enemies[w].xPos, enemies[w].yPos)){
                    (*playerHitBox).shots[j].show = 0;
                    enemies[w].show = 0;
                }
            }
        }
    }
    int8_t hit = 0;
    for(int8_t w = 0; w < 3; w++){
        if (hit == 0 && checkColliderXEnemy((*playerHitBox).xPos, (*playerHitBox).xPosPrevious, (*playerHitBox).yPos, (*playerHitBox).yPosPrevious, (*playerHitBox).xVelocity, (*playerHitBox).yVelocity, enemies[w].xPos, enemies[w].yPos)){
            playerHitBox->lives = (*playerHitBox).lives - 1;
            hit = 1;
        }
        if (hit == 0 && checkColliderYEnemy((*playerHitBox).xPos, (*playerHitBox).xPosPrevious, (*playerHitBox).yPos, (*playerHitBox).yPosPrevious, (*playerHitBox).xVelocity, (*playerHitBox).yVelocity, enemies[w].xPos, enemies[w].yPos)){
            playerHitBox->lives = (*playerHitBox).lives - 1;
        }
    }
}

static uint8_t checkColliderXEnemy(uint16_t xPos, uint16_t xPosPrevious, uint8_t yPos, uint8_t yPosPrevious, int8_t xVelocity, int8_t yVelocity, uint16_t enemiesXPos, uint8_t enemiesYPos){
    if((yPosPrevious <= enemiesYPos && yPos >= enemiesYPos) || (yPosPrevious >= enemiesYPos && yPos <= enemiesYPos)){
        if(xVelocity > 0){
            if(xPosPrevious <= enemiesXPos && xPos >= enemiesXPos){
                return 1;
            }
        } else if (xVelocity < 0){
            if(xPosPrevious >= enemiesXPos && xPos <= enemiesXPos){
                return 1;
            }
        }
    }
    return 0;
}

static uint8_t checkColliderYEnemy(uint16_t xPos, uint16_t xPosPrevious, uint8_t yPos, uint8_t yPosPrevious, int8_t xVelocity, int8_t yVelocity, uint16_t enemiesXPos, uint8_t enemiesYPos){
    if((xPosPrevious <= enemiesXPos && xPos >= enemiesXPos) || (xPosPrevious >= enemiesXPos && xPos <= enemiesXPos)){
        if(yVelocity > 0){
            if(yPosPrevious <= enemiesYPos && yPos >= enemiesYPos){
                return 1;
            }
        } else if (yVelocity < 0){
            if(yPosPrevious >= enemiesYPos && yPos <= enemiesYPos){
                return 1;
            }
        }
    }
    return 0;
}

static uint16_t checkColliderLeftToRight(uint16_t xPos, uint16_t xPosPrevious, uint8_t yPos, uint8_t yPosPrevious, int8_t xVelocity, int8_t yVelocity, uint16_t i){
    if(xPosStart[i] == xPosSlut[i] && xVelocity > 0){
        if(xPosPrevious < xPosStart[i] && xPosStart[i] <= xPos && yPosStart[i] <= yPos && yPosSlut[i] >= yPos){
            uint16_t xPosTemp = xPos;
            for(int8_t j = xPos - xPosPrevious; j > 0; j--){
                if(xPosPrevious < xPosStart[i] && xPosStart[i] <= xPosTemp){
                    xPosTemp = xPosTemp - 1;
                }
            }
            xPos = xPosTemp;
        }
    }
    return xPos;
}

static uint16_t checkColliderRightToLeft(uint16_t xPos, uint16_t xPosPrevious, uint8_t yPos, uint8_t yPosPrevious, int8_t xVelocity, int8_t yVelocity, uint16_t i){
    if(xPosStart[i] == xPosSlut[i] && xVelocity < 0){
        if(xPosPrevious > xPosStart[i] && xPosStart[i] >= xPos && yPosStart[i] <= yPos && yPosSlut[i] >= yPos){
            uint16_t xPosTemp = xPos;
            for(int8_t j = xPosPrevious-xPos; j > 0; j--){
                if(xPosPrevious > xPosStart[i] && xPosStart[i] >= xPosTemp){
                    xPosTemp = xPosTemp + 1;
                }
            }
            xPos = xPosTemp;
        }
    }
    return xPos;
}

static uint16_t checkColliderTopToBottom(uint16_t xPos, uint16_t xPosPrevious, uint8_t yPos, uint8_t yPosPrevious, int8_t xVelocity, int8_t yVelocity, uint16_t i){
    if(yPosStart[i] == yPosSlut[i] && yVelocity > 0){
        if(yPosPrevious < yPosStart[i] && yPosStart[i] <= yPos && xPosStart[i] <= xPos && xPosSlut[i] >= xPos){
            uint8_t yPosTemp = yPos;
            for(int8_t j = yPos - yPosPrevious; j > 0; j--){
                if(yPosPrevious < yPosStart[i] && yPosStart[i] <= yPosTemp){
                    yPosTemp = yPosTemp - 1;
                }
            }
            yPos = yPosTemp;
        }
    }
    return yPos;
}

static uint16_t checkColliderBottomToTop(uint16_t xPos, uint16_t xPosPrevious, uint8_t yPos, uint8_t yPosPrevious, int8_t xVelocity, int8_t yVelocity, uint16_t i){
    if(yPosStart[i] == yPosSlut[i] && yVelocity < 0){
        if(yPosPrevious > yPosStart[i] && yPosStart[i] >= yPos && xPosStart[i] <= xPos && xPosSlut[i] >= xPos){
            uint8_t yPosTemp = yPos;
            for(int8_t j = yPosPrevious-yPos; j > 0; j--){
                if(yPosPrevious > yPosStart[i] && yPosStart[i] >= yPosTemp){
                    yPosTemp = yPosTemp + 1;
                }
            }
            yPos = yPosTemp;
        }
    }
    return yPos;
}


