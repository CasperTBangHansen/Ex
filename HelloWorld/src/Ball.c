#include <stdio.h>
#include "Ball.h"
#include "Ex22.h"
#include <time.h>
#include <stdlib.h>

void InitBallPosition(struct ball *v, uint8_t Xstart, uint8_t Ystart)
{
 gotoxy(Xstart,Ystart);
 v->Xposition = Xstart;
 v->Yposition = Ystart;
 v->Xdir = -1;
 v->Ydir = -1;
 printf("%c%c",0x7f,111);
}


void BallMovement(struct ball *v)
{
    uint8_t Xpos = (*v).Xposition;
    uint8_t Ypos = (*v).Yposition;
    gotoxy(Xpos,Ypos);
    printf("%c%c",0x7f,0);
    Xpos = (Xpos + (*v).Xdir);
    Ypos = (Ypos + (*v).Ydir);
    gotoxy(Xpos, Ypos);
    printf("%c%c",0x7f,111);
    v->Xposition = Xpos;
    v->Yposition= Ypos;
}
