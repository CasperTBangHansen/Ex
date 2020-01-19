/*
Control.h
*/

#ifndef _CONTROLSYSTEM_H_
#define _CONTROLSYSTEM_H_

#include "Collider.h"
#include "Update.h"
#include <stdint.h>
#include <stdio.h>


uint8_t userInput(struct player *player);
static void setupBullet(struct player *player, int8_t xPosOffSet, int8_t yPosOffSet, int8_t xShotsMaxVelocity, int8_t yShotsMaxVelocity, uint8_t i);


#endif _CONTROLSYSTEM_H_

