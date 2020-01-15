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
    uint16_t Xbegin[] = {10,10,160,10,10,160,10,160,161,200,161,200,200,163,163,163,197,160,200,161,163,163,163,197};
    uint16_t Xstop[] = {160,10,160,160,10,160,10,160,200,200,200,200,200,163,197,197,197,160,200,199,163,197,197,197};

    uint8_t Ybegin[] = {5,5,5,55,5,5,55,55,5,5,55,5,55,7,7,11,7,31,31,31,33,33,37,33};
    uint8_t Ystop[] = {5,55,55,55,5,5,55,55,5,55,55,5,55,11,7,11,11,31,31,31,37,33,37,37};


    char CharType[] = {0xC4,0xB3,0xB3,0xC4,0xDA,0xC2,0xC0,0xC1,0xC4,0xB3,0xC4,0xBF,0xD9,0xB1,0xB1,0xB0,0xB0,0xC3,0xB4,0xC4,0xB1,0xB1,0xB0,0xB0};

    for(uint8_t i = 0; i<(sizeof(CharType)); i++){
            DrawingSetValues(&drawValues, Xbegin[i], Ybegin[i], Xstop[i], Ystop[i], CharType[i]);
    }
    DrawEverything(&drawValues);
    gotoxy(172,9);
    printf("MISSION DETAILS");
    gotoxy(163,13);
    printf("Current Level: ");
    gotoxy(163,15);
    printf("Lives Left: ");
    gotoxy(163,17);
    printf("Score: ");
    gotoxy(163,19);
    printf("Total Time: ");
    gotoxy(163,21);
    printf("Split Time 1: ");
    gotoxy(163,23);
    printf("Split Time 2: ");
    gotoxy(163,25);
    printf("Split Time 3: ");
    gotoxy(163,27);
    printf("Split Time 4: ");
    gotoxy(163,29);
    printf("Split Time 5: ");
    gotoxy(172,35);
    printf("INVENTORY");
    gotoxy(163,39);
    printf("Current Ship Type: ");
    gotoxy(163,41);
    printf("Current Weapon: ");
    gotoxy(163,43);
    printf("Key Status: ");
}

void ConstructIntroMenu(){
    struct drawItems drawValues[1000];
    uint8_t Xbegin[] = {24,25,26,41,42,43,27,28,29,30,31,32,33,34,35,36,37,38,39,40, // M
    50,50,53,54,55,50,50, // I
    65,65,65,66,67,65,65,74,75,76,65,65, // S
    83,83,83,84,85,83,83,92,93,94,83,83, // S
    101,101,104,105,106,101,101, // I
    115,115,115,115,115,116,117,123,124,125, // O
    131,132,133,134,135,136,137,138,139,140,141,142,143,144, // N
    40,41,42,43,43,51,52,53, // 4
    59,59,70,71,72,59,59,59,60,61,62,62, // 2
    78,79,80,81,81,81,81,89,90,91, // 0
    97,98,99,100,100,100,100,100,100,108,109,110, // 6
    116,117,118,119,119,119,119,116,116,127,128,129}; // 9
    uint8_t Xstop[] = {24,25,26,41,42,43,27,28,29,30,31,32,33,34,35,36,37,38,39,40, // M
    58,58,53,54,55,58,58, // I
    76,76,65,66,67,76,76,74,75,76,76,76, // S
    94,94,83,84,85,94,94,92,93,94,94,94, // S
    109,109,104,105,106,109,109, // I
    125,125,125,125,115,116,117,123,124,125, // O
    131,132,133,134,135,136,137,138,139,140,141,142,143,144, // N
    40,41,42,50,50,51,52,53, // 4
    72,72,70,71,72,72,72,59,60,61,72,72, // 2
    78,79,80,88,88,88,88,89,90,91, // 0
    97,98,99,110,110,110,110,110,110,108,109,110, // 6
    116,117,118,129,129,129,129,129,129,127,128,129}; // 9

    uint8_t Ybegin[] = {10,10,10,10,10,10,11,11,12,12,13,13,14,14,13,13,12,12,11,11, // M
    10,11,10,10,10,19,20, // I
    10,11,10,10,10,14,15,16,16,16,19,20, // S
    10,11,10,10,10,14,15,16,16,16,19,20, // S
    10,11,10,10,10,19,20, // I
    10,11,19,20,10,10,10,10,10,10, // O
    10,10,10,11,12,13,14,15,16,17,18,10,10,10, // N
    23,23,23,27,28,23,23,23, // 4
    23,24,25,25,25,27,28,29,29,29,32,33, // 2
    23,23,23,23,24,32,33,23,23,23, // 0
    23,23,23,23,24,27,28,32,33,29,29,29, // 6
    23,23,23,23,24,27,28,32,33,23,23,23}; // 9
    uint8_t Ystop[] = {20,20,20,20,20,20,12,12,13,13,14,14,15,15,14,14,13,13,12,12, // M
    10,11,20,20,20,19,20, // I
    10,11,14,14,14,14,15,20,20,20,19,20, // S
    10,11,14,14,14,14,15,20,20,20,19,20, // S
    10,11,20,20,20,19,20, // I
    10,11,19,20,20,20,20,20,20,20, // O
    20,20,20,12,13,14,15,16,17,18,19,20,20,20, // N
    28,28,28,27,28,33,33,33, // 4
    23,24,28,28,28,27,28,33,33,33,32,33, // 2
    33,33,33,23,24,32,33,33,33,33, // 0
    33,33,33,23,24,27,28,32,33,31,31,31, // 6
    28,28,28,23,24,27,28,32,33,33,33,33}; // 9


    char CharType = 0xDB;


    for(uint8_t i = 0; i<(sizeof(Ystop)); i++){
            DrawingSetValues(&drawValues, Xbegin[i], Ybegin[i], Xstop[i], Ystop[i], CharType);
    }
    DrawEverything(&drawValues);
}


/*void clearscr() {
        printf("%c[%d%c",ESC,2,0x4A);
}*/

