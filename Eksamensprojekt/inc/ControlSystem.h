/*
Control.h
*/

#ifndef _CONTROLSYSTEM_H_
#define _CONTROLSYSTEM_H_

#include <stdint.h>
#include <stdio.h>

struct playerPos{
uint16_t xPosition;
uint8_t yPosition;
};

void gotoxy(uint16_t x, uint8_t y);
void InitPosition(uint16_t xPos, uint8_t yPos, struct playerPos *here);
uint8_t UserInput();
void Controller(int8_t moveDir, struct playerPos *there);

#endif _CONTROLSYSTEM_H_

