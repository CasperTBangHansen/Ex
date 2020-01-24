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

**********************************************************************/

//Includes
#include "Collider.h"

/**********************************************************************

   Description     :    setWallHitBox takes an input struct and saves this structs hitbox in this .c file.
                        This means the hitbox of the walles is saved and the map hitbox size is also saved.

   Input           :    struct drawItems *drawValues
                        uint16_t mapHitBoxSize

   Output          :    void

**********************************************************************/
void setWallHitBox(struct drawItems *drawValues, uint16_t mapHitBoxSize, struct wallHitBox *wallHitBox){
    //sets the size of mapHitBox
    wallHitBox->sizeOfArrays = mapHitBoxSize;
    //Saves all the positions in drawValues in a static uint array.
    for(uint16_t i = 0; i <= (*wallHitBox).sizeOfArrays; i++){
        (*wallHitBox).xPosStart[i] = drawValues[i].xStart;
        (*wallHitBox).yPosStart[i] = drawValues[i].yStart;
        (*wallHitBox).xPosSlut[i] = drawValues[i].xSlut;
        (*wallHitBox).yPosSlut[i] = drawValues[i].ySlut;
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

void checkCollider(struct player *playerHitBox, struct enemy *enemies, struct powerUp *powerUp, struct wallHitBox *wallHitBox){
    //Runes through all the walls
    for(int16_t i = 0; i <= (*wallHitBox).sizeOfArrays; i++){
        //checks if the player collides with a wall
        uint8_t hitWall = 0;
        if(objectWallCheck((*playerHitBox).xPos    , (*playerHitBox).yPos,i, wallHitBox)) hitWall = 1;
        if(objectWallCheck((*playerHitBox).xPos + 1, (*playerHitBox).yPos,i, wallHitBox)) hitWall = 1;
        if(objectWallCheck((*playerHitBox).xPos - 1, (*playerHitBox).yPos,i, wallHitBox)) hitWall = 1;

        if(objectWallCheck((*playerHitBox).xPos    , (*playerHitBox).yPos + 1,i, wallHitBox)) hitWall = 1;
        if(objectWallCheck((*playerHitBox).xPos + 1, (*playerHitBox).yPos + 1,i, wallHitBox)) hitWall = 1;
        if(objectWallCheck((*playerHitBox).xPos - 1, (*playerHitBox).yPos + 1,i, wallHitBox)) hitWall = 1;

        if(objectWallCheck((*playerHitBox).xPos    , (*playerHitBox).yPos - 1,i, wallHitBox)) hitWall = 1;
        if(objectWallCheck((*playerHitBox).xPos + 1, (*playerHitBox).yPos - 1,i, wallHitBox)) hitWall = 1;
        if(objectWallCheck((*playerHitBox).xPos - 1, (*playerHitBox).yPos - 1,i, wallHitBox)) hitWall = 1;


        if(hitWall == 1){
            playerHitBox->xPos = (*playerHitBox).xPosPrevious;
            playerHitBox->yPos = (*playerHitBox).yPosPrevious;
        }

        //Checks if the bullets collides with a wall
        for(int8_t j = 0; j < 3; j++){
            //Do the bullet exist?
            if((*playerHitBox).shots[j].show == 1){
                //Check collision
                if(objectWallCheck((*playerHitBox).shots[j].xPos, (*playerHitBox).shots[j].yPos,i, wallHitBox)){
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
                    if(twoObjectCollider((*playerHitBox).shots[j].xPos, (*playerHitBox).shots[j].yPos, enemies[w].xPos, enemies[w].yPos)){
                        (*playerHitBox).shots[j].show = 0;
                        enemies[w].show = 0;
                    }
                }
            }
        }
    }
    //player powerup
    uint8_t hit = 0;
    for(int8_t w = 0; w < 3; w++){
        //checks if the enemy exist
        if(powerUp[w].show == 1){
            //checks if the player hit an enemy in the x-direction and if the player was previously hit this tick.
            if(twoObjectCollider((*playerHitBox).xPos - 1, (*playerHitBox).yPos - 1, powerUp[w].xPos, powerUp[w].yPos)) hit = 1;
            if(twoObjectCollider((*playerHitBox).xPos, (*playerHitBox).yPos - 1, powerUp[w].xPos, powerUp[w].yPos)) hit = 1;
            if(twoObjectCollider((*playerHitBox).xPos + 1, (*playerHitBox).yPos - 1, powerUp[w].xPos, powerUp[w].yPos)) hit = 1;

            if(twoObjectCollider((*playerHitBox).xPos - 1, (*playerHitBox).yPos, powerUp[w].xPos, powerUp[w].yPos)) hit = 1;
            if(twoObjectCollider((*playerHitBox).xPos, (*playerHitBox).yPos, powerUp[w].xPos, powerUp[w].yPos)) hit = 1;
            if(twoObjectCollider((*playerHitBox).xPos + 1, (*playerHitBox).yPos, powerUp[w].xPos, powerUp[w].yPos)) hit = 1;

            if(twoObjectCollider((*playerHitBox).xPos - 1, (*playerHitBox).yPos + 1, powerUp[w].xPos, powerUp[w].yPos)) hit = 1;
            if(twoObjectCollider((*playerHitBox).xPos, (*playerHitBox).yPos + 1, powerUp[w].xPos, powerUp[w].yPos)) hit = 1;
            if(twoObjectCollider((*playerHitBox).xPos + 1, (*playerHitBox).yPos + 1, powerUp[w].xPos, powerUp[w].yPos)) hit = 1;

            if(hit == 1){
                if((*playerHitBox).bulletType == 1){
                    playerHitBox->bulletType = 2;
                } else {
                    playerHitBox->bulletType = 1;
                }
                powerUp[w].show = 0;
                hit = 0;
            }
        }
    }



    //Checks if the player collide with an enemy
    hit = 0;
    for(int8_t w = 0; w < 20; w++){
        //checks if the enemy exist
        if(enemies[w].show == 1){
            //checks if the player hit an enemy in the x-direction and if the player was previously hit this tick.
            if(twoObjectCollider((*playerHitBox).xPos - 1, (*playerHitBox).yPos - 1, enemies[w].xPos, enemies[w].yPos)) hit = 1;
            if(twoObjectCollider((*playerHitBox).xPos, (*playerHitBox).yPos - 1, enemies[w].xPos, enemies[w].yPos)) hit = 1;
            if(twoObjectCollider((*playerHitBox).xPos + 1, (*playerHitBox).yPos - 1, enemies[w].xPos, enemies[w].yPos)) hit = 1;

            if(twoObjectCollider((*playerHitBox).xPos - 1, (*playerHitBox).yPos, enemies[w].xPos, enemies[w].yPos)) hit = 1;
            if(twoObjectCollider((*playerHitBox).xPos, (*playerHitBox).yPos, enemies[w].xPos, enemies[w].yPos)) hit = 1;
            if(twoObjectCollider((*playerHitBox).xPos + 1, (*playerHitBox).yPos, enemies[w].xPos, enemies[w].yPos)) hit = 1;

            if(twoObjectCollider((*playerHitBox).xPos - 1, (*playerHitBox).yPos + 1, enemies[w].xPos, enemies[w].yPos)) hit = 1;
            if(twoObjectCollider((*playerHitBox).xPos, (*playerHitBox).yPos + 1, enemies[w].xPos, enemies[w].yPos)) hit = 1;
            if(twoObjectCollider((*playerHitBox).xPos + 1, (*playerHitBox).yPos + 1, enemies[w].xPos, enemies[w].yPos)) hit = 1;

            if(hit == 1){
                playerHitBox->lives = (*playerHitBox).lives - 1;
                hit = 0;
            }
        }
    }
}

uint8_t objectWallCheck(uint16_t xPos, uint8_t yPos, uint8_t i, struct wallHitBox *wallHitBox){
    if(xPos >= (*wallHitBox).xPosStart[i] && xPos <= (*wallHitBox).xPosSlut[i] && yPos >= (*wallHitBox).yPosStart[i] && yPos <= (*wallHitBox).yPosSlut[i]){
        return 1;
    } else {
        return 0;
    }
}

uint8_t twoObjectCollider(uint16_t objectXPos, uint8_t objectYPos, uint16_t object2XPos, uint8_t object2YPos){
    uint16_t enemyRelativePosX[] = {object2XPos - 1, object2XPos , object2XPos + 1, object2XPos - 1, object2XPos , object2XPos + 1, object2XPos - 1, object2XPos , object2XPos + 1};
    uint8_t enemyRelativePosY[] = {object2YPos - 1, object2YPos - 1, object2YPos - 1, object2YPos, object2YPos, object2YPos, object2YPos + 1, object2YPos + 1, object2YPos +1};
    for(uint8_t i = 0; i<8; i++){
        if(objectXPos == enemyRelativePosX[i] && objectYPos == enemyRelativePosY[i]){
            return 1;
        }
    }
    return 0;
}
