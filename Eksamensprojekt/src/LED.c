#include "LED.h"
/*********************************************************************
   Primary editor  :    Mathias Jensen
   Secondary editor:

**********************************************************************/
void GameLED(uint8_t tal){
    RCC->AHBENR |= RCC_AHBPeriph_GPIOA; // Enable clock for GPIO Port A
    RCC->AHBENR |= RCC_AHBPeriph_GPIOB; // Enable clock for GPIO Port B
    RCC->AHBENR |= RCC_AHBPeriph_GPIOC; // Enable clock for GPIO Port C

    // Set pin PA9 to output
     GPIOA->OSPEEDR &= ~(0x00000003 << (9 * 2)); // Clear speed register
     GPIOA->OSPEEDR |= (0x00000002 << (9 * 2)); // set speed register (0x01 - 10MHz, 0x02 - 2 MHz, 0x03 - 50 MHz)
     GPIOA->OTYPER &= ~(0x0001 << (9)); // Clear output type register
     GPIOA->OTYPER |= (0x0000 << (9)); // Set output type register (0x00 - Push pull, 0x01 - Open drain)
     GPIOA->MODER &= ~(0x00000003 << (9 * 2)); // Clear mode register
     GPIOA->MODER |= (0x00000001 << (9 * 2)); // Set mode register (0x00 – Input, 0x01 - Output, 0x02 - Alternate Function, 0x03 - Analog in/out)

     // Set pin PB4 to output
     GPIOB->OSPEEDR &= ~(0x00000003 << (4 * 2)); // Clear speed register
     GPIOB->OSPEEDR |= (0x00000002 << (4 * 2)); // set speed register (0x01 - 10MHz, 0x02 - 2 MHz, 0x03 - 50 MHz)
     GPIOB->OTYPER &= ~(0x0001 << (4)); // Clear output type register
     GPIOB->OTYPER |= (0x0000 << (4)); // Set output type register (0x00 - Push pull, 0x01 - Open drain)
     GPIOB->MODER &= ~(0x00000003 << (4 * 2)); // Clear mode register
     GPIOB->MODER |= (0x00000001 << (4 * 2)); // Set mode register (0x00 – Input, 0x01 - Output, 0x02 - Alternate Function, 0x03 - Analog in/out)

     // Set pin PC7 to output
     GPIOC->OSPEEDR &= ~(0x00000003 << (7 * 2)); // Clear speed register
     GPIOC->OSPEEDR |= (0x00000002 << (7 * 2)); // set speed register (0x01 - 10MHz, 0x02 - 2 MHz, 0x03 - 50 MHz)
     GPIOC->OTYPER &= ~(0x0001 << (7)); // Clear output type register
     GPIOC->OTYPER |= (0x0000 << (7)); // Set output type register (0x00 - Push pull, 0x01 - Open drain)
     GPIOC->MODER &= ~(0x00000003 << (7 * 2)); // Clear mode register
     GPIOC->MODER |= (0x00000001 << (7 * 2)); // Set mode register (0x00 – Input, 0x01 - Output, 0x02 - Alternate Function, 0x03 - Analog in/out)


    // Change the color depending on where in the game/menu you are
    switch (tal) {
        case 1: // Blue while in menu
        GPIOC->ODR |= (0x0001 << 7); //Set pin PA9 to high
        GPIOB->ODR |= (0x0001 << 4); //Set pin PA9 to high
        GPIOA->ODR &= ~(0x0001 << 9); //Set pin PA9 to low
        break;
        case 2: // Green while in game
        GPIOC->ODR &= ~(0x0001 << 7); //Set pin PC7 to low
        GPIOB->ODR |= (0x0001 << 4); //Set pin PB4 to high
        GPIOA->ODR |= (0x0001 << 9); //Set pin PA9 to high
            break;
        case 3: // red when life is lost
        GPIOC->ODR |= (0x0001 << 7); //Set pin PC7 to high
        GPIOB->ODR &= ~(0x0001 << 4); //Set pin PB4 to low
        GPIOA->ODR |= (0x0001 << 9); //Set pin PA9 to high
            break;
        case 4: //Yellow when loading
        GPIOC->ODR &= ~(0x0001 << 7); //Set pin PA9 to low
        GPIOB->ODR &= ~(0x0001 << 4); //Set pin PA9 to low
        GPIOA->ODR |= (0x0001 << 9); //Set pin PA9 to high
            break;
        default: // Dont change the color
            break;
    }
}

//setRedLED sets a timer so the red LED will turn on for longer
void setRedLED(struct player *player, uint8_t preLives){
    //init
    uint8_t ledTimer;
    //check if the player died
    if((*player).lives != preLives){
        //sets a timer
        if(counter.second <= 58){
            ledTimer = counter.second + 1;
        } else {
            ledTimer = 1;
        }
        //set the LED to red if the time hasn't chanced
        while(counter.second != ledTimer){
            //red led
            GameLED(3);
        }
    }
}
