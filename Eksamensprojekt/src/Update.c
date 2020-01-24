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
#define powerUpSize 3

/**********************************************************************

   Description     :    initStructs makes all the structs and starts the upDateFunction (the game)

   Input           :    void

   Output          :    void

**********************************************************************/

void initStructs(struct drawItems *drawValues, uint8_t ship, int32_t *highscore){
    //makes all the structs
    struct mapPackage maps;
    struct player player;
    struct enemy enemies[enemySize];
    struct wallHitBox wallHitBox;
    struct powerUp powerUp[powerUpSize];

    //sets timer
    SetTimer();

    //sets default parameter to all the structs (resets the structs)
    initEverythingFirstTime(&player, &enemies, &maps, &powerUp, &wallHitBox);

    //starts the game
    upDateFunction(&player, &enemies, &maps, drawValues, ship, highscore, &powerUp, &wallHitBox);
}


/**********************************************************************

   Description     :    initEverythingFirstTime sets all the default values in the structs

   Input           :    struct player *player
                        struct enemy *enemy
                        struct mapPackage *maps

   Output          :    void

**********************************************************************/

static void initEverythingFirstTime(struct player *player, struct enemy *enemy, struct mapPackage *maps, struct powerUp *powerUp, struct wallHitBox *wallHitBox){
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

    //Powerup
    for(uint8_t i = 0; i < powerUpSize; i++){
        powerUp[i].xPos = 2;
        powerUp[i].yPos = 2;
        powerUp[i].show = 0;
    }

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

    //wallHitBox
    wallHitBox->sizeOfArrays = 0;
}


/**********************************************************************

   Description     :    upDateFunction updates the game every 'tick' (every cycle)

   Input           :    struct player *player
                        struct enemy *enemy
                        struct mapPackage *maps
                        struct drawItems *drawValues

   Output          :    void

**********************************************************************/

static void upDateFunction(struct player *player, struct enemy *enemy, struct mapPackage *maps, struct drawItems *drawValues, uint8_t ship, int32_t *highscore,  struct powerUp *powerUp, struct wallHitBox *wallHitBox){
    //sets values
    uint8_t moveDirection;
    //drawMap is a variable that determents if the map should be drawn
    uint8_t drawMap = 1;
    //lives
    int8_t preLives;

    //Checks if the player is alive
    while((*player).lives > 0){
        //restart level
        moveDirection = setupLevel(maps, drawValues, player, enemy, drawMap, powerUp, wallHitBox, ship);

        //set lives
        preLives = (*player).lives;

        //SetMapDraw to false
        drawMap = 0;

        //checks if the player has the same amount if lives as the tick before.
        while((*player).lives == preLives){

            //update player movement
            if(counter.runPlayer == 1){
                counter.runPlayer = 0;
                moveDirection = userInput(player);
            }

            //update enemy movement
            if(counter.runEnemies == 1){
                counter.runEnemies = 0;
                upDatePosition(enemy);
            }

            //running collider
            checkCollider(player, enemy, powerUp,wallHitBox);

            //Draw every moving object
            drawMovingObjects(enemySize, moveDirection, drawValues, player, enemy, ship, powerUp);

            //draws UI
            upDateUIEveryTick(player, maps);

            //next level?
            if((*player).xPos >= 160){
                drawMap = 1;
                maps->mapChoice = (*maps).mapChoice + 1;
                ClearGameScreen(drawValues);
                player->score = (*player).score + 2000;
                break;
            }
        }

        //resetsmap
        playerKilled(enemy, player, drawValues, preLives);

        //game won
        if((*maps).mapChoice > 4){
            break;
        }

    }
    //endscreen
    endScreenScore(player, drawValues, highscore);

}






