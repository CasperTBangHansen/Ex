#ifndef _MAINMENU_H_
#define _MAINMENU_H_

#include "Update.h"
#include "MainMenu.h"
#include "MenuControls.h"

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
void ClearGameScreen(struct drawItems *drawValues);
void ConstructGoodLuck();
void ConstructSpaceShipMenu(drawValues);
void ClearSpaceShipMenu(drawValues);
void ConstructSpaceShip1Arrow();
void ConstructSpaceShip2Arrow();
void ClearSpaceShip1Arrow();
void ClearSpaceShip2Arrow();
void BeginMenuScreen(struct MenuSelection *MenuSelection,struct drawItems *drawValues);
void BeginHowToPlayMenu(struct drawItems *drawValues);
void BeginSettingMenu(struct drawItems *drawValues);
void BeginMainMenu(struct drawItems *drawValues);
void BeginGame(struct drawItems *drawValues);


#endif
