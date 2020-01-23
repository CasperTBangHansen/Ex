#ifndef _UPDATEUI_H_
#define _UPDATEUI_H_

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void upDateHealth(uint8_t lives);
void upDateWeapon(uint8_t activeWeapon);
void upDateScore(int32_t playerScore);
void upDateHighScore(int32_t highscore, uint8_t resetCurrentScore);


#endif

