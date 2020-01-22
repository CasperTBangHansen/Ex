#include "upDateUI.h"

#define FIX10_SHIFT 10
#define FIX10_MULT(a, b) ( (a)*(b) >> FIX10_SHIFT )
#define FIX10_DIV(a, b) ( ((a) << FIX10_SHIFT) / b )


void upDateHealth(uint8_t lives){
    uint8_t healthPosX = 176;
    uint8_t healthPosY = 81;
    uint8_t healthLength = 24;
    if(lives == 3){
        gotoxy(healthPosX,healthPosY);
        for(uint8_t i = 0; i <= healthLength; i++){
            printf("%c",0xB2);
        }
    } else if(lives == 2){
        gotoxy(healthPosX + 16,healthPosY);
        for(uint8_t i = healthLength; i >= healthLength-8; i--){
            printf("%c",0xFF);
        }
    } else if(lives == 1){
        gotoxy(healthPosX + 8,healthPosY);
        for(uint8_t i = healthLength - 8; i >= healthLength - 16; i--){
            printf("%c",0xFF);
        }
    } else if(lives == 0){
        gotoxy(healthPosX,healthPosY);
        for(uint8_t i = healthLength - 16; i >= 0; i--){
            printf("%c",0xFF);
        }
    }
}

void upDateWeapon(uint8_t activeWeapon){
    static uint8_t weaponType = 0;
    if(weaponType != activeWeapon){
        weaponType = activeWeapon;
        gotoxy(176,84);
        printf("             ");
        gotoxy(176,84);
        if(activeWeapon == 1){
            printf("Single bullet");
        } else if(activeWeapon == 2){
            printf("Multi bullet");
        }
    }
}

void upDateScore(int16_t playerScore){
    static int16_t currentScore = 1;
    if(playerScore != currentScore){
        currentScore = playerScore;
        gotoxy(175,87);
        printf("      ");
        gotoxy(175,87);
        printf("%d",currentScore);
    }
}

void upDateHighScore(int16_t highscore, uint8_t resetCurrentScore){
    static int16_t currentScore = -32768;
    if(resetCurrentScore == 1){
        currentScore = -32768;
    } else {
        if(highscore != currentScore){
            currentScore = highscore;
            gotoxy(180,90);
            printf("      ");
            gotoxy(180,90);
            printf("%d", highscore);
        }
    }
}



