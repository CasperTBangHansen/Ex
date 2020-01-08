// =====================================================================
//
//	Exported by Cearn's excellut v1.0
//	(comments, kudos, flames to daytshen@hotmail.com)
//
// =====================================================================

#include <stdio.h>

#ifndef SINEXPORT_H
#define SINEXPORT_H

// === LUT SIZES ===
#define SIN_SIZE 512

// === LUT DECLARATIONS ===
extern const signed short SIN[512];
int32_t calcSINUS(int32_t angle);
int32_t calcCOSINUS(int32_t angle);

#endif	// JI_H
