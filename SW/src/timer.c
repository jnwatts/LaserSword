#include "timer.h"

#define TICKS_PER_10MS (BOARD_FULLSPEED_CORE_CLOCK / 8 * 10/*ms*/)
ftm_config_t ftm_config;

void Timer_Init(void)
{
	FTM_GetDefaultConfig(&ftm_config);
	ftm_config.prescale = kFTM_Prescale_Divide_8;
	FTM_Init(BOARD_TIMER_FTM, &ftm_config);
	FTM_SetTimerPeriod(BOARD_TIMER_FTM, TICKS_PER_10MS);

	FTM_StartTimer(BOARD_TIMER_FTM, kFTM_SystemClock);
}