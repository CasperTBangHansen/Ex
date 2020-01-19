/*
**
**                           Drawing.c
**
**
**********************************************************************/
/*
   Primary editor  :    Casper Bang-Hansen
   Secondary editor:
   Last changed by :    19/01 - 2020

   Functions       :    uint16_t SetPos(uint8_t status);
                        void DrawingSetValues(struct drawItems *drawValues, uint16_t xPosStart, uint8_t yPosStart, uint16_t xPosSlut, uint8_t yPosSlut, char character);
                        void gotoxy(uint16_t x, uint8_t y);
                        void DrawEverything(struct drawItems *drawValues);

**********************************************************************/

//include .h file
#include "Drawing.h"


//defines
//Symbols
#define ESC 0x1B


/**********************************************************************

   Description     :    SetPos keeps track of the length of drawValues
                        Depending on the input SetPos will add one to the length, reset or return current length

   Input           :    uint8_t status      0   =   add currentPos by one
                                            1   =   resets currentPos
                                            2   =   current length

   Output          :    uint16_t currentPos

**********************************************************************/

uint16_t SetPos(uint8_t status){
    //Starts counting at -1 (since it is a uint16_t this value is 65535, but it gets added by 1 and therefor it is 0)
    static uint16_t currentPos = -1;
    //Checks if this function should reset or not
    if(status == 0){
        //updates currentPos by adding one
        currentPos++;
        return currentPos;
    } else if(status == 1){
        //reset currentPos
        currentPos = -1;
        return currentPos;
    } else if(status == 2){
        //returns currentPos
        return currentPos;
    }
}

/**********************************************************************

   Description     :    DrawingSetValues takes a coordinate set and a character and saves it in a struct.

   Input           :    struct drawItems *drawValues
                        uint16_t xPosStart
                        uint8_t yPosStart
                        uint16_t xPosSlut
                        uint8_t yPosSlut
                        char character

   Output          :    void

**********************************************************************/

void DrawingSetValues(struct drawItems *drawValues, uint16_t xPosStart, uint8_t yPosStart, uint16_t xPosSlut, uint8_t yPosSlut, char character){
    //adds current position by one and gets current position
    uint16_t position = SetPos(0);
    //sets array at current position to input values
    drawValues[position].xStart = xPosStart;
    drawValues[position].yStart = yPosStart;
    drawValues[position].xSlut = xPosSlut;
    drawValues[position].ySlut = yPosSlut;
    drawValues[position].text = character;
}

/**********************************************************************

   Description     :    gotoxy takes a coordinate set and goes to that position in the terminal

   Input           :    uint16_t x
                        uint8_t y

   Output          :    void

**********************************************************************/
void gotoxy(uint16_t x, uint8_t y){
    //goes to (x,y)
    printf("%c[%u;%u%c",ESC,y,x,0x48);
}

/**********************************************************************

   Description     :    DrawEverything takes a struct array were a coordinate set and a character is saved and draws this.
                        After this the function 'cleans' the struct by reseting the SetPos function

   Input           :    struct drawItems *drawValues

   Output          :    void

**********************************************************************/
void DrawEverything(struct drawItems *drawValues){
    //Gets current position + 1
    uint16_t maxPos = SetPos(0);
    //loops through the hole struct array
    for(uint16_t i = 0; i < maxPos; i++){
        //checks if there only should be drawn one character
        if((drawValues[i].xStart == drawValues[i].xSlut) &&(drawValues[i].yStart == drawValues[i].ySlut)){
            //Goes to a postion and drawns the one character
            gotoxy(drawValues[i].xStart,drawValues[i].yStart);
            printf("%c",drawValues[i].text);
        //check if there should be drawn a vertical line of characters
        } else if(drawValues[i].xStart == drawValues[i].xSlut){
            //loops through a column and draws all the characters
            for(uint16_t j = drawValues[i].yStart; j <= drawValues[i].ySlut; j++){
                gotoxy(drawValues[i].xStart, j);
                printf("%c",drawValues[i].text);
            }
        //check if there should be drawn a horizontal line of characters
        } else if(drawValues[i].yStart == drawValues[i].ySlut){
            gotoxy(drawValues[i].xStart, drawValues[i].yStart);
            //loops through a row and draws all the characters
            for(uint16_t j = drawValues[i].xStart; j <= drawValues[i].xSlut; j++){
                printf("%c",drawValues[i].text);
            }
        }
    }
    SetPos(1);
}

