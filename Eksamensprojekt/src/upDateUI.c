#include "upDateUI.h"

#define FIX10_SHIFT 10
#define FIX10_MULT(a, b) ( (a)*(b) >> FIX10_SHIFT )
#define FIX10_DIV(a, b) ( ((a) << FIX10_SHIFT) / b )


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



