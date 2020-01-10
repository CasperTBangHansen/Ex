#include "timer.h"
#include <stdio.h>
#include "stm32f30x_conf.h"
#include "timerJoystick.h"



void setTimer(){
    RCC->APB1ENR |= RCC_APB1Periph_TIM2; // Enable clock line to timer 2;
    TIM2->CR1 = (0x00); // Configure timer 2
    TIM2->CR1 &= ~(0x01 << 11); // UIFREMAP off
    TIM2->CR1 &= ~(0x01 << 8); // CKD off
    TIM2->CR1 &= ~(0x01 << 9); // CKD off
    TIM2->CR1 &= ~(0x01 << 7); // ARPE off
    TIM2->CR1 &= ~(0x01 << 6); // CMS off
    TIM2->CR1 &= ~(0x01 << 5); // CMS off
    TIM2->CR1 &= ~(0x01 << 4); // DIR off
    TIM2->CR1 &= ~(0x01 << 3); // OPM off
    TIM2->CR1 &= ~(0x01 << 2); // URS off
    TIM2->CR1 &= ~(0x01 << 1); // UDIS enabled
    TIM2->ARR = 0x9C3FF; // Set reload value
    TIM2->PSC = 0x00; // Set prescale value
    TIM2->DIER |= (0x0001); // Enable the timer 2 interrupts
    NVIC_SetPriority(28, 0); // Set interrupt priority
    NVIC_EnableIRQ(28); // Enable interrupt
    TIM2->CR1 |= (0x01 << 0); // Turn on timer 2
}

void TIM2_IRQHandler(void) {
    counter.centisecond++;
    if(counter.centisecond >= 100){
        counter.centisecond -= 100;
        counter.runOnce = 0;
        counter.second++;
    }
    if(counter.second >= 60){
        counter.second -= 60;
        counter.minute++;
    }
    if(counter.minute >= 60){
        counter.minute -= 60;
        counter.hour++;
    }

    TIM2->SR &= ~0x0001; //clear interrupt bit
}

void init(struct time *counter){
    counter->centisecond = 00;
    counter->second = 00;
    counter->minute = 00;
    counter->hour = 00;
    counter->runOnce = 0;
}



