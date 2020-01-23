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
    struct powerUp powerUp[powerUpSize];
    SetTimer();

    //sets default parameter to all the structs (resets the structs)
    initEverythingFirstTime(&player, &enemies, &maps, &powerUp);

    //starts the game
    upDateFunction(&player, &enemies, &maps, drawValues, ship, highscore, &powerUp);
}


/**********************************************************************

   Description     :    initEverythingFirstTime sets all the default values in the structs

   Input           :    struct player *player
                        struct enemy *enemy
                        struct mapPackage *maps

   Output          :    void

**********************************************************************/

static void initEverythingFirstTime(struct player *player, struct enemy *enemy, struct mapPackage *maps, struct powerUp *powerUp){
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

}


/**********************************************************************

   Description     :    upDateFunction updates the game every 'tick' (every cycle)

   Input           :    struct player *player
                        struct enemy *enemy
                        struct mapPackage *maps
                        struct drawItems *drawValues

   Output          :    void

**********************************************************************/

static void upDateFunction(struct player *player, struct enemy *enemy, struct mapPackage *maps, struct drawItems *drawValues, uint8_t ship, int32_t *highscore,  struct powerUp *powerUp){
    //value for saving the player direction
    uint8_t moveDirection;
    uint8_t drawMap = 1;
    uint8_t ledTimer = 0;
    char splitTimer[11];
    char key = '\0';
    //Checks if the player is alive
    while((*player).lives > 0){
        int8_t preLives = (*player).lives;
        //init map and Draw Map and SetWallHitBox
        LevelManager(maps, drawValues, player, enemy, drawMap, powerUp);

        //draw current map
        gotoxy(187,29);
        printf("%d",(*maps).mapChoice);


        //LED
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

            //check max/min score
            if((*player).score > 2100000000){
                player->score = 2100000000;
            } else if ((*player).score < -2100000000){
                player->score = -2100000000;
            }

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
            checkCollider(player, enemy, powerUp);

            //draw powerup
            for(uint8_t i = 0; i < powerUpSize; i++){
                if(powerUp[i].show == 1){
                    printf("%c[%u;%u%c%c%c[%u;%u%c%c%c[%u;%u%c%c%c[%u;%u%c%c%c[%u;%u%c%c",0x1B,powerUp[i].yPos,powerUp[i].xPos,0x48,0xC5,0x1B,powerUp[i].yPos-1,powerUp[i].xPos,0x48,0xB3,0x1B,powerUp[i].yPos,powerUp[i].xPos-1,0x48,0xC4,0x1B,powerUp[i].yPos,powerUp[i].xPos+1,0x48,0xC4,0x1B,powerUp[i].yPos+1,powerUp[i].xPos,0x48,0xB3);
                } else if(powerUp[i].xPos != 2 && powerUp[i].xPos != 2){
                    printf("%c[%u;%u%c%c%c[%u;%u%c%c%c[%u;%u%c%c%c[%u;%u%c%c%c[%u;%u%c%c",0x1B,powerUp[i].yPos,powerUp[i].xPos,0x48,0xFF,0x1B,powerUp[i].yPos-1,powerUp[i].xPos,0x48,0xFF,0x1B,powerUp[i].yPos,powerUp[i].xPos-1,0x48,0xFF,0x1B,powerUp[i].yPos,powerUp[i].xPos+1,0x48,0xFF,0x1B,powerUp[i].yPos+1,powerUp[i].xPos,0x48,0xFF);
                    powerUp[i].yPos = 2;
                    powerUp[i].yPos = 2;
                }
            }

            //Draw every moving object
            drawMovingObjects(enemySize, moveDirection, drawValues, player, enemy, ship);

            //draw weapontype
            upDateWeapon((*player).bulletType);
            //draw Score
            upDateScore((*player).score);


            //next level? 160
            if((*player).xPos >= 160){
                drawMap = 1;
                maps->mapChoice = (*maps).mapChoice + 1;
                ClearGameScreen(drawValues);
                player->score = (*player).score + 2000;
                break;
            }

            //Display timer
            if(counter.upDateSeconds == 1){
                counter.upDateSeconds = 0;
                Split_Time_Function(splitTimer);
                gotoxy(182,32);
                printf("%s",splitTimer);
                switch((*maps).mapChoice){
                    case 1:
                        gotoxy(182,35);
                        printf("%s",splitTimer);
                        break;
                    case 2:
                        gotoxy(182,38);
                        printf("%s",splitTimer);
                    case 3:
                        gotoxy(182,41);
                        printf("%s",splitTimer);
                    default:
                        break;
                }

            }

        }
        //removes enemies
        for(uint8_t i = 0; i < enemySize; i++){
            drawEnemy(0,enemy, drawValues, i);
            enemy[i].show = 0;
            enemy[i].xPos = 1;
            enemy[i].yPos = 1;
        }


        //clear player position
        ShipSelection(1, 0, player, drawValues);
        DrawEverything(drawValues);


        //red LED
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

        if((*maps).mapChoice > 3){
            break;
        }
    }
    //Set health bar
    upDateHealth((*player).lives);

    //adds score depending on time
    if(counter.minute <= 5 && counter.hour == 0 && (*player).lives != 0){
        (*player).score += 10*60*counter.minute;
        (*player).score += 10*counter.second;
    }


    //check highscore
    if((*player).score >= (*highscore)){
        (*highscore) = (*player).score;
    }
    //draw highscore
    upDateHighScore((*highscore),0);

    //Draw highscore
    ClearGameScreen(drawValues);

    gotoxy(78,65);
    printf("Your score: %010d",(*player).score);
    upDateScore((*player).score);
    gotoxy(78,67);
    printf("Highscore:  %010d",(*highscore));

    if((*player).score == (*highscore)){
        printf("%c[%d%c",0x1B,05,0x6D);
        gotoxy(20,27);
        printf("888b    888 8888888888 888       888      888    888 8888888 .d8888b.  888    888  .d8888b.   .d8888b.   .d88888b.  8888888b.  8888888888 ");
        gotoxy(20,28);
        printf("8888b   888 888        888   o   888      888    888   888  d88P  Y88b 888    888 d88P  Y88b d88P  Y88b d88P\" \"Y88b 888   Y88b 888        ");
        gotoxy(20,29);
        printf("88888b  888 888        888  d8b  888      888    888   888  888    888 888    888 Y88b.      888    888 888     888 888    888 888        ");
        gotoxy(20,30);
        printf("888Y88b 888 8888888    888 d888b 888      8888888888   888  888        8888888888  \"Y888b.   888        888     888 888   d88P 8888888    ");
        gotoxy(20,31);
        printf("888 Y88b888 888        888d88888b888      888    888   888  888  88888 888    888     \"Y88b. 888        888     888 8888888P\"  888        ");
        gotoxy(20,32);
        printf("888  Y88888 888        88888P Y88888      888    888   888  888    888 888    888       \"888 888    888 888     888 888 T88b   888        ");
        gotoxy(20,33);
        printf("888   Y8888 888        8888P   Y8888      888    888   888  Y88b  d88P 888    888 Y88b  d88P Y88b  d88P Y88b. .d88P 888  T88b  888        ");
        gotoxy(20,34);
        printf("888    Y888 8888888888 888P     Y888      888    888 8888888 \"Y8888P88 888    888  \"Y8888P\"   \"Y8888P\"   \"Y88888P\"  888   T88b 8888888888");
        printf("%c[%d%c",0x1B,25,0x6D);
    }
    uart_clear();
    while(1){
        key = uart_get_char();
        if(key != '\0'){
            break;
        }
        uart_clear();
    }
}







