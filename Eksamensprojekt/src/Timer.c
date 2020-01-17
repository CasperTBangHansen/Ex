#include "Timer.h"
#include <stdio.h>
#include "stm32f30x_conf.h"
#include "30010_io.h"
#include <stdlib.h>

// @@@@@@@@@ EXAMPLE MAIN @@@@@@@@@@


/*
int main(void)
{
    uart_init( 9600 );
    InitTimerStruct(&counter);
    SetTimer();
    uint8_t initMap = 1;
    char currentSplitTime[11];
    Split_Time_Function(&counter, &currentSplitTime);
    printf("splitTime : %s \n",currentSplitTime);
    while(1){
            Split_Time_Function(&counter, &currentSplitTime);
            printf("splitTime : %s \n",currentSplitTime);
    }
}
*/



void SetTimer(){ //Enables the clock, and starts the timer.
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

void TIM2_IRQHandler(void) { //Makes sure that there's only 100 centiseconds on a second, and 60 seconds on a minute etc.
    counter.centisecond++;
    if(counter.centisecond >= 100){
        counter.centisecond -= 100;
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

void InitTimerStruct(struct time *counter){ //Initialize the struct
    counter->centisecond = 0;
    counter->second = 0;
    counter->minute = 0;
    counter->hour = 0;
    }

void Split_Time_Function(struct time *counter, char *splitTime){ //Take the struct, and the address for a char, then prints the current time to that char address, so it can be used later on.
sprintf((splitTime),"%02d:%02d:%02d:%02d",counter->hour,counter->minute,counter->second,counter->centisecond);
}


// No idea if the code below works. Idea was to store a static char everytime we get new data on
/*
void LoadSplitTimes(uint8_t initMap, uint8_t mapChoice){
    if (initMap == 1 && mapChoice == 2){
            Split_Time_Function(&counter, &currentSplitTime);
            static char *map1 = currentSplitTime;
            printf("splitTime : %s \n",map1);
    }
    if (initMap == 1 && mapChoice == 3){
            Split_Time_Function(&counter, &currentSplitTime);
            static char *map2 = currentSplitTime;
            printf("splitTime : %s \n",map2);
    }
    if (initMap == 1 && mapChoice == 4){
            Split_Time_Function(&counter, &currentSplitTime);
            static char *map3 = currentSplitTime;
            printf("splitTime : %s \n",map3);
    }
    if (initMap == 1 && mapChoice == 5){
            Split_Time_Function(&counter, &currentSplitTime);
            static char *map4 = currentSplitTime;
            printf("splitTime : %s \n",map4);
    }
    if (initMap == 1 && mapChoice == 6){
            Split_Time_Function(&counter, &currentSplitTime);
            static char *map5 = currentSplitTime;
            printf("splitTime : %s \n",map5);
}
return;
}
*/
