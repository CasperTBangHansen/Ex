#include <stdint.h>
#include <stdio.h>

#ifndef _TIMER_H_
#define _TIMER_H_

struct time{
    uint8_t hour;
    uint8_t minute;
    uint8_t second;
    uint8_t centisecond;
    uint8_t runOnce;
};

struct time counter;

void setTimer();
void TIM2_IRGHandler(void);

void init(struct time *counter);

#endif
