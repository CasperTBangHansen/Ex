#ifndef _MAINMENU_H_
#define _MAINMENU_H_

#include "Update.h"


void ConstructWindow(struct drawItems *drawValues);
void clearscr();


void ConstructTitle();
void ConstructMainMenu();


void ConstructPlayGameArrow();
void ClearPlayGameArrow();

void ConstructHowToPlayArrow();
void ClearHowToPlayArrow();

void ConstructSettingsArrow();
void ClearSettingsArrow();

void ConstructBackArrow();
void ClearBackArrow();

void ConstructSpeedArrow();
void ClearSpeedArrow();

void ConstructSpaceshipArrow();
void ClearSpaceshipArrow();

void ClearSubMenu(struct drawItems *drawValues);

void ConstructHowToPlayMenu(struct drawItems *drawValues);
void ConstructSettingsMenu(struct drawItems *drawValues);

void ClearSubSettingsMenu(struct drawItems *drawValues);

void ConstructSpeedMenu(struct drawItems *drawValues);

void ConstructSpaceShipMenu(struct drawItems *drawValues);



#endif
