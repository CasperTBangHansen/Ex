#include <stdint.h>;
#include <stdio.h>;

//define header
#ifndef _BALLBOUNCE_H_
#define _BALLBOUNCE_H_

//define functions
struct windowSize{
    int32_t x1;
    int32_t y1;
    int32_t x2;
    int32_t y2;
    char title[9];
    int32_t style;
};

struct ball{
    uint8_t Xposition;
    uint8_t Yposition;
    int8_t Xdir;
    int8_t Ydir;
};




void initalizerWindow(struct windowSize *win, uint8_t x1Val, uint8_t y1Val, uint8_t x2Val, uint8_t y2Val, char titleVal[], uint8_t styleVal);
void initalizerBallBounce(struct windowSize win);
void initalizerBall(struct ball *ballstruct);
void colider(struct windowSize win, struct ball *ballstruct, struct ball ballVall);
void update();

//end header
#endif
