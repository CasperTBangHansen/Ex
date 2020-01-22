#ifndef _COLLIDER_H_
#define _COLLIDER_H_

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "Drawing.h"


struct enemy{
    uint16_t xPos;
    uint16_t xPosPrevious;
    uint8_t yPos;
    uint8_t yPosPrevious;
    int8_t xVelocity;
    int8_t yVelocity;
    uint8_t show;
    uint16_t xPath[10];
    uint8_t yPath[10];
    uint8_t arrayPathSize;
};

struct bullet{
    uint16_t xPos;
    uint16_t xPosPrevious;
    uint8_t yPos;
    uint8_t yPosPrevious;
    uint8_t show;
    int8_t xVelocity;
    int8_t yVelocity;
};

struct player{
    uint16_t xPos;
    uint16_t xPosPrevious;
    uint8_t yPos;
    uint8_t yPosPrevious;
    int8_t lives;
    uint8_t direction;
    uint8_t bulletType;
    int16_t score;
    struct bullet shots[3];
};

struct drawItems{
    uint16_t xStart;
    uint16_t xSlut;
    uint8_t yStart;
    uint8_t ySlut;
    char text;
};

void setWallHitBox(struct drawItems *drawValues, uint16_t mapHitBoxSize);
void checkCollider(struct player *playerHitBox, struct enemy *enemies);
uint8_t objectWallCheck(uint16_t xPos, uint8_t yPos, uint8_t i);
uint8_t enemyCollider(uint16_t objectXPos, uint8_t objectYPos, uint16_t enemyXPos, uint8_t enemyYPos);



#endif
