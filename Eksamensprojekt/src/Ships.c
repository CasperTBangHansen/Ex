#include <stdio.h>
#include "Ships.h"

void ShipSelection(uint8_t control, uint8_t skin, struct playerPos *playerPos, struct drawItems *drawValues){
char charType[] = {0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};

uint16_t x[] = {(*playerPos).xPosition--,(*playerPos).xPosition,(*playerPos).xPosition++,(*playerPos).xPosition--,(*playerPos).xPosition,(*playerPos).xPosition++,(*playerPos).xPosition--,(*playerPos).xPosition,(*playerPos).xPosition++};
uint8_t y[] = {(*playerPos).yPosition--,(*playerPos).yPosition--,(*playerPos).yPosition--,(*playerPos).yPosition,(*playerPos).yPosition,(*playerPos).yPosition,(*playerPos).yPosition++,(*playerPos).yPosition++,(*playerPos).yPosition++};
//uint8_t x[] = {10,11,12,10,11,12,10,11,12};
//uint8_t y[] = {10,10,10,11,11,11,12,12,12};
if (skin == 1 && control != 0){
    switch (control){
        case 1:{
            charType[0] = 0xFF;
            charType[1] = 0xB3;
            charType[2] = 0xFF;
            charType[3] = 0xB3;
            charType[4] = 0xBA;
            charType[5] = 0xB3;
            charType[6] = 0xC8;
            charType[7] = 0xCA;
            charType[8] = 0xBC;
            break;
        }
        case 2:{
            charType[0] = 0xFF;
            charType[1] = 0xC4;
            charType[2] = 0xBB;
            charType[3] = 0xC4;
            charType[4] = 0xCD;
            charType[5] = 0xB9;
            charType[6] = 0xFF;
            charType[7] = 0xC4;
            charType[8] = 0xBC;
            break;
        }
        case 3:{
            charType[0] = 0xC9;
            charType[1] = 0xCB;
            charType[2] = 0xBB;
            charType[3] = 0xB3;
            charType[4] = 0xBA;
            charType[5] = 0xB3;
            charType[6] = 0xFF;
            charType[7] = 0xB3;
            charType[8] = 0xFF;
            break;
        }
        case 4:{
            charType[0] = 0xC9;
            charType[1] = 0xC4;
            charType[2] = 0xFF;
            charType[3] = 0xCC;
            charType[4] = 0xCD;
            charType[5] = 0xC4;
            charType[6] = 0xC8;
            charType[7] = 0xC4;
            charType[8] = 0xFF;
            break;
        }
        default:{
            break;
        }
    }

    // Draw it all
    if(charType[4] != 0xFF){
        for(uint8_t i = 0; i<=(8); i++){
            DrawingSetValues(drawValues, x[i], y[i], x[i], y[i], charType[i]);
        }
        DrawEverything(drawValues);
    }
}

if (skin == 2 && control != 0){
    switch (control){
        case 1:{
            charType[0] = 0xFF;
            charType[1] = 0xBA;
            charType[2] = 0xFF;
            charType[3] = 0xCC;
            charType[4] = 0xCA;
            charType[5] = 0xB9;
            charType[6] = 0xBA;
            charType[7] = 0xFF;
            charType[8] = 0xBA;
            break;
        }
        case 2:{
            charType[0] = 0xFF;
            charType[1] = 0xCB;
            charType[2] = 0xCD;
            charType[3] = 0xCD;
            charType[4] = 0xB9;
            charType[5] = 0xFF;
            charType[6] = 0xFF;
            charType[7] = 0xCA;
            charType[8] = 0xCD;
            break;
        }
        case 3:{
            charType[0] = 0xBA;
            charType[1] = 0xFF;
            charType[2] = 0xBA;
            charType[3] = 0xCC;
            charType[4] = 0xCB;
            charType[5] = 0xB9;
            charType[6] = 0xFF;
            charType[7] = 0xBA;
            charType[8] = 0xFF;
            break;
        }
        case 4:{
            charType[0] = 0xCD;
            charType[1] = 0xCB;
            charType[2] = 0xFF;
            charType[3] = 0xFF;
            charType[4] = 0xCC;
            charType[5] = 0xCD;
            charType[6] = 0xCD;
            charType[7] = 0xCA;
            charType[8] = 0xFF;
            break;
        }
        default:
            break;
    }

    // Draw it all
    if(charType[4] != 0xFF){
        for(uint8_t i = 0; i<=(8); i++){
            DrawingSetValues(drawValues, x[i], y[i], x[i], y[i], charType[i]);
        }
    DrawEverything(drawValues);
    }

}

    if (skin == 3 && control != 0){
    switch (control){
        case 1:{
            charType[0] = 0xB3;
            charType[1] = 0xFF;
            charType[2] = 0xB3;
            charType[3] = 0xCC;
            charType[4] = 0x4F;
            charType[5] = 0xB9;
            charType[6] = 0xB3;
            charType[7] = 0xFF;
            charType[8] = 0xB3;
            break;
        }
        case 2:{
            charType[0] = 0xC4;
            charType[1] = 0xCB;
            charType[2] = 0xC4;
            charType[3] = 0xFF;
            charType[4] = 0x4F;
            charType[5] = 0xFF;
            charType[6] = 0xC4;
            charType[7] = 0xCA;
            charType[8] = 0xC4;
            break;
        }
        case 3:{
            charType[0] = 0xB3;
            charType[1] = 0xFF;
            charType[2] = 0xB3;
            charType[3] = 0xCC;
            charType[4] = 0x4F;
            charType[5] = 0xB9;
            charType[6] = 0xB3;
            charType[7] = 0xFF;
            charType[8] = 0xB3;
            break;
        }
        case 4:{
            charType[0] = 0xC4;
            charType[1] = 0xCB;
            charType[2] = 0xC4;
            charType[3] = 0xFF;
            charType[4] = 0x4F;
            charType[5] = 0xFF;
            charType[6] = 0xC4;
            charType[7] = 0xCA;
            charType[8] = 0xC4;
            break;
        }
        default:
            break;
    }

    // Draw it all
    if(charType[4] != 0xFF){
        for(uint8_t i = 0; i<=(8); i++){
            DrawingSetValues(drawValues, x[i], y[i], x[i], y[i], charType[i]);
        }
    DrawEverything(drawValues);
    }
}
    if (skin != 1 && skin != 2 && skin !=3){
    skin = 1;
}
}

