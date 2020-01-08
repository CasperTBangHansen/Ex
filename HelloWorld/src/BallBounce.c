
#include "BallBounce.h"

void initalizerWindow(struct windowSize *win, uint8_t x1Val, uint8_t y1Val, uint8_t x2Val, uint8_t y2Val, char titleVal[], uint8_t styleVal){
    uint8_t X1 = x1Val, X2 = x2Val, Y1 = y1Val, Y2 = y2Val;
    if(y1Val>=y2Val){
        Y1 = y2Val;
        Y2 = y1Val;
    }
    if(x1Val>=x2Val){
        X1 = x2Val;
        X2 = x1Val;
    }
    x1Val = X1;
    x2Val = X2;
    y1Val = Y1;
    y2Val = Y2;

    win->x1 = x1Val;
    win->y1 = y1Val;
    win->x2 = x2Val;
    win->y2 = y2Val;
    for(uint8_t i = 0; i<10;i++){
        win->title[i] = titleVal[i];
    }
    win->style = styleVal;
}


void initalizerBallBounce(struct windowSize *win){
    clearscr();
    window((*win).x1, (*win).y1, (*win).x2, (*win).y2, (*win).title, (*win).style);
}

void InitBallPosition(struct ball *v, uint8_t Xstart, uint8_t Ystart, int8_t XdirStart, int8_t YdirStart)
{
 gotoxy(Xstart,Ystart);
 v->Xposition = Xstart;
 v->Yposition = Ystart;
 v->Xdir = XdirStart;
 v->Ydir = YdirStart;
 v->counter = 0;
 printf("%c%c",0x7f,111);
}

void BallMovement(struct ball *ballstruct)
{
    int8_t Xpos = (*ballstruct).Xposition;
    int8_t Ypos = (*ballstruct).Yposition;
    gotoxy(Xpos,Ypos);
    printf("%c%c",0x7f,0);
    Xpos = (Xpos + (*ballstruct).Xdir);
    Ypos = (Ypos + (*ballstruct).Ydir);
    gotoxy(Xpos, Ypos);
    printf("%c%c",0x7f,111);
    ballstruct->Xposition = Xpos;
    ballstruct->Yposition= Ypos;
}

void colider(struct windowSize *win, struct ball *ballstruct){
    if((*win).x1+2 == (*ballstruct).Xposition || (*win).x2-1 == (*ballstruct).Xposition){
        ballstruct->Xdir = (*ballstruct).Xdir*(-1);
        (*ballstruct).counter++;
        gotoxy(1,(*win).y2+2);
        printf("%s%d","Counter: ",(*ballstruct).counter);
    }
    if((*win).y1+1 == (*ballstruct).Yposition || (*win).y2-1 == (*ballstruct).Yposition){
        ballstruct->Ydir = (*ballstruct).Ydir*(-1);
        (*ballstruct).counter++;
        gotoxy(1,(*win).y2+2);
        printf("%s%d","Counter: ",(*ballstruct).counter);
    }
}


void update(struct windowSize *win, struct ball *ballstruct){
    for(uint8_t i = 0; i<10000; i++){
        colider(win,ballstruct);
        BallMovement(ballstruct);
    }
}
