/*
    Input mapChoice: The map number of choice; which map the player is currently on
    Input initMap: Boolean value from mapPackage, if true this initializes the level
    Struct mapPackage: Structure containing map choice and boolean true/false value to initialize level
*/
#include "ManageLevels.h"

void MapInit(struct mapPackage *initMaps){
    initMaps->mapChoice = 2; // Map number of choice
    initMaps->initMap = 1; // Boolean value to know if the current level has been completed
}



// The function that resets the map of choice the first time you enter and then loads the map.
void LevelManager(struct mapPackage *maps){
switch ((*maps).mapChoice) // Loads map of choice
{
case 1: // Map 1
    {
        if ((*maps).initMap == 1){ // First time you enter it loads and builds the entire map
            printf("map 1 has been reset!\n");
            //MapSetup();
            (*maps).initMap = 0;
            }
        else{
            printf("map 1 test\n");
        }
    }
    break;
case 2: // Map 2
    {
        if ((*maps).initMap == 1){ // First time you enter it loads and builds the entire map
            printf("map 2 has been reset!\n");
            //MapSetup();
            maps->initMap = 0;
        }
        else{
            printf("map 2 test\n");
        }
    }
    break;
case 3: // Map 3
    {
        if ((*maps).initMap == 1){ // First time you enter it loads and builds the entire map
            printf("map 3 has been reset!\n");
            //MapSetup();
            (*maps).initMap = 0;
            }
        else{
            printf("map 1 test\n");
        }
    }
    break;
default:
    break;
}
}

