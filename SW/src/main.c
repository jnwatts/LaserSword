#include <fsl_ftm.h>

#include "pin_mux.h"
#include "clock_config.h"
#include "board.h"
#include "leds.h"
#include "buttons.h"

#ifdef DEBUG
//TODO: Trim fat of debug console, else we currently over-shoot flash size by 50%
#include <fsl_debug_console.c>
#define DBG PRINTF
#else
#define DBG(...)
#define DBG(...)
#endif

#define BOARD_PERIODIC_FTM FTM0
#define TICKS_PER_10MS (BOARD_FULLSPEED_CORE_CLOCK / 8 * 10/*ms*/)
ftm_config_t ftm_config;

int main(void)
{
	uint32_t status;

	/* Init board hardware */
	BOARD_InitBootPins();
	BOARD_InitBootClocks();
	BOARD_InitDebugConsole();

	FTM_GetDefaultConfig(&ftm_config);
	ftm_config.prescale = kFTM_Prescale_Divide_8;
	FTM_Init(BOARD_PERIODIC_FTM, &ftm_config);
	FTM_SetTimerPeriod(BOARD_PERIODIC_FTM, TICKS_PER_10MS);

	Buttons_Init();
	Leds_Init();

	FTM_StartTimer(BOARD_PERIODIC_FTM, kFTM_SystemClock);
	while (1) {
		status = FTM_GetStatusFlags(BOARD_PERIODIC_FTM);
		if (status & kFTM_TimeOverflowFlag) {
			FTM_ClearStatusFlags(BOARD_PERIODIC_FTM, kFTM_TimeOverflowFlag);

			if (ReadL1State() || ReadL2State()) {
				Leds_SetColor(LEDS_PURPLE);
			} else {
				Leds_SetColor(LEDS_OFF);
			}

			Leds_Think();
		}
	}
}