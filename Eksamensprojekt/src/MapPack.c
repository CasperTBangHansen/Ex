/*
**
**                           MapPack.c
**
**
**********************************************************************/
/*
   Primary editor  :    Martin Kolster
   Secondary editor:
   Last changed by :    19/01 - 2020

   Functions       :    void firstMapSetup(struct drawItems *drawValues);
                        void secondMapSetup(struct drawItems *drawValues);

**********************************************************************/

//include .h file
#include "MapPack.h"

/**********************************************************************

   Description     :    firstMapSetup draws the all the walls and gives the walls hitbox to the collider

   Input           :    struct drawItems *drawValues

   Output          :    void

**********************************************************************/

//Each function
void firstMapSetup(struct drawItems *drawValues, struct wallHitBox *wallHitBox) {


//Coordinates for all the walls in the first map. Creates lines based on coordinates.
// X value for the start of the line
    const uint8_t Xbegin[] = {
// X value for the end of the line
    16,17,164,163,
    16,16,
    141,141,
    40,40,40,141,40,141,
    46,46,46,50,50,60,
    66,66,70,
    76,76,100,96,76,96,
    81,81,81,86,90,86,
    71,71,71,75,
    56,61,65,56,61,46,50,46,60,46,50,
    46,46,46,50,
    41,41,41,45,
    56,56,56,66,66,70,
    56,56,56,60,
    76,76,76,80,
    56,70,56,56,
    76,90,76,76,86,86,
    96,96,96,100,
    96,96,96,100,
    96,96,96,110,100,100,
    116,116,116,120,
    110,106,106,110,120,106,
    106,106,106,125,
    106,106,110,115,110,106,110,115,
    121,121,125,
    116,116,116,120,
    131,131,131,135,
    126,126,126,135,
    126,121,126,135,121,121,
    131,131,131,135,
    116,116,116,125,
    131,131,126,135,126,126,
    126,126,
    51,51,51,75,
    81,81,81,90,86,86,
    86,86,90,
    66,66,66,80,
    76,76,76,80,
    56,56,56,70,
    46,46,46,50,
    56,56,56,60
    };
    const uint8_t Xstop[] = {
// Y value for the start of the line
    16,17,164,163,
    40,40,
    164,164,
    40,40,141,141,141,141,
    60,46,50,50,60,60,
    66,70,70,
    76,100,100,96,96,100,
    81,90,85,86,90,90,
    75,75,71,75,
    65,65,65,56,60,56,60,46,60,50,50,
    46,50,50,50,
    41,45,45,45,
    66,56,70,66,70,70,
    56,60,60,60,
    76,80,80,80,
    56,70,70,70,
    76,90,85,90,86,90,
    96,100,100,100,
    96,100,100,100,
    96,100,110,110,100,110,
    116,120,120,120,
    120,120,106,110,120,110,
    106,125,125,125,
    115,106,115,115,110,115,115,115,
    121,125,125,
    116,120,120,120,
    131,135,135,135,
    126,135,135,135,
    126,135,135,135,121,125,
    131,135,135,135,
    116,125,125,125,
    131,135,135,135,126,131,
    126,140,
    51,75,75,75,
    81,90,86,90,86,90,
    86,90,90,
    66,80,80,80,
    76,80,80,80,
    56,70,70,70,
    46,50,50,50,
    56,60,60,60};
    const uint8_t Ybegin[] = {
// X value for the end of the line
    61,61,61,61,
    60,70,
    60,70,
    20,70,20,20,111,70,
    26,26,35,30,30,26,
    20,30,20,
    26,26,26,31,30,45,
    36,36,40,40,36,55,
    36,40,36,36,
    36,40,36,36,40,41,45,41,40,55,46,
    61,61,75,61,
    81,81,85,81,
    61,61,65,46,46,46,
    51,51,55,51,
    46,46,60,46,
    71,71,71,75,
    66,61,66,75,61,61,
    51,70,51,51,
    76,85,76,76,
    91,91,105,101,91,101,
    101,101,105,101,
    91,95,71,71,91,71,
    61,61,65,61,
    55,26,51,51,30,26,30,26,
    21,30,21,
    36,36,45,36,
    26,26,30,26,
    36,36,40,36,
    46,55,46,46,50,50,
    61,61,70,61,
    71,71,85,71,
    76,76,95,76,91,91,
    101,101,
    81,81,85,81,
    81,81,85,81,86,95,
    101,101,101,
    101,101,105,101,
    91,91,95,91,
    91,91,95,91,
    91,91,105,91,
    101,101,105,101};
    const uint8_t Ystop[] = {
// What kind of Hex character to draw that specific line
    69,69,69,69,
    60,70,
    60,70,
    60,110,20,60,111,111,
    26,35,35,35,30,30,
    30,30,30,
    30,26,45,45,30,45,
    40,36,40,55,55,55,
    36,40,40,40,
    36,40,40,40,45,41,45,55,45,55,55,
    75,61,75,75,
    85,81,85,85,
    61,65,65,61,46,65,
    55,51,55,55,
    60,46,60,60,
    75,75,71,75,
    75,75,66,75,66,61,
    70,70,51,70,
    85,85,76,85,
    105,91,105,105,101,101,
    105,101,105,105,
    91,95,95,91,95,71,
    65,61,65,65,
    55,55,51,55,51,26,30,30,
    30,30,30,
    45,36,45,45,
    30,26,30,30,
    40,36,40,40,
    50,55,46,55,55,50,
    70,61,70,70,
    85,71,85,85,
    90,76,95,95,95,91,
    110,101,
    85,81,85,85,
    85,81,85,95,95,95,
    110,101,110,
    105,101,105,105,
    95,91,95,95,
    95,91,95,95,
    105,91,105,105,
    105,101,105,105
    };
    char charType[] = {
    0xAF,0xAF,0xAF,0xAF,
    0xB2,0xB2,
    0xB2,0xB2,
    0xB2,0xB2,0xB2,0xB2,0xB2,0xB2,
    0xB2,0xB2,0xB2,0xB2,0xB2,0xB2,
    0xB2,0xB2,0xB2,
    0xB2,0xB2,0xB2,0xB2,0xB2,0xB2,
    0xB2,0xB2,0xB2,0xB2,0xB2,0xB2,
    0xB2,0xB2,0xB2,0xB2,
    0xB2,0xB2,0xB2,0xB2,0xB2,0xB2,0xB2,0xB2,0xB2,0xB2,0xB2,
    0xB2,0xB2,0xB2,0xB2,
    0xB2,0xB2,0xB2,0xB2,
    0xB2,0xB2,0xB2,0xB2,0xB2,0xB2,
    0xB2,0xB2,0xB2,0xB2,
    0xB2,0xB2,0xB2,0xB2,
    0xB2,0xB2,0xB2,0xB2,
    0xB2,0xB2,0xB2,0xB2,0xB2,0xB2,
    0xB2,0xB2,0xB2,0xB2,
    0xB2,0xB2,0xB2,0xB2,
    0xB2,0xB2,0xB2,0xB2,0xB2,0xB2,
    0xB2,0xB2,0xB2,0xB2,
    0xB2,0xB2,0xB2,0xB2,0xB2,0xB2,
    0xB2,0xB2,0xB2,0xB2,
    0xB2,0xB2,0xB2,0xB2,0xB2,0xB2,0xB2,0xB2,
    0xB2,0xB2,0xB2,
    0xB2,0xB2,0xB2,0xB2,
    0xB2,0xB2,0xB2,0xB2,
    0xB2,0xB2,0xB2,0xB2,
    0xB2,0xB2,0xB2,0xB2,0xB2,0xB2,
    0xB2,0xB2,0xB2,0xB2,
    0xB2,0xB2,0xB2,0xB2,
    0xB2,0xB2,0xB2,0xB2,0xB2,0xB2,
    0xB2,0xB2,
    0xB2,0xB2,0xB2,0xB2,
    0xB2,0xB2,0xB2,0xB2,0xB2,0xB2,
    0xB2,0xB2,0xB2,
    0xB2,0xB2,0xB2,0xB2,
    0xB2,0xB2,0xB2,0xB2,
    0xB2,0xB2,0xB2,0xB2,
    0xB2,0xB2,0xB2,0xB2,
    0xB2,0xB2,0xB2,0xB2
    };

    //Sets all the walls drawing in the drawing buffer
    for(uint8_t i = 0; i<(sizeof(Ystop)); i++){
        DrawingSetValues(drawValues, Xbegin[i], Ybegin[i], Xstop[i], Ystop[i], charType[i]);
    }
    //frees up Xbegin, Ystop, Xstop
    free(&Xbegin);
    free(&Ybegin);
    free(&Xstop);

    //Gives the collider the hitbox of the walls
    setWallHitBox(drawValues,SetPos(2), wallHitBox);
    //Draws the entire maze
    DrawEverything(drawValues);
}

/**********************************************************************

   Description     :    secondMapSetup draws the all the walls and gives the walls hitbox to the collider

   Input           :    struct drawItems *drawValues

   Output          :    void

**********************************************************************/

void secondMapSetup(struct drawItems *drawValues, struct wallHitBox *wallHitBox) {


//Coordinates for all the walls in the first maps maze
// X value for the start of the line
    const uint8_t Xbegin[] = {
        // X value for the end of the line
    16,17,164,163,
    16,16,
    142,142,
    40,40,40,142,40,142,
    40,40,
    46,46,46,55,
    46,46,46,55,
    46,46,46,55,
    61,61,61,65,65,70,
    61,61,61,65,65,70,
    71,71,71,75,
    71,71,71,75,
    76,76,76,80,
    81,81,86,86,90,81,
    81,81,81,86,86,90,
    96,96,96,100,
    96,96,96,100,
    96,96,96,100,
    106,106,106,110,
    116,116,116,120,
    116,116,116,120,
    126,126,
    126,126,126,136,
    126,126
    };
    const uint8_t Xstop[] = {
        // Y value for the start of the line
    16,17,164,163,
    40,40,
    164,164,
    40,40,142,142,142,142,
    142,142,
    46,55,55,55,
    46,55,55,55,
    46,55,55,55,
    61,65,70,65,70,70,
    61,70,65,65,70,70,
    71,75,75,75,
    71,75,75,75,
    76,80,80,80,
    81,85,86,90,90,90,
    81,90,86,86,90,90,
    96,100,100,100,
    96,100,100,100,
    96,100,100,100,
    106,110,110,110,
    116,120,120,120,
    116,120,120,120,
    126,141,
    126,136,136,136,
    126,141
    };
    const uint8_t Ybegin[] = {
        // Y value for the end of the line
    61,61,61,61,
    60,70,
    60,70,
    20,70,20,20,111,70,
    47,83,
    63,63,67,63,
    53,53,57,53,
    73,73,77,73,
    48,48,62,48,58,58,
    68,68,82,72,72,68,
    48,48,52,48,
    78,78,82,78,
    58,58,72,58,
    48,52,52,62,48,48,
    78,82,78,68,68,68,
    53,53,57,53,
    63,63,67,63,
    73,73,77,73,
    53,53,77,53,
    53,53,62,53,
    68,68,77,68,
    48,57,
    63,63,67,63,
    73,73
    };
    const uint8_t Ystop[] = {
    // what kind of Hex character to draw that specific line
    69,69,69,69,
    60,70,
    60,70,
    60,110,20,60,111,111,
    47,83,
    67,63,67,67,
    57,53,57,57,
    77,73,77,77,
    62,48,62,58,58,62,
    82,68,82,82,72,72,
    52,48,52,52,
    82,78,82,82,
    72,58,72,72,
    52,52,62,62,62,48,
    82,82,78,77,68,82,
    57,53,57,57,
    67,63,67,67,
    77,73,77,77,
    77,53,77,77,
    62,53,62,62,
    77,68,77,77,
    57,57,
    67,63,67,67,
    82,73
    };
    char charType[] = {
    0xAF,0xAF,0xAF,0xAF,
    0xB2,0xB2,
    0xB2,0xB2,
    0xB2,0xB2,0xB2,0xB2,0xB2,0xB2,
    0xB2,0xB2,
    0xB2,0xB2,0xB2,0xB2,
    0xB2,0xB2,0xB2,0xB2,
    0xB2,0xB2,0xB2,0xB2,
    0xB2,0xB2,0xB2,0xB2,0xB2,0xB2,
    0xB2,0xB2,0xB2,0xB2,0xB2,0xB2,
    0xB2,0xB2,0xB2,0xB2,
    0xB2,0xB2,0xB2,0xB2,
    0xB2,0xB2,0xB2,0xB2,
    0xB2,0xB2,0xB2,0xB2,0xB2,0xB2,
    0xB2,0xB2,0xB2,0xB2,0xB2,0xB2,
    0xB2,0xB2,0xB2,0xB2,
    0xB2,0xB2,0xB2,0xB2,
    0xB2,0xB2,0xB2,0xB2,
    0xB2,0xB2,0xB2,0xB2,
    0xB2,0xB2,0xB2,0xB2,
    0xB2,0xB2,0xB2,0xB2,
    0xB2,0xB2,
    0xB2,0xB2,0xB2,0xB2,
    0xB2,0xB2
    };

    //Sets all the walls drawing in the drawing buffer
    for(uint8_t i = 0; i<(sizeof(Ystop)); i++){
        DrawingSetValues(drawValues, Xbegin[i], Ybegin[i], Xstop[i], Ystop[i], charType[i]);
    }
    //frees up Xbegin, Ystop, Xstop

    //Gives the collider the hitbox of the walls
    setWallHitBox(drawValues,SetPos(2), wallHitBox);
    //Draws the entire maze
    DrawEverything(drawValues);
}



void thirdMapSetup(struct drawItems *drawValues, struct wallHitBox *wallHitBox) {

//Coordinates for all the walls in the first maps maze
// X value for the start of the line
    const uint8_t Xbegin[] = {
        // X value for the end of the line
    16,17,164,163,
    16,16,
    141,141,
    40,40,40,142,40,142,
    40,40,
    41,46,46,50,50,81,71,71,71,76,71,71,71,80,81,90,90,96,96,105,105,131,131,136,136,40,50,50,56,56,61,56,56,56,65,60,60,60,65,65,96,86,86,86,105,105,131,131,136,136,111,111,115,115,121,121,125,121,121,115,115,111
    };
    const uint8_t Xstop[] = {
         // Y value for the start of the line
    16,17,164,163,
    40,40,
    164,164,
    40,40,142,142,142,142,
    142,142,
    46,46,50,50,81,81,81,71,76,76,76,71,80,80,90,90,96,96,105,105,131,131,136,136,140,50,50,56,56,61,61,61,56,65,65,65,60,65,65,96,96,96,86,105,105,131,131,136,136,140,111,115,115,121,121,125,125,125,121,121,115,115
    };
    const uint8_t Ybegin[] = {
        // Y value for the end of the line
    61,61,61,61,
    60,70,
    60,70,
    20,70,20,20,111,70,
    47,83,
    56,56,66,51,51,51,57,57,61,61,67,67,76,61,61,56,56,56,61,51,51,51,61,60,60,72,72,77,67,67,61,61,57,57,57,71,71,77,77,82,76,76,67,67,67,77,66,66,67,70,57,57,57,62,57,57,57,71,66,66,66,71
    };
    const uint8_t Ystop[] = {
        // What kind of Hex character to draw that specific line
    69,69,69,69,
    60,70,
    60,70,
    60,110,20,60,111,111,
    47,83,
    56,66,66,66,51,57,57,61,61,67,67,76,76,76,61,61,56,61,61,61,51,61,61,61,60,72,77,77,77,67,67,61,61,57,71,71,77,77,82,82,82,76,76,67,77,77,77,66,70,70,71,57,62,62,62,57,71,71,71,66,71,71
    };
    char charType[] = {
    0xAF,0xAF,0xAF,0xAF,
    0xB2,0xB2,
    0xB2,0xB2,
    0xB2,0xB2,0xB2,0xB2,0xB2,0xB2,
    0xB2,0xB2,
    0xB2,0xB2,0xB2,0xB2,0xB2,0xB2,0xB2,0xB2,0xB2,0xB2,0xB2,0xB2,0xB2,0xB2,0xB2,0xB2,0xB2,0xB2,0xB2,0xB2,0xB2,0xB2,0xB2,0xB2,0xB2,0xB2,0xB2,0xB2,0xB2,0xB2,0xB2,0xB2,0xB2,0xB2,0xB2,0xB2,0xB2,0xB2,0xB2,0xB2,0xB2,0xB2,0xB2,0xB2,0xB2,0xB2,0xB2,0xB2,0xB2,0xB2,0xB2,0xB2,0xB2,0xB2,0xB2,0xB2,0xB2,0xB2,0xB2,0xB2,0xB2,0xB2
    };

    //Sets all the walls drawing in the drawing buffer
    for(uint8_t i = 0; i<(sizeof(Ystop)); i++){
        DrawingSetValues(drawValues, Xbegin[i], Ybegin[i], Xstop[i], Ystop[i], charType[i]);
    }
    //frees up Xbegin, Ystop, Xstop
    /* free(&Xbegin);
    free(&Ybegin);
    free(&Xstop);
 */
    //Gives the collider the hitbox of the walls
    setWallHitBox(drawValues,SetPos(2), wallHitBox);
    //Draws the entire maze
    DrawEverything(drawValues);
}



void fourthMapSetup(struct drawItems *drawValues, struct wallHitBox *wallHitBox){
    const uint8_t Xbegin[] = {
    16,17,164,163,
    16,16,
    141,141,
    40,40,40,141,40,141,
    46,46,46,66,66,70,46,46,46,56,60,60,56,
    46,50,50,60,46,46,50,50,
    46,46,
    };
    const uint8_t Xstop[] = {
    16,17,164,163,
    40,40,
    164,164,
    40,40,141,141,141,141,
    66,46,66,66,66,70,66,56,46,56,60,70,60,
    46,50,50,60,50,50,60,60,

    };
    const uint8_t Ybegin[] = {
    61,61,61,61,
    60,70,
    60,70,
    27,70,27,27,103,70,
    33,34,37,28,38,28,43,47,44,47,47,47,57,
    53,53,67,63,53,77,63,67,

    };
    const uint8_t Ystop[] = {
    69,69,69,69,
    60,70,
    60,70,
    60,102,27,60,103,103,
    33,36,37,32,42,46,43,47,46,57,57,47,57,
    77,63,77,67,53,77,63,67,
    ''
    };
    char charType[] = {
    0xAF,0xAF,0xAF,0xAF,
    0xB2,0xB2,
    0xB2,0xB2,
    0xB2,0xB2,0xB2,0xB2,0xB2,0xB2,
    0xB2,0xB2,0xB2,0xB2,0xB2,0xB2,0xB2,0xB2,0xB2,0xB2,0xB2,0xB2,0xB2,
    0xB2,0xB2,0xB2,0xB2,0xB2,0xB2,0xB2,0xB2,

    };
     for(uint8_t i = 0; i<(sizeof(Ystop)); i++){
        DrawingSetValues(drawValues, Xbegin[i], Ybegin[i], Xstop[i], Ystop[i], charType[i]);
    }
    //frees up Xbegin, Ystop, Xstop
    free(&Xbegin);
    free(&Ybegin);
    free(&Xstop);

    //Gives the collider the hitbox of the walls
    setWallHitBox(drawValues,SetPos(2), wallHitBox);
    //Draws the entire maze
    DrawEverything(drawValues);

}
