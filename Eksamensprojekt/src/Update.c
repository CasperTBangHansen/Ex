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
#define enemySize 20
#define drawValuesSize 300

/**********************************************************************

   Description     :    initStructs makes all the structs and starts the upDateFunction (the game)

   Input           :    void

   Output          :    void

**********************************************************************/

void initStructs(struct drawItems *drawValues, uint8_t ship, int16_t *highscore){
    //makes all the structs
    struct mapPackage maps;
    struct player player;
    struct enemy enemies[enemySize];
    SetTimer();

    //sets default parameter to all the structs (resets the structs)
    initEverythingFirstTime(&player, &enemies, &maps);

    //starts the game
    upDateFunction(&player, &enemies, &maps, drawValues, ship, highscore);
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
    player->lives = 3;
    player->direction = 4;
    player->bulletType = 1;
    player->score = 0;

    //Timer initialization
    counter.centisecond = 0;
    counter.second = 0;
    counter.minute = 0;
    counter.hour = 0;
    counter.runPlayer = 1;
    counter.runEnemies = 1;
    counter.runBullet = 1;

    //update speed
    counter.speedBullet = 1;
    counter.speedPlayer = 1;
    counter.speedEnemies = 10;

    //Player shots initialization
    xSTART = 2;
    ySTART = 2;
    for(int8_t i = 0; i < 3; i++){
        player->shots[i].xPos = xSTART;
        player->shots[i].yPos = ySTART;
        player->shots[i].xVelocity = 0;
        player->shots[i].yVelocity = 0;
        player->shots[i].show = 0;
    }

    //Enemy initialization
    xSTART = 1;
    ySTART = 1;
    for(int8_t i = 0; i < enemySize; i++){
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

static void upDateFunction(struct player *player, struct enemy *enemy, struct mapPackage *maps, struct drawItems *drawValues, uint8_t ship, int16_t *highscore){
    //value for saving the player direction
    uint8_t moveDirection;
    uint8_t drawMap = 1;
    uint8_t ledTimer = 0;
    //Checks if the player is alive
    while((*player).lives > 0){
        int8_t preLives = (*player).lives;
        //init map and Draw Map and SetWallHitBox
        LevelManager(maps, drawValues, player, enemy, drawMap);
        GameLED(2);
        //Set health bar
        upDateHealth((*player).lives);
        //SetMapDraw to false
        drawMap = 0;
        //sets player direction to look right
        moveDirection = 4;
        player->direction = moveDirection;
        //draws the players initial position
        ShipSelection(moveDirection, ship, player, drawValues);

        //checks if the player has the same amount if lives as the tick before.
        while((*player).lives == preLives){
            //Bullet movement
            if(counter.runBullet == 1){
                counter.runBullet = 0;
                for(int8_t i = 0; i < 3; i++){
                    if((*player).shots[i].show == 1){
                        (*player).shots[i].xPos += (*player).shots[i].xVelocity;
                        (*player).shots[i].yPos += (*player).shots[i].yVelocity;
                    }
                }
            }
            //Player movement
            if(counter.runPlayer == 1){
                counter.runPlayer = 0;
                moveDirection = userInput(player);
            }

            //Enemy
            if(counter.runEnemies == 1){
                counter.runEnemies = 0;
                upDatePosition(enemy);
            }

            //running collider
            checkCollider(player, enemy);

            //Draw every moving object
            drawMovingObjects(enemySize, moveDirection, drawValues, player, enemy, ship);

            //draw weapontype
            upDateWeapon((*player).bulletType);
            //draw Score
            upDateScore((*player).score);

            //check highscore
            if((*player).score >= (*highscore)){
                (*highscore) = (*player).score;
            }
            //draw highscore
            upDateHighScore((*highscore),0);

            //next level? 160
            if((*player).xPos >= 160){
                drawMap = 1;
                maps->mapChoice = (*maps).mapChoice + 1;
                ClearGameScreen(drawValues);
                player->score = (*player).score + 2000;
                break;
            }
        }

        for(uint8_t i = 0; i < enemySize; i++){
            drawEnemy(0,enemy, drawValues, i);
        }
        //clear player position
        ShipSelection(1, 0, player, drawValues);
        DrawEverything(drawValues);

        if((*player).lives != preLives){
            if(counter.second <= 58){
                ledTimer = counter.second + 1;
            } else {
                ledTimer = 1;
            }

            while(counter.second != ledTimer){
                GameLED(3);
            }
        }


    }
}







