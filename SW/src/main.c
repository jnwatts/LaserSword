#include "pin_mux.h"
#include "clock_config.h"
#include "board.h"
#include "leds.h"
#include "buttons.h"
#include "timer.h"

#ifdef DEBUG
//TODO: Trim fat of debug console, else we currently over-shoot flash size by 50%
#include <fsl_debug_console.c>
#define DBG PRINTF
#else
#define DBG(...)
#define DBG(...)
#endif

int main(void)
{
	/* Init board hardware */
	BOARD_InitBootPins();
	BOARD_InitBootClocks();
	BOARD_InitDebugConsole();

	Timer_Init();

	Buttons_Init();
	Leds_Init();

	while (1) {
		if (Timer_Ready()) {
			if (ReadL1State() || ReadL2State()) {
				Leds_SetColor(LEDS_PURPLE);
			} else {
				Leds_SetColor(LEDS_OFF);
			}

			Leds_Think();
		}
	}
}