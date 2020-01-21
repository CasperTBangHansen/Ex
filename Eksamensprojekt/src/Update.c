/*
**
**                           Update.c
**
**
**********************************************************************/
/*
   Primary editor  :    Casper Bang-Hansen
   Secondary editor:
   Last changed by :    19/01 - 2020

   Functions       :    void initStructs();
                        static void initEverythingFirstTime(struct player *player, struct enemy *enemy, struct mapPackage *maps);
                        static void upDateFunction(struct player *player, struct enemy *enemy, struct mapPackage *maps, struct drawItems *drawValues);

**********************************************************************/

//include .h file
#include "Update.h"

//defines
//amount of enemy and draw buffer
#define enemySize 21
#define drawValuesSize 300


/**********************************************************************

   Description     :    initStructs makes all the structs and starts the upDateFunction (the game)

   Input           :    void

   Output          :    void

**********************************************************************/

void initStructs(){
    //makes all the structs
    struct drawItems drawValues[drawValuesSize];
    struct mapPackage maps;
    struct player player;
    struct enemy enemies[enemySize];
    SetTimer();
    //sets default parameter to all the structs (resets the structs)
    initEverythingFirstTime(&player, &enemies, &maps);

    //starts the game
    upDateFunction(&player, &enemies, &maps, &drawValues);
}


/**********************************************************************

   Description     :    initEverythingFirstTime sets all the default values in the structs

   Input           :    struct player *player
                        struct enemy *enemy
                        struct mapPackage *maps

   Output          :    void

**********************************************************************/

static void initEverythingFirstTime(struct player *player, struct enemy *enemy, struct mapPackage *maps){
    //Player initialization
    uint16_t xSTART = 1;
    uint16_t ySTART = 1;
    player->xPos = xSTART;
    player->yPos = ySTART;
    player->xPosPrevious = xSTART;
    player->yPosPrevious = ySTART;
    player->xVelocity = 0;
    player->yVelocity = 0;
    player->lives = 3;
    player->direction = 4;

    //Timer initialization
    counter.centisecond = 0;
    counter.second = 0;
    counter.minute = 0;
    counter.hour = 0;
    counter.runProgram = 1;

    //Player shots initialization
    xSTART = 1;
    ySTART = 1;
    for(int8_t i = 0; i < 3; i++){
        player->shots[i].xPos = xSTART;
        player->shots[i].yPos = ySTART;
        player->shots[i].xPosPrevious = xSTART + 1;
        player->shots[i].yPosPrevious = ySTART + 1;
        player->shots[i].xVelocity = 0;
        player->shots[i].yVelocity = 0;
        player->shots[i].show = 0;
    }

    //Enemy initialization
    for(int8_t i = 0; i < enemySize; i++){
        xSTART = 1;
        ySTART = 1;
        enemy[i].xPos = xSTART;
        enemy[i].yPos = ySTART;
        enemy[i].xPosPrevious = xSTART;
        enemy[i].yPosPrevious = ySTART;
        enemy[i].xVelocity = 0;
        enemy[i].yVelocity = 0;
        enemy[i].show = 0;
        enemy[i].arrayPathSize = 0;
    }
    //Map initialization
    maps->mapChoice = 1; // Map number of choice

}


/**********************************************************************

   Description     :    upDateFunction updates the game every 'tick' (every cycle)

   Input           :    struct player *player
                        struct enemy *enemy
                        struct mapPackage *maps
                        struct drawItems *drawValues

   Output          :    void

**********************************************************************/

static void upDateFunction(struct player *player, struct enemy *enemy, struct mapPackage *maps, struct drawItems *drawValues){
    //value for saving the player direction
    uint8_t moveDirection;
    uint8_t drawMap = 1;
    //Checks if the player is alive
    while((*player).lives >= 0){
        int8_t preLives = (*player).lives;
        //init map and Draw Map and SetWallHitBox
        LevelManager(maps, drawValues, player, enemy, drawMap);
        drawMap = 0;

        //sets player direction to look right
        moveDirection = 4;
        //draws the players initial position
        ShipSelection(moveDirection, 1, player, drawValues);

        //checks if the player has the same amount if lives as the tick before.
        while((*player).lives == preLives){
            if(counter.runProgram == 1){
                counter.runProgram = 0;
                //Player movement
                moveDirection = userInput(player);

                //Enemy
                if(counter.runEnemies == 1){
                    counter.runEnemies = 0;
                    upDatePosition(enemy);
                }
                //For TESTING
                gotoxy(1,1);
                printf("(%d,%d,%d)\n",(*player).xPos,(*player).yPos,(*player).lives);
                printf("(%d,%d,%d)\n",(*player).shots[0].xPos,(*player).shots[0].yPos,(*player).shots[0].show);
                printf("(%d,%d,%d)\n",(*player).shots[1].xPos,(*player).shots[1].yPos,(*player).shots[1].show);
                printf("(%d,%d,%d)\n",(*player).shots[2].xPos,(*player).shots[2].yPos,(*player).shots[2].show);
                printf("(%d,%d,%d)\n",enemy[0].xPos,enemy[0].yPos,enemy[0].show);
                //running collider
                checkCollider(player, enemy);

                //Draws player
                ShipSelection(moveDirection, 1, player, drawValues);



                //updates player previous position to current position
                player->xPosPrevious = (*player).xPos;
                player->yPosPrevious = (*player).yPos;

                //updates enemy position and draws enemy
                for(uint8_t i = 0; i < enemySize; i++){
                    if(enemy[i].show == 1){
                        gotoxy(enemy[i].xPosPrevious,enemy[i].yPosPrevious);
                        printf("%c",0xFF);
                        gotoxy(enemy[i].xPos,enemy[i].yPos);
                        printf("X");
                        enemy[i].xPosPrevious = enemy[i].xPos;
                        enemy[i].yPosPrevious = enemy[i].yPos;
                    }
                }

                //Forloop for all 3 bullets
                for(int8_t i = 0; i < 3; i++){
                    //checks if bullet hit wall and removes it
                    if((*player).shots[i].xPos == (*player).shots[i].xPosPrevious && ((*player).shots[i].xPosPrevious != (*player).xPos || (*player).shots[i].yPosPrevious != (*player).yPos)){
                        DrawingSetValues(drawValues,(*player).shots[i].xPosPrevious,(*player).shots[i].yPosPrevious,(*player).shots[i].xPosPrevious,(*player).shots[i].yPosPrevious,0xFF);
                    }
                    //set draw of bullet in queue
                    if((*player).shots[i].show == 1 && ((*player).shots[i].xPosPrevious != (*player).xPosPrevious || (*player).shots[i].yPosPrevious != (*player).yPosPrevious)){
                        DrawingSetValues(drawValues,(*player).shots[i].xPosPrevious,(*player).shots[i].yPosPrevious,(*player).shots[i].xPosPrevious,(*player).shots[i].yPosPrevious,0xFF);
                        DrawingSetValues(drawValues,(*player).shots[i].xPos,(*player).shots[i].yPos,(*player).shots[i].xPos,(*player).shots[i].yPos,'o');
                    }
                    //Removes bullet from map (set position to (2,2))
                    if((*player).shots[i].show == 0){
                        (*player).shots[i].xPos = 2;
                        (*player).shots[i].yPos = 2;
                    }
                    //Updates bullets previous position to bullets current position
                    (*player).shots[i].xPosPrevious = (*player).shots[i].xPos;
                    (*player).shots[i].yPosPrevious = (*player).shots[i].yPos;
                }
                //draws bullet
                DrawEverything(drawValues);
            }
        }
        //Clear enemy position
        for(uint8_t i = 0; i < enemySize; i++){
            if(enemy[i].show == 1){
                gotoxy(enemy[i].xPosPrevious,enemy[i].yPosPrevious);
                printf("%c",0xFF);
            }
        }
        //clear player position
       ShipSelection(1, 0, player, drawValues);


    }
}







