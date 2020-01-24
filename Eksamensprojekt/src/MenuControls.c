/*
**
**                           ControlSystem.c
**
**
**********************************************************************/
/*********************************************************************
   Primary editor  :    Martin Kolster & Mathias Jensen
   Secondary editor:

**********************************************************************/

//include .h file
#include "MenuControls.h"
//defines
//Symbols
#define ESC 0x1B
#define SPACE 0x20

// userInput takes the users keyboard input and sets either the players position or spawns bullets


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

    // if up is pressed on the joystick or w on the keyboard, the menu arrow will go one up.
    if (up>0 || buttonPress == 'w') {
        if (storage != 1){
            if ((*MenuSelection).MainMenu == 1) {  // If we're in the main menu
                if ((*MenuSelection).Hover == 1) { // if arrow is on play game, clears arrow, go up and create arrow on settings
                    MenuSelection->Hover = 3;
                    ClearPlayGameArrow();
                    ConstructSettingsArrow();
                }
                else if ((*MenuSelection).Hover == 2){ // if arrow is on how to play, clears arrow, go up and create arrow on play to game
                    MenuSelection->Hover = 1;
                    ClearHowToPlayArrow();
                    ConstructPlayGameArrow();
                }
                else if ((*MenuSelection).Hover == 3){ // if arrow is on settings, clears arrow, go up and create arrow on how to play
                    MenuSelection->Hover = 2;
                    ClearSettingsArrow();
                    ConstructHowToPlayArrow();
                }
            }

            else if (((*MenuSelection).MainMenu == 2) && ((*MenuSelection).Setting == 1)) {
                if ((*MenuSelection).Hover == 1) { // if arrow is on spaceship, clears arrow, go up and create arrow on back
                    MenuSelection->Hover = 2;
                    ClearSpaceshipArrow();
                    ConstructBackArrow();
                }
                else if ((*MenuSelection).Hover == 2) { // if arrow is on back, clears arrow, go up and create arrow on spaceship
                    MenuSelection->Hover = 1;
                    ClearBackArrow();
                    ConstructSpaceshipArrow();
                }
            }
            else if (((*MenuSelection).MainMenu == 2) && ((*MenuSelection).Setting == 2)) {
                if ((*MenuSelection).Hover == 1) { // if arrow is on space ship 1, clears arrow, go up and create arrow on space ship 2
                        MenuSelection->Hover = 2;
                        ClearSpaceShip1Arrow();
                        ConstructSpaceShip2Arrow();
                }
                else if ((*MenuSelection).Hover == 2) { // if arrow is on space ship 2, clears arrow, go up and create arrow on space ship 1
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
                if ((*MenuSelection).Hover == 3) { // if arrow is on settings, clears arrow, go down and create arrow on play game
                    MenuSelection->Hover = 1;
                    ClearSettingsArrow();
                    ConstructPlayGameArrow();
                }
                else if ((*MenuSelection).Hover == 1) { // if arrow is on play game, clears arrow, go down and create arrow on how to play
                    MenuSelection->Hover = 2;
                    ClearPlayGameArrow();
                    ConstructHowToPlayArrow();
                }
                else if ((*MenuSelection).Hover == 2) { // if arrow is on how to play, clears arrow, go down and create arrow on setting
                    MenuSelection->Hover = 3;
                    ClearHowToPlayArrow();
                    ConstructSettingsArrow();
                }
            }
            else if (((*MenuSelection).MainMenu == 2) && ((*MenuSelection).Setting == 1)) {
                if ((*MenuSelection).Hover == 1) { // if arrow is on space ship, clears arrow, go down and create arrow on back
                    MenuSelection->Hover = 2;
                    ClearSpaceshipArrow();
                    ConstructBackArrow();
                }
                else if ((*MenuSelection).Hover == 2) { // if arrow is on back, clears arrow, go down and create arrow on space ship
                    MenuSelection->Hover = 1;
                    ClearBackArrow();
                    ConstructSpaceshipArrow();
                }
            }
            else if (((*MenuSelection).MainMenu == 2) && ((*MenuSelection).Setting == 2)) {
                if ((*MenuSelection).Hover == 1) { // if arrow is on spaceship 1, clears arrow, go down and create arrow on spaceship 2
                        MenuSelection->Hover = 2;
                        ClearSpaceShip1Arrow();
                        ConstructSpaceShip2Arrow();
                }
                else if ((*MenuSelection).Hover == 2) { // if arrow is on spaceship 2, clears arrow, go down and create arrow on spaceship 1
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
            if (((*MenuSelection).MainMenu == 1) && ((*MenuSelection).Hover) == 1) { // If space is pressed, and hover is on play game, clear game screen, set variable to 0 that inits the game
                BeginGame(drawValues);
                MenuSelection->MainMenu = 0;
            }
            else if (((*MenuSelection).MainMenu == 1) && ((*MenuSelection).Hover) == 2) { // If space is pressed and hover is on how to play, create howtoplay menu.
                BeginHowToPlayMenu(drawValues);
                MenuSelection->MainMenu = 2;
                MenuSelection->H2P = 1;
                MenuSelection->Hover = 1;
                ConstructBackArrow();
            }
            else if (((*MenuSelection).MainMenu == 2) && ((*MenuSelection).H2P == 1)) { // if space is pressed in the H2p Menu, hover is on back and it will go back to main menu.
                    if (((*MenuSelection).Hover) == 1) {
                        BeginMainMenu(drawValues);
                        MenuSelection->MainMenu = 1;
                        MenuSelection->H2P = 0;
                        MenuSelection->Hover = 2;
                        ConstructHowToPlayArrow();
                    }
            }
            else if (((*MenuSelection).MainMenu == 1) && ((*MenuSelection).Hover) == 3) { // If space is pressed and hover is over settings, go into settings submenu
                BeginSettingMenu(drawValues);
                MenuSelection->MainMenu = 2;
                MenuSelection->Setting = 1;
                MenuSelection->Hover = 1;
                ConstructSpaceshipArrow();
            }
            else if (((*MenuSelection).MainMenu == 2) && ((*MenuSelection).Setting == 1)) { // check if inside the settings submenu
                if ((*MenuSelection).Hover == 2) { // if space is pressed in the settings menu while hover is on back, go back to main menu
                    BeginMainMenu(drawValues);
                    MenuSelection->MainMenu = 1;
                    MenuSelection->Setting = 0;
                    MenuSelection->Hover = 3;
                    ConstructSettingsArrow();
                }
                else if ((*MenuSelection).Hover == 1) { // if space is pressed on the spaceship menu, open spaceship selection menu
                    ConstructSpaceShipMenu(drawValues);
                    MenuSelection->Setting = 2;
                    MenuSelection->Hover = 1;
                    ConstructSpaceShip1Arrow();
                }
            }
            else if (((*MenuSelection).MainMenu == 2) && ((*MenuSelection).Setting == 2)) { // check if in spaceship selection menu
                if ((*MenuSelection).Hover == 1){ // If in spaceship selection menu, and hover is over spaceship 1, select spaceship 1 and return value 1
                    ClearSpaceShipMenu(drawValues);
                    MenuSelection->Setting = 1;
                    MenuSelection->Hover = 1;
                    returnValue = 1;
                }
                else if ((*MenuSelection).Hover == 2){ // if in spaceship selection menu and hover is ove spaceship 2, return value 2.
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
if (buttonPress == 0x1B){ // if pressed escape, initiate boss key.
    printf("%c[%d%c",0x1B,2,0x4A);
    gotoxy(1,1);
    printf("Microsoft Windows [Version 10.0.17763.914]\n");
    printf("(c) 2018 Microsoft Corporation. All rights reserved.\n");
    printf("C:\\Users\\StarWarsFan180381>");
    while(1);
}

    //returns the players direction
    return returnValue; // Return what spaceship you selected.
    // clears the input
    uart_clear();
}

