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
    int8_t xVelocity;
    int8_t yVelocity;
    int8_t lives;
    uint8_t direction;
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
static uint16_t checkColliderLeftToRight(uint16_t xPos, uint16_t xPosPrevious, uint8_t yPos, uint8_t yPosPrevious, int8_t xVelocity, int8_t yVelocity, uint16_t i);
static uint16_t checkColliderRightToLeft(uint16_t xPos, uint16_t xPosPrevious, uint8_t yPos, uint8_t yPosPrevious, int8_t xVelocity, int8_t yVelocity, uint16_t i);
static uint16_t checkColliderTopToBottom(uint16_t xPos, uint16_t xPosPrevious, uint8_t yPos, uint8_t yPosPrevious, int8_t xVelocity, int8_t yVelocity, uint16_t i);
static uint16_t checkColliderBottomToTop(uint16_t xPos, uint16_t xPosPrevious, uint8_t yPos, uint8_t yPosPrevious, int8_t xVelocity, int8_t yVelocity, uint16_t i);
static uint8_t checkColliderXEnemy(uint16_t xPos, uint16_t xPosPrevious, uint8_t yPos, uint8_t yPosPrevious, int8_t xVelocity, int8_t yVelocity, uint16_t enemiesXPos, uint8_t enemiesYPos);
static uint8_t checkColliderYEnemy(uint16_t xPos, uint16_t xPosPrevious, uint8_t yPos, uint8_t yPosPrevious, int8_t xVelocity, int8_t yVelocity, uint16_t enemiesXPos, uint8_t enemiesYPos);



#endif
