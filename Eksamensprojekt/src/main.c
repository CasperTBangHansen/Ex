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


int main(void)
{
    uart_init( 115200 );
    //reset screen
    struct MenuSelection MenuSelection;
    struct drawItems drawValues[300];
    MenuSelection.MainMenu = 1;
    MenuSelection.Hover = 1;
    MenuSelection.H2P = 0;
    MenuSelection.Setting = 0;
    MenuSelection.Ship = 0;

    //shipValue
    uint8_t shipValue = 1;
    while(1){
        BeginMenuScreen(&MenuSelection,&drawValues);
        while(1){
            if(MenuSelection.MainMenu != 0){
                shipValue = MenuUserInput(&MenuSelection,&drawValues);
            }else {
                initStructs(&drawValues, shipValue);
                MenuSelection.MainMenu = 1;
                break;
            }
        }
    }
}
