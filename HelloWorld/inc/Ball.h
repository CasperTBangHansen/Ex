#include <stdint.h>;
#include <stdio.h>;
#include <time.h>;

#ifndef _BALL_H_
#define _BALL_H_

struct ball{
 uint8_t Xposition;
 uint8_t Yposition;
 int8_t Xdir;
 int8_t Ydir;
};

void InitBallPosition(struct ball *v, uint8_t Xstart, uint8_t Ystart);
void BallMovement(struct ball *v);


#endif

