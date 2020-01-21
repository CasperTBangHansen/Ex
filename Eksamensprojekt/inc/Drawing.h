#ifndef _DRAWING_H_
#define _DRAWING_H_

#include "Collider.h"
#include "Update.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>


void DrawingSetValues(struct drawItems *drawValues, uint16_t xPosStart, uint8_t yPosStart, uint16_t xPosSlut, uint8_t yPosSlut, char character);
void DrawEverything(struct drawItems *drawValues);
uint16_t SetPos(uint8_t status);
void gotoxy(uint16_t x, uint8_t y);

#endif
