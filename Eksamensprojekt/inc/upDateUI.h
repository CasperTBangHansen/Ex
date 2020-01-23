#ifndef _UPDATEUI_H_
#define _UPDATEUI_H_

#include "Collider.h"
#include "ManageLevels.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void upDateHealth(uint8_t lives);
void upDateWeapon(uint8_t activeWeapon);
void upDateScore(int32_t playerScore);
void upDateHighScore(int32_t highscore, uint8_t resetCurrentScore);
void maxMinScore(struct player *player);
void upDateCurrentLevel(struct mapPackage *maps);
void upDateTimer(struct mapPackage *maps);
void endScreenScore(struct player *player, struct drawItems *drawValues, int32_t *highscore);
void upDateUIEveryTick(struct player *player, struct mapPackage *maps);


#endif

