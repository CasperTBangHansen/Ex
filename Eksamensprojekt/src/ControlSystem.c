/*
**
**                           ControlSystem.c
**
**
**********************************************************************/
/*
   Primary editor  :    Mathias Jensen
   Secondary editor:    Casper Bang-Hansen
   Last changed by :    19/01 - 2020

   Functions       :    uint8_t userInput(struct player *player);
                        static void setupBullet(struct player *player, int8_t xPosOffSet, int8_t yPosOffSet, int8_t xShotsMaxVelocity, int8_t yShotsMaxVelocity, uint8_t i);

**********************************************************************/

//include .h file
#include "ControlSystem.h"

//defines
//Symbols
#define ESC 0x1B
#define SPACE 0x20


/**********************************************************************

   Description     :    userInput takes the users keyboard input and sets either the players position or spawns bullets
                        depending on what key is pressed

   Input           :    struct player *player

   Output          :    uint8_t direction

**********************************************************************/


uint8_t userInput(struct player *player){
    // Adds a variable to use for registering the pressed button
    char buttonPress;
    //makes variable to get the players direction
    uint8_t moveDirection = 0;

    //player and shots max velocities in a given direction
    int8_t playerMaxVelocity = 1;
    int8_t shotsMaxVelocity = 1;

    //Bullet movement
    for(int8_t i = 0; i < 3; i++){
        if((*player).shots[i].show == 1){
            (*player).shots[i].xPos += (*player).shots[i].xVelocity;
            (*player).shots[i].yPos += (*player).shots[i].yVelocity;
        }
    }

    //Set the players velocities to 0
    player->yVelocity = 0;
    player->xVelocity = 0;

    //Sets the variable to the button the person has pressed
    buttonPress = uart_get_char();

    //returns 0 if there were no button pressed (makes the function much faster)
    if (buttonPress == '\0'){
        return 0;
    }

    // If and only if the pressed button is "w", the players moves up
    if(buttonPress == 'w' ){
        player->yVelocity = -playerMaxVelocity;
        player->direction = 1;
        moveDirection = 1;
    }

    // If and only if the pressed button is "a", the players moves left
    if(buttonPress == 'a'){
        player->xVelocity = -playerMaxVelocity;
        player->direction = 2;
        moveDirection = 2;
    }

    // If and only if the pressed button is "s", the players moves down
    if(buttonPress == 's'){
        player->yVelocity = playerMaxVelocity;
        player->direction = 3;
        moveDirection = 3;
    }

    // If and only if the pressed button is "d", the players moves right
    if(buttonPress == 'd'){
        player->xVelocity = playerMaxVelocity;
        player->direction = 4;
        moveDirection = 4;
    }
    // If and only if the pressed button is 0x20 (space), the players shoots (if the player can shoot)
    if(buttonPress == 0x20){
        //runs through all the bullets
        for(int8_t i = 0; i < 3; i++){
            //checks if there is a bullet that doesn't exist
            if((*player).shots[i].show == 0){
                //set the bullet to exist
                (*player).shots[i].show = 1;
                //checks the player direction and depending on the direction the bullet will spawn in front of the player with a velocity in that direction
                if((*player).direction == 1){
                    setupBullet(player, 0, -2, 0, -shotsMaxVelocity, i);
                } else if((*player).direction == 2) {
                    setupBullet(player, -2, 0, -shotsMaxVelocity, 0, i);
                } else if((*player).direction == 3){
                    setupBullet(player, 0, 2, 0, shotsMaxVelocity, i);
                } else if((*player).direction == 4){
                    setupBullet(player, 2, 0, shotsMaxVelocity, 0, i);
                }
            //when a bullet is spawned break out of the forloop (makes the function faster, because there is no need for checking for other bullets after)
            break;
            }
        }
    }
    //updates the players position
    player->xPos = (*player).xVelocity + (*player).xPos;
    player->yPos = (*player).yVelocity + (*player).yPos;
    //cleans the uart input
    uart_clear();
    //returns the players direction
    return moveDirection;
}


/**********************************************************************

   Description     :    depending on the input a bullet is spawned with a given position and velocity.

   Input           :    struct player *player
                        int8_t xPosOffSet
                        int8_t yPosOffSet
                        int8_t xShotsMaxVelocity
                        int8_t yShotsMaxVelocity
                        uint8_t i


   Output          :    void

**********************************************************************/

static void setupBullet(struct player *player, int8_t xPosOffSet, int8_t yPosOffSet, int8_t xShotsMaxVelocity, int8_t yShotsMaxVelocity, uint8_t i){
    //spawns a bullet with a given position and velocity
    (*player).shots[i].xPos = (*player).xPos + xPosOffSet;
    (*player).shots[i].xPosPrevious = (*player).xPosPrevious;
    (*player).shots[i].yPos = (*player).yPos + yPosOffSet;
    (*player).shots[i].yPosPrevious = (*player).yPosPrevious;
    (*player).shots[i].xVelocity = xShotsMaxVelocity;
    (*player).shots[i].yVelocity = yShotsMaxVelocity;
}

