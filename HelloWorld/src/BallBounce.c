
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


void initalizerBallBounce(struct windowSize win){
    clearscr();
    window(win.x1, win.y1, win.x2, win.y2,win.title, win.style);
}
void initalizerBall(struct ball *ballstruct){
    ballstruct->Xposition = 8;
    ballstruct->Yposition = 10;
    ballstruct->Xdir = 1;
    ballstruct->Xdir = 1;
}


void colider(struct windowSize win, struct ball *ballstruct, struct ball ballVall){
    if(win.x1+1 == ballVall.Xposition || win.x2-1 == ballVall.Xposition){
        ballstruct->Xdir = ballVall.Xdir*(-1);
    }
    if(win.y1+1 == ballVall.Yposition || win.y2-1 == ballVall.Yposition){
        ballstruct->Ydir = ballVall.Ydir*(-1);
    }
}


void update(){

}
