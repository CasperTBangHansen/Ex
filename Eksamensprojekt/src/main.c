/*
**
**                           Main.c
**
**
**********************************************************************/
/*
   Primary editor  :    Casper Bang - Hansen
   Secondary editor:
   Last changed by :    19/01 - 2020

   Functions       :    int main(void);

**********************************************************************/

//include .h file
#include "stm32f30x_conf.h"
#include "30010_io.h"
#include "Update.h"


int main(void)
{
    uart_init( 115200 );
    //reset screen
    printf("%c[%d%c",0x1B,2,0x4A);
    //starts game
    initStructs();
    while(1){}
}
