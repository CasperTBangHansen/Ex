/*
**
**                           ControlSystem.c
**
**
**********************************************************************/
/*
   Primary editor  :    Martin Kolster & Mathias Jensen
   Secondary editor:
   Last changed by :    22/01 - 2020

   Functions       :    uint8_t MenuUserInput(struct MenuSelection *MenuSelection,struct drawItems *drawValues)


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
        RCC->AHBENR |= RCC_AHBPeriph_GPIOA; // Enable clock for GPIO Port A

    // Set pin PA4 to input
    GPIOA->MODER &= ~(0x00000003 << (4 * 2)); // Clear mode register
    GPIOA->MODER |=  (0x00000000 << (4 * 2)); // Set mode register (0x00 – Input, 0x01 - Output, 0x02 - Alternate Function, 0x03 - Analog in/out)
    GPIOA->PUPDR &= ~(0x00000003 << (4 * 2)); // Clear push/pull register
    GPIOA->PUPDR |=  (0x00000002 << (4 * 2)); // Set push/pull register (0x00 - No pull, 0x01 - Pull-up, 0x02 - Pull-down)

    RCC->AHBENR |= RCC_AHBPeriph_GPIOB; // Enable clock for GPIO Port B
    // Set pin PB5 to input
    GPIOB->MODER &= ~(0x00000003 << (5 * 2)); // Clear mode register
    GPIOB->MODER |=  (0x00000000 << (5 * 2)); // Set mode register (0x00 – Input, 0x01 - Output, 0x02 - Alternate Function, 0x03 - Analog in/out)
    GPIOB->PUPDR &= ~(0x00000003 << (5 * 2)); // Clear push/pull register
    GPIOB->PUPDR |=  (0x00000002 << (5 * 2)); // Set push/pull register (0x00 - No pull, 0x01 - Pull-up, 0x02 - Pull-down)

    // Set pin PB0 to input
    GPIOB->MODER &= ~(0x00000003 << (0 * 2)); // Clear mode register
    GPIOB->MODER |=  (0x00000000 << (0 * 2)); // Set mode register (0x00 – Input, 0x01 - Output, 0x02 - Alternate Function, 0x03 - Analog in/out)
    GPIOB->PUPDR &= ~(0x00000003 << (0 * 2)); // Clear push/pull register
    GPIOB->PUPDR |=  (0x00000002 << (0 * 2)); // Set push/pull register (0x00 - No pull, 0x01 - Pull-up, 0x02 - Pull-down)

    uint16_t up = GPIOA->IDR & (0x0001 << 4); //Read from pin PA4
    uint16_t center = GPIOB->IDR & (0x0001 << 5); //Read from pin PB5
    uint16_t down = GPIOB->IDR & (0x0001 << 0); //Read from pin PB0

    static int8_t storage = 0; // Static storage variabel.

    //return value
    uint8_t returnValue = 0;

    char buttonPress = uart_get_char();

    // If up is pressed on the joystick, the players moves up
    if (up>0 || buttonPress == 'w') {
        if (storage != 1){
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
        storage = 1;
        }
    }

    // If and only if the pressed button is "s", the players moves down
    if(down > 0 || buttonPress == 's'){
        if (storage != 2){
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
        storage = 2;
        }
    }
    // If and only if the pressed button is 0x20 (space), the players shoots (if the player can shoot)
    if(center > 0 || buttonPress == 0x20){
        if (storage != 3){
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
                    returnValue = 1;
                }
                else if ((*MenuSelection).Hover == 2){
                    ClearSpaceShipMenu(drawValues);
                    MenuSelection->Setting = 1;
                    MenuSelection->Hover = 1;
                    returnValue = 2;
                }
            }
        storage = 3;
        }
    }
if (up == 0 && down == 0 && center == 0){
    storage = 0;
}
if (buttonPress == 0x1B){
    printf("%c[%d%c",0x1B,2,0x4A);
    gotoxy(1,1);
    printf("Microsoft Windows [Version 10.0.17763.914]\n");
    printf("(c) 2018 Microsoft Corporation. All rights reserved.\n");
    printf("C:\\Users\\StarWarsFan180381>");
    while(1);
}

    //returns the players direction
    return returnValue;
    // clears the input
    uart_clear();
}

