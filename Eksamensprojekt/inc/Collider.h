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
    uint8_t lives;
    struct bullet shots[3];
};

void initEverything(struct player *player, struct enemy *enemy);
void setWallHitBox(struct drawItems *drawValues, uint16_t mapHitBoxSize);
int16_t getWallHitBoxSize();
void getWallHitBox(struct mapHitBox *mapCollider);
void checkCollider(struct player *playerHitBox, struct enemy *enemies);
static uint16_t checkColliderLeftToRight(uint16_t xPos, uint16_t xPosPrevious, uint8_t yPos, uint8_t yPosPrevious, int8_t xVelocity, int8_t yVelocity, uint16_t i);
static uint16_t checkColliderRightToLeft(uint16_t xPos, uint16_t xPosPrevious, uint8_t yPos, uint8_t yPosPrevious, int8_t xVelocity, int8_t yVelocity, uint16_t i);
static uint16_t checkColliderTopToBottom(uint16_t xPos, uint16_t xPosPrevious, uint8_t yPos, uint8_t yPosPrevious, int8_t xVelocity, int8_t yVelocity, uint16_t i);
static uint16_t checkColliderBottomToTop(uint16_t xPos, uint16_t xPosPrevious, uint8_t yPos, uint8_t yPosPrevious, int8_t xVelocity, int8_t yVelocity, uint16_t i);
static uint8_t checkColliderXEnemy(uint16_t xPos, uint16_t xPosPrevious, uint8_t yPos, uint8_t yPosPrevious, int8_t xVelocity, int8_t yVelocity, uint16_t enemiesXPos, uint8_t enemiesYPos);
static uint8_t checkColliderYEnemy(uint16_t xPos, uint16_t xPosPrevious, uint8_t yPos, uint8_t yPosPrevious, int8_t xVelocity, int8_t yVelocity, uint16_t enemiesXPos, uint8_t enemiesYPos);



#endif
