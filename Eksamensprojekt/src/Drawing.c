
#include "Drawing.h"

/*------------------------------HOW TO------------------------------
\\\\\\\\\\\\\\\\\\\\\\\\\\\\EXAMPLE MAIN////////////////////////////

struct drawItems drawValues[1000];
for(int i = 0; i<64; i++){
    DrawingSetValues(&drawValues, 1, i, 10, i, '-');
}
for(int i = 0; i<10; i++){
    DrawingSetValues(&drawValues, 11+i, 1, 11+i, 10, '|');
}
DrawEverything(&drawValues);
while(1){}
\\\\\\\\\\\\\\\\\\\\\\\\\\\\EXAMPLE MAIN////////////////////////////
--------------------------------HOW TO------------------------------
*/



/*
    SetPos is a function the keeps track of the length of the drawValues array (DONT CALL THIS FUNCTION)

    Input:  reset       (uint8_t 0/1)

    output: currentPos  (uint16_t 0-999)
*/
static uint16_t SetPos(uint8_t reset){
    static uint16_t currentPos = -1;
    if(reset == 0){
        currentPos++;
    } else if(reset == 1){
        currentPos = -1;
    }
    return currentPos;
}

/*
    DrawingSetValues is a funktion that takes postion (xStart,yStart) and (xSlut,ySlut) and a character. Then a struct array to these values

    Input:  *drawValyes (struct drawItems adresse)
            xPosStart   (uint16_t 1-271)
            yPosStart   (uint8_t  1-65 )
            xPosSlut    (uint16_t 1-271)
            yPosSlut    (uint8_t  1-65 )
            character   (char     'X'  )

    output: void
*/
void DrawingSetValues(struct drawItems *drawValues, uint16_t xPosStart, uint8_t yPosStart, uint16_t xPosSlut, uint8_t yPosSlut, char character){
    uint16_t position = SetPos(0);
    drawValues[position].xStart = xPosStart;
    drawValues[position].yStart = yPosStart;
    drawValues[position].xSlut = xPosSlut;
    drawValues[position].ySlut = yPosSlut;
    drawValues[position].text = character;
}

/*
    gotoxy is a function that moves the curser to a (x,y) postion
    Input:  x       (uint16_t 1-271)
            y       (uint8_t  1-65 )

    output: void
*/
static void gotoxy(uint16_t x, uint8_t y){
        printf("%c[%u;%u%c",0x1B,y,x,0x48);
}

/*
    DrawEverything draws the hole struct array
    Input:  *drawValyes (struct drawItems adresse)

    output: void
*/

void DrawEverything(struct drawItems *drawValues){
    uint16_t maxPos = SetPos(0);
    for(uint16_t i = 0; i < maxPos; i++){
        if((drawValues[i].xStart == drawValues[i].xSlut) &&(drawValues[i].yStart == drawValues[i].ySlut)){
            gotoxy(drawValues[i].xStart,drawValues[i].yStart);
            printf("%c",drawValues[i].text);
        } else if(drawValues[i].xStart == drawValues[i].xSlut){
            for(uint16_t j = drawValues[i].yStart; j <= drawValues[i].ySlut; j++){
                gotoxy(drawValues[i].xStart, j);
                printf("%c",drawValues[i].text);
            }
        } else if(drawValues[i].yStart == drawValues[i].ySlut){
            gotoxy(drawValues[i].xStart, drawValues[i].yStart);
            for(uint16_t j = drawValues[i].xStart; j <= drawValues[i].xSlut; j++){
                printf("%c",drawValues[i].text);
            }
        }
    }
    SetPos(1);
}
