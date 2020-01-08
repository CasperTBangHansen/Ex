#include <stdint.h>;
#include <stdio.h>;

//define header
#ifndef _printing_H_
#define _printing_H_

//define functions
void clearscr();
void clreol();
void gotoxy(uint8_t x, uint8_t y);
void underline(uint8_t on);
void blink(uint8_t on);
void inverse(uint8_t on);

//end header
#endif
