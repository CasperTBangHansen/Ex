/*
**
**                           Main.c
**
**
**********************************************************************/
/*
   Primary editor  :    Casper Bang - Hansen
   Secondary editor:
   Last changed by :    19/01 - 2020

   Functions       :    int main(void);

**********************************************************************/

//include .h file
#include "stm32f30x_conf.h"
#include "30010_io.h"
#include "Update.h"
#include "MainMenu.h"
#include "MenuControls.h"
#include "upDateUI.h"
#include "LED.h"

int main(void)
{
    uart_init( 115200 );
    //reset screen
    printf("%c[%d%c",0x1B,2,0x4A);
    //starts game
    struct MenuSelection MenuSelection;
    struct drawItems drawValues[300];
    MenuSelection.MainMenu = 1;
    MenuSelection.Hover = 1;
    MenuSelection.H2P = 0;
    MenuSelection.Setting = 0;
    MenuSelection.Ship = 0;

    //highscore
    int16_t *highscore;
    highscore = 0;
    //shipValue
    uint8_t temp = 0;
    uint8_t shipValue = 1;
    while(1){
        upDateHighScore(highscore,1);
        BeginMenuScreen(&MenuSelection,&drawValues);
        GameLED(1);
        while(1){
            if(MenuSelection.MainMenu != 0){
                temp = MenuUserInput(&MenuSelection,&drawValues);
                upDateHighScore(highscore,0);
                if(temp != 0){
                    shipValue = temp;
                }
            }else {
                initStructs(&drawValues, shipValue, &highscore);
                MenuSelection.MainMenu = 1;
                break;
            }
        }
    }
}
