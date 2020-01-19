/*
Control.h
*/

#ifndef _MANAGELEVELS_H_
#define _MANAGELEVELS_H_

#include <stdint.h>
#include <stdio.h>
#include "MapPack.h"

struct mapPackage {
    uint8_t mapChoice;
};

void LevelManager(struct mapPackage *maps, struct drawItems *drawValues);


#endif

