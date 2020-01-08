
#include "vectorRot.h"
#include <stdio.h>
#define FIX14_SHIFT 14
#define FIX14_MULT(a, b) ( (a)*(b) >> FIX14_SHIFT )
#define FIX14_DIV(a, b) ( ((a) << FIX14_SHIFT) / b )


void initVector(struct vector_t *v, int32_t xValue, int32_t yValue) {
    v->x = xValue;
    v->y = yValue;
}


//Denne funktion tager imod en vektor v, som er i memory &v. Derudover tages imod vaerdiernen v. Der tages ogsaa i mod en vinkel
// Foerst regnes vinklen ud med vaerdierne v.x og v.y, samt cos/sin. Der bruges vMem til at butte tilbage i memory
void rotateVector(struct vector_t *vMem, struct vector_t v, int32_t angle){
    vMem->x = FIX14_MULT(v.x,calcCOSINUS(angle))-FIX14_MULT(v.y,calcSINUS(angle));
    vMem->y = FIX14_MULT(v.x,calcSINUS(angle))+FIX14_MULT(v.y,calcCOSINUS(angle));
}
