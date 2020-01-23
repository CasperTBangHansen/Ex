#ifndef _DRAWOBJECTS_H_
#define _DRAWOBJECTS_H_

#include "Timer.h"
#include "Collider.h"
#include "Update.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>


void drawMovingObjects(uint8_t enemySize, uint8_t moveDirection, struct drawItems *drawValues, struct player *player, struct enemy *enemy, uint8_t ship, struct powerUp *powerUp);
void drawEnemy(uint8_t control, struct enemy *enemy, struct drawItems *drawValues, uint8_t i);
void removeEnemy(struct enemy *enemy, struct drawItems *drawValues);
void playerKilled(struct enemy *enemy, struct player *player ,struct drawItems *drawValues, uint8_t preLives);

#endif
