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

/***********************************
Interrupt settings

***********************************/
void InterruptSet(){
RCC->APB1ENR |= RCC_APB1Periph_TIM2; // Enable clock line to timer 2;
TIM2->CR1 = 0x00; // Configure timer 2
TIM2->CR1 &= ~(0x0001 << (11 * 2));
TIM2->CR1 &= ~(0x0001 << (9 * 2));
TIM2->CR1 &= ~(0x0001 << (8 * 2));
TIM2->CR1 &= ~(0x0001 << (7 * 2));
TIM2->CR1 &= ~(0x0001 << (6 * 2));
TIM2->CR1 &= ~(0x0001 << (5 * 2));
TIM2->CR1 &= ~(0x0001 << (4 * 2));
TIM2->CR1 &= ~(0x0001 << (3 * 2));
TIM2->CR1 &= ~(0x0001 << (2 * 2));
TIM2->CR1 &= ~(0x0001 << (1 * 2));
TIM2->CR1 |= (0x0001 << (0 * 2));
TIM2->ARR = 0x2C; // Set reload value
TIM2->PSC = 0x28; // Set prescale value
}


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
    uint16_t xSTART = 19;
    uint16_t ySTART = 65;
    player->xPos = xSTART;
    player->yPos = ySTART;
    player->xPosPrevious = xSTART;
    player->yPosPrevious = ySTART;
    player->xVelocity = 0;
    player->yVelocity = 0;
    player->lives = 3;
    player->direction = 4;

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

    //Checks if the player is alive
    while((*player).lives >= 0){
        uint8_t preLives = (*player).lives;
        //init map and Draw Map and SetWallHitBox
        LevelManager(maps, drawValues);

        //sets player direction to look right
        moveDirection = 4;
        //draws the players initial position
        ShipSelection(moveDirection, 1, player, drawValues);

        //checks if the player has the same amount if lives as the tick before.
        while((*player).lives == preLives){

            //Player movement
            moveDirection = userInput(player);

            //For TESTING
            gotoxy(1,1);
            printf("(%d,%d)\n",(*player).xPos,(*player).yPos);
            printf("(%d,%d,%d)\n",(*player).shots[0].xPos,(*player).shots[0].yPos,(*player).shots[0].show);
            printf("(%d,%d,%d)\n",(*player).shots[1].xPos,(*player).shots[1].yPos,(*player).shots[1].show);
            printf("(%d,%d,%d)\n",(*player).shots[2].xPos,(*player).shots[2].yPos,(*player).shots[2].show);

            //running collider
            checkCollider(player, enemy);

            //Draws player
            ShipSelection(moveDirection, 1, player, drawValues);


            //enemy

            //updates player previous position to current position
            player->xPosPrevious = (*player).xPos;
            player->yPosPrevious = (*player).yPos;

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
}
