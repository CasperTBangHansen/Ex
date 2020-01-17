#include "stm32f30x_conf.h"
#include "30010_io.h"
#include <stdio.h>


#ifndef _TIMER_H_
#define _TIMER_H_

struct time {
int8_t centisecond;
int8_t second;
int8_t minute;
int8_t hour;
int8_t currentMap;
}counter;


void SetTimer();
void TIM2_IRQHandler(void);
void InitTimerStruct(struct time *counter);
void Split_Time_Function(struct time *counter, char *splitTime);

#endif
