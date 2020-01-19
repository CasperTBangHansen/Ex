/*
**
**                           Collider.c
**
**
**********************************************************************/
/*
   Primary editor  :    Casper Bang - Hansen
   Secondary editor:
   Last changed by :    19/01 - 2020

   Functions       :    void setWallHitBox(struct drawItems *drawValues, uint16_t mapHitBoxSize);
                        void checkCollider(struct player *playerHitBox, struct enemy *enemies);
                        static uint16_t checkColliderLeftToRight(uint16_t xPos, uint16_t xPosPrevious, uint8_t yPos, uint8_t yPosPrevious, int8_t xVelocity, int8_t yVelocity, uint16_t i);
                        static uint16_t checkColliderRightToLeft(uint16_t xPos, uint16_t xPosPrevious, uint8_t yPos, uint8_t yPosPrevious, int8_t xVelocity, int8_t yVelocity, uint16_t i);
                        static uint16_t checkColliderTopToBottom(uint16_t xPos, uint16_t xPosPrevious, uint8_t yPos, uint8_t yPosPrevious, int8_t xVelocity, int8_t yVelocity, uint16_t i);
                        static uint16_t checkColliderBottomToTop(uint16_t xPos, uint16_t xPosPrevious, uint8_t yPos, uint8_t yPosPrevious, int8_t xVelocity, int8_t yVelocity, uint16_t i);
                        static uint8_t checkColliderXEnemy(uint16_t xPos, uint16_t xPosPrevious, uint8_t yPos, uint8_t yPosPrevious, int8_t xVelocity, int8_t yVelocity, uint16_t enemiesXPos, uint8_t enemiesYPos);
                        static uint8_t checkColliderYEnemy(uint16_t xPos, uint16_t xPosPrevious, uint8_t yPos, uint8_t yPosPrevious, int8_t xVelocity, int8_t yVelocity, uint16_t enemiesXPos, uint8_t enemiesYPos);



**********************************************************************/

//Includes
#include "Collider.h"

//Draw buffer size
#define arraySize 300

//static variables that can be seen by all functions in this .c file
static uint16_t xPosStart[arraySize];
static uint8_t yPosStart[arraySize];
static uint16_t xPosSlut[arraySize];
static uint8_t yPosSlut[arraySize];
static uint16_t sizeOfArrays = 0;


/**********************************************************************

   Description     :    setWallHitBox takes an input struct and saves this structs hitbox in this .c file.
                        This means the hitbox of the walles is saved and the map hitbox size is also saved.

   Input           :    struct drawItems *drawValues
                        uint16_t mapHitBoxSize

   Output          :    void

**********************************************************************/
void setWallHitBox(struct drawItems *drawValues, uint16_t mapHitBoxSize){
    //sets the size of mapHitBox
    sizeOfArrays = mapHitBoxSize;
    //Saves all the positions in drawValues in a static uint array.
    for(uint16_t i = 0; i <= sizeOfArrays; i++){
        xPosStart[i] = drawValues[i].xStart;
        yPosStart[i] = drawValues[i].yStart;
        xPosSlut[i] = drawValues[i].xSlut;
        yPosSlut[i] = drawValues[i].ySlut;
    }
}

/**********************************************************************

   Description     :    checkCollider checks collision with other objects.
                        The check collisions are:
                        Player - Wall
                        Shot   - Wall
                        Player - Enemy
                        Enemy  - Shot

   Input           :    struct drawItems *drawValues
                        struct enemy *enemies

   Output          :    void

**********************************************************************/

void checkCollider(struct player *playerHitBox, struct enemy *enemies){
    //Runes through all the walls
    for(int16_t i = 0; i <= sizeOfArrays; i++){

        //Checks all 3 pixels on the far right of the players hit box
        playerHitBox->xPos = checkColliderLeftToRight((*playerHitBox).xPos + 1, (*playerHitBox).xPosPrevious, (*playerHitBox).yPos + 1, (*playerHitBox).yPosPrevious, (*playerHitBox).xVelocity, (*playerHitBox).yVelocity, i) - 1;
        playerHitBox->xPos = checkColliderLeftToRight((*playerHitBox).xPos + 1, (*playerHitBox).xPosPrevious, (*playerHitBox).yPos, (*playerHitBox).yPosPrevious, (*playerHitBox).xVelocity, (*playerHitBox).yVelocity, i) - 1;
        playerHitBox->xPos = checkColliderLeftToRight((*playerHitBox).xPos + 1, (*playerHitBox).xPosPrevious, (*playerHitBox).yPos - 1, (*playerHitBox).yPosPrevious, (*playerHitBox).xVelocity, (*playerHitBox).yVelocity, i) - 1;

        //Checks all 3 pixels on the far left of the players hit box
        playerHitBox->xPos = checkColliderRightToLeft((*playerHitBox).xPos - 1, (*playerHitBox).xPosPrevious, (*playerHitBox).yPos + 1, (*playerHitBox).yPosPrevious, (*playerHitBox).xVelocity, (*playerHitBox).yVelocity, i) + 1;
        playerHitBox->xPos = checkColliderRightToLeft((*playerHitBox).xPos - 1, (*playerHitBox).xPosPrevious, (*playerHitBox).yPos, (*playerHitBox).yPosPrevious, (*playerHitBox).xVelocity, (*playerHitBox).yVelocity, i) + 1;
        playerHitBox->xPos = checkColliderRightToLeft((*playerHitBox).xPos - 1, (*playerHitBox).xPosPrevious, (*playerHitBox).yPos - 1, (*playerHitBox).yPosPrevious, (*playerHitBox).xVelocity, (*playerHitBox).yVelocity, i) + 1;

        //Checks all 3 pixels on the top of the players hit box
        playerHitBox->yPos = checkColliderTopToBottom((*playerHitBox).xPos + 1, (*playerHitBox).xPosPrevious, (*playerHitBox).yPos + 1, (*playerHitBox).yPosPrevious, (*playerHitBox).xVelocity, (*playerHitBox).yVelocity, i) - 1;
        playerHitBox->yPos = checkColliderTopToBottom((*playerHitBox).xPos, (*playerHitBox).xPosPrevious, (*playerHitBox).yPos + 1, (*playerHitBox).yPosPrevious, (*playerHitBox).xVelocity, (*playerHitBox).yVelocity, i) - 1;
        playerHitBox->yPos = checkColliderTopToBottom((*playerHitBox).xPos - 1, (*playerHitBox).xPosPrevious, (*playerHitBox).yPos + 1, (*playerHitBox).yPosPrevious, (*playerHitBox).xVelocity, (*playerHitBox).yVelocity, i) - 1;

        //Checks all 3 pixels on the Bottom of the players hit box
        playerHitBox->yPos = checkColliderBottomToTop((*playerHitBox).xPos + 1, (*playerHitBox).xPosPrevious, (*playerHitBox).yPos - 1, (*playerHitBox).yPosPrevious, (*playerHitBox).xVelocity, (*playerHitBox).yVelocity, i) + 1;
        playerHitBox->yPos = checkColliderBottomToTop((*playerHitBox).xPos, (*playerHitBox).xPosPrevious, (*playerHitBox).yPos - 1, (*playerHitBox).yPosPrevious, (*playerHitBox).xVelocity, (*playerHitBox).yVelocity, i) + 1;
        playerHitBox->yPos = checkColliderBottomToTop((*playerHitBox).xPos - 1, (*playerHitBox).xPosPrevious, (*playerHitBox).yPos - 1, (*playerHitBox).yPosPrevious, (*playerHitBox).xVelocity, (*playerHitBox).yVelocity, i) + 1;


        //Checks if the bullets collide with a wall
        for(int8_t j = 0; j < 3; j++){
            //Do the bullet exist?
            if((*playerHitBox).shots[j].show == 1){
                //Check collision
                (*playerHitBox).shots[j].xPos = checkColliderLeftToRight((*playerHitBox).shots[j].xPos, (*playerHitBox).shots[j].xPosPrevious, (*playerHitBox).shots[j].yPos, (*playerHitBox).shots[j].yPosPrevious, (*playerHitBox).shots[j].xVelocity, (*playerHitBox).shots[j].yVelocity, i);
                (*playerHitBox).shots[j].xPos = checkColliderRightToLeft((*playerHitBox).shots[j].xPos, (*playerHitBox).shots[j].xPosPrevious, (*playerHitBox).shots[j].yPos, (*playerHitBox).shots[j].yPosPrevious, (*playerHitBox).shots[j].xVelocity, (*playerHitBox).shots[j].yVelocity, i);
                (*playerHitBox).shots[j].yPos = checkColliderTopToBottom((*playerHitBox).shots[j].xPos, (*playerHitBox).shots[j].xPosPrevious, (*playerHitBox).shots[j].yPos, (*playerHitBox).shots[j].yPosPrevious, (*playerHitBox).shots[j].xVelocity, (*playerHitBox).shots[j].yVelocity, i);
                (*playerHitBox).shots[j].yPos = checkColliderBottomToTop((*playerHitBox).shots[j].xPos, (*playerHitBox).shots[j].xPosPrevious, (*playerHitBox).shots[j].yPos, (*playerHitBox).shots[j].yPosPrevious, (*playerHitBox).shots[j].xVelocity, (*playerHitBox).shots[j].yVelocity, i);

                //If the bullets position was the same as last tick the bullet should not exist anymore.
                //This is because if the previous position is the same as the current the bullet have hit a wall
                if((*playerHitBox).shots[j].xPos == (*playerHitBox).shots[j].xPosPrevious && (*playerHitBox).shots[j].yPos == (*playerHitBox).shots[j].yPosPrevious){
                   (*playerHitBox).shots[j].show = 0;
                }
            }
        }
    }

    //Checks if the bullets collide with an enemy
    for(int8_t j = 0; j < 3; j++){
        //Do the bullet exist?
        if((*playerHitBox).shots[j].show == 1){
            //Checks for every enemy
            for(uint8_t w = 0; w < 20; w++){
                //Do the enemy exist?
                if(enemies[w].show == 1){
                     //Check collision between an enemy and a bullet in the x-direction
                    if (checkColliderXEnemy((*playerHitBox).shots[j].xPos, (*playerHitBox).shots[j].xPosPrevious, (*playerHitBox).shots[j].yPos, (*playerHitBox).shots[j].yPosPrevious, (*playerHitBox).shots[j].xVelocity, (*playerHitBox).shots[j].yVelocity, enemies[w].xPos, enemies[w].yPos)){
                        //removes bullet and enemy
                        (*playerHitBox).shots[j].show = 0;
                        enemies[w].show = 0;
                    }
                      //Check collision between an enemy and a bullet in the y-direction
                    if (checkColliderYEnemy((*playerHitBox).shots[j].xPos, (*playerHitBox).shots[j].xPosPrevious, (*playerHitBox).shots[j].yPos, (*playerHitBox).shots[j].yPosPrevious, (*playerHitBox).shots[j].xVelocity, (*playerHitBox).shots[j].yVelocity, enemies[w].xPos, enemies[w].yPos)){
                        //removes bullet and enemy
                        (*playerHitBox).shots[j].show = 0;
                        enemies[w].show = 0;
                    }
                }
            }
        }
    }
    //Checks if the player collide with an enemy
    int8_t hit = 0;
    //Checks for every enemy
    for(int8_t w = 0; w < 20; w++){
        //checks if the enemy exist
        if(enemies[w].show == 1){
            //checks if the player hit an enemy in the x-direction and if the player was previously hit this tick.
            if (hit == 0 && checkColliderXEnemy((*playerHitBox).xPos, (*playerHitBox).xPosPrevious, (*playerHitBox).yPos, (*playerHitBox).yPosPrevious, (*playerHitBox).xVelocity, (*playerHitBox).yVelocity, enemies[w].xPos, enemies[w].yPos)){
                //sets the players live counter one lower then it was before
                playerHitBox->lives = (*playerHitBox).lives - 1;
                hit = 1;
            }
            //checks if the player hit an enemy in the y-direction and if the player was previously hit this tick.
            if (hit == 0 && checkColliderYEnemy((*playerHitBox).xPos, (*playerHitBox).xPosPrevious, (*playerHitBox).yPos, (*playerHitBox).yPosPrevious, (*playerHitBox).xVelocity, (*playerHitBox).yVelocity, enemies[w].xPos, enemies[w].yPos)){
                //sets the players live counter one lower then it was before
                playerHitBox->lives = (*playerHitBox).lives - 1;
                hit = 1;
            }
        }
    }
}

/**********************************************************************

   Description     :    checkColliderXEnemy checks if the object hit an enemy in the x-direction

   Input           :    uint16_t xPos               (object)
                        uint16_t xPosPrevious       (object)
                        uint8_t yPos                (object)
                        uint8_t yPosPrevious        (object)
                        int8_t xVelocity            (object)
                        int8_t yVelocity            (object)
                        uint16_t enemiesXPos        (enemy)
                        uint8_t enemiesYPo          (enemy)


   Output          :    uint8_t                     (1/0)

**********************************************************************/

static uint8_t checkColliderXEnemy(uint16_t xPos, uint16_t xPosPrevious, uint8_t yPos, uint8_t yPosPrevious, int8_t xVelocity, int8_t yVelocity, uint16_t enemiesXPos, uint8_t enemiesYPos){
    if((yPosPrevious <= enemiesYPos && yPos >= enemiesYPos) || (yPosPrevious >= enemiesYPos && yPos <= enemiesYPos)){
        if(xVelocity > 0){
            if(xPosPrevious <= enemiesXPos && xPos >= enemiesXPos){
                //player hit the enemy
                return 1;
            }
        } else if (xVelocity < 0){
            if(xPosPrevious >= enemiesXPos && xPos <= enemiesXPos){
                //player hit the enemy
                return 1;
            }
        }
    }
    //object didn't hit the enemy
    return 0;
}

/**********************************************************************

   Description     :    checkColliderYEnemy checks if the object hit an enemy in the y-direction

   Input           :    uint16_t xPos               (object)
                        uint16_t xPosPrevious       (object)
                        uint8_t yPos                (object)
                        uint8_t yPosPrevious        (object)
                        int8_t xVelocity            (object)
                        int8_t yVelocity            (object)
                        uint16_t enemiesXPos        (enemy)
                        uint8_t enemiesYPo          (enemy)


   Output          :    uint8_t                     (1/0)

**********************************************************************/

static uint8_t checkColliderYEnemy(uint16_t xPos, uint16_t xPosPrevious, uint8_t yPos, uint8_t yPosPrevious, int8_t xVelocity, int8_t yVelocity, uint16_t enemiesXPos, uint8_t enemiesYPos){
    if((xPosPrevious <= enemiesXPos && xPos >= enemiesXPos) || (xPosPrevious >= enemiesXPos && xPos <= enemiesXPos)){
        if(yVelocity > 0){
            if(yPosPrevious <= enemiesYPos && yPos >= enemiesYPos){
                //player hit the enemy
                return 1;
            }
        } else if (yVelocity < 0){
            if(yPosPrevious >= enemiesYPos && yPos <= enemiesYPos){
                //player hit the enemy
                return 1;
            }
        }
    }
    //object didn't hit the enemy
    return 0;
}

/**********************************************************************

   Description     :    checkColliderLeftToRight checks if the object hit a wall in the x-direction from left to right

   Input           :    uint16_t xPos
                        uint16_t xPosPrevious
                        uint8_t yPos
                        uint8_t yPosPrevious
                        int8_t xVelocity
                        int8_t yVelocity
                        uint8_t i


   Output          :    uint16_t xPos       (objects position)

**********************************************************************/

static uint16_t checkColliderLeftToRight(uint16_t xPos, uint16_t xPosPrevious, uint8_t yPos, uint8_t yPosPrevious, int8_t xVelocity, int8_t yVelocity, uint16_t i){
    //checks if the object moves in the positive x-direction and the wall is horizontal
    if(xPosStart[i] == xPosSlut[i] && xVelocity > 0){
        //checks if the objects previous position was before the wall and the objects current position is after the wall.
        //checks if the wall is in the right y-position for the object to hit it.
        if(xPosPrevious < xPosStart[i] && xPosStart[i] <= xPos && yPosStart[i] <= yPos && yPosSlut[i] >= yPos){
            //temp value
            uint16_t xPosTemp = xPos;
            //lowers the speed of the object by one until it hits zero
            for(int8_t j = xPos - xPosPrevious; j > 0; j--){
                //checks if the object could move closer to the wall if the object had a lower speed
                if(xPosPrevious < xPosStart[i] && xPosStart[i] <= xPosTemp){
                    xPosTemp = xPosTemp - 1;
                }
            }
            //updates the objects position
            xPos = xPosTemp;
        }
    }
    //returns the objects position
    return xPos;
}

/**********************************************************************

   Description     :    checkColliderRightToLeft checks if the object hit a wall in the x-direction from right to left

   Input           :    uint16_t xPos
                        uint16_t xPosPrevious
                        uint8_t yPos
                        uint8_t yPosPrevious
                        int8_t xVelocity
                        int8_t yVelocity
                        uint8_t i


   Output          :    uint16_t xPos       (objects position)

**********************************************************************/

static uint16_t checkColliderRightToLeft(uint16_t xPos, uint16_t xPosPrevious, uint8_t yPos, uint8_t yPosPrevious, int8_t xVelocity, int8_t yVelocity, uint16_t i){
    //checks if the object moves in the negative x-direction and the wall is horizontal
    if(xPosStart[i] == xPosSlut[i] && xVelocity < 0){
        //checks if the objects previous position was before the wall and the objects current position is after the wall.
        //checks if the wall is in the right y-position for the object to hit it.
        if(xPosPrevious > xPosStart[i] && xPosStart[i] >= xPos && yPosStart[i] <= yPos && yPosSlut[i] >= yPos){
            //temp value
            uint16_t xPosTemp = xPos;
            //lowers the speed of the object by one until it hits zero
            for(int8_t j = xPosPrevious-xPos; j > 0; j--){
                //checks if the object could move closer to the wall if the object had a lower speed
                if(xPosPrevious > xPosStart[i] && xPosStart[i] >= xPosTemp){
                    xPosTemp = xPosTemp + 1;
                }
            }
            //updates the objects position
            xPos = xPosTemp;
        }
    }
    //returns the objects position
    return xPos;
}

/**********************************************************************

   Description     :    checkColliderTopToBottom checks if the object hit a wall in the y-direction from top to bottom

   Input           :    uint16_t xPos
                        uint16_t xPosPrevious
                        uint8_t yPos
                        uint8_t yPosPrevious
                        int8_t xVelocity
                        int8_t yVelocity
                        uint8_t i


   Output          :    uint16_t yPos       (objects position)

**********************************************************************/

static uint16_t checkColliderTopToBottom(uint16_t xPos, uint16_t xPosPrevious, uint8_t yPos, uint8_t yPosPrevious, int8_t xVelocity, int8_t yVelocity, uint16_t i){
    //checks if the object moves in the positive y-direction and the wall is vertical
    if(yPosStart[i] == yPosSlut[i] && yVelocity > 0){
        //checks if the objects previous position was before the wall and the objects current position is after the wall.
        //checks if the wall is in the right x-position for the object to hit it.
        if(yPosPrevious < yPosStart[i] && yPosStart[i] <= yPos && xPosStart[i] <= xPos && xPosSlut[i] >= xPos){
            //temp value
            uint8_t yPosTemp = yPos;
            //lowers the speed of the object by one until it hits zero
            for(int8_t j = yPos - yPosPrevious; j > 0; j--){
                //checks if the object could move closer to the wall if the object had a lower speed
                if(yPosPrevious < yPosStart[i] && yPosStart[i] <= yPosTemp){
                    yPosTemp = yPosTemp - 1;
                }
            }
            //updates the objects position
            yPos = yPosTemp;
        }
    }
    //returns the objects position
    return yPos;
}

/**********************************************************************

   Description     :    checkColliderBottomToTop checks if the object hit a wall in the y-direction from bottom to top

   Input           :    uint16_t xPos
                        uint16_t xPosPrevious
                        uint8_t yPos
                        uint8_t yPosPrevious
                        int8_t xVelocity
                        int8_t yVelocity
                        uint8_t i


   Output          :    uint16_t yPos       (objects position)

**********************************************************************/

static uint16_t checkColliderBottomToTop(uint16_t xPos, uint16_t xPosPrevious, uint8_t yPos, uint8_t yPosPrevious, int8_t xVelocity, int8_t yVelocity, uint16_t i){
    //checks if the object moves in the negative y-direction and the wall is vertical
    if(yPosStart[i] == yPosSlut[i] && yVelocity < 0){
        //checks if the objects previous position was before the wall and the objects current position is after the wall.
        //checks if the wall is in the right x-position for the object to hit it.
        if(yPosPrevious > yPosStart[i] && yPosStart[i] >= yPos && xPosStart[i] <= xPos && xPosSlut[i] >= xPos){
            //temp value
            uint8_t yPosTemp = yPos;
            //lowers the speed of the object by one until it hits zero
            for(int8_t j = yPosPrevious-yPos; j > 0; j--){
                //checks if the object could move closer to the wall if the object had a lower speed
                if(yPosPrevious > yPosStart[i] && yPosStart[i] >= yPosTemp){
                    yPosTemp = yPosTemp + 1;
                }
            }
            //updates the objects position
            yPos = yPosTemp;
        }
    }
    //returns the objects position
    return yPos;
}


