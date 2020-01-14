#include "30010_io.h"
#include "stm32f30x_conf.h"
#include "MainMenu.h"
#include <stdio.h>
#include "Drawing.h"
#define ESC 0x1B

/*
@@@@@@@@@@@@@@@@@@@@@@ MAIN @@@@@@@@@@@@@@@@@@@@@@@
#include "stm32f30x_conf.h"
#include "30010_io.h"
#include "Timer.h"
#include <stdio.h>
#include "Drawing.h"
#include "MainMenu.h"

int main(void)
{
    uart_init( 115200 );
    clearscr();
    ConstructWindow();
    ConstructIntroMenu();
    while(1){}
}
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
*/

void ConstructWindow(){
    struct drawItems drawValues[1000];
     // Arrays for maps. First 4 are game window outline in order (Top,left,right,bottom).
     // Next 4 are the different game window corners, in the order (Top left, Top right, Bottom left, Bottom Right)
     // Next 3 are are the lines for the high score window (Top, Right, Bottom)
     // Next 2 are the top right corner and then bottom right corner
    int Xbegin[] = {10,10,160,10,10,160,10,160,161,200,161,200,200,163,163,163,197};
    int Xstop[] = {160,10,160,160,10,160,10,160,200,200,200,200,200,163,197,197,197};

    int Ybegin[] = {5,5,5,55,5,5,55,55,5,5,55,5,55,7,7,11,7};
    int Ystop[] = {5,55,55,55,5,5,55,55,5,55,55,5,55,11,7,11,11};


    char CharType[100] = {0xC4,0xB3,0xB3,0xC4,0xDA,0xC2,0xC0,0xC1,0xC4,0xB3,0xC4,0xBF,0xD9,0xB1,0xB1,0xB0,0xB0};

    for(int i = 0; i<(100); i++){
            DrawingSetValues(&drawValues, Xbegin[i], Ybegin[i], Xstop[i], Ystop[i], CharType[i]);
    }
    DrawEverything(&drawValues);
    gotoxy(172,9);
    uint8_t HISCORE = 132;
    printf("MISSION DETAILS");
}

void ConstructIntroMenu(){
    struct drawItems drawValues[1000];
    int Xbegin[] = {24,25,26,41,42,43,27,28,29,30,31,32,33,34,35,36,37,38,39,40,
    50,50,53,54,55,50,50,
    65,65,65,66,67,65,65,74,75,76,65,65,
    83,83,83,84,85,83,83,92,93,94,83,83,
    101,101,104,105,106,101,101,
    115,115,115,115,115,116,117,123,124,125,
    131,132,133,134,135,136,137,138,139,140,141,142,143,144};
    int Xstop[] = {24,25,26,41,42,43,27,28,29,30,31,32,33,34,35,36,37,38,39,40,
    58,58,53,54,55,58,58,
    76,76,65,66,67,76,76,74,75,76,76,76,
    94,94,83,84,85,94,94,92,93,94,94,94,
    109,109,104,105,106,109,109,
    125,125,125,125,115,116,117,123,124,125,
    131,132,133,134,135,136,137,138,139,140,141,142,143,144};

    int Ybegin[] = {14,14,14,14,14,14,15,15,16,16,17,17,18,18,17,17,16,16,15,15,
    14,15,14,14,14,23,24,
    14,15,14,14,14,18,19,20,20,20,23,24,
    14,15,14,14,14,18,19,20,20,20,23,24,
    14,15,14,14,14,23,24,
    14,15,23,24,14,14,14,14,14,14,
    14,14,14,15,16,17,18,19,20,21,22,14,14,14};
    int Ystop[] = {24,24,24,24,24,24,16,16,17,17,18,18,19,19,18,18,17,17,16,16,
    14,15,24,24,24,23,24,
    14,15,18,18,18,18,19,24,24,24,23,24,
    14,15,18,18,18,18,19,24,24,24,23,24,
    14,15,24,24,24,23,24,
    14,15,23,24,24,24,24,24,24,24,
    24,24,24,16,17,18,19,20,21,22,23,24,24,24};


    char CharType[100] = {0xDB,0xDB,0xDB,0xDB,0xDB,0xDB,0xDB,0xDB,0xDB,0xDB,0xDB,0xDB,0xDB,0xDB,0xDB,0xDB,0xDB,0xDB,0xDB,0xDB,
    0xDB,0xDB,0xDB,0xDB,0xDB,0xDB,0xDB,
    0xDB,0xDB,0xDB,0xDB,0xDB,0xDB,0xDB,0xDB,0xDB,0xDB,0xDB,0xDB,
    0xDB,0xDB,0xDB,0xDB,0xDB,0xDB,0xDB,0xDB,0xDB,0xDB,0xDB,0xDB,
    0xDB,0xDB,0xDB,0xDB,0xDB,0xDB,0xDB,
    0xDB,0xDB,0xDB,0xDB,0xDB,0xDB,0xDB,0xDB,0xDB,0xDB,
    0xDB,0xDB,0xDB,0xDB,0xDB,0xDB,0xDB,0xDB,0xDB,0xDB,0xDB,0xDB,0xDB,0xDB};

    for(int i = 0; i<(100); i++){
            DrawingSetValues(&drawValues, Xbegin[i], Ybegin[i], Xstop[i], Ystop[i], CharType[i]);
    }
    DrawEverything(&drawValues);
}


void clearscr() {
        printf("%c[%d%c",ESC,2,0x4A);
}

