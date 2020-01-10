#include "Joystick.h"
#include "stm32f30x_conf.h"
#include <stdio.h>
#include "timer.h"

void initscreen(){
    clearscr();
        gotoxy(3,3);
        printf("Time since start  %01d:%02d:%02d.--\n",counter.hour, counter.minute ,counter.second);
        gotoxy(3,5);
        printf("1. Split time     %01d:%02d:%02d.%02d\n",counter.hour, counter.minute,counter.second,counter.centisecond);
        gotoxy(3,7);
        printf("2. Split time     %01d:%02d:%02d.%02d\n",counter.hour, counter.minute ,counter.second,counter.centisecond);
        }

char readTimerJoystick(){

    RCC->AHBENR |= RCC_AHBPeriph_GPIOA; // Enable clock for GPIO Port A

    // Set pin PA4 to input
    GPIOA->MODER &= ~(0x00000003 << (4 * 2)); // Clear mode register
    GPIOA->MODER |=  (0x00000000 << (4 * 2)); // Set mode register (0x00 – Input, 0x01 - Output, 0x02 - Alternate Function, 0x03 - Analog in/out)
    GPIOA->PUPDR &= ~(0x00000003 << (4 * 2)); // Clear push/pull register
    GPIOA->PUPDR |=  (0x00000002 << (4 * 2)); // Set push/pull register (0x00 - No pull, 0x01 - Pull-up, 0x02 - Pull-down)



    RCC->AHBENR |= RCC_AHBPeriph_GPIOC; // Enable clock for GPIO Port C
    // Set pin PC0 to input
    GPIOC->MODER &= ~(0x00000003 << (0 * 2)); // Clear mode register
    GPIOC->MODER |=  (0x00000000 << (0 * 2)); // Set mode register (0x00 – Input, 0x01 - Output, 0x02 - Alternate Function, 0x03 - Analog in/out)
    GPIOC->PUPDR &= ~(0x00000003 << (0 * 2)); // Clear push/pull register
    GPIOC->PUPDR |=  (0x00000002 << (0 * 2)); // Set push/pull register (0x00 - No pull, 0x01 - Pull-up, 0x02 - Pull-down)

    // Set pin PC1 to input
    GPIOC->MODER &= ~(0x00000003 << (1 * 2)); // Clear mode register
    GPIOC->MODER |=  (0x00000000 << (1 * 2)); // Set mode register (0x00 – Input, 0x01 - Output, 0x02 - Alternate Function, 0x03 - Analog in/out)
    GPIOC->PUPDR &= ~(0x00000003 << (1 * 2)); // Clear push/pull register
    GPIOC->PUPDR |=  (0x00000002 << (1 * 2)); // Set push/pull register (0x00 - No pull, 0x01 - Pull-up, 0x02 - Pull-down)


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
    uint16_t right = GPIOC->IDR & (0x0001 << 0); //Read from pin PC0
    uint16_t left = GPIOC->IDR & (0x0001 << 1); //Read from pin PC1
    uint16_t center = GPIOB->IDR & (0x0001 << 5); //Read from pin PB5
    uint16_t down = GPIOB->IDR & (0x0001 << 0); //Read from pin PB0


    static int8_t storage = 0x00; // Static storage variabel.

    if(up>0){ // If up is larger than 0 and up is pressed and storage is not equal to 0x01, storage bit 1 is flipped.
        if(storage != 0x01){
            storage |= 1 << 0;
            gotoxy(14,20);
            printf("Casper\n");
            gotoxy(15,21);
            printf("senpai\n");
            gotoxy(16,22);
            printf("i made a big fuky wucky\n");
            gotoxy(17,23);
            printf("uWu");
        }
    }
    else{
        storage &= ~(1 << 0);
    }
    if(down>0){ // If down is larger than 0 and down is pressed and storage bit 2 is not equal to 0x02, storage bit 2 is flipped by first
        if(storage != 0x02){
            storage |= 1 << 1;
            TIM2->CR1 &= ~(0x01 << 0); // Turn off timer 2
            init(&counter);
            clearscr();
            gotoxy(3,3);
            printf("Time since start  %01d:%02d:%02d.--\n",counter.hour, counter.minute ,counter.second);
            gotoxy(3,7);
            printf("2. Split time     %01d:%02d:%02d.%02d\n",counter.hour, counter.minute ,counter.second,counter.centisecond);
            gotoxy(3,5);
            printf("1. Split time     %01d:%02d:%02d.%02d\n",counter.hour, counter.minute,counter.second,counter.centisecond);
            gotoxy(3,9);
            printf("Stop watch has been reset. \n");
        }
    }
    else{
        storage &= ~(1 << 1);
    }
    if(left>0){ // If left is larger than 0 and left is pressed and storage bit 3 is not equal to 0x03, storage bit 3 is flipped by first
        if(storage != 0x04){
            storage |= 1 << 2;
            __disable_irq();
            gotoxy(3,5);
            printf("1. Split time     %01d:%02d:%02d.%02d\n",counter.hour, counter.minute,counter.second,counter.centisecond);
            __enable_irq();
        }
    }
    else{
        storage &= ~(1 << 2);
    }
    if(right>0){ // If right is larger than 0 and right is pressed and storage bit 3 is not equal to 0x04, storage bit 3 is flipped by first
        if(storage != 0x08){
            storage |= 1 << 3;
            __disable_irq();
            gotoxy(3,7);
            printf("2. Split time     %01d:%02d:%02d.%02d\n",counter.hour, counter.minute ,counter.second,counter.centisecond);
            __enable_irq();
        }
    }
    else{
        storage &= ~(1 << 3);
    }
    if(center>0){ // If center is larger than 0 and center is pressed and storage bit 4 is not equal to 0x05, storage bit 4 is flipped by first
        if(storage != 0x10){
            storage |= 1 << 4;
            uint8_t bit = TIM2->CR1 & (0x01 << 0);
            if (bit == 1) {
                TIM2->CR1 &= ~(0x01 << 0); // Turn off timer 2
            }
            if (bit == 0) {
                setTimer();
                gotoxy(3,9);
                clreol();
            }
        }
    }
    else{
        storage &= ~(1 << 4);
    }
    /* if(storage == 0){
        printf("No direction pressed");
    } */
    //printf("%d\n",storage);
    return storage;

}


