#ifndef _DRAWING_H_
#define _DRAWING_H_

#include "ManageLevels.h"
#include "Drawing.h"
#include "Collider.h"
#include "ControlSystem.h"
#include "EnemyController.h"
#include "Timer.h"

void initStructs(struct drawItems *drawValues, uint8_t shipValue);
static void initEverythingFirstTime(struct player *player, struct enemy *enemy, struct mapPackage *maps);
static void upDateFunction(struct player *player, struct enemy *enemy, struct mapPackage *maps, struct drawItems *drawValues, uint8_t shipValue);
void InterruptSet();

#endif


