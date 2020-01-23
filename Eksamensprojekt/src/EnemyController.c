/*
**
**                           EnemyController.c
**
**
**********************************************************************/
/*
   Primary editor  :    Casper Bang-Hansen
   Secondary editor:
   Last changed by :    20/01 - 2020

   Functions       :

**********************************************************************/

//include .h file
#include "EnemyController.h"
#define enemySize 20



void upDatePosition(struct enemy *enemies){
    gotoxy(1,10);
    uint8_t maxEnemyVelocity = 1;
    uint8_t position;
    for(uint8_t i = 0; i < enemySize; i++){
        if(enemies[i].show == 1){
            for(uint8_t j = 0; j < enemies[i].arrayPathSize; j++){
                if(enemies[i].xPos == enemies[i].xPath[j] && enemies[i].yPos == enemies[i].yPath[j]){
                    if(j == enemies[i].arrayPathSize-1){
                        position = 0;
                    } else{
                        position = j + 1;
                    }

                    if(enemies[i].xPath[j] == enemies[i].xPath[position]){
                        if(enemies[i].yPath[j] > enemies[i].yPath[position]){
                            enemies[i].xVelocity = 0;
                            enemies[i].yVelocity = -maxEnemyVelocity;
                        } else {
                            enemies[i].xVelocity = 0;
                            enemies[i].yVelocity = maxEnemyVelocity;
                        }
                    } else if(enemies[i].yPath[j] == enemies[i].yPath[position]){
                        if(enemies[i].xPath[j] > enemies[i].xPath[position]){
                            enemies[i].xVelocity = -maxEnemyVelocity;
                            enemies[i].yVelocity = 0;
                        } else {
                            enemies[i].xVelocity = maxEnemyVelocity;
                            enemies[i].yVelocity = 0;
                        }
                    }
                }
            }
            enemies[i].xPos += enemies[i].xVelocity;
            enemies[i].yPos += enemies[i].yVelocity;
        }
    }
}

