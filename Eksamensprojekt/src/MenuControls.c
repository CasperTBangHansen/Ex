/*
**
**                           ControlSystem.c
**
**
**********************************************************************/
/*
   Primary editor  :    Martin Kolster
   Secondary editor:    Casper Bang-Hansen & Mathias Jensen
   Last changed by :    19/01 - 2020

   Functions       :    uint8_t userInput(struct player *player);
                        static void setupBullet(struct player *player, int8_t xPosOffSet, int8_t yPosOffSet, int8_t xShotsMaxVelocity, int8_t yShotsMaxVelocity, uint8_t i);

**********************************************************************/

//include .h file
#include "MenuControls.h"

//defines
//Symbols
#define ESC 0x1B
#define SPACE 0x20


/**********************************************************************

   Description     :    userInput takes the users keyboard input and sets either the players position or spawns bullets
                        depending on what key is pressed

   Input           :    struct player *player

   Output          :    uint8_t direction

**********************************************************************/


uint8_t MenuUserInput(struct MenuSelection *MenuSelection,struct drawItems *drawValues) {
    // Adds a variable to use for registering the pressed button
    char buttonPress;

    //Sets the variable to the button the person has pressed
    buttonPress = uart_get_char();


    //returns 0 if there were no button pressed (makes the function much faster)
    if (buttonPress == '\0'){
        return 0;
    }

    // If and only if the pressed button is "w", the players moves up
    if(buttonPress == 'w' ) {
        if ((*MenuSelection).MainMenu == 1) {
            if ((*MenuSelection).Hover == 1) {
                MenuSelection->Hover = 3;
                ClearPlayGameArrow();
                ConstructSettingsArrow();
            }
            else if ((*MenuSelection).Hover == 2){
                MenuSelection->Hover = 1;
                ClearHowToPlayArrow();
                ConstructPlayGameArrow();
            }
            else if ((*MenuSelection).Hover == 3){
                MenuSelection->Hover = 2;
                ClearSettingsArrow();
                ConstructHowToPlayArrow();
            }
        }

        else if (((*MenuSelection).MainMenu == 2) && ((*MenuSelection).Setting == 1)) {
            if ((*MenuSelection).Hover == 1) {
                MenuSelection->Hover = 2;
                ClearSpaceshipArrow();
                ConstructBackArrow();
            }
            else if ((*MenuSelection).Hover == 2) {
                MenuSelection->Hover = 1;
                ClearBackArrow();
                ConstructSpaceshipArrow();
            }
        }
        else if (((*MenuSelection).MainMenu == 2) && ((*MenuSelection).Setting == 2)) {
            if ((*MenuSelection).Hover == 1) {
                    MenuSelection->Hover = 2;
                    ClearSpaceShip1Arrow();
                    ConstructSpaceShip2Arrow();
            }
            else if ((*MenuSelection).Hover == 2) {
                    MenuSelection->Hover = 1;
                    ClearSpaceShip2Arrow();
                    ConstructSpaceShip1Arrow();
            }
        }
    }

    // If and only if the pressed button is "a", the players moves left
    if(buttonPress == 'a'){
    }

    // If and only if the pressed button is "s", the players moves down
    if(buttonPress == 's'){
        if ((*MenuSelection).MainMenu == 1) {
            if ((*MenuSelection).Hover == 3) {
                MenuSelection->Hover = 1;
                ClearSettingsArrow();
                ConstructPlayGameArrow();
            }
            else if ((*MenuSelection).Hover == 1) {
                MenuSelection->Hover = 2;
                ClearPlayGameArrow();
                ConstructHowToPlayArrow();
            }
            else if ((*MenuSelection).Hover == 2) {
                MenuSelection->Hover = 3;
                ClearHowToPlayArrow();
                ConstructSettingsArrow();
            }
        }
        else if (((*MenuSelection).MainMenu == 2) && ((*MenuSelection).Setting == 1)) {
            if ((*MenuSelection).Hover == 1) {
                MenuSelection->Hover = 2;
                ClearSpaceshipArrow();
                ConstructBackArrow();
            }
            else if ((*MenuSelection).Hover == 2) {
                MenuSelection->Hover = 1;
                ClearBackArrow();
                ConstructSpaceshipArrow();
            }
        }
        else if (((*MenuSelection).MainMenu == 2) && ((*MenuSelection).Setting == 2)) {
            if ((*MenuSelection).Hover == 1) {
                    MenuSelection->Hover = 2;
                    ClearSpaceShip1Arrow();
                    ConstructSpaceShip2Arrow();
            }
            else if ((*MenuSelection).Hover == 2) {
                    MenuSelection->Hover = 1;
                    ClearSpaceShip2Arrow();
                    ConstructSpaceShip1Arrow();
            }
        }
    }

    // If and only if the pressed button is "d", the players moves right
    if(buttonPress == 'd'){
    }
    // If and only if the pressed button is 0x20 (space), the players shoots (if the player can shoot)
    if(buttonPress == 0x20){
            if (((*MenuSelection).MainMenu == 1) && ((*MenuSelection).Hover) == 1) {
                BeginGame(drawValues);
                MenuSelection->MainMenu = 0;
            }
            else if (((*MenuSelection).MainMenu == 1) && ((*MenuSelection).Hover) == 2) {
                BeginHowToPlayMenu(drawValues);
                MenuSelection->MainMenu = 2;
                MenuSelection->H2P = 1;
                MenuSelection->Hover = 1;
                ConstructBackArrow();
            }
            else if (((*MenuSelection).MainMenu == 2) && ((*MenuSelection).H2P == 1)) {
                    if (((*MenuSelection).Hover) == 1) {
                        BeginMainMenu(drawValues);
                        MenuSelection->MainMenu = 1;
                        MenuSelection->H2P = 0;
                        MenuSelection->Hover = 2;
                        ConstructHowToPlayArrow();
                    }
            }
            else if (((*MenuSelection).MainMenu == 1) && ((*MenuSelection).Hover) == 3) {
                BeginSettingMenu(drawValues);
                MenuSelection->MainMenu = 2;
                MenuSelection->Setting = 1;
                MenuSelection->Hover = 1;
                ConstructSpaceshipArrow();
            }
            else if (((*MenuSelection).MainMenu == 2) && ((*MenuSelection).Setting == 1)) {
                if ((*MenuSelection).Hover == 2) {
                    BeginMainMenu(drawValues);
                    MenuSelection->MainMenu = 1;
                    MenuSelection->Setting = 0;
                    MenuSelection->Hover = 3;
                    ConstructSettingsArrow();
                }
                else if ((*MenuSelection).Hover == 1) {
                    ConstructSpaceShipMenu(drawValues);
                    MenuSelection->Setting = 2;
                    MenuSelection->Hover = 1;
                    ConstructSpaceShip1Arrow();
                }
            }
            else if (((*MenuSelection).MainMenu == 2) && ((*MenuSelection).Setting == 2)) {
                if ((*MenuSelection).Hover == 1){
                    ClearSpaceShipMenu(drawValues);
                    MenuSelection->Setting = 1;
                    MenuSelection->Hover = 1;
                }
                else if ((*MenuSelection).Hover == 2){
                    ClearSpaceShipMenu(drawValues);
                    MenuSelection->Setting = 1;
                    MenuSelection->Hover = 1;
                }
            }

    }






    //cleans the uart input
    uart_clear();
    //returns the players direction
}

