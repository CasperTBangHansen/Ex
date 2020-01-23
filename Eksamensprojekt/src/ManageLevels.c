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

void LevelManager(struct mapPackage *maps, struct drawItems *drawValues, struct player *player, struct enemy *enemies, uint8_t drawMap, struct powerUp *powerUp){
    // Loads map of choice
    player->direction = 4;
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

            //Sets powerup position
            powerUp[0].xPos = 98;
            powerUp[0].yPos = 73;
            powerUp[0].show = 1;



            //enemy speed
            counter.speedEnemies = 40;
            //Sets enemies spawn position and earlier position
            enemies[0].xPos = 103;
            enemies[0].yPos = 48;
            enemies[0].xPosPrevious = enemies[0].xPos;
            enemies[0].yPosPrevious = enemies[0].yPos;
            enemies[0].show = 1;
            // Next lines define the path it should walk.
            enemies[0].xPath[0] = 103;
            enemies[0].yPath[0] = 48;


            enemies[0].xPath[1] = 93;
            enemies[0].yPath[1] = 48;


            enemies[0].xPath[2] = 93;
            enemies[0].yPath[2] = 73;

            enemies[0].xPath[3] = 103;
            enemies[0].yPath[3] = 73;
            //Amount of lines the enemy walks
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


            enemies[2].xPos = 68;
            enemies[2].yPos = 33;
            enemies[2].xPosPrevious = enemies[2].xPos;
            enemies[2].yPosPrevious = enemies[2].yPos;
            enemies[2].show = 1;

            enemies[2].xPath[0] = 68;
            enemies[2].yPath[0] = 33;


            enemies[2].xPath[1] = 68;
            enemies[2].yPath[1] = 43;


            enemies[2].xPath[2] = 78;
            enemies[2].yPath[2] = 43;

            enemies[2].xPath[3] = 78;
            enemies[2].yPath[3] = 33;

            enemies[2].arrayPathSize = 4;

            enemies[3].xPos = 73;
            enemies[3].yPos = 88;
            enemies[3].xPosPrevious = enemies[3].xPos;
            enemies[3].yPosPrevious = enemies[3].yPos;
            enemies[3].show = 1;

            enemies[3].xPath[0] = 73;
            enemies[3].yPath[0] = 88;


            enemies[3].xPath[1] = 73;
            enemies[3].yPath[1] = 98;


            enemies[3].xPath[2] = 83;
            enemies[3].yPath[2] = 98;

            enemies[3].xPath[3] = 83;
            enemies[3].yPath[3] = 88;

            enemies[3].arrayPathSize = 4;



            enemies[4].xPos = 53;
            enemies[4].yPos = 48;
            enemies[4].xPosPrevious = enemies[4].xPos;
            enemies[4].yPosPrevious = enemies[4].yPos;
            enemies[4].show = 1;

            enemies[4].xPath[0] = 53;
            enemies[4].yPath[0] = 48;


            enemies[4].xPath[1] = 53;
            enemies[4].yPath[1] = 58;


            enemies[4].xPath[2] = 63;
            enemies[4].yPath[2] = 58;

            enemies[4].xPath[3] = 63;
            enemies[4].yPath[3] = 48;

            enemies[4].arrayPathSize = 4;

            enemies[5].xPos = 128;
            enemies[5].yPos = 58;
            enemies[5].xPosPrevious = enemies[5].xPos;
            enemies[5].yPosPrevious = enemies[5].yPos;
            enemies[5].show = 1;

            enemies[5].xPath[0] = 128;
            enemies[5].yPath[0] = 58;


            enemies[5].xPath[1] = 128;
            enemies[5].yPath[1] = 73;


            enemies[5].xPath[2] = 138;
            enemies[5].yPath[2] = 73;


            enemies[5].xPath[3] = 138;
            enemies[5].yPath[3] = 58;

            enemies[5].arrayPathSize = 4;

            enemies[6].xPos = 113;
            enemies[6].yPos = 98;
            enemies[6].xPosPrevious = enemies[6].xPos;
            enemies[6].yPosPrevious = enemies[6].yPos;
            enemies[6].show = 1;

            enemies[6].xPath[0] = 113;
            enemies[6].yPath[0] = 98;


            enemies[6].xPath[1] = 113;
            enemies[6].yPath[1] = 108;

            enemies[6].xPath[2] = 123;
            enemies[6].yPath[2] = 108;

            enemies[6].xPath[3] = 123;
            enemies[6].yPath[3] = 98;

            enemies[6].arrayPathSize = 4;

            enemies[7].xPos = 113;
            enemies[7].yPos = 33;
            enemies[7].xPosPrevious = enemies[7].xPos;
            enemies[7].yPosPrevious = enemies[7].yPos;
            enemies[7].show = 1;

            enemies[7].xPath[0] = 113;
            enemies[7].yPath[0] = 33;


            enemies[7].xPath[1] = 113;
            enemies[7].yPath[1] = 48;

            enemies[7].xPath[2] = 123;
            enemies[7].yPath[2] = 48;

            enemies[7].xPath[3] = 123;
            enemies[7].yPath[3] = 33;

            enemies[7].arrayPathSize = 4;

            break;
        }
        // Map 2
        case 2:{
            if(drawMap == 1){
                secondMapSetup(drawValues);
            }
            powerUp[0].xPos = 26;
            powerUp[0].yPos = 65;
            powerUp[0].show = 1;

            powerUp[1].xPos = 83;
            powerUp[1].yPos = 65;
            powerUp[1].show = 1;

            //Sets player position
            uint16_t xSTART = 19;
            uint16_t ySTART = 65;
            player->xPos = xSTART;
            player->yPos = ySTART;
            player->xPosPrevious = xSTART;
            player->yPosPrevious = ySTART;

            //enemy speed
            counter.speedEnemies = 20;
            //Sets enemies position
            enemies[0].xPos = 58;
            enemies[0].yPos = 50;
            enemies[0].xPosPrevious = enemies[0].xPos;
            enemies[0].yPosPrevious = enemies[0].yPos;
            enemies[0].show = 1;

            enemies[0].xPath[0] = 58;
            enemies[0].yPath[0] = 50;


            enemies[0].xPath[1] = 58;
            enemies[0].yPath[1] = 60;


            enemies[0].xPath[2] = 43;
            enemies[0].yPath[2] = 60;

            enemies[0].xPath[3] = 43;
            enemies[0].yPath[3] = 50;

            enemies[0].arrayPathSize = 4;

            enemies[1].xPos = 58;
            enemies[1].yPos = 60;
            enemies[1].xPosPrevious = enemies[1].xPos;
            enemies[1].yPosPrevious = enemies[1].yPos;
            enemies[1].show = 1;

            enemies[1].xPath[0] = 58;
            enemies[1].yPath[0] = 60;


            enemies[1].xPath[1] = 58;
            enemies[1].yPath[1] = 70;


            enemies[1].xPath[2] = 43;
            enemies[1].yPath[2] = 70;

            enemies[1].xPath[3] = 43;
            enemies[1].yPath[3] = 60;

            enemies[1].arrayPathSize = 4;

            enemies[2].xPos = 58;
            enemies[2].yPos = 70;
            enemies[2].xPosPrevious = enemies[2].xPos;
            enemies[2].yPosPrevious = enemies[2].yPos;
            enemies[2].show = 1;

            enemies[2].xPath[0] = 58;
            enemies[2].yPath[0] = 70;


            enemies[2].xPath[1] = 58;
            enemies[2].yPath[1] = 80;


            enemies[2].xPath[2] = 43;
            enemies[2].yPath[2] = 80;

            enemies[2].xPath[3] = 43;
            enemies[2].yPath[3] = 70;

            enemies[2].arrayPathSize = 4;

            // First 3 walls done, next 2 L figures

            enemies[3].xPos = 78;
            enemies[3].yPos = 55;
            enemies[3].xPosPrevious = enemies[3].xPos;
            enemies[3].yPosPrevious = enemies[3].yPos;
            enemies[3].show = 1;

            enemies[3].xPath[0] = 78;
            enemies[3].yPath[0] = 55;

            enemies[3].xPath[1] = 78;
            enemies[3].yPath[1] = 50;

            enemies[3].arrayPathSize = 2;



            enemies[4].xPos = 78;
            enemies[4].yPos = 75;
            enemies[4].xPosPrevious = enemies[4].xPos;
            enemies[4].yPosPrevious = enemies[4].yPos;
            enemies[4].show = 1;


            enemies[4].xPath[0] = 78;
            enemies[4].yPath[0] = 75;

            enemies[4].xPath[1] = 78;
            enemies[4].yPath[1] = 80;

            enemies[4].arrayPathSize = 2;

            enemies[5].xPos = 73;
            enemies[5].yPos = 75;
            enemies[5].xPosPrevious = enemies[5].xPos;
            enemies[5].yPosPrevious = enemies[5].yPos;
            enemies[5].show = 1;

            enemies[5].xPath[0] = 73;
            enemies[5].yPath[0] = 75;


            enemies[5].xPath[1] = 73;
            enemies[5].yPath[1] = 55;

            enemies[5].arrayPathSize = 2;

            enemies[6].xPos = 93;
            enemies[6].yPos = 50;
            enemies[6].xPosPrevious = enemies[6].xPos;
            enemies[6].yPosPrevious = enemies[6].yPos;
            enemies[6].show = 1;

            enemies[6].xPath[0] = 93;
            enemies[6].yPath[0] = 50;


            enemies[6].xPath[1] = 103;
            enemies[6].yPath[1] = 50;

            enemies[6].xPath[2] = 103;
            enemies[6].yPath[2] = 60;

            enemies[6].xPath[3] = 93;
            enemies[6].yPath[3] = 60;

            enemies[6].arrayPathSize = 4;

            enemies[7].xPos = 93;
            enemies[7].yPos = 80;
            enemies[7].xPosPrevious = enemies[7].xPos;
            enemies[7].yPosPrevious = enemies[7].yPos;
            enemies[7].show = 1;

            enemies[7].xPath[0] = 93;
            enemies[7].yPath[0] = 80;


            enemies[7].xPath[1] = 103;
            enemies[7].yPath[1] = 80;

            enemies[7].xPath[2] = 103;
            enemies[7].yPath[2] = 70;

            enemies[7].xPath[3] = 93;
            enemies[7].yPath[3] = 70;

            enemies[7].arrayPathSize = 4;

            enemies[8].xPos = 93;
            enemies[8].yPos = 60;
            enemies[8].xPosPrevious = enemies[8].xPos;
            enemies[8].yPosPrevious = enemies[8].yPos;
            enemies[8].show = 1;

            enemies[8].xPath[0] = 93;
            enemies[8].yPath[0] = 60;


            enemies[8].xPath[1] = 103;
            enemies[8].yPath[1] = 60;

            enemies[8].arrayPathSize = 2;

            enemies[9].xPos = 93;
            enemies[9].yPos = 70;
            enemies[9].xPosPrevious = enemies[9].xPos;
            enemies[9].yPosPrevious = enemies[9].yPos;
            enemies[9].show = 1;

            enemies[9].xPath[0] = 93;
            enemies[9].yPath[0] = 70;


            enemies[9].xPath[1] = 103;
            enemies[9].yPath[1] = 70;

            enemies[9].arrayPathSize = 2;

            enemies[10].xPos = 113;
            enemies[10].yPos = 65;
            enemies[10].xPosPrevious = enemies[10].xPos;
            enemies[10].yPosPrevious = enemies[10].yPos;
            enemies[10].show = 1;

            enemies[10].xPath[0] = 113;
            enemies[10].yPath[0] = 65;

            enemies[10].xPath[1] = 113;
            enemies[10].yPath[1] = 80;

            enemies[10].xPath[2] = 123;
            enemies[10].yPath[2] = 80;

            enemies[10].xPath[3] = 123;
            enemies[10].yPath[3] = 50;

            enemies[10].xPath[4] = 113;
            enemies[10].yPath[4] = 50;

            enemies[10].arrayPathSize = 5;

            enemies[11].xPos = 123;
            enemies[11].yPos = 50;
            enemies[11].xPosPrevious = enemies[11].xPos;
            enemies[11].yPosPrevious = enemies[11].yPos;
            enemies[11].show = 1;

            enemies[11].xPath[0] = 123;
            enemies[11].yPath[0] = 50;

            enemies[11].xPath[1] = 113;
            enemies[11].yPath[1] = 50;

            enemies[11].xPath[2] = 113;
            enemies[11].yPath[2] = 80;

            enemies[11].xPath[3] = 123;
            enemies[11].yPath[3] = 80;

            enemies[11].arrayPathSize = 4;

            enemies[12].xPos = 123;
            enemies[12].yPos = 80;
            enemies[12].xPosPrevious = enemies[12].xPos;
            enemies[12].yPosPrevious = enemies[12].yPos;
            enemies[12].show = 1;

            enemies[12].xPath[0] = 123;
            enemies[12].yPath[0] = 80;

            enemies[12].xPath[1] = 123;
            enemies[12].yPath[1] = 50;

            enemies[12].xPath[2] = 113;
            enemies[12].yPath[2] = 50;

            enemies[12].xPath[3] = 113;
            enemies[12].yPath[3] = 80;

            enemies[12].arrayPathSize = 4;

            enemies[13].xPos = 123;
            enemies[13].yPos = 60;
            enemies[13].xPosPrevious = enemies[13].xPos;
            enemies[13].yPosPrevious = enemies[13].yPos;
            enemies[13].show = 1;

            enemies[13].xPath[0] = 123;
            enemies[13].yPath[0] = 60;

            enemies[13].xPath[1] = 123;
            enemies[13].yPath[1] = 70;

            enemies[13].xPath[2] = 140;
            enemies[13].yPath[2] = 70;

            enemies[13].xPath[3] = 140;
            enemies[13].yPath[3] = 60;

            enemies[13].arrayPathSize = 4;

            break;
        }
        // Map 3
        case 3:{
            if(drawMap == 1){
                thirdMapSetup(drawValues);
            }

            powerUp[1].xPos = 93;
            powerUp[1].yPos = 59;
            powerUp[1].show = 1;


            //Sets player position
            uint16_t xSTART = 19;
            uint16_t ySTART = 65;
            player->xPos = xSTART;
            player->yPos = ySTART;
            player->xPosPrevious = xSTART;
            player->yPosPrevious = ySTART;

            counter.speedEnemies = 20;
            //Sets enemies position
            enemies[0].xPos = 53;
            enemies[0].yPos = 75;
            enemies[0].xPosPrevious = enemies[0].xPos;
            enemies[0].yPosPrevious = enemies[0].yPos;
            enemies[0].show = 1;

            enemies[0].xPath[0] = 53;
            enemies[0].yPath[0] = 75;


            enemies[0].xPath[1] = 53;
            enemies[0].yPath[1] = 54;

            enemies[0].arrayPathSize = 2;


            enemies[1].xPos = 63;
            enemies[1].yPos = 54;
            enemies[1].xPosPrevious = enemies[1].xPos;
            enemies[1].yPosPrevious = enemies[1].yPos;
            enemies[1].show = 1;

            enemies[1].xPath[0] = 63;
            enemies[1].yPath[0] = 54;


            enemies[1].xPath[1] = 78;
            enemies[1].yPath[1] = 54;

            enemies[1].arrayPathSize = 2;

            enemies[2].xPos = 68;
            enemies[2].yPos = 64;
            enemies[2].xPosPrevious = enemies[2].xPos;
            enemies[2].yPosPrevious = enemies[2].yPos;
            enemies[2].show = 1;

            enemies[2].xPath[0] = 68;
            enemies[2].yPath[0] = 64;


            enemies[2].xPath[1] = 73;
            enemies[2].yPath[1] = 64;


            enemies[2].arrayPathSize = 2;

            // First 3 walls done, next 2 L figures

            enemies[3].xPos = 68;
            enemies[3].yPos = 74;
            enemies[3].xPosPrevious = enemies[3].xPos;
            enemies[3].yPosPrevious = enemies[3].yPos;
            enemies[3].show = 1;

            enemies[3].xPath[0] = 68;
            enemies[3].yPath[0] = 74;


            enemies[3].xPath[1] = 63;
            enemies[3].yPath[1] = 74;

            enemies[3].arrayPathSize = 2;

            enemies[4].xPos = 78;
            enemies[4].yPos = 79;
            enemies[4].xPosPrevious = enemies[4].xPos;
            enemies[4].yPosPrevious = enemies[4].yPos;
            enemies[4].show = 1;

            enemies[4].xPath[0] = 78;
            enemies[4].yPath[0] = 79;


            enemies[4].xPath[1] = 93;
            enemies[4].yPath[1] = 79;

            enemies[4].arrayPathSize = 2;

            enemies[5].xPos = 83;
            enemies[5].yPos = 64;
            enemies[5].xPosPrevious = enemies[5].xPos;
            enemies[5].yPosPrevious = enemies[5].yPos;
            enemies[5].show = 1;

            enemies[5].xPath[0] = 83;
            enemies[5].yPath[0] = 64;


            enemies[5].xPath[1] = 108;
            enemies[5].yPath[1] = 64;

            enemies[5].arrayPathSize = 2;

            enemies[6].xPos = 118;
            enemies[6].yPos = 59;
            enemies[6].xPosPrevious = enemies[6].xPos;
            enemies[6].yPosPrevious = enemies[6].yPos;
            enemies[6].show = 1;

            enemies[6].xPath[0] = 118;
            enemies[6].yPath[0] = 59;


            enemies[6].xPath[1] = 118;
            enemies[6].yPath[1] = 54;

            enemies[6].arrayPathSize = 2;

            enemies[7].xPos = 118;
            enemies[7].yPos = 69;
            enemies[7].xPosPrevious = enemies[7].xPos;
            enemies[7].yPosPrevious = enemies[7].yPos;
            enemies[7].show = 1;

            enemies[7].xPath[0] = 118;
            enemies[7].yPath[0] = 69;


            enemies[7].xPath[1] = 118;
            enemies[7].yPath[1] = 74;

            enemies[7].arrayPathSize = 2;

            enemies[8].xPos = 128;
            enemies[8].yPos = 54;
            enemies[8].xPosPrevious = enemies[8].xPos;
            enemies[8].yPosPrevious = enemies[8].yPos;
            enemies[8].show = 1;

            enemies[8].xPath[0] = 128;
            enemies[8].yPath[0] = 54;


            enemies[8].xPath[1] = 128;
            enemies[8].yPath[1] = 73;

            enemies[8].arrayPathSize = 2;
            break;
        }
        //default (wrong input)
        default:{
            break;
        }
    }
}

uint8_t setupLevel(struct mapPackage *maps, struct drawItems *drawValues, struct player *player, struct enemy *enemy, uint8_t drawMap, struct powerUp *powerUp, uint8_t ship){
    //init map and Draw Map and SetWallHitBox
    LevelManager(maps, drawValues, player, enemy, drawMap, powerUp);

    //draws the players initial position
    uint8_t moveDirection = (*player).direction;
    ShipSelection(moveDirection, ship, player, drawValues);

    //draw currentMapLevel
    upDateCurrentLevel(maps);
    //draw health
    upDateHealth((*player).lives);

    //LED
    GameLED(2);
    return moveDirection;
}


