/*
**
**                           ManageLevels.c
**
**
**********************************************************************/
/*
   Primary editor  :    Mathias Jensen
   Secondary editor:
   Last changed by :    19/01 - 2020

   Functions       :    void LevelManager(struct mapPackage *maps, struct drawItems *drawValues);

**********************************************************************/

//include .h file
#include "ManageLevels.h"



/**********************************************************************

   Description     :    LevelManager keeps track of the levels and sets the levels up.

   Input           :    struct mapPackage *maps
                        struct drawItems *drawValues
                        struct player *player
                        struct enemy *enemies
                        uint8_t drawMap

   Output          :    void

**********************************************************************/

void LevelManager(struct mapPackage *maps, struct drawItems *drawValues, struct player *player, struct enemy *enemies, uint8_t drawMap){
    // Loads map of choice
    switch ((*maps).mapChoice){
        // Map 1
        case 1:{
            //Draws first map
            if(drawMap == 1){
                firstMapSetup(drawValues);
            }

            //Sets player position
            uint16_t xSTART = 19;
            uint16_t ySTART = 65;
            player->xPos = xSTART;
            player->yPos = ySTART;
            player->xPosPrevious = xSTART;
            player->yPosPrevious = ySTART;

            //Sets enemies position
            enemies[0].xPos = 103;
            enemies[0].yPos = 48;
            enemies[0].xPosPrevious = enemies[0].xPos;
            enemies[0].yPosPrevious = enemies[0].yPos;
            enemies[0].show = 1;

            enemies[0].xPath[0] = 103;
            enemies[0].yPath[0] = 48;


            enemies[0].xPath[1] = 93;
            enemies[0].yPath[1] = 48;


            enemies[0].xPath[2] = 93;
            enemies[0].yPath[2] = 73;

            enemies[0].xPath[3] = 103;
            enemies[0].yPath[3] = 73;

            enemies[0].arrayPathSize = 4;

            enemies[1].xPos = 43;
            enemies[1].yPos = 54;
            enemies[1].xPosPrevious = enemies[1].xPos;
            enemies[1].yPosPrevious = enemies[1].yPos;
            enemies[1].show = 1;

            enemies[1].xPath[0] = 43;
            enemies[1].yPath[0] = 54;


            enemies[1].xPath[1] = 43;
            enemies[1].yPath[1] = 78;

            enemies[1].arrayPathSize = 2;

            break;
        }
        // Map 2
        case 2:{
            printf("map 2 has been reset!\n");
            break;
        }
        // Map 3
        case 3:{
            printf("map 3 has been reset!\n");
            break;
        }
        //default (wrong input)
        default:{
            break;
        }
    }
}

