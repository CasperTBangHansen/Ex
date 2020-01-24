#include "upDateUI.h"


void upDateHealth(uint8_t lives){ // Function that controls the UI for lives. (Decrease health bar)
    uint8_t healthPosX = 176; // Set X and Y position + length of the health bar
    uint8_t healthPosY = 81;
    uint8_t healthLength = 24;
    if(lives == 3){ //if full life, go to position and print full bar.
        gotoxy(healthPosX,healthPosY);
        for(uint8_t i = 0; i <= healthLength; i++){
            printf("%c",0xB2);
        }
    } else if(lives == 2){ // if life decreases to 2, go to position and print 2/3's of the max health bar.
        gotoxy(healthPosX + 16,healthPosY);
        for(uint8_t i = healthLength; i >= healthLength-8; i--){
            printf("%c",0xFF);
        }
    } else if(lives == 1){
        gotoxy(healthPosX + 8,healthPosY); // if life decreases to 1, go to position and print 1/3 of the max health bar.
        for(uint8_t i = healthLength - 8; i >= healthLength - 16; i--){
            printf("%c",0xFF);
        }
    } else if(lives == 0){ // if life decreases to 0, go to position and print 0/3 of the max health bar.
        gotoxy(healthPosX,healthPosY);
        for(int8_t i = healthLength - 16; i >= 0; i--){
            printf("%c",0xFF);
        }
    }
}

void upDateWeapon(uint8_t activeWeapon){ // Displays what type of weapon you have activated
    static uint8_t weaponType = 0;
    if(weaponType != activeWeapon){ //If weapontype is not equal to the active weapon, make it the new active weapon
        weaponType = activeWeapon; // this enables us to create a boolean for a swap between single and multi bullets through the same powerup.
        gotoxy(176,84); //Go to the placement of weapon type, and clear it
        printf("             ");
        gotoxy(176,84); //dependant on the current active weapon, print it
        if(activeWeapon == 1){
            printf("Single bullet");
        } else if(activeWeapon == 2){
            printf("Multi bullet");
        }
    }
}

void upDateScore(int32_t playerScore){ // Updates the score
    static int32_t currentScore = 1;
    if(playerScore != currentScore){ // If the playerscore is not equal to the "current score", set the current score to be equal to the current score.
        currentScore = playerScore; // this funciton basically updates itself everytime the player gets a negative or positive point added to their score.
        gotoxy(180,87);
        printf("          ");
        gotoxy(180,87);
        printf("%010d",playerScore);
    }
}

void upDateHighScore(int32_t highscore, uint8_t resetCurrentScore){ // Updates the high score.
    static int32_t currentScore = -2147483648; // sets the highscore to that maximum negative value of a 32bit integer.
    if(resetCurrentScore == 1){ // if we need to reset the current score, set it to the maxmium negative value of a 32 bit integer.
        currentScore = -2147483648;
    } else {
        if(highscore != currentScore){ // if not needed to reset, and the highscore is not equal to the current score, set the current score to the highscore.
            currentScore = highscore; // this only runs at the end of the game.
            gotoxy(180,90);
            printf("          ");
            gotoxy(180,90);
            printf("%010d", highscore);
        }
    }
}

void maxMinScore(struct player *player){
    //check max/min score
    if((*player).score > 2100000000){
        player->score = 2100000000;
    } else if ((*player).score < -2100000000){
        player->score = -2100000000;
    }
}

void upDateCurrentLevel(struct mapPackage *maps){//draw current map
    //goes to level current level
    gotoxy(187,29);
    //draws current level
    printf("%d",(*maps).mapChoice);
}

void upDateTimer(struct mapPackage *maps){
    char splitTimer[11];
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
                break;
            case 3:
                gotoxy(182,41);
                printf("%s",splitTimer);
                break;
            default:
                break;
        }

    }
}

void endScreenScore(struct player *player, struct drawItems *drawValues, int32_t *highscore){
    char key = '\0';
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

void upDateUIEveryTick(struct player *player, struct mapPackage *maps){
    //draw weapontype
    upDateWeapon((*player).bulletType);
    //check if valid score
    maxMinScore(player);
    //draw Score
    upDateScore((*player).score);
    //update timer
    upDateTimer(maps);
}
