/*
Control.h
*/

#ifndef _LEVELMANAGER_H_
#define _LEVELMANAGER_H_

#include <stdint.h>
#include <stdio.h>

struct mapPackage {
uint8_t mapChoice;
uint8_t initMap;
};

void MapInit(struct mapPackage *initMaps);
void LevelManager(struct mapPackage *maps);


#endif _LEVELMANAGER_H_

