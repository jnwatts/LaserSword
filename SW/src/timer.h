#ifndef TIMER_H
#define TIMER_H

#include <stdbool.h>

#include <fsl_ftm.h>

#include "board.h"

void Timer_Init(void);

static inline bool Timer_Ready(void) {
	uint32_t status;

	status = FTM_GetStatusFlags(BOARD_TIMER_FTM);
	if (status & kFTM_TimeOverflowFlag) {
		FTM_ClearStatusFlags(BOARD_TIMER_FTM, kFTM_TimeOverflowFlag);
		return true;
	}

	return false;
}

#endif