/*
**
**                           Collider.c
**
**
**********************************************************************/
/*********************************************************************
   Primary editor  :    Casper Bang - Hansen
   Secondary editor:

**********************************************************************/
//Includes
#include "Collider.h"

// setWallHitBox takes an input struct and saves this structs hitbox in this .c file.
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
 //  checkCollider checks collision with other objects.
void checkCollider(struct player *playerHitBox, struct enemy *enemies, struct powerUp *powerUp, struct wallHitBox *wallHitBox){
    //Runes through all the walls
    for(int16_t i = 0; i <= (*wallHitBox).sizeOfArrays; i++){

        //checks if the player collides with a wall
        uint8_t hitWall = 0;

        //middel section of player
        if(objectWallCheck((*playerHitBox).xPos    , (*playerHitBox).yPos,i, wallHitBox)) hitWall = 1;
        if(objectWallCheck((*playerHitBox).xPos + 1, (*playerHitBox).yPos,i, wallHitBox)) hitWall = 1;
        if(objectWallCheck((*playerHitBox).xPos - 1, (*playerHitBox).yPos,i, wallHitBox)) hitWall = 1;

        //bottom section of player
        if(objectWallCheck((*playerHitBox).xPos    , (*playerHitBox).yPos + 1,i, wallHitBox)) hitWall = 1;
        if(objectWallCheck((*playerHitBox).xPos + 1, (*playerHitBox).yPos + 1,i, wallHitBox)) hitWall = 1;
        if(objectWallCheck((*playerHitBox).xPos - 1, (*playerHitBox).yPos + 1,i, wallHitBox)) hitWall = 1;

        //top section of player
        if(objectWallCheck((*playerHitBox).xPos    , (*playerHitBox).yPos - 1,i, wallHitBox)) hitWall = 1;
        if(objectWallCheck((*playerHitBox).xPos + 1, (*playerHitBox).yPos - 1,i, wallHitBox)) hitWall = 1;
        if(objectWallCheck((*playerHitBox).xPos - 1, (*playerHitBox).yPos - 1,i, wallHitBox)) hitWall = 1;

        //if the player hit a wall
        if(hitWall == 1){
            //set the players position to the players previous position
            playerHitBox->xPos = (*playerHitBox).xPosPrevious;
            playerHitBox->yPos = (*playerHitBox).yPosPrevious;
        }

        //Checks if the bullets collides with a wall
        for(int8_t j = 0; j < 3; j++){
            //Do the bullet exist?
            if((*playerHitBox).shots[j].show == 1){
                //Check with th wall
                if(objectWallCheck((*playerHitBox).shots[j].xPos, (*playerHitBox).shots[j].yPos,i, wallHitBox)){
                    //kills bullet
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
                        //kills bullet and enemy
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
        //checks if the powerUp exist
        if(powerUp[w].show == 1){

            //top section of player
            if(twoObjectCollider((*playerHitBox).xPos - 1, (*playerHitBox).yPos - 1, powerUp[w].xPos, powerUp[w].yPos)) hit = 1;
            if(twoObjectCollider((*playerHitBox).xPos, (*playerHitBox).yPos - 1, powerUp[w].xPos, powerUp[w].yPos)) hit = 1;
            if(twoObjectCollider((*playerHitBox).xPos + 1, (*playerHitBox).yPos - 1, powerUp[w].xPos, powerUp[w].yPos)) hit = 1;

            //middel section of player
            if(twoObjectCollider((*playerHitBox).xPos - 1, (*playerHitBox).yPos, powerUp[w].xPos, powerUp[w].yPos)) hit = 1;
            if(twoObjectCollider((*playerHitBox).xPos, (*playerHitBox).yPos, powerUp[w].xPos, powerUp[w].yPos)) hit = 1;
            if(twoObjectCollider((*playerHitBox).xPos + 1, (*playerHitBox).yPos, powerUp[w].xPos, powerUp[w].yPos)) hit = 1;

            //bottom section of player
            if(twoObjectCollider((*playerHitBox).xPos - 1, (*playerHitBox).yPos + 1, powerUp[w].xPos, powerUp[w].yPos)) hit = 1;
            if(twoObjectCollider((*playerHitBox).xPos, (*playerHitBox).yPos + 1, powerUp[w].xPos, powerUp[w].yPos)) hit = 1;
            if(twoObjectCollider((*playerHitBox).xPos + 1, (*playerHitBox).yPos + 1, powerUp[w].xPos, powerUp[w].yPos)) hit = 1;

            //if the player hit the powerup
            if(hit == 1){
                //change bullet type
                if((*playerHitBox).bulletType == 1){
                    playerHitBox->bulletType = 2;
                //change bullet type
                } else {
                    playerHitBox->bulletType = 1;
                }
                //kill powerUp
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

            //top section of player
            if(twoObjectCollider((*playerHitBox).xPos - 1, (*playerHitBox).yPos - 1, enemies[w].xPos, enemies[w].yPos)) hit = 1;
            if(twoObjectCollider((*playerHitBox).xPos, (*playerHitBox).yPos - 1, enemies[w].xPos, enemies[w].yPos)) hit = 1;
            if(twoObjectCollider((*playerHitBox).xPos + 1, (*playerHitBox).yPos - 1, enemies[w].xPos, enemies[w].yPos)) hit = 1;

            //middel section of player
            if(twoObjectCollider((*playerHitBox).xPos - 1, (*playerHitBox).yPos, enemies[w].xPos, enemies[w].yPos)) hit = 1;
            if(twoObjectCollider((*playerHitBox).xPos, (*playerHitBox).yPos, enemies[w].xPos, enemies[w].yPos)) hit = 1;
            if(twoObjectCollider((*playerHitBox).xPos + 1, (*playerHitBox).yPos, enemies[w].xPos, enemies[w].yPos)) hit = 1;

            //bottom section of player
            if(twoObjectCollider((*playerHitBox).xPos - 1, (*playerHitBox).yPos + 1, enemies[w].xPos, enemies[w].yPos)) hit = 1;
            if(twoObjectCollider((*playerHitBox).xPos, (*playerHitBox).yPos + 1, enemies[w].xPos, enemies[w].yPos)) hit = 1;
            if(twoObjectCollider((*playerHitBox).xPos + 1, (*playerHitBox).yPos + 1, enemies[w].xPos, enemies[w].yPos)) hit = 1;

            //player hit
            if(hit == 1){
                //sets playerlives to one less
                playerHitBox->lives = (*playerHitBox).lives - 1;
                hit = 0;
            }
        }
    }
}

//checks collision with walls
uint8_t objectWallCheck(uint16_t xPos, uint8_t yPos, uint8_t i, struct wallHitBox *wallHitBox){
    //does the object collide with a wall
    if(xPos >= (*wallHitBox).xPosStart[i] && xPos <= (*wallHitBox).xPosSlut[i] && yPos >= (*wallHitBox).yPosStart[i] && yPos <= (*wallHitBox).yPosSlut[i]){
        //yes
        return 1;
    } else {
        //no
        return 0;
    }
}

//check collision between two objects
uint8_t twoObjectCollider(uint16_t objectXPos, uint8_t objectYPos, uint16_t object2XPos, uint8_t object2YPos){
    //relative coordinates for object2
    uint16_t enemyRelativePosX[] = {object2XPos - 1, object2XPos , object2XPos + 1, object2XPos - 1, object2XPos , object2XPos + 1, object2XPos - 1, object2XPos , object2XPos + 1};
    uint8_t enemyRelativePosY[] = {object2YPos - 1, object2YPos - 1, object2YPos - 1, object2YPos, object2YPos, object2YPos, object2YPos + 1, object2YPos + 1, object2YPos +1};

    //runs through all relative position
    for(uint8_t i = 0; i<8; i++){
        //checks every relative position to object1's position
        if(objectXPos == enemyRelativePosX[i] && objectYPos == enemyRelativePosY[i]){
            //yes
            return 1;
        }
    }
    //no
    return 0;
}
