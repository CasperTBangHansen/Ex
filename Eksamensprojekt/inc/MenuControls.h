/*
MenuControl.h
*/

#ifndef _MENUCONTROLS_H_
#define _MENUCONTROLS_H_

#include "Collider.h"
#include "Update.h"
#include <stdint.h>
#include <stdio.h>
#include "MainMenu.h"

struct MenuSelection{
    uint8_t Hover;
    uint8_t MainMenu;
    uint8_t H2P;
    uint8_t Setting;
    uint8_t Ship;
};

uint8_t MenuUserInput(struct MenuSelection *MenuSelection,struct drawItems *drawValues);


#endif

