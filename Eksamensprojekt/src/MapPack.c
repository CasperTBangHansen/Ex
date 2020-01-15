#include <stdio.h>
#include "stm32f30x_conf.h"
#include "30010_io.h"
#include "Drawing.h"
#include "MapPack.h"

void MapSelection() {
    struct drawItems drawValues[1000];
     // Begrænsninginger for window (X : 10 -> 160, Y : 5 -> 55)
     // HEX CODES FOR WALLS IN GAME
     // Horizontal 0xCD
     // Vertical 0xBA
     // top left 0xC9
     // top right 0xBB
     // bottom right 0xBC
     // bottom left 0xC8
     // Outline for middle box ( X = 51 -> 119, Y = 16 -> 43 )
    uint16_t Xbegin[] = {
    11,12,158,159, // Left side entrance, right side exit
    11,11,16,16,16,16,17,17,17,17,18,18, // Left side tunnel
    120,120,153,153,153,153,154,154,154,154,155,155, // right side tunnel
    51,51,51,51,51,51,52,52,119,119,119,119,119,119, //outline for middle "map area"
    53,53,53,65, //  Top left box
    67,67,67,80, // Box to the right of the above
    67,67,67,90, // Box below the above
    53,53,53,65, // box to the left of the above
    53,53,53,94, // long right box below entrance
    53,53,53,66, // lower left corner box
    68,68,68,82, // to the right of above
    84,84,84,94, // to the right of above
    67,67,67,94, // Small long box above long long box
    92,92,92,94, // Vertical long box
    96,96,96,97 // Vertical line
    };
    uint16_t Xstop[] = {
    11,12,158,159,
    15,15,16,16,16,16,17,17,17,17,50,50,
    152,152,153,153,153,153,154,154,154,154,159,159,
    51,51,51,51,51,51,118,118,119,119,119,119,119,119,
    65,65,53,65,
    80,80,67,80,
    90,90,67,90,
    65,65,53,65,
    94,94,53,94,
    66,66,53,66,
    82,82,68,82,
    94,94,84,94,
    94,94,67,94,
    94,94,92,94,
    97,97,96,97
    };
    uint8_t Ybegin[] = {
    27,27,27,27,
    26,32,26,32,27,31,27,31,28,30,28,30,
    28,30,28,30,27,31,27,31,26,32,26,32,
    28,30,16,31,15,43,15,43,15,43,16,31,28,30,
    17,22,17,17,
    17,19,17,17,
    21,28,21,21,
    24,32,24,24,
    34,36,34,34,
    38,41,38,38,
    38,41,38,38,
    38,41,38,38,
    30,32,30,30,
    17,28,17,17,
    17,41,17,17
    };
    uint8_t Ystop[] = {
    31,31,31,31,
    26,32,26,32,27,31,27,31,28,30,28,30,
    28,30,28,30,27,31,27,31,26,32,26,32,
    28,30,27,42,15,43,15,43,15,43,27,42,28,30,
    17,22,22,22,
    17,19,19,19,
    21,28,28,28,
    24,32,32,32,
    34,36,36,36,
    38,41,41,41,
    38,41,41,41,
    38,41,41,41,
    30,32,32,32,
    17,28,28,28,
    17,41,41,41
    };
    char charType[] = {
    0xAF,0xAF,0xAF,0xAF,
    0xBCD,0xCD,0xBB,0xBC,0xC8,0xC9,0xBB,0xBC,0xC8,0xC9,0xCD,0xCD,
    0xCD,0xCD,0xBC,0xBB,0xC9,0xC8,0xBC,0xBB,0xC9,0xC8,0xCD,0xCD,
    0xBC,0xBB,0xBA,0xBA,0xC9,0xC8,0xCD,0xCD,0xBB,0xBC,0xBA,0xBA,0xC8,0xC9,
    0xDB,0xDB,0xDB,0xDB,
    0xDB,0xDB,0xDB,0xDB,
    0xDB,0xDB,0xDB,0xDB,
    0xDB,0xDB,0xDB,0xDB,
    0xDB,0xDB,0xDB,0xDB,
    0xDB,0xDB,0xDB,0xDB,
    0xDB,0xDB,0xDB,0xDB,
    0xDB,0xDB,0xDB,0xDB,
    0xDB,0xDB,0xDB,0xDB,
    0xDB,0xDB,0xDB,0xDB,
    0xDB,0xDB,0xDB,0xDB
    };

    for(uint8_t i = 0; i<(sizeof(charType)); i++){
            DrawingSetValues(&drawValues, Xbegin[i], Ybegin[i], Xstop[i], Ystop[i], charType[i]);
    }
    DrawEverything(&drawValues);
}
/* case level_2 {
    struct drawItems drawValues[1000];
     // Arrays for maps. First 4 are game window outline in order (Top,left,right,bottom).
     // Next 4 are the different game window corners, in the order (Top left, Top right, Bottom left, Bottom Right)
     // Next 3 are are the lines for the high score window (Top, Right, Bottom)
     // Next 2 are the top right corner and then bottom right corner
    uint16_t Xbegin[] = {};
    uint16_t Xstop[] = {};

    uint8_t Ybegin[] = {};
    uint8_t Ystop[] = {};


    char charType[] = {};

    for(uint8_t i = 0; i<(sizeof(CharType)); i++){
            DrawingSetValues(&drawValues, Xbegin[i], Ybegin[i], Xstop[i], Ystop[i], charType[i]);
    }
    DrawEverything(&drawValues);
}*/


