/*
**
**                           Ships.c
**
**
**********************************************************************/
/*
   Primary editor  :    Mathias Jensen
   Secondary editor:    Casper Bang - Hansen
   Last changed by :    19/01 - 2020

   Functions       :    void ShipSelection(uint8_t control, uint8_t skin, struct player *player, struct drawItems *drawValues){

**********************************************************************/

//include .h file
#include <stdio.h>
#include "Ships.h"

/**********************************************************************

   Description     :    ShipSelection draws the player model and removes the players previous position model.

   Input           :    uint8_t control
                        uint8_t skin
                        struct player *player
                        struct drawItems *drawValues

   Output          :    void

**********************************************************************/

void ShipSelection(uint8_t control, uint8_t skin, struct player *player, struct drawItems *drawValues){
    if(control != 0){
        //defines chartype
        char charType[] = {'\0','\0','\0','\0','\0','\0','\0','\0','\0'};

        //makes an array with every position around the players current position (3x3)
        uint16_t x[] = {(*player).xPos - 1, (*player).xPos ,(*player).xPos + 1,(*player).xPos - 1, (*player).xPos ,(*player).xPos + 1,(*player).xPos - 1, (*player).xPos ,(*player).xPos + 1};
        uint8_t y[] =  {(*player).yPos - 1, (*player).yPos - 1, (*player).yPos - 1, (*player).yPos, (*player).yPos ,(*player).yPos ,(*player).yPos +1 , (*player).yPos + 1, (*player).yPos +1};

        //makes an array with every position around the players previous position (3x3)
        uint16_t xP[] = {(*player).xPosPrevious - 1, (*player).xPosPrevious ,(*player).xPosPrevious + 1,(*player).xPosPrevious - 1, (*player).xPosPrevious ,(*player).xPosPrevious + 1,(*player).xPosPrevious - 1, (*player).xPosPrevious ,(*player).xPosPrevious + 1};
        uint8_t yP[] =  {(*player).yPosPrevious - 1, (*player).yPosPrevious - 1, (*player).yPosPrevious - 1, (*player).yPosPrevious, (*player).yPosPrevious ,(*player).yPosPrevious ,(*player).yPosPrevious +1 , (*player).yPosPrevious + 1, (*player).yPosPrevious +1};

        //checks if the skin is equal to one and what direction the player is looking, and then changes the chartype array to the player skin in that direction
        if (skin == 1){
            switch (control){
                case 1:{
                    charType[0] = 0xFF; charType[1] = 0xB3; charType[2] = 0xFF; charType[3] = 0xB3; charType[4] = 0xBA; charType[5] = 0xB3; charType[6] = 0xC8; charType[7] = 0xCA; charType[8] = 0xBC;
                    break;
                }
                case 2:{
                    charType[0] = 0xFF; charType[1] = 0xC4; charType[2] = 0xBB; charType[3] = 0xC4; charType[4] = 0xCD; charType[5] = 0xB9; charType[6] = 0xFF; charType[7] = 0xC4; charType[8] = 0xBC;
                    break;
                }
                case 3:{
                    charType[0] = 0xC9; charType[1] = 0xCB; charType[2] = 0xBB; charType[3] = 0xB3; charType[4] = 0xBA; charType[5] = 0xB3; charType[6] = 0xFF; charType[7] = 0xB3; charType[8] = 0xFF;
                    break;
                }
                case 4:{
                    charType[0] = 0xC9; charType[1] = 0xC4; charType[2] = 0xFF; charType[3] = 0xCC; charType[4] = 0xCD; charType[5] = 0xC4; charType[6] = 0xC8; charType[7] = 0xC4; charType[8] = 0xFF;
                    break;
                }
                default:{
                    break;
                }
            }
        //checks if the skin is equal to two and what direction the player is looking, and then changes the chartype array to the player skin in that direction
        }else if (skin == 2){
            switch (control){
                case 1:{
                    charType[0] = 0xFF; charType[1] = 0xBA; charType[2] = 0xFF; charType[3] = 0xCC; charType[4] = 0xCA; charType[5] = 0xB9; charType[6] = 0xBA; charType[7] = 0xFF; charType[8] = 0xBA;
                    break;
                }
                case 2:{
                    charType[0] = 0xFF; charType[1] = 0xCB; charType[2] = 0xCD; charType[3] = 0xCD; charType[4] = 0xB9; charType[5] = 0xFF; charType[6] = 0xFF; charType[7] = 0xCA; charType[8] = 0xCD;
                    break;
                }
                case 3:{
                    charType[0] = 0xBA; charType[1] = 0xFF; charType[2] = 0xBA; charType[3] = 0xCC; charType[4] = 0xCB; charType[5] = 0xB9; charType[6] = 0xFF; charType[7] = 0xBA; charType[8] = 0xFF;
                    break;
                }
                case 4:{
                    charType[0] = 0xCD; charType[1] = 0xCB; charType[2] = 0xFF; charType[3] = 0xFF; charType[4] = 0xCC; charType[5] = 0xCD; charType[6] = 0xCD; charType[7] = 0xCA; charType[8] = 0xFF;
                    break;
                }
                default:
                    break;
            }
        //checks if the skin is equal to three and what direction the player is looking, and then changes the chartype array to the player skin in that direction
        }else if(skin == 3){
            switch (control){
                case 1:{
                    charType[0] = 0xB3; charType[1] = 0xFF; charType[2] = 0xB3; charType[3] = 0xCC; charType[4] = 0x4F; charType[5] = 0xB9; charType[6] = 0xB3; charType[7] = 0xFF; charType[8] = 0xB3;
                    break;
                }
                case 2:{
                    charType[0] = 0xC4; charType[1] = 0xCB; charType[2] = 0xC4; charType[3] = 0xFF; charType[4] = 0x4F; charType[5] = 0xFF; charType[6] = 0xC4; charType[7] = 0xCA; charType[8] = 0xC4;
                    break;
                }
                case 3:{
                    charType[0] = 0xB3; charType[1] = 0xFF; charType[2] = 0xB3; charType[3] = 0xCC; charType[4] = 0x4F; charType[5] = 0xB9; charType[6] = 0xB3; charType[7] = 0xFF; charType[8] = 0xB3;
                    break;
                }
                case 4:{
                    charType[0] = 0xC4; charType[1] = 0xCB; charType[2] = 0xC4; charType[3] = 0xFF; charType[4] = 0x4F; charType[5] = 0xFF; charType[6] = 0xC4; charType[7] = 0xCA; charType[8] = 0xC4;
                    break;
                }
                default:
                    break;
            }
        }
        //checks if the player skins exists
        if(skin >= 0 && skin <= 3){
            //sets the players previous position (3x3) to 0xFF (empty) in the drawer que
            for(uint8_t i = 0; i<=(8); i++){
                DrawingSetValues(drawValues, xP[i], yP[i], xP[i], yP[i], 0xFF);
            }
            //sets the players current position (3x3) to the right character in the drawer que
            for(uint8_t i = 0; i<=(8); i++){
                DrawingSetValues(drawValues, x[i], y[i], x[i], y[i], charType[i]);
            }
            //draws both 'player models' right after each other
            DrawEverything(drawValues);
        }
    }

}

