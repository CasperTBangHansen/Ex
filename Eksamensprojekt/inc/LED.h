#ifndef _LED_H_
#define _LED_H_

#include "Collider.h"
#include "Timer.h"
#include "stm32f30x_conf.h"
#include "30010_io.h"
#include <stdint.h>
#include <stdio.h>

void GameLED(uint8_t tal);
void setRedLED(struct player *player, uint8_t preLives);


#endif _LED_H_
