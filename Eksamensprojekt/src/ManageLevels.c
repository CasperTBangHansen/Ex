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

   Output          :    void

**********************************************************************/

void LevelManager(struct mapPackage *maps, struct drawItems *drawValues){
    // Loads map of choice
    switch ((*maps).mapChoice){
        // Map 1
        case 1:{
            //Draws first map
            firstMapSetup(drawValues);
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

