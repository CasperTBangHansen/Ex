#include "LED.h"
#include "stm32f30x_conf.h"
#include "30010_io.h"
#include <stdint.h>
#include <stdio.h>



// Initializing outputting to the LED:
int setLed(int8_t colour) {
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


    // 1: Red, 2: Green, 3: Blue
    switch (colour) {
        case 1: // Red
        GPIOC->ODR |= (0x0001 << 7); //Set pin PA9 to high
        GPIOB->ODR &= ~(0x0001 << 4); //Set pin PA9 to low
        GPIOA->ODR |= (0x0001 << 9); //Set pin PA9 to high
            break;
        case 2: // Green
        GPIOC->ODR &= ~(0x0001 << 7); //Set pin PA9 to low
        GPIOB->ODR |= (0x0001 << 4); //Set pin PA9 to high
        GPIOA->ODR |= (0x0001 << 9); //Set pin PA9 to high
            break;
        case 4: // Blue
        GPIOC->ODR |= (0x0001 << 7); //Set pin PA9 to high
        GPIOB->ODR |= (0x0001 << 4); //Set pin PA9 to high
        GPIOA->ODR &= ~(0x0001 << 9); //Set pin PA9 to low
            break;
        case 8: // Cyan
        GPIOC->ODR &= ~(0x0001 << 7); //Set pin PA9 to low
        GPIOB->ODR |= (0x0001 << 4); //Set pin PA9 to high
        GPIOA->ODR &= ~(0x0001 << 9); //Set pin PA9 to low
            break;
        case 16: // Magenta
        GPIOC->ODR |= (0x0001 << 7); //Set pin PA9 to high
        GPIOB->ODR &= ~(0x0001 << 4); //Set pin PA9 to low
        GPIOA->ODR &= ~(0x0001 << 9); //Set pin PA9 to low
            break;
        case 32: // Yellow
        GPIOC->ODR &= ~(0x0001 << 7); //Set pin PA9 to low
        GPIOB->ODR &= ~(0x0001 << 4); //Set pin PA9 to low
        GPIOA->ODR |= (0x0001 << 9); //Set pin PA9 to high
            break;
        case 64: // White
        GPIOC->ODR &= ~(0x0001 << 7); //Set pin PA9 to low
        GPIOB->ODR &= ~(0x0001 << 4); //Set pin PA9 to low
        GPIOA->ODR &= ~(0x0001 << 9); //Set pin PA9 to low
            break;
        default: // Dont change the color
            break;
    }
}

