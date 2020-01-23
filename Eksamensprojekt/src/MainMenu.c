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

   Functions       :    Everything in here is DRAW functions. they only
   draw various elements. There is 3 kind of draw functions.

   The 3 draw functions :

   1. Go to (x,y) and printf.

   2. Draw lines from an array with xStart, Xend, Ystart and Yend and a
   character Hex number.

   3. A for loop which creates an array. This is ONLY used to create a
   clear function to clear a certain area of the screen for prints.

**********************************************************************/
//include .h file
#include "MainMenu.h"

//defines
//Symbols
#define ESC 0x1B

//Main Window

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
        printf("MAP 3 TIME: ");

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
        printf("WEAPON: ");
    gotoxy(168,87);
        printf("Score: ");
    gotoxy(168,90);
        printf("High score: ");
}



//Construct pure text

void ConstructTitle(){
        gotoxy(40,25);
        printf(" .oooooo..o ooooooooooooo       .o.       ooooooooo.         .oooooo.   ooooooooo.    .oooooo..o ");
        gotoxy(40,26);
        printf("d8P'    `Y8 8'   888   `8      .888.      `888   `Y88.      d8P'  `Y8b  `888   `Y88. d8P'    `Y8 ");
        gotoxy(40,27);
        printf("Y88bo.           888          .8'888.      888   .d88'     888      888  888   .d88' Y88bo.      ");
        gotoxy(40,28);
        printf(" `'Y8888o.       888         .8' `888.     888ooo88P'      888      888  888ooo88P'   `'Y8888o.  ");
        gotoxy(40,29);
        printf("     `'Y88b      888        .88ooo8888.    888`88b.        888      888  888              `'Y88b ");
        gotoxy(40,30);
        printf("oo     .d8P      888       .8'     `888.   888  `88b.      `88b    d88'  888         oo     .d8P ");
        gotoxy(40,31);
        printf("8''88888P'      o888o     o88o     o8888o o888o  o888o      `Y8bood8P'  o888o        8''88888P'  ");
        gotoxy(55,35);
        printf("        a8    ad888888b,    ,a888a,      ad8888ba,  ad88888ba  ");
        gotoxy(55,36);
        printf("      ,d88   d8'     '88  ,8P'' `'Y8,   8P'    'Y8 d8'     '88 ");
        gotoxy(55,37);
        printf("     a8P88            88 ,8P       Y8, d8          88       88 ");
        gotoxy(55,38);
        printf("   ,d8' 88           d8P 88         88 88          88       88 ");
        gotoxy(55,39);
        printf("  a8P'  88          a8P  88         88 88,dd888bb, Y8,    ,d88 ");
        gotoxy(55,40);
        printf(",d8'    88        ,d8P   88         88 88P'    `8b  'PPPPPP'88 ");
        gotoxy(55,41);
        printf("888888888888    ,d8P'    88         88 88       88          88 ");
        gotoxy(55,42);
        printf("        88    ,d8P'      `8b       d8' 88       88          8P ");
        gotoxy(55,43);
        printf("        88   a88'         `8ba, ,ad8'  88a     a8P 8b,    a8P  ");
        gotoxy(55,44);
        printf("        88   88888888888    'Y888P'     'Y88888P'  `'Y8888P'   ");
}

void ConstructGoodLuck(){
    gotoxy(50,90);
    printf("  #####   #######  #######  ######       #        #     #   #####   #    # ");
    gotoxy(50,91);
    printf(" #     #  #     #  #     #  #     #      #        #     #  #     #  #   #  ");
    gotoxy(50,92);
    printf(" #        #     #  #     #  #     #      #        #     #  #        #  #   ");
    gotoxy(50,93);
    printf(" #  ####  #     #  #     #  #     #      #        #     #  #        ###    ");
    gotoxy(50,94);
    printf(" #     #  #     #  #     #  #     #      #        #     #  #        #  #   ");
    gotoxy(50,95);
    printf(" #     #  #     #  #     #  #     #      #        #     #  #     #  #   #  ");
    gotoxy(50,96);
    printf("  #####   #######  #######  ######       #######   #####    #####   #    #");

}



//Construct Menu

void ConstructMainMenu(){

    gotoxy(50,60);
    printf(" ######   #           #     #     #       #####      #     #     #  ####### ");
    gotoxy(50,61);
    printf(" #     #  #          # #     #   #       #     #    # #    ##   ##  #   ");
    gotoxy(50,62);
    printf(" #     #  #         #   #     # #        #         #   #   # # # #  #    ");
    gotoxy(50,63);
    printf(" ######   #        #     #     #         #  ####  #     #  #  #  #  #####   ");
    gotoxy(50,64);
    printf(" #        #        #######     #         #     #  #######  #     #  #     ");
    gotoxy(50,65);
    printf(" #        #        #     #     #         #     #  #     #  #     #  #   ");
    gotoxy(50,66);
    printf(" #        #######  #     #     #          #####   #     #  #     #  ####### ");


    gotoxy(50,77);
    printf(" #     # ####### #     #   ####### #######   ######  #          #    #     # ");
    gotoxy(50,78);
    printf(" #     # #     # #  #  #      #    #     #   #     # #         # #    #   #  ");
    gotoxy(50,79);
    printf(" #     # #     # #  #  #      #    #     #   #     # #        #   #    # #  ");
    gotoxy(50,80);
    printf(" ####### #     # #  #  #      #    #     #   ######  #       #     #    #  ");
    gotoxy(50,81);
    printf(" #     # #     # #  #  #      #    #     #   #       #       #######    #    ");
    gotoxy(50,82);
    printf(" #     # #     # #  #  #      #    #     #   #       #       #     #    #   ");
    gotoxy(50,83);
    printf(" #     # #######  ## ##       #    #######   #       ####### #     #    #  ");


    gotoxy(53,94);
    printf("  #####   #######  #######  #######  ###  #     #   #####    #####  ");
    gotoxy(53,95);
    printf(" #     #  #           #        #      #   ##    #  #     #  #     # ");
    gotoxy(53,96);
    printf(" #        #           #        #      #   # #   #  #        #       ");
    gotoxy(53,97);
    printf("  #####   #####       #        #      #   #  #  #  #  ####   #####  ");
    gotoxy(53,98);
    printf("       #  #           #        #      #   #   # #  #     #        # ");
    gotoxy(53,99);
    printf(" #     #  #           #        #      #   #    ##  #     #  #     # ");
    gotoxy(53,100);
    printf("  #####   #######     #        #     ###  #     #   #####    #####  ");
}

void ConstructHowToPlayMenu(struct drawItems *drawValues){
     uint8_t Xbegin[] = {20,20,20,160};
     uint8_t Xstop[] = {20,160,160,160};
     uint8_t Ybegin[] = {50,50,110,50};
     uint8_t Ystop[] = {110,50,110,110};
     char charType[] = {0xB0,0xB0,0xB0,0xB0};
     for(uint8_t i = 0; i<(sizeof(charType)); i++){
        DrawingSetValues(drawValues, Xbegin[i], Ybegin[i], Xstop[i], Ystop[i], charType[i]);
    }
    DrawEverything(drawValues);


    gotoxy(45,55);
    printf(" .----------------.  ");
    gotoxy(45,56);
    printf("| .--------------. |");
    gotoxy(45,57);
    printf("| | _____  _____ | |");
    gotoxy(45,58);
    printf("| ||_   _||_   _|| |");
    gotoxy(45,59);
    printf("| |  | | / || |  | |");
    gotoxy(45,60);
    printf("| |  | |/  || |  | |");
    gotoxy(45,61);
    printf("| |  |   /|   |  | |");
    gotoxy(45,62);
    printf("| |  |__/  |__|  | |");
    gotoxy(45,63);
    printf("| |              | |");
    gotoxy(45,64);
    printf("| '--------------' |");
    gotoxy(45,65);
    printf(" '----------------'");


    gotoxy(24,67);
    printf(" .----------------.   .----------------.   .----------------. ");
    gotoxy(24,68);
    printf("| .--------------. | | .--------------. | | .--------------. |");
    gotoxy(24,69);
    printf("| |      __      | | | |    _______   | | | |  ________    | |");
    gotoxy(24,70);
    printf("| |     /  |     | | | |   /  ___  |  | | | | |_   ___ `.  | |");
    gotoxy(24,71);
    printf("| |    / /| |    | | | |  |  (__ |_|  | | | |   | |   `. | | |");
    gotoxy(24,72);
    printf("| |   / ____ |   | | | |   '.___`-.   | | | |   | |    | | | |");
    gotoxy(24,73);
    printf("| | _/ /    | |_ | | | |  |`|____) |  | | | |  _| |___.' / | |");
    gotoxy(24,74);
    printf("| ||____|  |____|| | | |  |_______.'  | | | | |________.'  | |");
    gotoxy(24,75);
    printf("| |              | | | |              | | | |              | |");
    gotoxy(24,76);
    printf("| '--------------' | | '--------------' | | '--------------' |");
    gotoxy(24,77);
    printf(" '----------------'   '----------------'   '----------------' ");



    gotoxy(24,82);
    printf(" .------------------------------------------------------------------.");
    gotoxy(24,83);
    printf("| .---------------------------------------------------------------. |");
    gotoxy(24,84);
    printf("| |    _______    ______         __          ______    _________  | |");
    gotoxy(24,85);
    printf("| |   /  ___  |  |_   __ |      /  |       .' ___  |  |_   ___  | | |");
    gotoxy(24,86);
    printf("| |  |  (__ |_|    | |__) |    / /| |     / .'   |_|    | |_  |_| | |");
    gotoxy(24,87);
    printf("| |   '.___`-.     |  ___/    / ____ |    | |           |  _|  _  | |");
    gotoxy(24,88);
    printf("| |  |`|____) |   _| |_     _/ /    | |_  | `.___.'|    | |___/ | | |");
    gotoxy(24,89);
    printf("| |  |_______.'  |_____|   |____|  |____|  `._____.'  |_________| | |");
    gotoxy(24,90);
    printf("| |                                                               | |");
    gotoxy(24,91);
    printf("| '---------------------------------------------------------------' |");
    gotoxy(24,92);
    printf(" '------------------------------------------------------------------'");


    gotoxy(95,60);
    printf("  #        ####### #######    #     # ####### #     # ####### ");
    gotoxy(95,61);
    printf(" ###          #    #     #    ##   ## #     # #     # #    ");
    gotoxy(95,62);
    printf("  #           #    #     #    # # # # #     # #     # #      ");
    gotoxy(95,63);
    printf("              #    #     #    #  #  # #     # #     # #####   ");
    gotoxy(95,64);
    printf("  #           #    #     #    #     # #     #  #   #  #       ");
    gotoxy(95,65);
    printf(" ###          #    #     #    #     # #     #   # #   #        ");
    gotoxy(95,66);
    printf("  #           #    #######    #     # #######    #    ####### ");


    gotoxy(95,84);
    printf("  #    ####### #######    #####  #     # ####### ####### ####### ");
    gotoxy(95,85);
    printf(" ###      #    #     #   #     # #     # #     # #     #    #   ");
    gotoxy(95,86);
    printf("  #       #    #     #   #       #     # #     # #     #    #    ");
    gotoxy(95,87);
    printf("          #    #     #    #####  ####### #     # #     #    #    ");
    gotoxy(95,88);
    printf("  #       #    #     #         # #     # #     # #     #    #    ");
    gotoxy(95,89);
    printf(" ###      #    #     #   #     # #     # #     # #     #    #    ");
    gotoxy(95,90);
    printf("  #       #    #######    #####  #     # ####### #######    #    ");



    gotoxy(73,98);
    printf(" ######     #     #####  #    # ");
    gotoxy(73,99);
    printf(" #     #   # #   #     # #   #  ");
    gotoxy(73,100);
    printf(" #     #  #   #  #       #  #   ");
    gotoxy(73,101);
    printf(" ######  #     # #       ###    ");
    gotoxy(73,102);
    printf(" #     # ####### #       #  #   ");
    gotoxy(73,103);
    printf(" #     # #     # #     # #   #  ");
    gotoxy(73,104);
    printf(" ######  #     #  #####  #    # ");
}

void ConstructSettingsMenu(struct drawItems *drawValues){
     uint8_t Xbegin[] = {20,20,20,160};
     uint8_t Xstop[] = {20,160,160,160};
     uint8_t Ybegin[] = {50,50,110,50};
     uint8_t Ystop[] = {110,50,110,110};
     char charType[] = {0xB0,0xB0,0xB0,0xB0};
     for(uint8_t i = 0; i<(sizeof(charType)); i++){
        DrawingSetValues(drawValues, Xbegin[i], Ybegin[i], Xstop[i], Ystop[i], charType[i]);
    }
    DrawEverything(drawValues);

    gotoxy(55,66);
    printf("  #####  ######     #     #####  #######  #####  #     # ### ######  ");
    gotoxy(55,67);
    printf(" #     # #     #   # #   #     # #       #     # #     #  #  #     # ");
    gotoxy(55,68);
    printf(" #       #     #  #   #  #       #       #       #     #  #  #     # ");
    gotoxy(55,69);
    printf("  #####  ######  #     # #       #####    #####  #######  #  ######  ");
    gotoxy(55,70);
    printf("       # #       ####### #       #             # #     #  #  #      ");
    gotoxy(55,71);
    printf(" #     # #       #     # #     # #       #     # #     #  #  #       ");
    gotoxy(55,72);
    printf("  #####  #       #     #  #####  #######  #####  #     # ### #       ");


    gotoxy(73,98);
    printf(" ######     #     #####  #    # ");
    gotoxy(73,99);
    printf(" #     #   # #   #     # #   #  ");
    gotoxy(73,100);
    printf(" #     #  #   #  #       #  #   ");
    gotoxy(73,101);
    printf(" ######  #     # #       ###    ");
    gotoxy(73,102);
    printf(" #     # ####### #       #  #   ");
    gotoxy(73,103);
    printf(" #     # #     # #     # #   #  ");
    gotoxy(73,104);
    printf(" ######  #     #  #####  #    # ");
}

void ConstructSpaceShipMenu(struct drawItems *drawValues){
     uint8_t Xbegin[] = {130,130,130,158,150,151,152,150,151,152,150,151,152,150,151,152,150,151,152,150,151,152
     };
     uint8_t Xstop[] = {130,158,158,158,150,151,152,150,151,152,150,151,152,150,151,152,150,151,152,150,151,152
     };
     uint8_t Ybegin[] = {52,52,108,52,60,60,60,61,61,61,62,62,62,70,70,70,71,71,71,72,72,72
     };
     uint8_t Ystop[] = {108,52,108,108,60,60,60,61,61,61,62,62,62,70,70,70,71,71,71,72,72,72
     };
     char charType[] = {0xB0,0xB0,0xB0,0xB0,0xFF,0xB3,0xFF,0xB3,0xBA,0xB3,0xC8,0xCA,0xBC,0xFF,0xBA,0xFF,0xCC,0xCA,0xB9,0xBA,0xFF,0xBA
     };
     for(uint8_t i = 0; i<(sizeof(charType)); i++){
        DrawingSetValues(drawValues, Xbegin[i], Ybegin[i], Xstop[i], Ystop[i], charType[i]);
    }
    DrawEverything(drawValues);
    /* Insert the different models for space ships in here, and then add some arrows for each spaceship variant */
}




// All functions that clears something

void clearscr() {
        printf("%c[%d%c",ESC,2,0x4A);
}

void ClearGameScreen(struct drawItems *drawValues){
    // 16->164 i X, 16-114 i Y
     GameLED(4);
     uint8_t Xbegin[99];
     uint8_t Xstop[99];
     uint8_t Ybegin[99];
     uint8_t Ystop[99];
     char charType[99];
     for(uint8_t j = 0; j<99; j++){
        Xbegin[j] = 16;
        Xstop[j] = 164;
        Ybegin[j] = 16 + j;
        Ystop[j] = 16 + j;
        charType[j] = 0xFF;
     }
     for(uint8_t i = 0; i<(sizeof(charType)); i++){
        DrawingSetValues(drawValues, Xbegin[i], Ybegin[i], Xstop[i], Ystop[i], charType[i]);
    }
    DrawEverything(drawValues);
}

void ClearSpaceShipMenu(struct drawItems *drawValues){
     uint8_t Xbegin[57];
     uint8_t Xstop[57];
     uint8_t Ybegin[57];
     uint8_t Ystop[57];
     char charType[57];
     for(uint8_t j = 0; j<57; j++){
        Xbegin[j] = 130;
        Xstop[j] = 158;
        Ybegin[j] = 52 + j;
        Ystop[j] = 52 + j;
        charType[j] = 0xFF;
     }
     for(uint8_t i = 0; i<(sizeof(charType)); i++){
        DrawingSetValues(drawValues, Xbegin[i], Ybegin[i], Xstop[i], Ystop[i], charType[i]);
    }
    DrawEverything(drawValues);
}

void ClearSubSettingsMenu(struct drawItems *drawValues){
     uint8_t Xbegin[26];
     uint8_t Xstop[26];
     uint8_t Ybegin[26];
     uint8_t Ystop[26];
     char charType[26];
     for(uint8_t j = 0; j<26; j++){
        Xbegin[j] = 81;
        Xstop[j] = 157;
        Ybegin[j] = 55 + j;
        Ystop[j] = 55 + j;
        charType[j] = 0xFF;
     }
     for(uint8_t i = 0; i<(sizeof(charType)); i++){
        DrawingSetValues(drawValues, Xbegin[i], Ybegin[i], Xstop[i], Ystop[i], charType[i]);
    }
    DrawEverything(drawValues);
}

void ClearSubMenu(struct drawItems *drawValues){
     uint8_t Xbegin[61];
     uint8_t Xstop[61];
     uint8_t Ybegin[61];
     uint8_t Ystop[61];
     char charType[61];
     for(uint8_t j = 0; j<63; j++){
        Xbegin[j] = 20;
        Xstop[j] = 160;
        Ybegin[j] = 50 + j;
        Ystop[j] = 50 + j;
        charType[j] = 0xFF;
     }
     for(uint8_t i = 0; i<(sizeof(charType)); i++){
        DrawingSetValues(drawValues, Xbegin[i], Ybegin[i], Xstop[i], Ystop[i], charType[i]);
    }
    DrawEverything(drawValues);
}




// CONSTRUCT ARROWS AND CLEAR ARROWS
void ConstructSpaceShip1Arrow(){
    gotoxy(136,60);
    printf("    #");
    gotoxy(136,61);
    printf("######");
    gotoxy(136,62);
    printf("    #");
}

void ClearSpaceShip1Arrow(){
    gotoxy(136,60);
    printf("     ");
    gotoxy(136,61);
    printf("      ");
    gotoxy(136,62);
    printf("     ");
}

void ConstructSpaceShip2Arrow(){
    gotoxy(136,70);
    printf("    #");
    gotoxy(136,71);
    printf("######");
    gotoxy(136,72);
    printf("    #");
}

void ClearSpaceShip2Arrow(){
    gotoxy(136,70);
    printf("     ");
    gotoxy(136,71);
    printf("      ");
    gotoxy(136,72);
    printf("     ");
}

void ConstructPlayGameArrow(){
    gotoxy(40,60);
    printf("#");
    gotoxy(40,61);
    printf("###");
    gotoxy(40,62);
    printf("#####");
    gotoxy(40,63);
    printf("#######");
    gotoxy(40,64);
    printf("#####");
    gotoxy(40,65);
    printf("###");
    gotoxy(40,66);
    printf("#");
}

void ClearPlayGameArrow(){
    gotoxy(40,60);
    printf("         ");
    gotoxy(40,61);
    printf("         ");
    gotoxy(40,62);
    printf("         ");
    gotoxy(40,63);
    printf("         ");
    gotoxy(40,64);
    printf("         ");
    gotoxy(40,65);
    printf("         ");
    gotoxy(40,66);
    printf("         ");
}

void ConstructHowToPlayArrow(){
    gotoxy(40,77);
    printf("#");
    gotoxy(40,78);
    printf("###");
    gotoxy(40,79);
    printf("#####");
    gotoxy(40,80);
    printf("#######");
    gotoxy(40,81);
    printf("#####");
    gotoxy(40,82);
    printf("###");
    gotoxy(40,83);
    printf("#");
}

void ClearHowToPlayArrow(){
    gotoxy(40,77);
    printf("         ");
    gotoxy(40,78);
    printf("         ");
    gotoxy(40,79);
    printf("         ");
    gotoxy(40,80);
    printf("         ");
    gotoxy(40,81);
    printf("         ");
    gotoxy(40,82);
    printf("         ");
    gotoxy(40,83);
    printf("         ");
    }

void ConstructSettingsArrow(){
    gotoxy(40,94);
    printf("#");
    gotoxy(40,95);
    printf("###");
    gotoxy(40,96);
    printf("#####");
    gotoxy(40,97);
    printf("#######");
    gotoxy(40,98);
    printf("#####");
    gotoxy(40,99);
    printf("###");
    gotoxy(40,100);
    printf("#");
}

void ClearSettingsArrow(){
    gotoxy(40,94);
    printf("       ");
    gotoxy(40,95);
    printf("       ");
    gotoxy(40,96);
    printf("       ");
    gotoxy(40,97);
    printf("       ");
    gotoxy(40,98);
    printf("       ");
    gotoxy(40,99);
    printf("       ");
    gotoxy(40,100);
    printf("       ");
}

void ConstructBackArrow(){
    gotoxy(60,98);
    printf("#");
    gotoxy(60,99);
    printf("###");
    gotoxy(60,100);
    printf("#####");
    gotoxy(60,101);
    printf("#######");
    gotoxy(60,102);
    printf("#####");
    gotoxy(60,103);
    printf("###");
    gotoxy(60,104);
    printf("#");
}

void ClearBackArrow(){
    gotoxy(60,98);
    printf(" ");
    gotoxy(60,99);
    printf("   ");
    gotoxy(60,100);
    printf("     ");
    gotoxy(60,101);
    printf("       ");
    gotoxy(60,102);
    printf("     ");
    gotoxy(60,103);
    printf("   ");
    gotoxy(60,104);
    printf(" ");
}

void ConstructSpaceshipArrow(){
    gotoxy(42,66);
    printf("#");
    gotoxy(42,67);
    printf("###");
    gotoxy(42,68);
    printf("#####");
    gotoxy(42,69);
    printf("#######");
    gotoxy(42,70);
    printf("#####");
    gotoxy(42,71);
    printf("###");
    gotoxy(42,72);
    printf("#");
}

void ClearSpaceshipArrow(){
    gotoxy(42,66);
    printf(" ");
    gotoxy(42,67);
    printf("   ");
    gotoxy(42,68);
    printf("     ");
    gotoxy(42,69);
    printf("       ");
    gotoxy(42,70);
    printf("     ");
    gotoxy(42,71);
    printf("   ");
    gotoxy(42,72);
    printf(" ");
    }



// Below is draw functions which take several of the functions above and collects them in  a single function.

void BeginMenuScreen(struct MenuSelection *MenuSelection, struct drawItems *drawValues){
    clearscr();
    ConstructWindow(drawValues);
    ConstructTitle();
    ConstructMainMenu();
    ConstructPlayGameArrow();
}

void BeginHowToPlayMenu(struct drawItems *drawValues){
    ClearSubMenu(drawValues);
    ConstructHowToPlayMenu(drawValues);
}

void BeginMainMenu(struct drawItems *drawValues){
    ClearSubMenu(drawValues);
    ConstructMainMenu();
}

void BeginSettingMenu(struct drawItems *drawValues){
    ClearSubMenu(drawValues);
    ConstructSettingsMenu(drawValues);
}

void BeginGame(struct drawItems *drawValues){
    ClearSubMenu(drawValues);
    ConstructGoodLuck();
    ClearGameScreen(drawValues);
}



