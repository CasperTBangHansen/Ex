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
    uint16_t Xbegin[] = {
    15,15,15,205, // Outer window
    15,15,205,205, //Corners outer window
    165,165,165, // Line between game window and score
    167,167,167,203, // Outline for score title
    167,167,167,203, // Outline for inventory title
    165,165,205 // Line between inventory and score
    };
    uint16_t Xstop[] = {
    205,205,15,205,
    15,15,205,205,
    165,165,165,
    203,203,167,203,
    203,203,167,203,
    205,165,205

    };
    uint8_t Ybegin[] = {
    15,115,15,15,
    15,115,15,115,
    15,15,115,
    17,25,17,17,
    69,77,69,69,
    67,67,67
    };
    uint8_t Ystop[] = {
    15,115,115,115,
    15,115,15,115,
    115,15,115,
    17,25,25,25,
    69,77,77,77,
    67,67,67

    };

     // HEX CODES FOR WALLS IN GAME
     // Horizontal 0xCD
     // Vertical 0xBA
     // top left 0xC9
     // top right 0xBB
     // bottom right 0xBC
     // bottom left 0xC8
    char charType[] = {
    0xCD,0xCD,0xBA,0xBA,
    0xC9,0xC8,0xBB,0xBC,
    0xBA,0xCB,0xCA,
    0xB0,0xB0,0xB0,0xB0,
    0xB0,0xB0,0xB0,0xB0,
    0xCD,0xCC,0xB9


    };
    for(uint8_t i = 0; i<(sizeof(charType)); i++){
            DrawingSetValues(&drawValues, Xbegin[i], Ybegin[i], Xstop[i], Ystop[i], charType[i]);
    }
    DrawEverything(&drawValues);

}

void ConstructIntroMenu(){
     struct drawItems drawValues[1000];
     uint8_t Xbegin[] = {};
     uint8_t Xstop[] = {};
     uint8_t Ybegin[] = {};
     uint8_t Ystop[] = {};
     char charType[] = {};
     for(uint8_t i = 0; i<(sizeof(charType)); i++){
            DrawingSetValues(&drawValues, Xbegin[i], Ybegin[i], Xstop[i], Ystop[i], charType[i]);
    }
    DrawEverything(&drawValues);
}




void clearscr() {
        printf("%c[%d%c",ESC,2,0x4A);
}




