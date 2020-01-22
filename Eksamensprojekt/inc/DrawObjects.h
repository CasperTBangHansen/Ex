#ifndef _DRAWOBJECTS_H_
#define _DRAWOBJECTS_H_

#include "Collider.h"
#include "Update.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>


void drawMovingObjects(uint8_t enemySize, uint8_t moveDirection, struct drawItems *drawValues, struct player *player, struct enemy *enemy, uint8_t ship);
void drawEnemy(uint8_t control, uint16_t xPos, uint8_t yPos, uint16_t xPPos, uint8_t yPPos, struct drawItems *drawValues);

#endif
