/*
**
**                           MainMenu.c
**
**
**********************************************************************/
/*
   Primary editor  :    Martin Kolster
   Secondary editor:    Mathias Jensen
   Last changed by :    19/01 - 2020

   Functions       :    ConstructWindow(struct drawItems *drawValues);
                        ConstructIntroMenu(struct drawItems *drawValues);
                        void clearscr();

**********************************************************************/
//include .h file
#include "MainMenu.h"

//defines
//Symbols
#define ESC 0x1B



void ConstructWindow(struct drawItems *drawValues){
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
            DrawingSetValues(drawValues, Xbegin[i], Ybegin[i], Xstop[i], Ystop[i], charType[i]);
    }
    DrawEverything(drawValues);

    gotoxy(168,19);
        printf(" __  __ ___ ___ ___ ___ ___  _  _ ");
    gotoxy(168,20);
        printf("|  \\/  |_ _/ __/ __|_ _/ _ \\| \\| |");
    gotoxy(168,21);
        printf("| |\\/| || |\\__ \\__ \\| | (_) | .` |");
    gotoxy(168,22);
        printf("|_|  |_|___|___|___|___\\___/|_|\\_|");
    gotoxy(168,29);
        printf("CURRENT MAP LEVEL: ");
    gotoxy(168,32);
        printf("TIME ELAPSED: ");
    gotoxy(168,35);
        printf("MAP 1 TIME: ");
    gotoxy(168,38);
        printf("MAP 2 TIME: ");
    gotoxy(168,41);
        printf("SCORE: ");
    gotoxy(168,44);
        printf("");

    gotoxy(170,71);
        printf(" _____ _____ _____ _____ _____");
    gotoxy(170,72);
        printf("|   __|_   _|  _  |_   _|   __|");
    gotoxy(170,73);
        printf("|__   | | | |     | | | |__   |");
    gotoxy(170,74);
        printf("|_____| |_| |__|__| |_| |_____|");
    gotoxy(168,81);
        printf("HEALTH: ");
    gotoxy(168,84);
        printf("AMMO: ");
    gotoxy(168,87);
        printf("WEAPON: ");
}

void ConstructIntroMenu(struct drawItems *drawValues){
     uint8_t Xbegin[] = {};
     uint8_t Xstop[] = {};
     uint8_t Ybegin[] = {};
     uint8_t Ystop[] = {};
     char charType[] = {};
     for(uint8_t i = 0; i<(sizeof(charType)); i++){
            DrawingSetValues(drawValues, Xbegin[i], Ybegin[i], Xstop[i], Ystop[i], charType[i]);
    }
    DrawEverything(drawValues);
}




void clearscr() {
        printf("%c[%d%c",ESC,2,0x4A);
}




