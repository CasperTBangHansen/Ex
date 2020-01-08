#include <stdint.h>
#include <stdio.h>

#ifndef _VECTORROT_H_
#define _VECTORROT_H_

struct vector_t{
    int32_t x;
    int32_t y;
};


void initVector(struct vector_t *v, int32_t xValue, int32_t yValue);
void rotateVector(struct vector_t *vMem, struct vector_t v , int32_t angle);

#endif /* _ANSI_H_ */
