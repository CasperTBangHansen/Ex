/*
**
**                           Main.c
**
**
**********************************************************************/
/*
   Last committed:     $Revision: 00 $
   Last changed by:    $Author: $
   Last changed date:  $Date:  $
   ID:                 $Id:  $

**********************************************************************/
#include "stm32f30x_conf.h"
#include "30010_io.h"
#include "SINexport.h"
#include "vectorRot.h"
#include "window.h"
#include "BallBounce.h"
#include "Joystick.h"

#define FIX14_SHIFT 14
#define FIX14_MULT(a, b) ( (a)*(b) >> FIX14_SHIFT )
#define FIX14_DIV(a, b) ( ((a) << FIX14_SHIFT) / b )




int main(void)
{
    uart_init( 9600 ); // Initialize USB serial emulation at 9600 baud
    while(1){
        readJoystick();
    }




    //Ball Game:
    /*struct windowSize win;
    struct ball ballstruct;
    initalizerWindow(&win, 1 , 1, 100, 5, "BALL GAME", 2);
    initalizerBallBounce(&win);
    InitBallPosition(&ballstruct, 50, 3, -1 , 1);
    update(&win ,&ballstruct);*/

    /*struct vector_t v;
    initVector(&v,1,0);

    printf("(%d,%d) -> ",v.x,v.y);
    rotateVector(&v, v,0);
    printf("(%d,%d) -> ",v.x,v.y);
    rotateVector(&v, v,90);
    printf("(%d,%d) -> ",v.x,v.y);
    rotateVector(&v, v,180);
    printf("(%d,%d) -> ",v.x,v.y);
    rotateVector(&v, v,270);
    printf("(%d,%d) -> ",v.x,v.y);
    rotateVector(&v, v,360);
    printf("(%d,%d)\n",v.x,v.y);
    printFIX(FIX14_MULT(FIX14_DIV(17, 8),FIX14_DIV(9, 4)));*/
    while(1){}
}
