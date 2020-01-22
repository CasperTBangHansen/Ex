#ifndef _TIMER_H_
#define _TIMER_H_

#include "stm32f30x_conf.h"
#include "30010_io.h"
#include <stdio.h>


struct time {
    uint8_t centisecond;
    uint8_t second;
    uint8_t minute;
    uint8_t hour;
    uint8_t runPlayer;
    uint8_t runBullet;
    uint8_t runEnemies;
    uint8_t speedPlayer;
    uint8_t speedBullet;
    uint8_t speedEnemies;
}counter;


void SetTimer();
void TIM2_IRQHandler(void);
void InitTimerStruct(struct time *counter);
void Split_Time_Function(struct time *counter, char *splitTime);

#endif
