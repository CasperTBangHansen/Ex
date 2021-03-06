/*
Control.h
*/

#ifndef _MANAGELEVELS_H_
#define _MANAGELEVELS_H_

#include <stdint.h>
#include <stdio.h>
#include "MapPack.h"
#include "Timer.h"

struct mapPackage {
    uint8_t mapChoice;
};

void LevelManager(struct mapPackage *maps, struct drawItems *drawValues, struct player *player, struct enemy *enemies, uint8_t drawMap, struct powerUp *powerUp, struct wallHitBox *wallHitBox);
uint8_t setupLevel(struct mapPackage *maps, struct drawItems *drawValues, struct player *player, struct enemy *enemy, uint8_t drawMap, struct powerUp *powerUp, struct wallHitBox *wallHitBox, uint8_t ship);

#endif

