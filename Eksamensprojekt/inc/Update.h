#ifndef _DRAWING_H_
#define _DRAWING_H_

#include "ManageLevels.h"
#include "Drawing.h"
#include "Collider.h"
#include "ControlSystem.h"
#include "EnemyController.h"
#include "Timer.h"
#include "DrawObjects.h"
#include "upDateUI.h"
#include "MainMenu.h"
#include "LED.h"

void initStructs(struct drawItems *drawValues, uint8_t ship, int64_t *highscore);
static void initEverythingFirstTime(struct player *player, struct enemy *enemy, struct mapPackage *maps, struct powerUp *powerUp);
static void upDateFunction(struct player *player, struct enemy *enemy, struct mapPackage *maps, struct drawItems *drawValues, uint8_t ship, int64_t *highscore, struct powerUp *powerUp);
void InterruptSet();

#endif


