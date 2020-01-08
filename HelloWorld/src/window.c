#include "window.h"
#define ESC 0x1B

void window(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, char title[], uint8_t style){
    clearscr();
    //x1=11,y1=25,x2=31,y2=8
    uint8_t X1 = x1, X2 = x2, Y1 = y1, Y2 = y2;
    if(y1>=y2){
        Y1 = y2;
        Y2 = y1;
    }
    if(x1>=x2){
        X1 = x2;
        X2 = x1;
    }
    x1 = X1;
    x2 = X2;
    y1 = Y1;
    y2 = Y2;

    uint8_t length = strlen(title);
    char ULcorner; // Upper left corner
    char URcorner; // Upper right corner
    char LT; // Left for title "stopper"
    char RT; // Right for title "stopper"
    char SH; // Straight horizontal
    char SV; // Straight Vertical
    char LLcorner; // Lower left corner
    char LRcorner; // Lower right corner
    uint8_t toolong = 0;
    if (style == 1){
        ULcorner = 201;
        URcorner = 187;
        LT = 185;
        RT = 204;
        SH = 205;
        SV = 186;
        LLcorner = 200;
        LRcorner = 188;
    }
    else if (style == 2){
        ULcorner = 218;
        URcorner = 191;
        LT = 180;
        RT = 195;
        SH = 196;
        SV = 179;
        LLcorner = 192;
        LRcorner = 217;
    }
    else {
        printf("ERROR : No valid style chosen.");
    }

    if (x2-x1-4 < length) {
        toolong = 1;
    }
    if (toolong == 1) {
        printf("ERROR : Title too long.\n");
    }
    else { // Hvis der er plads, gaa til det oeverste til venstre hjoerne
            gotoxy(x1,y1);
            printf("%c%c",ULcorner,LT); // Skab hjoernet, og gaa vandret mod hoejre.
            printf("%s",title); // title
            printf("%c",RT); // Hoejre stopper
            for (uint8_t i = 0;i<x2-(x1+length+3);i++){ //Horizontal side, saa den passer med title.
                printf("%c",SH);
            }
            printf("%c",URcorner);
            for (uint8_t j = y1+1;j<=y2-1;j++){ //Lav de verticale sider.
                gotoxy(x1,j);
                printf("%c",SV);
                gotoxy(x2,j);
                printf("%c",SV);
            }
            gotoxy(x1,y2); // Lav den horizontale bund.
            printf("%c",LLcorner);
            for (uint8_t i = x1+1;i<=x2-1;i++){
                printf("%c",SH);
            }
            printf("%c",LRcorner);
    }
}
