//Includes
#include "printing.h"

//Defines
#define ESC 0x1B

//Clears terminal
void clearscr() {
        printf("%c[%d%c",ESC,2,0x4A);
}
//Clears rest of line
void clreol() {
        printf("%c[%c",ESC,0x4B);
}
//Goes to a x,y position
void gotoxy(uint8_t x, uint8_t y){
        printf("%c[%u;%u%c",ESC,y,x,0x48);

}
//Underlines text (on/off)
void underline(uint8_t on){
    if (on == 1){
            printf("%c[%d%c",ESC,04,0x6D);
    }
    else if (on == 0){
            printf("%c[%d%c",ESC,24,0x6D);
    }
}

//Blink (on/off)
void blink(uint8_t on){
    if (on == 1){
            printf("%c[%d%c",ESC,05,0x6D);
    }
    else if (on == 0){
            printf("%c[%d%c",ESC,25,0x6D);
    }
}

//Inverse background
void inverse(uint8_t on){
    if (on == 1){
            printf("%c[%d%c",ESC,07,0x6D);
    }
    else if (on == 0){
            printf("%c[%d%c",ESC,27,0x6D);
    }
}
