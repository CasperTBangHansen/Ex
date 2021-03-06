/*
**
**                           ControlSystem.c
**
**
**********************************************************************/
/*********************************************************************
   Primary editor  :    Mathias Jensen
   Secondary editor: Casper Bang - Hansen

**********************************************************************/

//include .h file
#include "ControlSystem.h"

//defines
//Symbols
#define ESC 0x1B
#define SPACE 0x20

// userInput takes the users keyboard input and sets either the players position or spawns bullets

uint8_t userInput(struct player *player){
    // Adds a variable to use for registering the pressed button
    char buttonPress;
    //makes variable to get the players direction
    uint8_t moveDirection = 0;
    //for checking if a bullet is shot
    uint8_t shootAllBullets = 0;

    //Set the players velocities to 0
    int8_t yVelocity = 0;
    int8_t xVelocity = 0;

    //Sets the variable to the button the person has pressed
    buttonPress = uart_get_char();

    //returns 0 if there were no button pressed (makes the function much faster)
    if (buttonPress == '\0'){
        return 0;
        //Boss key below
    } else if(buttonPress == 0x1B){
        printf("%c[%d%c",0x1B,2,0x4A);
        gotoxy(1,1);
        printf("Microsoft Windows [Version 10.0.17763.914]\n");
        printf("(c) 2018 Microsoft Corporation. All rights reserved.\n");
        printf("C:\\Users\\StarWarsFan180381>");
        while(1);
        //CHanges player direciton dependant on which key is pressed
    } else if(buttonPress == 'w' ){
        yVelocity = -1;
        player->direction = 1;
        moveDirection = 1;
    } else if(buttonPress == 'a'){
        xVelocity = -1;
        player->direction = 2;
        moveDirection = 2;
    } else if(buttonPress == 's'){
        yVelocity = 1;
        player->direction = 3;
        moveDirection = 3;
    } else if(buttonPress == 'd'){
        xVelocity = 1;
        player->direction = 4;
        moveDirection = 4;
    } else if(buttonPress == 0x20){

        if((*player).bulletType == 1){

        //runs through all the bullets
            for(int8_t i = 0; i < 3; i++){
                //checks if there is a bullet that doesn't exist
                if((*player).shots[i].show == 0){
                    player->score -= 50;
                    //set the bullet to exist
                    (*player).shots[i].show = 1;
                    //checks the player direction and depending on the direction the bullet will spawn in front of the player with a velocity in that direction
                    if((*player).direction == 1){
                        setupBullet(player, 0, -2, 0, -1,i);
                    } else if((*player).direction == 2) {
                        setupBullet(player, -2, 0, -1, 0, i);
                    } else if((*player).direction == 3){
                        setupBullet(player, 0, 2, 0, 1, i);
                    } else if((*player).direction == 4){
                        setupBullet(player, 2, 0, 1, 0, i);
                    }
                //when a bullet is spawned break out of the forloop (makes the function faster, because there is no need for checking for other bullets after)
                break;
                }
            }
        } else if((*player).bulletType == 2){
            for(int8_t i = 0; i < 3; i++){
                if((*player).shots[i].show == 1){
                    shootAllBullets = 1;
                }
            }
            if(shootAllBullets == 0){
                player->score -= 150;
                (*player).shots[0].show = 1;
                (*player).shots[1].show = 1;
                (*player).shots[2].show = 1;
                //checks the player direction and depending on the direction the bullet will spawn in front of the player with a velocity in that direction
                if((*player).direction == 1){
                    setupBullet(player, -1, -2, 0, -1, 0);
                    setupBullet(player, 0, -2, 0, -1, 1);
                    setupBullet(player, 1, -2, 0, -1, 2);
                } else if((*player).direction == 2) {
                    setupBullet(player, -2, -1, -1, 0, 0);
                    setupBullet(player, -2, 0, -1, 0, 1);
                    setupBullet(player, -2, 1, -1, 0, 2);
                } else if((*player).direction == 3){
                    setupBullet(player, -1, 2, 0, 1, 0);
                    setupBullet(player, 0, 2, 0, 1, 1);
                    setupBullet(player, 1, 2, 0, 1, 2);
                } else if((*player).direction == 4){
                    setupBullet(player, 2, -1, 1, 0, 0);
                    setupBullet(player, 2, 0, 1, 0, 1);
                    setupBullet(player, 2, 1, 1, 0, 2);
                }
            }
        }
    }
    //updates the players position
    player->xPos += xVelocity;
    player->yPos += yVelocity;
    //cleans the uart input
    uart_clear();
    //returns the players direction
    return moveDirection;
}


// depending on the input a bullet is spawned with a given position and velocity.

static void setupBullet(struct player *player, int8_t xPosOffSet, int8_t yPosOffSet, int8_t xShotsMaxVelocity, int8_t yShotsMaxVelocity, uint8_t i){
    //spawns a bullet with a given position and velocity
    (*player).shots[i].xPos = (*player).xPos + xPosOffSet;
    (*player).shots[i].yPos = (*player).yPos + yPosOffSet;
    (*player).shots[i].xVelocity = xShotsMaxVelocity;
    (*player).shots[i].yVelocity = yShotsMaxVelocity;
}

