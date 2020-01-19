#ifndef _DRAWING_H_
#define _DRAWING_H_

#include "ManageLevels.h"
#include "Drawing.h"
#include "Collider.h"
#include "ControlSystem.h"



void initStructs();
static void initEverythingFirstTime(struct player *player, struct enemy *enemy, struct mapPackage *maps);
static void upDateFunction(struct player *player, struct enemy *enemy, struct mapPackage *maps, struct drawItems *drawValues);

#endif


