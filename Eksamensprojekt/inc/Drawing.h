#ifndef _DRAWING_H_
#define _DRAWING_H_

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

struct drawItems{
    uint16_t xStart;
    uint16_t xSlut;
    uint8_t yStart;
    uint8_t ySlut;
    char text;
};

void DrawingSetValues(struct drawItems *drawValues, uint16_t xPosStart, uint8_t yPosStart, uint16_t xPosSlut, uint8_t yPosslut, char character);
void DrawEverything(struct drawItems *drawValues);
#endif
